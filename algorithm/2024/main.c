#include <stdio.h>
#include "./nfa.h"

int *getEpsilonClosure(NFA *nfa, int state, HashTable *table) {

	Node *node = GET_DATA(nfa->stateTable, state);
	if (!GET_DATA(*table, node->value)) {
		INSERT_HASH_TABLE(*table, node->value, node);
	}
	Link *link = GET_DATA(node->adjTable, EPSILON);
	Link *temp;
	LINK_ITER(link, temp) {
		int value = ((Node*)(temp->node))->value;
		Link *temp1, *temp2;
		Node *temp3;
		getEpsilonClosure(nfa, value, table);
	}
}

void *move(NFA *nfa, int c, HashTable *old, HashTable *new) {
	
	Link *temp1, *temp2;
	Node *node;
	HASH_ITER(*old, temp1, temp2, node) {
		Link *list = GET_DATA(node->adjTable, c);
		if (NULL == list) continue;
		Link *temp;
		LINK_ITER(list, temp) {
			getEpsilonClosure(nfa, ((Node*)(temp->node))->value, new);
		}
	}

}

void transerHashTable(HashTable *target, HashTable *origin) {
	
	Link *temp1, *temp2;
	Node *temp3;
	HASH_ITER(*target, temp1, temp2, temp3) {
		temp1->next = NULL;
		temp1->node = NULL;
		free(temp1);
		target->table[temp3->value] = NULL;
	}
	target->next = NULL;
	HASH_ITER(*origin, temp1, temp2, temp3) {
		INSERT_HASH_TABLE(*target, temp3->value, temp3);
		temp1->next = NULL;
		temp1->node = NULL;
		free(temp1);
		origin->table[temp3->value] = NULL;
	}
	origin->next = NULL;
}

int match(NFA *nfa, char *s) {

	Link *temp1, *temp2;
	Node *temp3;
	HashTable old, new;

	INIT_HASH_TABLE(old);
	INIT_HASH_TABLE(new);

	getEpsilonClosure(nfa, 0, &old);


	for (; *s != '\0'; s++) {
		move(nfa, *s, &old, &new);
		transerHashTable(&old, &new);
		 
	}
	HASH_ITER(old, temp1, temp2, temp3) {
		if (temp3 == nfa->accept[0]) return 1;
	}
	return 0;

}

char *getMatchWord(NFA *nfa, char *s) {
}

int main(void) {
	NFA *nfa1 = buildNFA("(a|(b|dee*)*)");
	#undef FUNC
	#define FUNC(from, to, key) {\
		printf("%d--%c-->%d\n", from, key == 0 ? '#' : key, to);\
	}
	//TRANS_ITER(nfa1, FUNC);
	//printf("%d***", match(nfa1, "aabceeeeee"));
	printf("%d***", match(nfa1, "a"));
	printf("%d***", match(nfa1, "b"));
	printf("%d***", match(nfa1, "d"));
	printf("%d***", match(nfa1, "bdeebde"));
	//NFA *nfa2 = buildNFA("aa(ab|cd|a*d)c*");

	/**      char s[] = "IFcfkik"; */
	/** char *matchWord = getMatchWord(nfa1, s); */
	/** if (getMatchWord(nfa2, matchWord)) { */
	/**     for (char *c = s; c != matchWord; c++) { */
	/**         printf("%c", *c); */
	/**     } */
	/** } */

	//NFA *nfa = buildNFA("ab*");
	/**  for (int i = 0; i < nfa->transNum; i++) { */
	/** printf("%d--%c-->%d\n", nfa->trans[i]->from, nfa->trans[i]->symbol == EPSILON ? 'e' : nfa->trans[i]->symbol, nfa->trans[i]->to); */
	/** } */
	return 0;
}
