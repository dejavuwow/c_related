#include <stdio.h>
#include <string.h>
#include <stdlib.h>
enum bool {
	false,
	true
};
typedef enum bool bool;
struct ListNode {
	struct ListNode *next;
	int val;
};
struct ListNode* partition(struct ListNode* head, int x){
	struct ListNode *current = head;
	struct ListNode *ret = NULL;
	struct ListNode *high = NULL;
	struct ListNode **lowTail,
					**highTail;
	while (current != NULL) {
		if (current->val < x) {
			if (!ret) {
				ret = current;
			}
			else {
				*lowTail = current;
			}
			lowTail = &(current->next);
		}
		else {
			if (!high) {
				high = current;
			}
			else {
				*highTail = current;
			}
			highTail = &(current->next);
		}
	}
	*lowTail = high;
	return ret;
}
int main(void) {
	int a = -6;
	if (a) {
		printf("***");
	}
	return 0;
}

struct HashTable {
    int key;
    int val;
    UT_hash_handle hh;
};

void modifyHashTable(struct HashTable** hashTable, int x, int inc) {
    struct HashTable* tmp;
    HASH_FIND_INT(*hashTable, &x, tmp);
    if (tmp == NULL) {
        tmp = malloc(sizeof(struct HashTable));
        tmp->key = x;
        tmp->val = inc;
        HASH_ADD_INT(*hashTable, key, tmp);
    } else {
        tmp->val += inc;
    }
}

bool checkHashTable(struct HashTable** hashTable) {
    struct HashTable *iter, *tmp;
    HASH_ITER(hh, *hashTable, iter, tmp) {
        if (iter->val) {
            return false;
        }
    }
    return true;
}

void freeHashTable(struct HashTable** hashTable) {
    struct HashTable *iter, *tmp;
    HASH_ITER(hh, *hashTable, iter, tmp) {
        HASH_DEL(*hashTable, iter);
        free(iter);
    }
}

bool equals(char* s1, char* s2, int i1, int i2, int len) {
    for (int i = 0; i < len; i++) {
        if (s1[i + i1] != s2[i + i2]) {
            return false;
        }
    }
    return true;
}

// 记忆化搜索存储状态的数组
// -1 表示 false，1 表示 true，0 表示未计算
int memo[30][30][31];

// 第一个字符串从 i1 开始，第二个字符串从 i2 开始，子串的长度为 length，是否和谐
bool dfs(char* s1, char* s2, int i1, int i2, int length) {
    if (memo[i1][i2][length]) {
        return memo[i1][i2][length] == 1;
    }

    // 判断两个子串是否相等
    if (equals(s1, s2, i1, i2, length)) {
        memo[i1][i2][length] = 1;
        return true;
    }

    // 判断是否存在字符 c 在两个子串中出现的次数不同
    struct HashTable* hashTable = NULL;

    for (int i = i1; i < i1 + length; ++i) {
        modifyHashTable(&hashTable, s1[i], 1);
    }
    for (int i = i2; i < i2 + length; ++i) {
        modifyHashTable(&hashTable, s2[i], -1);
    }
    if (!checkHashTable(&hashTable)) {
        memo[i1][i2][length] = -1;
        return false;
    }
    freeHashTable(&hashTable);

    // 枚举分割位置
    for (int i = 1; i < length; ++i) {
        // 不交换的情况
        if (dfs(s1, s2, i1, i2, i) && dfs(s1, s2, i1 + i, i2 + i, length - i)) {
            memo[i1][i2][length] = 1;
            return true;
        }
        // 交换的情况
        if (dfs(s1, s2, i1, i2 + length - i, i) && dfs(s1, s2, i1 + i, i2, length - i)) {
            memo[i1][i2][length] = 1;
            return true;
        }
    }

    memo[i1][i2][length] = -1;
    return false;
}

bool isScramble(char* s1, char* s2) {
    memset(memo, 0, sizeof(memo));
    return dfs(s1, s2, 0, 0, strlen(s1));
}
// 1073741824
 //T(n) = 2 (1 + T(n - 1)) = 2T(n - 1) = 2 * (2 * T(n - 2))
 //041
 //04
