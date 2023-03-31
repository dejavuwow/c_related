struct my_struct {
	char word[21];
	UT_hash_handle hh;         /* makes this structure hashable */
};
int array[21];
char str[21];
int array_len = 0;
struct my_struct *tmp, *item, *hash = NULL;

bool dfs(char *s, int startIndex) {
	if (startIndex >= strlen(s)) return true;
	for (int i = 0; i < array_len; i++) {
		strncpy(str, s + startIndex, array[i]);
		str[array[i]] = '\0';
		HASH_FIND_STR(hash, str, item);
        if (!item) continue;
        bool res = dfs(s, startIndex + array[i]);
        if (res) return true;
        else continue;
	}
	return false;
}
bool wordBreak(char * s, char ** wordDict, int wordDictSize){
	hash = NULL;
	char str[21];
	int length[21];
    array_len = 0;
	memset(length, 0, sizeof(length));
	for (int i = 0; i < wordDictSize; i++) {
		int l = strlen(wordDict[i]);
		if (!length[l]) {
			length[l] = 1;
			array[array_len++] = l;
		}
		HASH_FIND_STR(hash, str, tmp);
		if (tmp == NULL) {
			item = malloc(sizeof(struct my_struct));
			strcpy(item->word, wordDict[i]);
			HASH_ADD_STR(hash, word, item);
		}
	}
    return dfs(s, 0);
}
//输入:s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
//输出:["cats and dog","cat sand dog"]
//输入:s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
//输出:["pine apple pen apple","pineapple pen apple","pine applepen apple"]
//apple appleapple  ke  keke
//appleapple   keke 
//apple apple  keke
//aabbccddeeff
struct my_struct {
	char word[11];
	UT_hash_handle hh;         /* makes this structure hashable */
};
int array[21];
char str[11];
int array_len = 0;
struct my_struct *tmp, *other, *hash = NULL;
char *cur;
void dfs(char *s, int startIndex, int curIndex, char **ret, int *returnSize) {
	if (startIndex >= strlen(s)) {
		cur[curIndex - 1] = '\0';
		char *temp = malloc(sizeof(char) * curIndex);
		strcpy(temp, cur);
		ret[*returnSize] = temp;
		(*returnSize)++;
		return;
	}
	for (int i = 0; i < array_len; i++) {
		strncpy(str, s + startIndex, array[i]);
		str[array[i]] = '\0';
		HASH_FIND_STR(hash, str, other);
		if (other) {
			strncpy(cur + curIndex, s + startIndex, array[i]);
			cur[curIndex + array[i]] = ' ';
			dfs(s, startIndex + array[i], curIndex + array[i] + 1, ret, returnSize);
		}
	}
}
char ** wordBreak(char * s, char ** wordDict, int wordDictSize, int* returnSize){
	int l = strlen(s);
	cur = malloc(sizeof(char) * (2 * l - 1));
	char **ret = malloc(sizeof(char*) * 0x400);

	hash = NULL;
	char str[21];
	int length[21];
    array_len = 0;
	memset(length, 0, sizeof(length));
	for (int i = 0; i < wordDictSize; i++) {
		int l = strlen(wordDict[i]);
		if (!length[l]) {
			length[l] = 1;
			array[array_len++] = l;
		}
		HASH_FIND_STR(hash, wordDict[i], tmp);
		if (tmp == NULL) {
			ohter = malloc(sizeof(struct my_struct));
			strcpy(ohter->word, wordDict[i]);
			HASH_ADD_STR(hash, word, other);
		}
	}
	dfs(s, 0, 0, ret, returnSize);
	return ret;
	
}

char ** findAllConcatenatedWordsInADict(char ** words, int wordsSize, int* returnSize){
	int arr[30];
	int length[31];
	int array_len = 0;
	memset(length, 0, sizeof(length));
	for (int i = 0; i < wordsSize; i++) {
		int l = strlen(words[i]);
		if (!length[l]) {
			length[l] = 1;
			array[array_len++] = l;
		}
	}

}
