//31 * (1 - 128)
//6  33 1 13
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_SIZE 131
#define EPSILON 0


typedef struct HashTable HashTable;

typedef struct Node {
	int value;
	HashTable adjTable;
} Node;


typedef struct Link {
	void *node;
	void *next;
} Link;

struct HashTable {
	Link *table[MAX_SIZE];
	Link *next;
	int size;
};


typedef struct NFA {
	int acceptNum;
	int stateNum;
	Node *accept[MAX_SIZE];
	HashTable stateTable;
} NFA;
#define LINK_ITER(head, temp) (temp = head, head = head ? head->next : NULL; temp != NULL; temp = head, head = head ? head->next : NULL)

#define INIT_HASH_TABLE(table) {\
	table.size = 0;\
	table.next = NULL;\
	for (int i = 0; i < MAX_SIZE; i++) {\
		table.table[i] = NULL;\
	}\
}
#define HASH_ITER(table, temp1, temp2, node) for (temp1 = table.next, temp2 = temp1 ? temp1->next : NULL, node = temp1 ? temp1->node : NULL; temp1 != NULL; temp1 = temp2, temp2 = temp1 ? temp1->next : NULL, node = temp1 ? temp1->node : NULL)

#define INIT_NODE(value) ({\
	Node *node = malloc(sizeof(node));\
	node->value = value;\
	INIT_HASH_TABLE(node->adjTable);\
	node;\
})

#define INIT_NFA() ({\
	NFA *nfa = malloc(sizeof(NFA));\
	nfa->stateNum = 0;\
	nfa->acceptNum = 0;\
	INIT_HASH_TABLE(nfa->stateTable);\
	nfa;\
})

#define INSERT_HASH_TABLE(table, k, node) {\
	Link *next = table.next;\
	table.table[k] = malloc(sizeof(Link));\
	table.next = table[k];\
	table[k]->next = next;\
	table.table[k]->node = node;\
	table.size++;\
}

#define GET_DATA(table, k) ((table).table[k] ? (table).table[k]->node : NULL)

#define INSERT_ADJTABLE(fromNode, k, toNode) {\
	HashTable table = (fromNode)->adjTable;\
	Link *link = GET_DATA(table, k);\
	if (NULL == link) {\
		link = malloc(sizeof(Link));\
		link->next = NULL;\
		link->node = toNode;\
		INSERT_HASH_TABLE(table, k, link)\
	} else {\
		link *next = link->next;\
		link->next = malloc(sizeof(Link));\
		link->next->node = toNode;\
		link->next->next = next;\
	}\
}


void addTran(NFA *nfa, int from, int to, int symbol) {
	Node *fromNode = GET_DATA(nfa->stateTable, from),
		 *toNode = GET_DATA(nfa->stateTable, to);
	if (NULL == fromNode) {
		fromNode = INIT_NODE(from);
		INSERT_HASH_TABLE(nfa->stateTable, from, fromNode);
		nfa->stateNum++;
	}
	if (NULL == toNode) {
		toNode = INIT_NODE(to);
		INSERT_HASH_TABLE(nfa->stateTable, to, toNode);
		nfa->stateNum++;
	}
	INSERT_ADJTABLE(fromNode, symbol, toNode);
}

NFA *getSingleNfa(int symbol) {
	NFA *nfa = INIT_NFA();
	addTran(nfa, 0, 1, symbol);
	nfa->accept[nfa->acceptNum++] = GET_DATA(nfa->stateTable, 1);
	return nfa;
}

void freeNfa(NFA *nfa) {
	Link *link1, *link2;
	Node *node;
	HASH_ITER(nfa.stateTable, link1, link2, node) {
		Link *subLink1, *subLink2;
		Node *subNode;
		HASH_ITER(node.adjTable, subLink1, subLink2, subNode) {
			Link *temp;
			LINK_ITER(subNode, temp) {
				temp->next = NULL;
				temp->node = NULL;
				free(temp);
			}
			subLink1->node = NULL;
			subLink1->next = NULL;
			free(subLink1);
		}
		free(node);
		link1->next = NULL;
		link1->node = NULL;
		free(link1);
	}
	free(nfa)
}

NFA *concatNfa(NFA *nfa1, NFA *nfa2) {
	Node *nfa2StartNode = nfa2->stateTable[0];
	NodeList *list = nfa2StartNode->adjTable.table;
	int offset = nfa1->stateNum - 1;


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


