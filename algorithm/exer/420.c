#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1234
// 456
//1234
#define NUM(x) ((x) == 0 ? x : (x) - 0x30)
#define STR(x) ((x) + 0x30)
#define MAX(x, y) ((x) < (y) ? (y) : (x))

void add(char *s1, char *s2, int *i1, int j1, int i2, int j2) {
	int carry = 0;
	int total = 0;
	int width = j2 - i2;
	int i, j;
	for (i = j1, j = j2; i >= j1 - width; i--, j--) {
		printf("%d %d %d\n", j1, NUM(s1[i]), NUM(s2[j]));
		total = NUM(s1[i]) + NUM(s2[j]) + carry;
		carry = total >= 10 ? 1 : 0;
		total = total >= 10 ? total - 10 : total;
		s1[i] = STR(total);
	}
	if (carry) {
		s1[i--] = '1';
	}
	*i1 = i + 1;


} 
// 123
//456
char * multiply(char * num1, char * num2){
	int m = strlen(num1),
		n = strlen(num2);

	int total = 0,
		carry = 0;

	char ret[401] = {'\0'};
	char temp[204] = {'\0'};
	int idx = 202;
	int p = 202;
	int end = 399;
	int start = 399;
	for (int i = m - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			total = NUM(num1[i]) * NUM(num2[j]) + carry;
			carry = total / 10;
			total = total % 10;
			temp[idx--] = STR(total);
		}
		if (carry) temp[idx--] = ;
		printf("%s\n",temp + idx + 1);
		add(ret, temp, &start, end, idx + 1, p);
		printf("**%s\n",ret + start);
		temp[idx + 1] = 0;
		end--;
		idx = 202;
		carry = 0;
	}
	char *res = calloc(end - start + 2, sizeof(char));
	strncpy(res, ret + start, end - start + 1);
	return res;
}
int main(void) {
	printf("%s", multiply("9", "9"));
	return 0;
}
