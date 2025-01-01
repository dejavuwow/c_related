#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define EPSILON -1
#define MAX_SIZE 1000
int includes(int *set, int l, int value) {
	for (int i = 0; i < l; i++) {
		if (set[i] == value) return 1;
	}
	return 0;
}
typedef struct Tran {
	int from;
	int to;
	int symbol;
} Tran;

typedef struct NFA {
	int start;
	int accept;
	int stateNum;
	int transNum;
	Tran *trans[MAX_SIZE];
} NFA;

void addTran(NFA *nfa, int from, int to, int symbol) {
	Tran *tran = (Tran*)malloc(sizeof(Tran));

	tran->from = from;
	tran->to = to;
	tran->symbol = symbol;

	nfa->trans[nfa->transNum++] = tran;
}

NFA *getSingleNfa(int symbol) {
	NFA *nfa = malloc(sizeof(NFA));

	nfa->start = 0;
	nfa->accept = 1;
	nfa->stateNum = 2;
	nfa->transNum = 0;

	addTran(nfa, 0, 1, symbol);
	return nfa;
}


//0->1->2   0->1->2
NFA *concatNfa(NFA *nfa1, NFA *nfa2) {
	int offset = nfa1->stateNum - 1;
	nfa1->stateNum += offset;
	
	for (int i = 0; i < nfa2->transNum; i++) {
		int from = nfa2->start == nfa2->trans[i]->from ? nfa1->accept : nfa2->trans[i]->from + offset;

		addTran(nfa1, from, nfa2->trans[i]->to + offset, nfa2->trans[i]->symbol);
		free(nfa2->trans[i]);
		nfa2->trans[i] = NULL;
	}
	nfa1->accept = nfa2->accept + offset - 1;
	free(nfa2);
	return nfa1;
}

NFA *addAlternative(NFA *nfa1, NFA *nfa2) {

	NFA *nfa = concatNfa(getSingleNfa(EPSILON), nfa1);
	int offset = nfa->stateNum;
	nfa->stateNum += (nfa2->stateNum + 1);
	addTran(nfa, nfa->start, nfa2->start + offset, EPSILON);
	for (int i = 0; i < nfa2->transNum; i++) {
		addTran(nfa, nfa2->trans[i]->from + offset, nfa2->trans[i]->to + offset, nfa2->trans[i]->symbol);
		free(nfa2->trans[i]);
		nfa2->trans[i] = NULL;
	}
	free(nfa2);
	addTran(nfa, nfa->accept, nfa->stateNum - 1, EPSILON);
	addTran(nfa, nfa->stateNum - 2, nfa->stateNum - 1, EPSILON);
	nfa->accept = nfa->stateNum - 1;

	return nfa;
}

NFA *addKleene(NFA *nfa) {
	addTran(nfa, nfa->accept, nfa->start, EPSILON);
	NFA *nfa1 = getSingleNfa(EPSILON);
	NFA *nfa2 = getSingleNfa(EPSILON);
	nfa = concatNfa(nfa1, nfa);
	nfa = concatNfa(nfa, nfa2);
	addTran(nfa, nfa->start, nfa->accept, EPSILON);

	return  nfa;
}

NFA *buildNFA(char *regular) {
	NFA	*stack[100];
	NFA *n1, *n2, *n3, *n4;
	int top = -1;
	int hasAlternative = 0;
	stack[++top] = getSingleNfa(EPSILON);
	for (; *regular != '\0'; regular++) {
		printf("%c ", *regular);
		switch (*regular) {
			case '(':
				stack[++top] = getSingleNfa(EPSILON);
				break;
			case ')':
				if (hasAlternative) {
					n1 = stack[top--];
					n2 = stack[top--];
					n3 = top >= 0 ? stack[top--] : NULL;
					n4 = addAlternative(n1, n2);
					stack[++top] = n3 ? concatNfa(n3, n4) : n4;
				}
				hasAlternative = 0;
				break;
			case '*':
				n1 = addKleene(stack[top--]);
				n2 = top >= 0 ? stack[top--] : NULL;
				stack[++top] = n2 ? concatNfa(n2, n1) : n1;
				break;
			case '|':
				if (hasAlternative) {
					n1 = stack[top--];
					n2 = stack[top--];
					n3 = top >= 0 ? stack[top--] : NULL;
					n4 = addAlternative(n1, n2);
					stack[++top] = n3 ? concatNfa(n3, n4) : n4;
				}
				hasAlternative = 1;
				stack[++top] = getSingleNfa(EPSILON);
				break;
			default:
				n1 = stack[top--];
				n2 = getSingleNfa(*regular);
				if (*(regular + 1) == '*') {
					n2 = addKleene(n2);
					regular++;
				}
				stack[++top] = concatNfa(n1, n2);
				break;
		}
	}
	return stack[top];
}
int *getEpsilonClosure(NFA *nfa, int state, int *set, int *length) {
	int l = 0;
	set[l++] = state;
	int hasNew = 1;
	while (hasNew) {
		hasNew = 0;
		for (int i = 0; i < nfa->transNum; i++) {
			if (includes(set, l, nfa->trans[i]->from) && nfa->trans[i]->symbol == EPSILON && !includes(set, l, nfa->trans[i]->to)) {
				set[l++] = nfa->trans[i]->to;
				hasNew = 1;
			}
		}
	}
	*length = l;
	return set;
}

int *move(NFA *nfa, int state, int c, int *res, int *resLength) {
	for (int j = 0; j < nfa->transNum; j++) {

		int subRes[nfa->stateNum];
		int l = 0;
		if (state == nfa->trans[j]->from && c == nfa->trans[j]->symbol) {
			getEpsilonClosure(nfa, nfa->trans[j]->to, subRes, &l);
			for (int k = 0; k < l; k++) {
				if (!includes(res, *resLength, subRes[k])) {
					res[(*resLength)++] = subRes[k];
				}
			}
		}
	}
}

int *moveSet(NFA *nfa, int *set, int l, int c, int *res, int *resLength) {
	for (int i = 0; i < l; i++) {
		int subRes[nfa->stateNum];
		int n = 0;
		move(nfa, set[i], c, subRes, &n);
		printf("****%d\n", n);
		for (int j = 0; j < n; j++) {
			if (!includes(res, *resLength, subRes[j])) {
				res[(*resLength)++] = subRes[j];
			}
		}
	}
	return res;
}

int match(NFA *nfa, char *s) {
	int vol = nfa->stateNum;
	printf("^^^^^^^^^^%d\n", vol);
	int l = 0;
	int set[vol];
	int res[vol];
	getEpsilonClosure(nfa, nfa->start, set, &l);
	int resLength;
	for (; *s != '\0'; s++) {
		printf("%c \n", *s);
		resLength = 0;
		 moveSet(nfa, set, l, *s, res, &resLength);
		 printf("%d\n", resLength);
		 l = 0;
		 for (int j = 0; j < resLength; j++) {
			 set[l++] = res[j];
		 }
	}
	printf("DDDDD");
	while (resLength) {
		if (set[--resLength] == nfa->accept) return 1;
	}
	return 0;
}
int main(void) {
	NFA *nfa = buildNFA("ab*(abc|ab)aa*");
	printf("%d***", match(nfa, "aabcaaaaa"));
	return 0;
}
