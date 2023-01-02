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

int wordLength;
char **list;
char **tempList;
char *lastWord;
char *startWord;
int retLen;
int wordListLength;
int minLen = INT_MAX;
int *acc;
char ***ret;
char **copyList(char **list, int length, int wordLength) {
	char **copy = malloc(sizeof(char*) * (length+1));
	copy[0] = malloc(sizeof(char) * (wordLength + 1));
	memcpy(copy[0], startWord, wordLength);
	copy[0][wordLength] = '\0';
	for (int i = 0; i < length; i++) {
		copy[i + 1] = malloc(sizeof(char) * (wordLength + 1));
		memcpy(copy[i + 1], list[i], wordLength);
		copy[i + 1][wordLength] = '\0';
	}
	return copy;
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
			if (diff > 0) return 0;
			diff++;
		} 
	}
	return diff == 1;
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
	for (int i = 0; i < wordListLength; i++) {
		if (acc[i]) continue;
		if (match(list[i], str)) {
			tempList[index] = list[i];
			acc[i] = 1;
			func(list[i], index + 1, restLength - 1);
			acc[i] = 0;
		}
	}
}
/** ["hot","dot","dog","lot","log","cog"] */
/** "hit" -> "hot" -> "dot" -> "dog" -> "cog" */
/** "hit" -> "hot" -> "lot" -> "log" -> "cog" */
char *** findLadders(char * beginWord, char * endWord, char ** wordList, int wordListSize, int* returnSize, int** returnColumnSizes){
	retLen = 0;
	minLen = INT_MAX;
	ret = malloc(sizeof(char**) * 500);
	list = wordList;
	lastWord = endWord;
	startWord = beginWord;
	wordListLength = wordListSize;
	wordLength = strlen(beginWord);
	tempList = malloc(sizeof(char*) * wordListSize);
	acc = malloc(sizeof(int) * wordListSize);
	for (int i = 0; i < wordListSize; i++) {
		acc[i] = 0;
	}
	func(beginWord, 0, wordListSize);
	*returnSize = retLen;
	*returnColumnSizes =  malloc(sizeof(int) * retLen);
	for (int i = 0; i < retLen; i++) {
		(*returnColumnSizes)[i] = minLen + 1; 
	}
	return ret;

}

//
struct word {
	char word[6];
	UT_hash_handle hh;  
};
struct word *wordMap;
int wordLen;
int listSize;
char **list;
void getNeighbours(char *str, char **res, int *len) {
	int length = 0;
	for (int i = 0; i < wordLen; i++) {
		char old = str[i];
		struct word *temp;
		for (char j = 'a'; j <= 'z'; j++) {
			if (old == j) continue;
			str[i] = j;
			HASH_FIND_STR(wordMap, str, temp);
			if (temp) {
				res[length] = malloc(sizeof(char) * (wordLen + 1));
				strcpy(res[length++], str);
			}
			str[i] = old;
		}
	}
	*len = length;
}
void bfs(char *beginWord) {
	char *queue[listSize];
	char *path[listSize];
	char **neighbours;
	int head = 0;
	int end = -1;
	int *len;

	queue[++end % listSize] = beginWord;
	while (head <= end) {
		char *temp = queue[head++ % listSize];
		neighbours = malloc(sizeof(char*) * listSize);
		getNeighbours(temp, neighbours, len);
		
	}
}
char *** findLadders(char * beginWord, char * endWord, char ** wordList, int wordListSize, int* returnSize, int** returnColumnSizes){

	wordLen = strlen(beginWord);
	listSize = wordListSize;
	list = wordList;
	wordMap = NULL;
	struct word *temp = NULL;

	for (int i = 0; i < wordListSize; i++) {
		temp = (struct word *)malloc(sizeof(struct word));
		strcpy(temp->word, wordList[i]);
		HASH_ADD_STR(wordMap, word, temp);
	}
}
