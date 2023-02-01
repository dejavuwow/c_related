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
struct struct_path {
	char **path;
	int size;
} Path;
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
void bfs(char *beginWord, char *endWord) {
	char **queue[listSize];
	Path *path = malloc(sizeof(char**))
		char **neighbours;
	int head = 0;
	int end = -1;
	int *len;
	int index = 0;

	path[index++] = beginWord;
	queue[++end % listSize] = path;
	while (head <= end) {
		char **temp = queue[head++ % listSize];
		neighbours = malloc(sizeof(char*) * listSize);
		getNeighbours(temp[], neighbours, len);
		for (int i = 0; i < *len; i++) {
			if (strcmp(neighbours[i], endWord) == 0) {
			}
			queue[++end % listSize] = neighbours[i];
		}
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
//  2   13
//  24  13
//  
// 123 45 6  
//    23     7
//30000 / (1000 + 300)  10000 / (1000 + 300)
//   20      6
#define MAX(a,b) ((a) > (b) ? (a) : (b))
int deleteAndEarn(int* nums, int numsSize){
	int maxSize = INT_MIN;
	for (int i = 0; i < numsSize; i++) {
		maxSize = MAX(maxSize, nums[i]);
	}
	int sums[maxSize + 1];
	memset(sums, 0, sizeof(sums));
	for (int i = 0; i < numsSize; i++) {
		sums[nums[i]] += nums[i];
	}

	int first = sums[0],
	int second = MAX(sums[0], sums[1]);
	for (int i = 2; i < maxSize + 1; i++) {
		int temp = second;
		second = MAX(second, first + sums[i]);
		first = temp;
	}
	return second;
}
int getMax(int *sums, int size) {
	int first = sums[0],
	int second = MAX(sums[0], sums[1]);
	for (int i = 2; i < size; i++) {
		int temp = second;
		second = fmax(second, first + sums[i]);
		first = temp;
	}
	return second;
}

int cmp(const void *a, const void *b) {
	return *(int*)a - *(int *)b;
}
//排序 -> 
int deleteAndEarn(int* nums, int numsSize){
	int sums[numsSize];
	int j = 0;
	int max = 0;
	qsort(nums, numsSize, sizeof(int), cmp);
	sums[j++] = nums[0];
	for (int i = 1; i < numsSize; i++) {
		if (nums[i] == nums[i - 1]) {
			sums[j - 1] += nums[i];
		} else {
			if (nums[i] == nums[i - 1] + 1) {
				sums[j++] = nums[i];
			}
			else {
				max += getMax(sums, j);
				j = 0;
				sums[j++] = nums[i];
			}
		}
	}
	return max;
}
//s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles"
int getNumber(char *s, int *index) {
	int value = 0;
	int isNumber = 0;
	if (s[*index] >= 0x30 && s[*index] <= 0x39) {
		isNumber = 1;
	}
	while (s[*index] != '\0' && s[*index] != ' ') {
		if (isNumber) {
			value = value * 10 + s[*index] - 0x30;
		}
		(*index)++;
	}
	if (s[*index] == ' ') (*index)++;
	return value;
}	
bool areNumbersAscending(char * s){
	int l = strlen(s);
	int index = 0;
	/** int pre = getNumber(s, &index); */
	int pre = 0;
	int value;
	while (index < l) {
		value = getNumber(s, &index);
		if (value != 0) {
			if (pre != 0) {
				if (value > pre) {
					pre = value;
				}
				else return false;
			}
		} 
	}
	return true;
}
//[0,3,7,2,5,8,4,6,0,1]
//23  2
//78  2
//345  4
//
//6  5
//012
//
//
struct my_struct {
	int value;
	struct my_struct *left;
	struct my_struct *right;
	UT_hash_handle hh;       
};
int longestConsecutive(int* nums, int numsSize){
	struct my_struct *left, *right, *tmp, *users = NULL;
	int ret = 0;
	for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(users, &nums[i], tmp);
        if (tmp) continue;
		tmp = malloc(sizeof(struct my_struct));
		tmp->value = nums[i];
		tmp->order = 1;
		tmp->left = tmp->right = NULL;
		int value = nums[i] - 1;
		HASH_FIND_INT(users, &value, left);
		if (left) {
			left->right = tmp;
			tmp->left = left; 
		}
		value = nums[i] + 1;
		HASH_FIND_INT(users, &value, right);
		if (right) {
			right->left = tmp;
			tmp->right = right; 
		}
		HASH_ADD_INT(users, value, tmp);
	}
	for (tmp = users; tmp != NULL; tmp = tmp->hh.next) {
		int order = 0;
		if (tmp->left == NULL) {
			for (left = tmp; left != NULL; left = left->right) {
				order++;
			}
			ret = fmax(order, ret);
		}
    }
	return ret;
}
struct my_struct {
	int value;
	UT_hash_handle hh;       
};
int longestConsecutive(int* nums, int numsSize){
	struct my_struct *tmp, *cur, users = NULL;
	int ret = 0;
	for (int i = 0; i < numsSize; i++) {
		HASH_FIND_INT(users, &nums[i], tmp);
        if (tmp) continue;
		tmp = malloc(sizeof(struct my_struct));
		tmp->value = nums[i];
		HASH_ADD_INT(users, value, tmp);
	}
	for (tmp = users; tmp != NULL; tmp = tmp->hh.next) {
		int value = tmp->value - 1;
		HASH_FIND_INT(users, &value, cur);
		if (cur == NULL) {
			int length = 0;
			do {
				length++;
				value++;
				HASH_FIND_INT(users, &value, cur);
			} while (cur != NULL);
			ret = fmax(ret, length);
		}
    }
}
