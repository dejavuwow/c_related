#define NUMBER(x) ((x) - 0x30)
#define CHAR(x) ((x) + 0x30)
char * addBinary(char * a, char * b){
	int l1 = strlen(a),
		l2 = strlen(b);
	int l = l1 < l2 ? l2 : l1;
	char *ret = malloc(sizeof(char) * (l + 1));
	int carry = 0;
	ret[l] = 0;
	int i, j, k;

	for (i = l1 - 1, j = l2 - 1, k = l - 1; i >= 0 && j >= 0; i--, j--, k--) {
		int total = NUMBER(a[i]) + NUMBER(b[j]) + carry;
		ret[k] =  CHAR(total % 2);
		carry = total / 2; 
	}
	if (i < 0) {
		for (; j >= 0; j--, k--) {
			int total = NUMBER(b[j]) + carry;
			ret[k] =  CHAR(total % 2);
			carry = total / 2; 
		}
	}
	else {
		for (; i >= 0; i--, k--) {
			int total = NUMBER(a[i]) + carry;
			ret[k] =  CHAR(total % 2);
			carry = total / 2; 
		}
	}
    if (carry) {
		ret = realloc(ret, (l + 2) * sizeof(char));
		memmove(ret, ret + 1, sizeof(char) * (l + 1));
		ret[k] = '1';
	} 
	return ret;

}
 func() {
	 if ()
 }
char ** fullJustify(char ** words, int wordsSize, int maxWidth, int* returnSize){
	char **ret = malloc(sizeof(char*) * wordsSize);
	char *p = malloc(sizeof(char) * (maxWidth + 1));
	p[maxWidth] = 0;
	int index = 0;
	int rowWordNum = 0;
	int blankNum, avgBlank, remBlank;
	int backWord, backPos;
	for (int i = 0; i < wordsSize;) {
		if (index + strlen(words[i]) >= maxWidth && rowWordNum > 1) {
				blankNum = maxWidth - index + rowWordNum;
				avgBlank = blankNum / (rowWordNum - 1);
				remBlank = blankNum % (rowWordNum - 1);
				while (backWord < i) {
					int k = avgBlank;
					if (remBlank > 0) {
						k++;
						remBlank--;
					}
					p[backPos += k] = words[backWord];
					backPos += strlen(words[backWord]);
					backWord++;
				}
		}
	}
	
}
