int finalMax;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
int maxSub(struct TreeNode *root) {
	int leftContribution = maxSub(root->left),
		rightContribution = maxSub(root->right);

	int max = root->val + (leftContribution <= 0 ? 0 : leftContribution) + (rightContribution <= 0 ? 0 : rightContribution);
	finalMax = MAX(max, finalMax);
	int subMax = MAX(leftContribution, rightContribution)
		return root->val + subMax > 0 ? subMax : 0;
}
int maxPathSum(struct TreeNode* root){
	finalMax = INT_MIN;
	maxSub(root);
	return finalMax;
}
//[9,6,-3,null,null,-6,2,null,null,2,null,-6,-6,-6]
//1234
//abc
//"hit" -> "hot" -> "dot" -> "dog" -> "cog  cig hig
//"hit" -> "hot" -> "lot" -> "log" -> "cog"
//cog -> c    dog / log
int wordLength;
char **list;
char **tempList;
char *lastWord;
int retLen;
int wordListLength;
int minLen = INT_MAX;
int *access;
char **copyList(char **list, int length, int wordLength) {
	char **ret = malloc(sizeof(char*) * length);
	for (int i = 0; i < length; i++) {
		ret[i] = malloc(sizeof(char) * (wordLength + 1));
		memcpy(ret[i], list[i], wordLength);
		ret[i][wordLength] = '\0';
	}
	return ret;
}

#define freeList(list, length) {\
	for (int i = 0; i < length; i++) {\
		free(list[i]);\
	}\
}
int match(char *str1, char *str2) {
	int diff = 0;
	for (int i = 0; str1[i] != '\0'; i++) {
		if (str1[i] != str2[i]) {
			if (diff > 1) return 0;
			diff++;
		} 
	}
	return 1;
}
void func(char *str, int index, int restLength) {
	if (restLength == 0) return;
	if (strcmp(str, lastWord) == 0 && index <= minLen) {
		if (index < minLen) {
			freeList(ret, retLen);
			retLen = 0;
		}
		ret[retLen++] = copyList(tempList, index, wordLength);
		minLen = index;
		return;
	}
	for (int i = 0; i < wordListLength && !access[i]; i++) {
		if (match(list[i], str)) {
			tempList[index] = list[i];
			access[i] = 1;
			func(list[i], index + 1, restLength - 1);
			access[i] = 0;
		}
	}
}
//130 - 55- 
// 35 + 55 + 35  = 125
// 125 - 80 = 45
//
// 45 = 
//10 + 30
//35 - 55
//cog  hog coa 
char *** findLadders(char * beginWord, char * endWord, char ** wordList, int wordListSize, int* returnSize, int** returnColumnSizes){
	retLen = 0;
	ret = malloc(sizeof(char**) * wor)
	list = wordList;
	lastWord = endWord;
	wordListLength = wordListSize;
	wordLength = strlen(beginWord);
	tempList = malloc(sizeof(char*) * wordListSize);
	access = malloc(sizeof(int) * wordListSize);
	memset(access, 0, sizeof(access));
	func(beginWord, 0, wordListSize);
	*returnSize = retLen;

	
}
