#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int *getNext(char *s) {
	int l = strlen(s);
	int *next = malloc(sizeof(int) * l);
	next[0] = -1;
	int j = -1;
	for (int i = 0; i < l;) {
		if (j == -1 || s[i] == s[j]) {
			i++;
			j++;
			next[i] = j;

		} else {
			j = next[j];
		}
	}
	for (int i = 0; i < l; i++) {
		printf("%d ", next[i]);
	}
	return next;
}
//0 -1
//1 0
//3 1
int search(char *src, char *s) {
	int l = strlen(s);
	int m = strlen(src);
	int *next = getNext(s);
	int j = -1;
	for (int i = -1; i < m;) {
		if (j == -1 || src[i] == s[j]) {
			i++;
			j++;
			printf("%c %c\n", s[i], s[j]);
		}
		else {
			j = next[j];
		}
		if (j == l) return i - j;
	}
	return -1;
}
int main(void) {
	printf("%d", search("abbcacd", "cacd"));
	return 0;
}
