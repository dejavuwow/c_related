#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using i64 = long long;
int check(char **grid, int n, int m) {

#define TEST_BOUNDARY(x, y) (x < 0 || x >= n || y < 0 || y >= m)
	int count = 0;
	int cCount = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			switch (grid[i][j]) {
				case 'C':
					if ((!TEST_BOUNDARY(i, j -1) && !TEST_BOUNDARY(i, j + 1) && grid[i][j - 1] == 'R' && grid[i][j + 1] == 'L') ||(!TEST_BOUNDARY(i - 1, j) && !TEST_BOUNDARY(i + 1, j) && grid[i - 1][j] == 'D' && grid[i + 1][j] == 'U')) {
						return 0;
					}
					count++;
					cCount++;
					break;
				case 'U':
					if (TEST_BOUNDARY(i - 1, j) || grid[i - 1][j] != 'C') return 0;
					count++;
					break;
				case 'L':
					if (TEST_BOUNDARY(i, j - 1) || grid[i][j - 1] != 'C') return 0;
					count++;
					break;
				case 'D':
					if (TEST_BOUNDARY(i + 1, j) || grid[i + 1][j] != 'C') return 0;
					count++;
					break;
				case 'R':
					if (TEST_BOUNDARY(i, j + 1) || grid[i][j + 1] != 'C') return 0;
					count++;
					break;
				case '.':
					if (i != 0 || j != m - 1) return 0;
					break;
			}
		}
	}
	return count == m * n - 1 && cCount == (m * n - 1) / 3;
}
const std::vector<std::string> T[8] {
	{},
		{},
		{
			".D",
			"RC"
		},
		{},
		{
			".DRC",
			"RCDU",
			"DRCD",
			"CLRC"
		},
		{
			".CLRC",
			"DUCLU",
			"CLURC",
			"DRCDU",
			"CLUCL"
		},
		{},
		{
			".CLRCRC",
			"DUCLUDU",
			"CLURCCL",
			"DRCDURC",
			"CLUCLDU",
			"DRCDRCD",
			"CLUCLRC"
		}
};

std::vector<std::string> get(int n, int m) {
	if (n * m % 3 == 0 || n % 3 != m % 3) {
		return {};
	}
	std::vector<std::string> ans(n, std::string(m, '.'));
	int a = 0;
	 for (int t = 0; t < 2; t++) {
		while (n % 2 == 0 && m > 4) {
			for (int i = 0; i < n; i += 2) {
				ans[i][m - 3] = 'C';
				ans[i][m - 2] = 'L';
				ans[i][m - 1] = 'D';
				ans[i + 1][m - 3] = 'U';
				ans[i + 1][m - 2] = 'R';
				ans[i + 1][m - 1] = 'C';
			}
			m -= 3;
		}
		while (m % 2 == 0 && n > 4) {
			for (int i = 0; i < m; i += 2) {
				ans[n - 3][i] = 'C';
				ans[n - 2][i] = 'U';
				ans[n - 1][i] = 'R';
				ans[n - 3][i + 1] = 'L';
				ans[n - 2][i + 1] = 'D';
				ans[n - 1][i + 1] = 'C';
			}
			n -= 3;
		}
	 }
	while (m > 7) {
		for (int i = 0; i < n - 3; i += 2) {
			for (auto j : {0, 3}) {
				ans[i][m - j - 3] = 'C';
				ans[i][m - j - 2] = 'L';
				ans[i][m - j - 1] = 'D';
				ans[i + 1][m - j - 3] = 'U';
				ans[i + 1][m - j - 2] = 'R';
				ans[i + 1][m - j - 1] = 'C';
			}
		}
		for (int i = m - 6; i < m; i += 2) {
			ans[n - 3][i] = 'C';
			ans[n - 2][i] = 'U';
			ans[n - 1][i] = 'R';
			ans[n - 3][i + 1] = 'L';
			ans[n - 2][i + 1] = 'D';
			ans[n - 1][i + 1] = 'C';
		}
		m -= 6;
	}
	while (n > 7) {
		for (int i = 0; i < m - 3; i += 2) {
			for (auto j : {0, 3}) {
				ans[n - j - 3][i] = 'C';
				ans[n - j - 2][i] = 'U';
				ans[n - j - 1][i] = 'R';
				ans[n - j - 3][i + 1] = 'L';
				ans[n - j - 2][i + 1] = 'D';
				ans[n - j - 1][i + 1] = 'C';
			}
		}
		for (int i = n - 6; i < n; i += 2) {
			ans[i][m - 3] = 'C';
			ans[i][m - 2] = 'L';
			ans[i][m - 1] = 'D';
			ans[i + 1][m - 3] = 'U';
			ans[i + 1][m - 2] = 'R';
			ans[i + 1][m - 1] = 'C';
		}
		n -= 6;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans[i][j] = T[n][i][j];
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		std::reverse(ans[i].begin(), ans[i].end());
		for (auto &c : ans[i]) {
			if (c == 'L') {
				c = 'R';
			} else if (c == 'R') {
				c = 'L';
			}
		}
	}
	return ans;
}

void solve() {
   /*  int n, m; */
	/* std::cin >> n >> m; */
    /*  */
	/* auto ans = get(n, m); */
	/*         if (ans.empty()) { */
	/*             std::cout << "No\n"; */
	/*         } else { */
	/*             std::cout << "Yes\n"; */
			/* } */
	for (int n = 2; n <= 500; n++) {
		for (int m = 2; m <= 500; m++) {
			std::cout << n << "^^" << m << "\n";
			auto ans = get(n, m);
			if (ans.empty()) {
				std::cout << "No\n";
			} else {
				std::cout << "Yes\n";
			}
		}
	}
	std::cout << "Done\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

		solve();

	return 0;
}
