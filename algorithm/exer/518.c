struct ListNode* deleteDuplicates(struct ListNode* head){
	struct ListNode *current = head;
	while (current) {
		if (current->next && current->val == current-next->val) {
			free(current->next);
			current->next = current->next->next;
		}
		current = current->next;
	}
	return head;
}

int findKthNumber(int m, int n, int k){
	int i = 1,
		j = m * n;
	int mid;

	for (; i <= j;) {
		mid = (i + j) / 2;
		int count = mid / n * j;
		for (int x = mid / n + 1; x <= m; x++) {
			count += mid / x;
		}
		if (count >= k) {
			j = mid;
		}
		else i = mid + 1;
	}
	return i;
}
#define MAX(x, y) ((x) < (y) ? (y) : (x))
int largestRectangleArea(int* heights, int heightsSize){
	int stack[heightsSize];
	int top = -1;
	int left[heightsSize];
	int right[heightsSize];
	memset(right, heightsSize, heightsSize * sizeof(int));

	for (int i = 0; i < heightsSize; i++) {
		while (leftTop >= 0 && stack[top] >= heights[i]) {
			right[stack[top--]] = i;
		}
		left[i] = top >= 0 ? stack[top] : -1;
		stack[++top] = i;
	}
	
	int max = 0;
	int total = 0;
	for (int i = 0; i < heightsSize; i++) {
		max = MAX(max, (right[i] - left[i] + 1) * heights[i]);
	}
	return max;
}
#define MEM_SET(p, v) {\
	for (int i = 0; i < m; i++) {\
		p[i] = v;\
	}\
}
#define MAX(a, b) ((a) < (b) ? (b) : (a))
int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
	int m = matrixSize,
		n = matrixColSize[0];

	int stack[m];
	int top = -1;
	int left[m][n];
	int up[m];
	int down[m];
	int max = INT_MIN;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			left[i][j] = 0;
			if (matrix[i][j] == '1') {
				left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
			}
		}
	}
	for (int j = 0; j < n; j++) {
		top = -1;
		MEM_SET(down, m)
		for (int i = 0; i < m; i++) {
			while (top >= 0 && left[stack[top]][j] >= left[i][j]) {
				down[stack[top--]] = i;
			}
			up[i] = top >= 0 ? stack[top] : - 1;
			stack[++top] = i;
		}
		for (int i = 0; i < m; i++) {
			int area = (down[i] - up[i] - 1) * left[i][j];
			max = MAX(max, area);
		}
	}
	return max;
}

