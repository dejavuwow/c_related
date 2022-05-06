#include <stdio.h>
//abcb
// f(i,j) = {
//  str[i] != str[j]
//  str[i] == str[j], fn(i + 1, j - 1)
// }
// i = j true
// i + 1 = j true
//  ****1**4**
//  n + x = j
//  j + x = i
// n = j - i + j
//  j - (i -j)
char * longestPalindrome(char * s){

	const int l = strlen(s);
	int dp[l][l];
	int max_length = 1;
	char *ret = (char*)malloc(sizeof(char) * 1001);
	ret[0] = s[0];
	ret[1] = 0;

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			dp[i][j] = i == j ? 1 : 0;
		}
	}

	for (int i = 1; i < l; i++) {
		for (int j = 0; j < l; j++) {
			if (j + i >= l) break;
			else if (i == 1) {
				dp[j][j + i] = s[j] == s[j + i];
			}
			else {
				dp[j][j + i] = s[j] != s[j+i] ? 0 : dp[j + 1][j + i - 1];
			}
			if (dp[i][j+i]&& max_length < i + 1) {
				strncpy(ret, &s[j], i);
				ret[i] = '\0';
				max_length = i + 1;
			}
		}
	}
	return ret;

}

#define MIN(x, y) ((x) < (y) ? (x) : (y))
char * longestPalindrome(char * s){
	const int l = strlen(s);
	char *ret = malloc(sizeof(char) * (l + 1));
	const int new_l = l * 2 + 2;
	char new_s[new_l];
	int radius[new_l];
	int index = 0;
	new[index++] = '#';

	for (int i = 0; i < l; i++) {
		new[index++] = s[i];
		new[index++] = '#';
	}
	new[index] = '\0';

	int j = -1;
	int right_l = -1;
	int max = 1;
	int start = 0;
	int end = 0;
	
	for (int i = 0; i < new_l; i++) {
		left = i - 1;
		right = i + 1;
		if (i < right_l) {
			int r = MIN(radius[2 * j - i], right_l - i);
			left = left - r;
			right = right + r;
		}
		while (left >= 0 && right < new_l && new_s[left] == new_s[right]) {
			left--;
			right++;
		}
		radius[i] = (right - left - 2) / 2;
		if (right - 1 > right_l) {
			right_l = right - 1;
			j = i;
		}
		if (radius[i] > max) {
			start = left + 1;
			end = right - 1;
		}
	}
	int o = 0;
	for (int i = start; i <= end; i++) {
		if (new_s[i] != '#') ret[o++] = new_s[i];
	}
	ret[o] = '\0';
	return ret;
}
int lengthOfLongestSubstring(char * s){
	int l = strlen(s);
	int map[128] = {0};
	int max = 0;
	
	for (int i = 0, j = 0; i < l; map[s[i]]--, i++) {
		while (j < l && map[s[j]] == 0) {
			map[s[j]]++;
			j++;
			max = MAX(max, j - i);
		}
	}
	return max;
}
int main(void)
{
	struct mpl {
		int age;
		void *data;
	};

	struct mpl test;
	test.age = 10;

	return 0;
}
