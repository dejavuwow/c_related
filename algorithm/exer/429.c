int directions[][2] = {{0, 1}, {1, 0}};
int total = 0;
void dfs(int x, int y, int m, int n) {
	// printf("%d %d\n", x, y);
	if (x >= m - 1 || y >= n - 1) {
		total++;
		return;
	}
	if (x == m - 1) {
		dfs (x,y)
	}
	for (int i = 0; i < 2; i++) {
		if (x + directions[i][0] <= m - 1 && y + directions[i][1] <= n - 1) {
			dfs(x + directions[i][0], y + directions[i][1], m, n);
		}
	}
}
int uniquePaths(int m, int n){
	total = 0;
	dfs(0, 0, m, n);
	return total;
}
// 7 + 6 + 5 + 4 + 3 + 2 + 1
// 3 + 2 + 1
// 3 + 2 + 1
//******
//****
//*** *
//***  *
//** **
//** * *
//**  **
//
//* ***
//* ** *
//* * **
//*  ***
//
// ****
// *** *
// ** **
// * ***
//  ****
//1234
//321
//132
//m + n - 2 ***  m + n -2 - (m -1)  +1
//
//12345
//5*4*3 n - m
//54321
//4321
//5 + 4 + 3 + 2 + 1
//n - 2 + ... + 1
//n - 3 + .... + 1
//...1
// m + n - 2 - m
// 4+3+2+1
// 3+2+1
// 2+1
// 1
//1    4 (4)
//n    n + 4
// n + m - 1
//
//1 3 11
//8 7 1
//6 1 4
int uniquePaths(int m, int n){
	int dp[m][n];
	for (int i = 0; i < m; i++) {
		dp[i][0] = 1;
	}
	for (int i = 0; i < n; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m - 1][n - 1];
}
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
	int m = obstacleGridSize,
		n = obstacleGridColSize[0];
	int dp[m][n];
	if (obstacleGrid[0][0]) return 0;
	dp[0][0] = 1;

	for (int i = 1; i < m; i++) {
		dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : dp[i - 1][0];
	}
	for (int i = 1; i < n; i++) {
		dp[0][i] = obstacleGrid[0][i] == 1 ? 0 : dp[0][i - 1];
	}

	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m - 1][n - 1];

}
// 12
// 11
#define MIN(x, y) ((x) < (y) ? (y) : (x))
int minPathSum(int** grid, int gridSize, int* gridColSize){
	int m = gridSize,
		n = gridColSize[0];

	int dp[m][n];
	dp[0][0] = grid[0][0];

	for (int i = 1; i < m; i++) {
		dp[i][0] += dp[i - 1][0];
	}
	for (int i = 1; i < n; i++) {
		dp[0][i] += dp[0][i - 1];
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			dp[i][j] =  MIN(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
		}
	}
	return dp[m - 1][n - 1];
}
// 18 -2 -3 12 1
#define MAX(x, y) ((x) < (y) ? (y) : (x))
int getMax(int *nums, int start, int end) {
	if (start == end) {
		return nums[start];
	}
	int mid = (start + end) / 2;
	int leftMax = getMax(start, mid);
	int rightMax = getMax(mid + 1, end);
	int sum = 0, lmax = INT_MIN, rmax = INT_MIN; 
	for (int i = mid; i >= start; i--) {
		sum += nums[i];
		lmax = MAX(lmax, sum);
	}
	sum = 0;
	for (int j = mid + 1; j <= end; j++) {
		sum += nums[i];
		rmax = MAX(rmax, sum);
	}
	return MAX(MAX(leftMax, rightMax), lax + rmax);
}
int maxSubArray(int* nums, int numsSize){
	return getMax(nums, 0, numsSize - 1);
}
enum State {
	STATE_INITIAL,
	STATE_INT,
	STATE_INT_SIGN,
	STATE_POINT,
	STATE_POINT_NOINT,
	STATE_EXP,
	STATE_EXP_SIGN,
	STATE_EXP_NUM,
	STATE_FRACTION,
	STATE_ILLEGAL
}

enum charType {
	TYPE_NUMBER,
	TYPE_SIGN,
	TYPE_POINT,
	TYPE_EXP,
	TYPE_ILLEGAL
}
enum charType getCharType(char ch) {
	if (ch >= '0' && ch <= '9') {
		return TYPE_NUMBER;
	}
	else if (ch == '+' || ch == '-') {
		return TYPE_SIGN;
	}
	else if (ch == '.') {
		return TYPE_POINT;
	}
	else if (ch == 'e' || ch == 'E') {
		return TYPE_EXP;
	}
	else return TYPE_ILLEGAL;
}
enum State getNextState(enum State st, enum charType ct) {
	if (st == STATE_INITIAL) {
		if (ct == TYPE_NUMBER) {
			return STATE_INT;
		}
		else if (ct == TYPE_SIGN) {
			return STATE_INT_SIGN;
		}
		else if (ct == TYPE_POINT) {
			return STATE_POINT_NOINT;
		}
		else return STATE_ILLEGAL;
	}
	else if (st == STATE_INT) {
		if (ct == TYPE_NUMBER) {
			return STATE_INT;
		}
		else if (ct == TYPE_POINT) {
			return STATE_POINT;
		}
		else if (ct == TYPE_EXP) {
			return STATE_EXP;
		}
		else return STATE_ILLEGAL;
	}
	else if (st == STATE_INT_SIGN) {
		if (ct == TYPE_NUMBER) {
			return STATE_INT;
		}
		else if (ct == TYPE_POINT) {
			return STATE_POINT_NOINT;
		}
		else return STATE_ILLEGAL;
	}
	else if (st == STATE_POINT) {
		if (ct == TYPE_NUMBER) {
			return STATE_FRACTION;
		}
		else if (ct == TYPE_EXP) {
			return STATE_EXP;
		}
		else return STATE_ILLEGAL;
	}
	else if (st == STATE_POINT_NOINT) {
		if (ct == TYPE_NUMBER) {
			return STATE_FRACTION;
		}
		else return STATE_ILLEGAL;
	}
	else if (st == STATE_EXP) {
		if (ct == TYPE_NUMBER) {
			return STATE_EXP_NUM;
		}
		else if (ct == TYPE_SIGN) {
			return STATE_EXP_SIGN;
		}
		else return STATE_ILLEGAL;
	}
	else if (st == STATE_EXP_SIGN) {
		if (ct == TYPE_NUMBER) {
			return STATE_EXP_NUM;
		}
		else return STATE_ILLEGAL;
	}
	else if (st == STATE_EXP_NUM) {
		if (ct == TYPE_NUMBER) {
			return STATE_EXP_NUM;
		}
		else return STATE_ILLEGAL;
	}
	else if (st == STATE_FRACTION) {
		if (ct == TYPE_NUMBER) {
			return STATE_FRACTION;
		}
		else if (ct == TYPE_EXP) {
			return STATE_EXP;
		}
		else return STATE_ILLEGAL;
	}
	else return STATE_ILLEGAL;
}
bool isNumber(char * s){
	int l = strlen(s);
	enum State state = STATE_INITIAL;
	enum charType t;
	for (int i = 0; i < l; i++) {
		t = getCharType(s[i]);
		if (t == TYPE_ILLEGAL) return false;
		state = getNextState(state, t);
		if (state == STATE_ILLEGAL) return false;
	}
	return state == STATE_INT || state == STATE_POINT || state == STATE_EXP_NUM || state == STATE_FRACTION;
}
