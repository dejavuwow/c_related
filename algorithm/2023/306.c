/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */
struct my_struct {
	struct Node *node;
	int val;
	UT_hash_handle hh;         /* makes this structure hashable */
};
struct my_struct *cur, *tmp, *users = NULL;
struct Node *cloneNode(struct Node *s) {
	if (s == NULL) return NULL;
	struct Node *ret;
	HASH_FIND_INT(users, &s->val, cur);
	if (cur) {
		ret = cur->node;
	} else {
		ret = malloc(sizeof(struct Node));
		ret->val = s->val;
		ret->numNeighbors = s->numNeighbors;
		ret->neighbors = malloc(sizeof(struct Node *) * ret->numNeighbors);
		cur = malloc(sizeof(struct my_struct));
		cur->node = ret;
		cur->val = ret->val;
		HASH_ADD_INT(users, val, cur);
		for (int i = 0; i < s->numNeighbors; i++) {
			ret->neighbors[i] = cloneNode(s->neighbors[i]);
		}
	}
	return ret;
}
struct Node *cloneGraph(struct Node *s) {
	users = NULL;
	return cloneNode(s);

}

//gas = [1,2,3,4,5], cost = [3,4,5,1,2]
//rem = [-2, -2, -2, 3, 3];
//
//gas = [4,5,2,6,5,3], cost = [3,2,7,3,2,9];
//rem = [1,3,-5,3,3,-6];
//[-3,7, -4, 2]
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
	int l = gasSize;
	int remain[l];
	int total = 0;
	int last = -1;

	for (int i = 0; i < l; i++) {
		remain[i] = gas[i] - cost[i]; 
	}

	for (int i = 0; i < 2 * l - 1; i++) {
		if (remain[i % l] + total < 0) {

			total = 0;
			last = -1;
		}
		else {
			total += remain[i % l];
			if (last == -1 && i < l) {
				last = i % l;
			}
		}
	}
	return last;
}
//123
// n(n + 1) / 2
int candy(int* ratings, int ratingsSize){

	int inc = 1,
		ret = 1;
	pre = 1,
		dec = 0;

	for (int i = 1; i < ratingsSize; i++) {
		if (ratings[i] >= ratings[i - 1]) {
			dec = 0;
			inc = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
			ret += inc;
			pre = inc;
		} else {
			dec++;
			if (dec == inc) {
				dec++;
			}
			ret += dec;
			pre = 1;
		}
	}
	return ret;
}
// s = y + 2x; 
// s / 3  - x
// y = 3 (a + ... + n) + x;
// ((y - x) / 3  + x )
int singleNumber(int* nums, int numsSize){
	int total;
	int ret = 0;
	for (int i = 0; i < 32; i++) {
		total = 0;
		for (int j = 0; j < numsSize; j++) {
			total += nums[j] >> i & 1
		}
		if (total % 3) {
			ret |=  1 << i;
		}
	}
	return ret;
}

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */
struct my_struct {
	void *key;
	void *copy;
	UT_hash_handle hh;         /* makes this structure hashable */
};
struct Node* copyRandomList(struct Node* head) {
	if (head == NULL) return NULL;
	struct my_struct *cur, *tmp, *users = NULL;
	struct Node *ret;
	struct Node *pre = NULL;
	for (struct Node *current = head; current != NULL; current = current->next) {
		tmp = malloc(sizeof(struct my_struct));
		cur = malloc(sizeof(struct Node));
		cur->val = current->val;
		cur->next = cur->random = NULL;
		tmp->key = current;
		tmp->copy = cur;
		HASH_ADD_PTR(users, key, tmp);
		if (pre) {
			pre->next = cur;
		} else {
			ret = cur;
		}
		pre = cur;
	}

	for (struct Node *current = head; current != NULL; current = current->next) {
		HASH_FIND_PTR(users, &current, tmp);
		if (current->random) {
			HASH_FIND_PTR(users, &current->random, cur);
		}
		((struct Node*)(tmp->copy))->random = (struct Node*)(cur->copy);
	}
	return ret;

}
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
struct my_struct {
	char word[21];
	UT_hash_handle hh;         /* makes this structure hashable */
};
struct my_struct *tmp, *item, *hash = NULL;
//
bool checkHash(char *s, int start, int end) {
	char str[21];
	strncpy(str, s + start, end - start + 1);
	str[en - start + 1] = '\0';
	HASH_FIND_STR(hash, str, item);
	return item != NULL;
}
bool wordBreak(char * s, char ** wordDict, int wordDictSize){
	int l = strlen(wordDict[i]);
	int dp[l + 1];
	char str[21];
	hash = NULL;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 0; i < wordDictSize; i++) {
		HASH_FIND_STR(hash, str, tmp);
		if (tmp == NULL) {
			item = malloc(sizeof(struct my_struct));
			strcpy(item->word, wordDict[i]);
			HASH_ADD_STR(hash, word, item);
		}
	}
	for (int i = 1; i <= l; i++) {
		for (int j = 0; j < i; j++) {
			if (dp[j] && checkHash(s, j, i)) {
				dp[i] = 1;
				break;
			}
		}
	}
	return dp[l];
}
