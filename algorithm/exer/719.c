//f(a,b) = {
//	f(0, 1) = 0, f(1, 0) = 1;
//	f(a - 1, b - 1) + f(a - 1, b) // a == b
//	f(a - 1, b)
//}
//https://hhd.test.dooffe.net/20-customer/activity-front/index.html#/zajindanAttent?activityId=1548128140957544448&userId=1546334233336705024&outId=oqlY-5_VTzfW3ZnIzldoXP_CcwhM
int numDistinct(char * s, char * t){
	int s_len = strlen(s),
		t_len = strlen(t);
	int dp[s_len][t_len];
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 1;

	for (int i = 1; i <= s_len; i++) {
		for (int j = 1; j <= t_len; j++) {
			dp[i][j] = s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] + dp[i - 1][j] : dp[i - 1][j];
		}
	}
	return dp[s_len][t_len];
}

void func(struct Node *first) {
	if (first == NULL) return;
	struct Node *current = first, *sub = NULL, *head = NULL;
	while (current != NULL) {
		if (sub != NULL) {
			if (current->left) {
				sub->next = current->left;
				sub = sub->next;
			}
			if (current->right) {
				sub->next = current->right;
				sub = sub->next;
			}
		}
		else {
			if (current->left) {
				head = sub = current->left;
			}
			if (current->right) {
				if (sub) {
					sub->next = current->right;
				} 
				else {
					head = current->right;
				}
				sub = current->right;
			}
		}
		current = current->next;
	}
	func(head);
}
struct Node* connect(struct Node* root) {
	if (root != NULL) {
		while (first != NULL) {
			struct Node *current = first, *sub = NULL, *head = NULL;
			while (current != NULL) {
				if (sub != NULL) {
					if (current->left) {
						sub->next = current->left;
						sub = sub->next;
					}
					if (current->right) {
						sub->next = current->right;
						sub = sub->next;
					}
				}
				else {
					if (current->left) {
						head = sub = current->left;
					}
					if (current->right) {
						if (sub) {
							sub->next = current->right;
						} 
						else {
							head = current->right;
						}
						sub = current->right;
					}
				}
				current = current->next;
			}
		}
		first = head;
	}
	return root;
}
//		1
//	   1 1
//	  1 2 1
//	 1 3 3 1
//	1 4 6 4 1
//
// n! / m!(n - m)!    n! / (m + 1)!(n - m - 1)!   (n - m) / (m + 1)
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
	int **ret = malloc(sizeof(int*) * numRows);
	*returnSize = numRows;
	*returnColumnSizes = malloc(sizeof(int) * numRows);
	for (int i = 0; i < numRows; i++) {
		int length = i + 1;
		int *row = malloc(sizeof(int) * length);
		int k = 1;
		row[0] = 1;
		row[length - 1] = 1;
		length -= 2;
		while (k < length - 1) {
			row[k] = ret[i - 1][k - 1] + ret[i - 1][k];
			k++;
		}
		(*returnColumnSizes)[i] = length;
		ret[i] = row;
	}
	return ret;
}
//12345
//5* 4 
int* getRow(int rowIndex, int* returnSize){
	int *currentRow = malloc(sizeof(int) * (rowIndex + 1));

	for (int i = 0; i <= rowIndex; i++) {
		int length = i + 1;
		int k = length - 2;
		currentRow[0] = currentRow[length - 1] = 1;
		while (k > 0) {
			currentRow[k] = currentRow[k - 1] + currentRow[k];
			k--;
		}
	}
	return currentRow;
}
//   2
//  2 3
// 2 5 3
//3 6 8 0
#define MIN(a,b) ((a) < (b) ? a : b)
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
	int bottomSize = triangleColSize[triangleSize - 1];
	int list[bottomSize];
	memcpy(list, triangle[triangleSize - 1], bottomSize * sizeof(int));
	for (int row = triangleSize - 2; row >= 0; row--) {
		int item = triangle[row];
		for (int col = 0; col < triangleColSize[row]; col++) {
			list[col] = MIN(list[col] + item[col], list[col + 1] + item[col]); 
		}
	}
	return list[0];
}
//012345
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) < (b) ? (b) : (a))
int subMaxProfit(int *prices, int start, int end) {
	int min = INT_MAX, max = 0;
	while (start <= end) {
		min = MIN(min, prices[start]);
		max = MAX(max, prices[start] - min);
		start++;
	}
	return max;
}


