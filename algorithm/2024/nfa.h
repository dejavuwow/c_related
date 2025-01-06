//31 * (1 - 128)
//6  33 1 13
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define MAX_SIZE 131
#define EPSILON 0


typedef struct HashTable HashTable;

typedef struct Link {
	void *node;
	void *next;
	int key;
} Link;

struct HashTable {
	Link *table[MAX_SIZE];
	Link *next;
	int size;
};

typedef struct Node {
	int value;
	HashTable adjTable;
} Node;


typedef struct NFA {
	int acceptNum;
	int stateNum;
	Node *accept[MAX_SIZE];
	HashTable stateTable;
} NFA;
#define LINK_ITER(head, temp) for (temp = head, head = head ? head->next : NULL; temp != NULL; temp = head, head = head ? head->next : NULL)

#define INIT_HASH_TABLE(__table__) {\
	__table__.size = 0;\
	__table__.next = NULL;\
	for (int i = 0; i < MAX_SIZE; i++) {\
		__table__.table[i] = NULL;\
	}\
}
#define HASH_ITER(table, temp1, temp2, __node__) for (temp1 = table.next, temp2 = temp1 ? temp1->next : NULL, __node__ = temp1 ? temp1->node : NULL; temp1 != NULL; temp1 = temp2, temp2 = temp1 ? temp1->next : NULL, __node__ = temp1 ? temp1->node : NULL)

#define INIT_NODE(__value__) ({\
	Node *node = malloc(sizeof(Node));\
	node->value = __value__;\
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

#define INSERT_HASH_TABLE(__table__, k, __node__) {\
	Link *next = (__table__).next;\
	(__table__).table[k] = malloc(sizeof(Link));\
	(__table__).next = (__table__).table[k];\
	(__table__).table[k]->next = next;\
	(__table__).table[k]->node = __node__;\
	(__table__).size++;\
}

#define GET_DATA(__table__, k) ((__table__).table[k] ? (__table__).table[k]->node : NULL)

#define INSERT_ADJTABLE(fromNode, k, toNode) {\
	HashTable *table = &((fromNode)->adjTable);\
	Link *link = GET_DATA((*table), k);\
	if (NULL == link) {\
		link = malloc(sizeof(Link));\
		link->next = NULL;\
		link->node = toNode;\
		link->key = k;\
		INSERT_HASH_TABLE((*table), k, link)\
	} else {\
		Link *next = link->next;\
		link->next = malloc(sizeof(Link));\
		((Link*)(link->next))->node = toNode;\
		((Link*)(link->next))->next = next;\
	}\
}
#define TRANS_ITER(nfa, func) {\
	Link *temp1, *temp2;\
	Node *node;\
	HASH_ITER(nfa->stateTable, temp1, temp2, node) {\
		Link *t1, *t2, *t3;\
		Link *n;\
		HASH_ITER(node->adjTable, t1, t2, n) {\
			int key = n->key;\
			LINK_ITER(n, t3) {\
				func(node->value, ((Node*)(t3->node))->value, key);\
			}\
		}\
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
	assert(nfa->accept[0] != NULL);

	return nfa;
}

void freeNfa(NFA *nfa) {
	Link *link1, *link2;
	Node *node;
	HASH_ITER(nfa->stateTable, link1, link2, node) {
		Link *subLink1, *subLink2;
		Link *subNode;
		HASH_ITER(node->adjTable, subLink1, subLink2, subNode) {
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
	free(nfa);
}

NFA *concatNfa(NFA *nfa1, NFA *nfa2) {
	Node *nfa2StartNode = GET_DATA(nfa2->stateTable, 0);
	Node *nfa1AcceptNode = nfa1->accept[0];
	int offset = nfa1->stateNum - 1;
	Link *temp1, *temp2;
	Node *node;


	#define ADD_TRAN(from, to, key) {\
		int f = from  == 0 ? nfa1AcceptNode->value : from + offset;\
		addTran(nfa1, from, to + offset, key);\
	}
	TRANS_ITER(nfa2, ADD_TRAN);

	nfa1->accept[0] = GET_DATA(nfa1->stateTable, nfa2->accept[0]->value + offset);

	freeNfa(nfa2);
	return nfa1;
}

NFA *addAlternative(NFA *nfa1, NFA *nfa2) {

	NFA *nfa = concatNfa(getSingleNfa(EPSILON), nfa1);
	int offset = nfa->stateNum;
	addTran(nfa, 0, 0 + offset, EPSILON);
	#undef ADD_TRAN
	#define ADD_TRAN(from, to, key) {\
		addTran(nfa, from + offset, to + offset, key);\
	}

	TRANS_ITER(nfa2, ADD_TRAN);
	int acceptVal = nfa2->accept[0]->value + offset;
	addTran(nfa, nfa->accept[0]->value, acceptVal + 1, EPSILON);
	addTran(nfa, acceptVal, acceptVal + 1, EPSILON);
	nfa->accept[0] = GET_DATA(nfa->stateTable, acceptVal + 1);

	freeNfa(nfa2);
	
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
		printf("%c \n", *regular);
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



