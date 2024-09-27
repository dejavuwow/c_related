void S() {
	if (lookhead == '0'):
		match('0'); S(); match("1");
}
}
void scan() {
	int peek;
	if (peek == '/' && peek[1] == '/') {
		while (System.in.read() == '\n') break;
	}

	if (peek == '/' && peek[1] == '*') {
		while (System.in.read() == '*')
	}
	if ("." == peek || isDigit(peek)) {
		pre = peek;
		peek = read();
		if (isDigit(pre)) {
			if (peek == '.') {
				while (isDigit(read()))
			}
		} else if ('.' == peek && isDigit(read())) {

		}
	}
}

class For extends Stmt {
	Expr e1, e2, e3;
	Stmt s;
	public For(Expr r1, Expr r2, Expr r3, Stmt s1) {
		e1 = r1;
		e2 = r2;
		e3 = r3;
		s = s1;
		loop = newlabel();
		after = newlabel();
	}
	public void gen() {
		e1.gen();
		emit(loop + ":");
		e2n = e2.rvalue();
		emit("ifFalse"+ e2n.toString()+ "goto" + after);
		s.gen();
		e3.gen();
		emit("goto" + loop);
		emit(after + ":");
	}
}
"abce", "abcdef"
//maxlength[i]: i下标结尾的字符串的最长子序列长度
//headmost[i]: i下标结尾的字符串最长子序列在另外一个字符串中的匹配的字符串最后一个字符的下标(匹配到的字符串中，该字符串的最后一个字符下标最小)
//str1[i] == str2[k], 且 k > headmost[i - 1], maxlength[i] = maxlength[i - 1] + 1
//
int longestCommonSubsequence(char* text1, char* text2) {

	int l1 = strlen(text1),
		l2 = strlen(text2);
	int maxlength[l];
	int headmost[l];
	int count = 1;

	memset(maxlength, 0, sizeof(maxlength));
	memset(headmost, l2, sizeof(headmost));

	int find = 0;
	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++) {
			if (text1[i] == text2[j]) {
				maxlength[i] = 1;
				headmost[count] = j; 
				find = 1;
				break;
			}
		}
		if (find) break;
	}


	for (int i = 0; i < l1; i++) {
		int find = 0;
		for (int j = headmost[count]; j < l2; j++) {
			if (text1[i] == text2[j]) {
				maxlength[i]++;
				headmost[++count] = j; 
				find = 1;
				break;
			}
		}
		if (!find) {
			int countIndex = count;
			while (countIndex > 0) {
				for (int j = headmost[countIndex - 1] + 1; j < headmost[countIndex]; j++) {
					if (text1[i] == text2[j]) {
						headmost[countIndex] = j; 
						break;
					}
				}
				countIndex--;
			}
		}
	}

	return maxlength[l1 - 1];
}

int longestCommonSubsequence(char* text1, char* text2) {
    int m = strlen(text1), n = strlen(text2);
    int dp[m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++) {

        char c1 = text1[i - 1];
		int maxLenth = 0;

        for (int j = 1; j <= n; j++) {
			
            char c2 = text2[j - 1];
			int newLen = fmax(maxlength, dp[i])

            if (c1 == c2) {
				dp[i] = dp[i]
            }
			maxlength = newLen;
        }
    }
    return dp[m][n];
}