//5 =  2T(4) + 2(T2) + 2T(3) 
//	 1 1 3 3 1 1 33
//	 1 1 11 22kk
//12345
//  1                    005
//001  114  041  104
//	   114
//001    004
//114    441
//041    014
//104    401
//
//
//12345  67
//67  12345
//1->2,
bool isScramble(char * s1, char * s2){
	int n1 = strlen(s1),
		n2 = strlen(s2);
	int dp[n1][n1][n + 1];
	memset(dp, 0, sizeof(dp));

	if (n1 != n2) return false;
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			dp[i][j][1] = s1[i] == s2[j];
		}
	}
	
	for (int len = 2; len < n1; len++) {
		for (int i = 0; i < n1 - len; i++) {
			for (int j = 0; j < n2; j++) {
				for (int k = 1; k < len - 1; k++) {
					if ((dp[i][j][k] == 1 && dp[i + k][j + k][len - k]) ||
							(dp[i][j + len - k][k] == 1 && dp[i + k][j][len - k] == 1)) {
						dp[i][j][len] = 1;
						break;
					}
				}
			}
		}
	}
	return dp[0][0][n1];
}

int* grayCode(int n, int* returnSize){
	int *ret = malloc(sizeof(int) * (1 << n));
	index = 0;
	ret[index++] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1 << i - 1; j >= 0; j--) {
			ret[index++] = 1 << i + ret[j];
		}
	}
	return ret;
}
int map[21];
int source[10];
int group[10];
int length = 0;
int len;

void dfs(int k, int index, int **ret, int *returnColumnSizes) {
	if (k >= len) return;
	dfs(k, index, ret, returnColumnSizes);
	for (int i = 0; i < map[source[k] + 10]; i++) {
		group[index + i] = source[k];
		int l = index + i + 1;
		int *list = malloc(sizeof(int) * l);
		memcpy(list, group, l * sizeof(int));
		ret[length] = list;
		returnColumnSizes[length++] = l;
		dfs(k + 1, l, ret, returnColumnSizes);
	}
 }
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	len = 0;
	length = 0;
	memset(map, 0, sizeof(map));
	int **ret = malloc(sizeof(int*) * 2000);
	(*returnColumnSizes) = malloc(sizeof(int) * 2000);
	for (int i = 0; i < numsSize; i++) {
		if (map[nums[i] + 10] == 0) {
			source[len++] = nums[i];
		}
		map[nums[i] + 10]++;
	}
	ret[length] = NULL;
	(*returnColumnSizes)[length++] = 0;
	dfs(0, 0, ret, *returnColumnSizes);
	*returnSize = length;
	return ret;
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int n = numsSize;
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * (1 << n));
    int** ans = malloc(sizeof(int*) * (1 << n));
    for (int mask = 0; mask < (1 << n); ++mask) {
        int* t = malloc(sizeof(int) * n);
        int tSize = 0;
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                if (i > 0 && (mask >> (i - 1) & 1) == 0 && nums[i] == nums[i - 1]) {
                    flag = false;
                    break;
                }
                t[tSize++] = nums[i];
            }
        }
        t = realloc(t, sizeof(int) * tSize);
        if (flag) {
            ans[*returnSize] = t;
            (*returnColumnSizes)[(*returnSize)++] = tSize;
        }
    }
    ans = realloc(ans, sizeof(int*) * (*returnSize));
    return ans;
}

//1  10  100 1000
//1000
//
//720 / 7
//10 + (10 * 9) / 2 + (4 * 3 * 2) / (1 * 2 * 3)
//S(k) = S(k - 1) *  (n - k + 1) / k (k > 1);
//S(k) = (S(k - 2) * (n - (k - 1) + 1) / (k - 1))
//S(1) = n;
//001
//011
//010
//110
//111
//101
//100
//1100
//1101
//1111
//1110
//1010
//0101
//1111
//0101
//
//1100
//0110
//
//1011
//1011
//0100
//
