#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define EPSILON -1
#define MAX_SIZE 1000
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
	Trans *tran = malloc(sizeof(Tran));

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

NFA *addKleene(NFA *nfa) {
	addTran(nfa, nfa->accept, nfa->start, EPSILON);
	NFA *nfa1 = getSingleNfa(EPSILON);
	NFA *nfa2 = getSingleNfa(EPSILON);
	nfa = concatNfa(concatNfa(nfa1, nfa), nfa2);
	addTran(nfa, nfa->start, nfa->accept, EPSILON);

	return  nfa;
}

NFA *addAlternative(NFA *nfa1, NFA *nfa2) {

}

//0->1->2   0->1->2
NFA *concatNfa(NFA *nfa1, NFA *nfa2) {
	int offset = nfa1->stateNum - 1;
	nfa1->stateNum += offset;
	nfa1->transNum += nfa2->transNum;

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


buildNFA(char *regular) {
	NFA	*stack[100];
	int top = -1;
	int hasAlternative = 0;
	stack[++top] = getSingleNfa(EPSILON);
	for (; *regular != '\0'; ) {
		switch (*regular) {
			case '(':
				stack[++top] = getSingleNfa(EPSILON);
				break
			case ')':
				if (hasAlternative) {
					NFA *nfa1 = stack[top--];
					NFA *nfa2 = stack[top--];
					NFA *nfa3 = top >= 0 ? stack[top--] : NULL;
					NFA *nfa4 = addAlternative(nfa1, nfa2);
					stack[++top] = nfa3 ? concatNfa(nfa3, nfa4) nfa4:
				}
				hasAlternative = 0;
				break;
			case '*':
				NFA *nfa1 = stack[top--];
				NFA *nfa2 = top >= 0 ? stack[top--] : NULL;
				NFA *nfa3 = addKleene(nfa1);
				stack[++top] = nfa2 ? concatNfa(nfa2, nfa3) : nfa3;
				break;
			case '|':
				if (hasAlternative) {
					NFA *nfa1 = stack[top--];
					NFA *nfa2 = stack[top--];
					NFA *nfa3 = top >= 0 ? stack[top--] : NULL;
					NFA *nfa4 = addAlternative(nfa1, nfa2);
					stack[++top] = nfa3 ? concatNfa(nfa3, nfa4) nfa4:
				}
				hasAlternative = 1;
				stack[++top] = getSingleNfa(EPSILON);
				break;
			default:
				NFA *nfa1 = stack[top--];
				NFA *nfa2 = getSingleNfa(*regular);
				stack[++top] = concatNfa(nfa1, nfa2);
				break;
		}
	}
}


