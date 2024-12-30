#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int *transTable;
void buildNFA(char *regular) {
	for (; *regular != '\0'; ) {
		switch (*regular) {
			case '(':
				buildNFA(++regular);
				break
			case ')':
				regular++;
				break;
			case '*':


		}
	}
}


