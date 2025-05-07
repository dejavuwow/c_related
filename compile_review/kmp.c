//ABDABC
//ABDABD
//相比较暴力匹配法(每次匹配失败，都需要从头匹配，复杂度 m * n)
//通过提前构建一个失效函数，模式串本身就能够从此前的匹配过程中记住相关信息，将其利用起来，提升匹配效率
//遍历模式串，对每一个位置计算以该位置结尾的子串的最长真公共前缀长度
//ABDABC: 该字符串索引4处的子串的最长真公共前缀为([AB]D[AB])AB, 即长度为2
//当在下一位匹配失败时，则只需要将目标串的该位置索引继续与当前串比较即可
//
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *failureFunc(const char *str) {
	int l = strlen(str);
	int *res = malloc(sizeof(int) * (l + 1));
	int t = 0;
	int s = 1;
	res[0] = 0;
	for (; s < l; s++) {
		while (t > 0 && str[s] != str[t]) {
			t = res[t - 1];
		}
		if (str[s] == str[t]) {
			t++;
		} 
		res[s] = t;
	}
	return res;
}

int contains(char *origin, char *target) {
	int l1 = strlen(origin),
		l2 = strlen(target);
	int *next = failureFunc(target);
	for (int i = 0, j = 0; i < l1 && j < l2; i++) {
		while (j > 0 && origin[i] != target[j]) {
			j = next[j - 1];
		}
		if (origin[i] == target[j]) {
			j++;
		}
		if (j == l2) return 1;
	}
	return 0;
}
int main(void) {
	char *origin = "ABCDdABCDkABDE";
	char *target = "ABCDAB";
	printf("%s", contains(origin, target) ? "yes" : "no");
	return 0;
}

