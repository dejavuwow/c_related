#include <stdio.h>
#include "./nfa.h"

int *getEpsilonClosure(NFA *nfa, int state, HashTable table) {

	Node *node = GET_DATA(nfa->stateTable, state);
	if (!GET_DATA(table, node->value)) {
		INSERT_HASH_TABLE(table, node->value, node);
	}
	Link *link = GET_DATA(node->adjTable, EPSILON);
	Link *temp;
	LINK_ITER(link, temp) {
		int value = ((Node*)(temp->node))->value;
		if (!GET_DATA(table, value)) {
			INSERT_HASH_TABLE(table, value, temp->node);
			getEpsilonClosure(nfa, value, table);
		}	
	}
}

void *move(NFA *nfa, int c, HashTable old, HashTable new) {
	
	Link *temp1, *temp2;
	Node *node;
	HASH_ITER(old, temp1, temp2, node) {
		Node *get = GET_DATA(nfa->stateTable, node->value);
		if (NULL != get) {
			getEpsilonClosure(nfa, get->value, new);
		}
	}
}

int match(NFA *nfa, char *s) {
	getEpsilonClosure(nfa, nfa->start, set, &l);
	int resLength;
	for (; *s != '\0'; s++) {
		resLength = 0;
		 moveSet(nfa, set, l, *s, res, &resLength);
		 l = 0;
		 for (int j = 0; j < resLength; j++) {
			 set[l++] = res[j];
		 }
	}

}

char *getMatchWord(NFA *nfa, char *s) {
}

int main(void) {
	NFA *nfa1 = buildNFA("ab|cd|ab*(ab|cd)ce*");
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
