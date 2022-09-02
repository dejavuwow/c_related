int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
	int l = n * n;
	int top = 0,
		right = n - 1,
		bottom = n - 1,
		left = 0;

	int i = 0;
	int j = 0;
	int index = 0;
	int **ret = malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		ret[i] = malloc(sizeof(int) * n);
	}

	while (index < l) {
		while (j <= right && index < l) {

			ret[i][j++] = ++index;
		}
		j--;
		i++;
		top++;

		while (i <= bottom && index < l) {

			ret[i++][j] = ++index;
		}
		i--;
		j--;
		right--;

		while (j >= left && index < l) {

			ret[i][j--] = ++index; 
		}
		j++;
		i--;
		bottom--;

		while (i >= top && index < l) {

			ret[i--][j] = ++index;
		}
		i++;
		j++;
		left++;
	}
	*returnColumnSizes = malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		(*returnColumnSizes)[i] = n;
	}
	*returnSize = n;
	return ret;

}
//612345
//612354
//612435
//612453
//612534
//612543
//613245
//675
void swap(char *a, char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}
void reSort(char *s, int start, int end) {
	while (start < end) {
		swap(&s[start], &s[end]);
		start++;
		end--;
	}
}
char * getPermutation(int n, int k){
	char *ret = malloc(sizeof(char) * (n + 1));
	ret[n] = 0;
	int pt = 1;
	for (int i = 1; i < n; i++) {
		pt *= i;
		ret[i - 1] = i + 0x30;
	}
	ret[n - 1] = n + 0x30;

	int head = (k - 1) / pt + 1;
	int s = k % pt ? k % pt : pt;
	for (int i = 0; i < n; i++) {
		if (head == ret[i] - 0x30) {
			for (int f = i; i > 0; i--) {
				ret[i] = ret[i - 1];
			}
			ret[0] = head + 0x30;
			break;
		}
	}

	for (int i = s - 1; i > 0; i--) {
		for (int j = n - 2; j >= 1; j--) {
			if (ret[j] < ret[j + 1]) {
				int d = n - 1;
				for (int c = j + 1; c <= n - 1; c++) {
					if (ret[c] < ret[j]) {
						d = c - 1;
						break;
					}
				}
				swap(&ret[j], &ret[d]);
				reSort(ret, j + 1, n - 1);
				break;
			}
		}
        printf("%s\n", ret);
	}
	return ret;
	
}
struct ListNode* rotateRight(struct ListNode* head, int k){
	int total = 1;
	struct ListNode *cur = head;
	struct ListNode *pre;
	for (; !!cur && !!cur->next; cur = cur->next) total++;
	cur->next = head;
	k = k % (total + 1);
	for (; k > 0; k--) {
		cur = head = head->next;
	}
	for (; total > 1; total--) {
		cur = cur->next;
	}
	cur->next = NULL;
	return head;
}
