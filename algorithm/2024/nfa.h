//31 * (1 - 128)
//6  33 1 13
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_SIZE 101
#define ALPHABET_SIZE 128
#define EPSILON 0


typedef struct HashTable HashTable;

typedef struct Node {
	int value;
	int edges[ALPHABET_SIZE];
	int edgeLength;
	HashTable adjTable;
} Node;

typedef struct NodeList {
	int size;
	Node *list[MAX_SIZE];
} NodeList;


struct HashTable {
	NodeList *table[ALPHABET_SIZE];
	int size;
};


typedef struct NFA {
	int acceptNum;
	int stateNum;
	int *stateList[MAX_SIZE];
	Node *accept[MAX_SIZE];
	Node *stateTable[MAX_SIZE];
} NFA;

#define INIT_NODE(value) ({\
	Node *node = malloc(sizeof(node));\
	node->value = value;\
	node->edgeLength = 0;\
	node->adjTable.size = 0;\
	node;\
})

#define INIT_NODE_LIST() ({\
	NodeList *list = malloc(sizeof(NodeList));\
	list->size = 0;\
	list;\
})

#define INIT_NFA() ({\
	NFA *nfa = malloc(sizeof(NFA));\
	nfa->stateNum = 0;\
	nfa->acceptNum = 0;\
	nfa;\
})

#define INSERT_NODE_LIST(list, node) {\
	list->list[list->size++] = node;\
}

#define INSERT_ADJTABLE(fromNode, c, toNode) {\
	HashTable *adjTable = fromNode->adjTable;\
	if (NULL == adjTable.table[c]) {\
		adjTable.table[c] = INIT_NODE_LIST();\
		fromNode->edges[fromNode->edgeLength++] = c;\
	}\
	INSERT_NODE_LIST(adjTable.table[c], toNode);\
}


void addTran(NFA *nfa, int from, int to, int symbol) {
	Node *fromNode = nfa->stateTable[from],
		 *toNode = nfa->stateTable[to];
	if (NULL == fromNode) {
		fromNode = INIT_NODE(from);
		nfa->stateList[nfa->stateNum++] = from;
	}
	if (NULL == toNode) {
		toNode = INIT_NODE(to);
		nfa->stateList[nfa->stateNum++] = to;
	}
	INSERT_ADJTABLE(fromNode, symbol, toNode);
}

NFA *getSingleNfa(int symbol) {
	NFA *nfa = INIT_NFA();
	addTran(nfa, 0, 1, symbol);
	nfa->accept[nfa->acceptNum++] = nfa->stateTable[1];
	return nfa;
}

void freeNfa(NFA *nfa) {
	for (int p = 0; p < nfa->stateNum; p++) {
		int i = nfa->stateList[p];
		NodeList *list = nfa->stateTable[i]->adjTable.table;
		for (int j = 0; j < nfa->stateTable[i]->edgeLength; j++) {
			int k = nfa->stateTable[i]->edges[j];
			free(list[k]);
			list[k] = NULL;
		}
		free(nfa->stateTable[i]);
		nfa->stateTable[i] = NULL;
	}
}

NFA *concatNfa(NFA *nfa1, NFA *nfa2) {
	Node *nfa2StartNode = nfa2->stateTable[0];
	NodeList *list = nfa2StartNode->adjTable.table;
	int offset = nfa1->stateNum - 1;

	//nfa1 accept gen nfa2 start trans

	for (int i = 0; i < nfa2->stateNum; i++) {
		int from = nfa2->stateList[i] == 0 ? nfa1->accept[0]->value : nfa2->stateList[i];
		Node *node = nfa2->stateTable[nfa2->stateList[i]];
		for (int j = 0; j < node->edgeLength; j++) {
			int k = node->edges[j];
			for (int n = 0; node->adjTable.table[k]->size; n++) {
				addTran(nfa1, from, node->adjTable.table[k]->list[n]->value + offset, k);
			}
		}
	}
	nfa1->accept[0] = nfa1->stateTable[nfa1->stateNum - 1];
	freeNfa(nfa2);
	return nfa1;
}

NFA *addAlternative(NFA *nfa1, NFA *nfa2) {

	NFA *nfa = concatNfa(getSingleNfa(EPSILON), nfa1);
	int offset = nfa->stateNum;
	addTran(nfa, nfa->accept[0]->value, 0 + offset, EPSILON);
	for (int i = 0; i < nfa2->stateNum; i++) {
		Node *node = nfa2->stateTable[nfa2->stateList[i]];
		for (int j = 0; j < node->edgeLength; j++) {
			int k = node->edges[j];
			for (int n = 0; node->adjTable.table[k]->size; n++) {
				addTran(nfa1, node->value + offset, node->adjTable.table[k]->list[n]->value + offset, k);
			}
		}

	}
	freeNfa(nfa2);
	addTran(nfa, nfa->accept[0]->value, nfa->stateNum - 1, EPSILON);
	addTran(nfa, nfa->stateNum - 2, nfa->stateNum - 1, EPSILON);
	nfa->accept[0] = nfa1->stateTable[nfa->stateNum - 1];

	return nfa;
}

NFA *addKleene(NFA *nfa) {
	addTran(nfa, nfa->accept[0]->value, 0, EPSILON);
	NFA *nfa1 = getSingleNfa(EPSILON);
	NFA *nfa2 = getSingleNfa(EPSILON);
	nfa = concatNfa(nfa1, nfa);
	nfa = concatNfa(nfa, nfa2);
	addTran(nfa, 0, nfa->accept[0]->value, EPSILON);

	return  nfa;
}

NFA *buildNFA(char *regular) {
	NFA	*stack[100];
	NFA *n1, *n2, *n3, *n4;
	int top = -1;
	int hasAlternative = 0;
	stack[++top] = getSingleNfa(EPSILON);
	for (; *regular != '\0'; regular++) {
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
	NodeList *list = nfa->stateTable[state]->adjTable.table[EPSILON];
	Node *list = nfa->stateTable[state]->adjTable.table[EPSILON]->list;
	*length = l;
	return set;
}


