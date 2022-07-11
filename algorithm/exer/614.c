//超时...
int length;
int count;
void dfs(char *s, int index) {
	if (index >= length) {
		count++;
		return;
	}
	if (s[index] == '0') return;

	for (int i = 0; i < 2 && index + i < length; i++) {
		if (i == 1 && (s[index] > '2' || (s[index] == '2' && s[index + 1] > '6'))) continue;
		dfs(s, index + i + 1);
	}

}
int numDecodings(char * s){
	count = 0;
	length = strlen(s);
	dfs(s, 0);
}

int numDecodings(char * s){
	int length = strlen(s);
	int dp[length];
	if (s[0] == '0') return 0;
	dp[0] = 1;
	dp[1] = 2;
	if (s[1] == '0') {
		dp[1]--;
	}
	if (s[0] > '2' || (s[0] == '2' && s[1] > '6')) dp[1]--;
	for (int i = 2; i < length; i++) {
		int v = 0;
		if (s[i] != '0') {
			v += dp[i - 1];
		}
		if (s[i - 1] < '2' || (s[i - 1] == '2' && s[i] < '6')) {
			v += dp[i - 2];
		}
		dp[i] = v;
	}
	return dp[length - 1];
}
struct ListNode *func(struct ListNode *node, struct ListNode *r , struct ListNode *lt) {
	if (node && node->next == r) {
		lt->next = node;
		return node;
	}
	func(node->next, r, lt)->next = node;
	return node;
}
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
	struct ListNode *temp = malloc(sizeof(struct ListNode));
	struct ListNode *lt, *current;
	int count = 1;
	temp->next = head;
	left++, right++;
	for (current = temp; current != NULL && count <= right; current = current->next, count++) {
		if (left == count + 1) {
			lt = current;
		}
	}
	func(lt->next, current, lt)->next = current;
	return temp->next;
}


struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
	struct ListNode *temp = malloc(sizeof(struct ListNode));
	struct ListNode *cur, *pre, *front;
	temp->next = head;
	pre = temp;
	int count = 1;
	for (struct ListNode *current = temp; count < left; current = current->next, count++) {
		pre = pre->next;
	}
	int k = 0;
	for (k = left, cur = pre->next; i <= right; i++) {
		front = cur->next;
		cur->next = front->next;
		front->next = cur;
		pre->next = front;
	}
	return temp->next;
}
char group[24];
char **ret;
int length;
int n;
void dfs(char *s, int index, int len, int section) {
	if (section == 4) {
		if (index >= length) {
			char *item = malloc(sizeof(char) * 24);
			strncpy(item, group, len);
			item[len - 1] = 0;
			ret[n++] = item;
		}
		return;
	}
	else {
		for (int i = 0; i < 3; i++) {
			if ((i >= 1 && s[index] == '0') || (i == 2 && (s[index] > '2' || (s[index] == '2' && (s[index + 1] > '5' || (s[index + 1] == '5' && s[index + 2] > '5')))))) {
				continue;
			}
			strncpy(group + len, s + index, i + 1);
			group[len + i + 1] = '.';
			dfs(s, index + i + 1, len + i + 2, section + 1);
		}
	}
}

char ** restoreIpAddresses(char * s, int* returnSize){
	ret = malloc(sizeof(char*) * 2187);
	length = strlen(s);
	n = 0;
	dfs(s, 0, 0, 0);
	*returnSize = n;
	return ret;
}

struct TreeNode *dfs(int min, int max, int *returnSize) {
	struct TreeNode **allTrees;
	if (min > max) {
		allTrees = malloc(sizeof(struct TreeNode*));
		allTrees[0] = NULL;
		*returnSize = 1;
		return allTrees;
	
	}
	allTrees = NULL;
	*returnSize = 0;
	for (int i = min; i <= max; i++) {

		int leftSize, rightSize;
		struct TreeNode **leftTrees = dfs(min, i - 1, &leftSize);
		struct TreeNode **rightTrees = dfs(i + 1, max, &rightSize);
		for (int j = 0; j < leftSize; j++) {
			for (int k = 0; k < rightSize; k++) {
				struct TreeNode *node = malloc(sizeof(struct TreeNode));
				node->val = i;
				node->left = leftTrees[j];
				node->right = rightTrees[k];
				allTrees = realloc(allTrees, (*returnSize + 1) * sizeof(struct TreeNode *));
				allTrees[(*returnSize)++] = node;
			}
		}
	}
	return allTrees;
}

struct TreeNode** generateTrees(int n, int* returnSize){
	return dfs(0, n, returnSize);
}

int numTrees(int n){
  int dp[n + 1][n + 1];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) {
	  dp[i][i] = 1;
	  dp[i][i - 1] = 1;
  }
  for (int i = 1; i <= n; i++) {
	  for (int j = 1; j <= i; j++) {
		  for (int k = j; k <= i; k++) {
			  dp[j][i] += dp[j][k - 1] * dp[k + 1][i];
		  }
	  }
  }
  return dp[1][n];
}
//125
//45
//41525
//14255
//1233
//45
//142533
//x + y
//1: x y 
//
//
bool isInterleave(char * s1, char * s2, char * s3){
	int l1 = strlen(s1),
		l2 = strlen(s2),
		l3 = strlen(s3);
	
	if (l3 != l1 + l2) return false;
	bool dp[l1 + 1][l2 + 1];
	dp[0][0] = true;

	for (int i = 0; i <= l1; i++) {
		for (int j = 0; j <= l2; j++) {
			if (i > 0) {
				dp[i][j] = dp[i - 1][j] && (s1[i - 1] == l3[i + j - 1]);
			}
			if (j > 0) {
				dp[i][j] = dp[i][j] || (dp[i][j - 1] && (s1[j - 1] == l3[i + j - 1]));
			}
		}
	}
	return dp[l1][l2];
}

bool isInterleave(char * s1, char * s2, char * s3){
	int l1 = strlen(s1),
		l2 = strlen(s2),
		l3 = strlen(s3);
	
	if (l3 != l1 + l2) return false;
	bool dp[l2 + 1]

    memset(dp, 0, sizeof(dp));
	dp[0][0] = true;

	for (int i = 0; i <= l1; i++) {
		for (int j = 0; j <= l2; j++) {
			if (i > 0) {
				dp[j] = dp[j] && (s1[i - 1] == s3[i + j - 1]);
			}
			if (j > 0) {
				dp[j] = dp[j] || (dp[j - 1] && (s2[j - 1] == s3[i + j - 1]));
			}
		}
	}
	return dp[l2];
}
