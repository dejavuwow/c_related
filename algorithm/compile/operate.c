//节点n nullable firstpos
// n=c1?    true	firstpos(c1) lastpos()
// n=c1+	nullable(c1)o	
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100


void parseExpr(const char *str) {
	int nullableStack[MAX_SIZE];
	int nullTop = -1;

	int firstStack[MAX_SIZE][MAX_SIZE];
	int firstRowStack[MAX_SIZE];
	int firstRowTop = -1;
	int firstTop = -1;

	int lastStack[MAX_SIZE][MAX_SIZE];
	int lastRowStack[MAX_SIZE];
	int lastRowTop = -1;
	int lastTop = -1;


	for (char *c = str; c != '\0'; c++) {
		if ('(' == *c) {
			continue;
		} else if (')' == *c) {

				
		} else if ('*' == *c) {
			nullableStack[++nullTop] = 1;
			for (int i = 0; i < lastRowStack[lastRowTop]; i++) {
				
			}
		}
	}
}
