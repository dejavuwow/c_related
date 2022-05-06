#include <stdio.h>
#include <string.h>
int sel(char * S,char *T){
	int i=0,j=0;
	while (i<strlen(S) && j<strlen(T)) {//循环开始
		if (S[i]==T[j]) {//首字符对比
			i++;
			j++;
		}else{
			i=i-j+1;//匹配失败，回到上次匹配的下一位
			j=0;//从T的首字符和S的下一位字符再继续匹配
		}
	}

	if (j==strlen(T)) {//当j等于T的长度时说明匹配成功返回位置
		return i-strlen(T)+1;
	}
	return 0;
}

//next数组, 索引为模式串的最后一位索引，值为最长公共子串前缀的最后一位索引
//初始值为 -1
int *getNext(char *T) {
	int l = strlen(T);
	int *next = malloc(sizeof(int) * (l + 1));
	next[0] = -1;
	for (int i = 0, j = -1; i < size;) {
		if (j == - 1 || T[j] == T[i]) {
			i++;
			j++;
			next[i] = j;
		} 
		else {
			j = next[j];
		}
	}
	return next;
}
//abf abd abf abf
int kmp(char *S, char *T) {
	int m = strlen(S),
		n = strlen(T);

	int *next = getNext(T);
	for (int i = -1, j = -1; i < m; i++) {
		if (j == -1 || S[i] == T[j]) {
			j++;
		}
		else {
			j = next[j];
			i--;
		}
		if (j == n) return i - j + 1;
	}
	return -1;
}
int main(void) {
	int add=kmp("ababacdadf", "adf");
	printf("%d",add);
	return 0;
}