//dp[0][0] = 0, min = INT_MAX
//dp[0][i],  min = MIN(min, p[i]),  max(dp[0][i - 1], p[i] - min);
//dp[j][l], min = MIN(min, p[j]), max(dp[j + 1][l], p[l] - min)
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) < (b) ? (b) : (a))
int maxProfit(int* prices, int pricesSize){
	int left[pricesSize];
	int right[pricesSize];

	int min1 = prices[0];
	int min2 = prices[pricesSize - 1];
	int max = 0;
    int max2 = prices[pricesSize - 1];
	left[0] = 0;
	right[pricesSize - 1] = 0;

	for (int i = 1; i < pricesSize; i++) {
		min1 = MIN(min1, prices[i]);
		min2 = MIN(min2, prices[pricesSize - i - 1]);
        max2 = MAX(max2, prices[pricesSize - i - 1]);

		left[i] = MAX(left[i - 1], prices[i] - min1);
        right[pricesSize - 1 - i] = min2 == prices[pricesSize - i - 1] ? MAX(right[pricesSize - i], max2 - min2) : MAX(max2 - prices[pricesSize - i - 1], right[pricesSize - i]);


	}
	for (int i = 1; i < pricesSize - 1; i++) {
		max = MAX(max, left[i] + right[i+1]);
	}
	return MAX(left[pricesSize - 1], max);
}
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) < (b) ? (b) : (a))
int maxProfit(int k, int* prices, int pricesSize){
    if (pricesSize == 0) return 0;
	int n = MIN(pricesSize / 2, k) + 1;
	int m = pricesSize;
	int buy, sell;
	
	for (int j = 1; j < n; j++) {
		buy = -prices[0];
		sell = 0;
		for (int i = 1; i < m; i++) {
			buy = MAX(sell - prices[i], buy);
			sell = MAX(buy[i - 1][j - 1] + prices[i], sell);
		}
	}
	return sell;
}
/** int maxProfit(int k, int* prices, int pricesSize){ */
    /** if (pricesSize == 0) return 0; */
	/** int n = MIN(pricesSize / 2, k) + 1; */
	/** int m = pricesSize; */
	/** int buy[m][n]; */
	/** int sell[m][n]; */
    /** int max = INT_MIN; */
    /** int maxBuy = INT_MIN; */
    /**  */
	/** for (int i = 0; i < n; i++) { */
	/**     buy[0][i] = -prices[0]; */
	/**     sell[0][i] = 0; */
	/** } */
	/** for (int i = 0; i < m; i++) { */
	/**     buy[i][0] = maxBuy = MAX(maxBuy, -prices[i]); */
	/**     sell[i][0] = 0; */
	/** } */
	/** for (int j = 1; j < n; j++) { */
	/**     for (int i = 1; i < m; i++) { */
	/**         buy[i][j] = MAX(sell[i - 1][j] - prices[i], buy[i - 1][j]); */
	/**         sell[i][j] = MAX(buy[i - 1][j - 1] + prices[i], sell[i - 1][j]); */
	/**     } */
	/** } */
	/** return sell[m-1][n-1]; */
/** } */
//buy[i-1][j-1] = sell[i-2][j-1] - prices[i-1], buy[i-2][j-1]
//
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) < (b) ? (b) : (a))
int maxProfit(int k, int* prices, int pricesSize){
    if (pricesSize == 0) return 0;
	int n = MIN(pricesSize / 2, k) + 1;
	int m = pricesSize;
	int buy[m][n];
	int sell[m][n];
    int max = INT_MIN;
    int maxBuy = INT_MIN;

	for (int i = 0; i < n; i++) {
		buy[0][i] = -prices[0];
		sell[0][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		buy[i][0] = maxBuy = MAX(maxBuy, -prices[i]);
		sell[i][0] = 0;
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			buy[i][j] = MAX(sell[i - 1][j] - prices[i], buy[i - 1][j]);
			sell[i][j] = MAX(buy[i - 1][j - 1] + prices[i], sell[i - 1][j]);
		}
	}
	return sell[m-1][n-1];
}
//buy[i][j-1] = sell[i-1][j-1] - prices[i], buy[i-1][j-1]
//
//sell[i][j - 1] = buy[i-1][j-2], sell[i-1][j-1]
//sell[i][j] = buy[i-1][j-1] + prices[i], sell[i-1][j-1], sell[i-1][j]
//
//sell[i-1][j-1], sell[i-1][j], buy[i-1][j-1] + prices[i]
//0 -1073741824 1     1
//-1073741824 -1073741824 -1073741822 2
//-1073741824 -1073741824 -1073741822 3
//
//0 1 3
//1 -1073741822 -1073741820
//-1073741822 -1073741822 -1073741820
//
//0 3 6
//3 1 4
//1 -1073741820 -1073741817
//
//0 6 2
//6 4 0
//4 1 -3
//
//0 6 4
//6 6 8
