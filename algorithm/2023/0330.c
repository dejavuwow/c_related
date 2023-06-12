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

struct my_struct {
	char word[31];
	UT_hash_handle hh;         /* makes this structure hashable */
};
char str[31];
int array[30];
int array_len;
struct my_struct *tmp, *other, *hash = NULL;
bool dfs(char *word, int start) {
	bool ret = false;
	int l = strlen(word);
	if (word[start] == '\0') {
		return true;
	}
	for (int i = 0;i < array_len; i++) {
		if (start + array[i] > l - 1) continue;
		strncpy(str, word + start, array[i]);
		str[array[i]] = '\0';
		if (strcmp(str, word) == 0) continue;

		HASH_FIND_STR(hash, str, other);
		if (other && dfs(word, start + array[i] + 1)) {
			ret = true;
		}
	}
	return ret;
}
//a ab
//将单词长度记录
char ** findAllConcatenatedWordsInADict(char ** words, int wordsSize, int* returnSize){
	char **ret = malloc(sizeof(char*) * wordsSize);
	int l = 0;
	int length[31];
	array_len = 0;

	memset(length, 0, sizeof(length));
	for (int i = 0; i < wordsSize; i++) {
		int l = strlen(words[i]);
		if (!length[l]) {
			length[l] = 1;
			array[array_len++] = l;
		}
		HASH_FIND_STR(hash, words[i], tmp);
		if (tmp == NULL) {
			other = malloc(sizeof(struct my_struct));
			strcpy(other->word, words[i]);
			HASH_ADD_STR(hash, word, other);
		}
	}
	for (int i = 0; i < wordsSize; i++) {
		if (dfs(words[i], 0)) {
			char *str = malloc(sizeof(char) * (strlen(words[i]) + 1));
			strcpy(str, words[i]);
			ret[l++] = str;
		}
	}
	*returnSize = l;
	return ret;
}

#define MAX 100000
typedef struct {
	int son[MAX][26];
	int tail[MAX];
	int count;
} Trie;

Trie* trieCreate() {
	Trie * ret = malloc(sizeof(Trie));
	ret->count = 0;
	memset(ret->son, 0, sizeof(ret->son));
	memset(ret->tail, 0, sizeof(ret->tail));
	return ret;
}

void trieInsert(Trie* obj, char * word) {
	int root = 0;
	int l = strlen(word);
	for (int i = 0; i < l; i++) {
		int k = word[i] - 'a';
		if (!obj->son[root][k]) {
			obj->son[root][k] = ++obj->count;
		}
		root = obj->son[root][k];
	}
	obj->tail[root]++;
}

bool trieSearch(Trie* obj, char * word) {
	int root = 0;
	int l = strlen(word);
	for (int i = 0; i < l; i++) {
		int k = word[i] - 'a';
		if (!obj->son[root][k]) return false;
		root = obj->son[root][k];
	}
	return obj->tail[root];
}

bool trieStartsWith(Trie* obj, char * prefix) {
	int root = 0;
	int l = strlen(prefix);
	for (int i = 0; i < l; i++) {
		int k = prefix[i] - 'a';
		if (!obj->son[root][k]) return false;
		root = obj->son[root][k];
	}
	return true;
}

void trieFree(Trie* obj) {
	free(obj);
	obj = NULL;
}
int cmpFunc(const void *a, const void *b) {
	return strlen(*(char**)a) - strlen(*(char**)b);
}

int search(Trie *dict, char *word, int start, int visited[30]) {
	if (*(word + start) == '\0') return 1;
	if (visited[start]) return 0;
	for (int i = 0; *(word + start + i) != '\0'; i++) {
		char temp = word[start + i + 1];
		word[start + i + 1] = '\0';
		int res = trieSearch(dict, word + start);
		word[start + i + 1] = temp;
		if (res && search(dict, word, start + i + 1)) {
			return 1;
		}
	}
	visited[start] = 1;
	return 0;
}

char ** findAllConcatenatedWordsInADict(char ** words, int wordsSize, int* returnSize){
	char **ret = malloc(sizeof(char*) * wordsSize);
	char str[31];
	int visited[30];
	int size = 0;
	qsort(words, wordsSize, sizeof(char*), cmpFunc);
	Trie *dict = trieCreate();
	for (int i = 0; i < wordsSize; i++) {
		memset(visited, 0, sizof(visited));
		if (search(dict, words[i], 0, visited)) {
			char *str = malloc(sizeof(char) * (strlen(words[i]) + 1));
			strcpy(str, words[i]);
			ret[size++] = str;
		} else {
			trieInsert(dict, words[i]);
		}
	}
	trieFree(dict);
	*returnSize = size;
	return ret;
}
