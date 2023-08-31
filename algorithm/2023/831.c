int top = -1;
#define PUSH(stack, item) (stack[++top] = item)
#define POP(stack) (stack[top--])
#define IS_EMPTY (top < 0)
int parseInt(char *s) {
	int flag = 1;
	int res = 0;
	while (*s != '\0') {
		if (*s == '-') flag = -1;
		else {
			res = res * 10 + *s;
		}
		s++;
	}
	return flag * res;
}
int evalRPN(char ** tokens, int tokensSize){
	int stack[tokensSize];
	top = -1;
	for (int i = 0; i < tokensSize; i++) {
		int l = strlen(tokens[i]);
		int value;
		char cur = tokens[i][0];
		if (l == 1 && (cur == '+' || cur == '-' || cur == '*' || cur == '/')) {
			int second = POP(stack);
			int first = POP(stack);
			if (cur == '+') {
				value = first + second;
			} else if (cur == '-') {
				value = first - second;
			} else if (cur == '*') {
				value = first * second;
			} else {
				value = first / second;
			}
		} else {
			value = parseInt(tokens[i]);
		}
		PUSH(stack, value);
	}
	return stack[top];
}
//abcde
//bcdae
//f(x, y, k) = 
bool isScramble(char * s1, char * s2){
	int l = strlen(s1);
	int dp[l][l][l + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; i++) {
			dp[i][j][1] = s1[i] == s2[j];
		}
	}

	for (int len = 2; len <= l; len++) {
		for (int i = 0; i <= l - len; i++) {
			for (int j = 0; j <= l -len; j++) {
				for (int k = 1; k < len; k++) {
					if (dp[i][j][k] && dp[i + k][j + k][])
				}
			}
		}
	}
}
