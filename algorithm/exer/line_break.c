#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int x;
	int n, m;
	scanf("%d", &x);
	char word[11];
	char temp[11];
	while(x--) {
		scanf("%d %d", &n, &m);
		int l = 0;
		int count = 0;
		while (n--) {
			scanf("%s", word);
			if ((l += strlen(word)) > m) {
				printf("%d\n", count);
				while (n--) {
					scanf("%s", temp);
				}
				break;
			} else {
				count++;
			}
			if (n == 0) {
				printf("%d\n", count);
			}
		}
	}
	return 0;
}
---------------------
| | | | | |
---------------------
