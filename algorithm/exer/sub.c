#include <stdio.h>
#include <stdlib.h>
// 12361234 * 43216123|4
//{1,2,3}
void printSubArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			for (int k = i; k <= j; k++)
				printf("%d ", array[k]);

			putchar('\n');

		}
	}
}
int numOfSubarrays(int* arr, int arrSize, int k, int threshold){
	int sum = 0;
	int target = k * threshold;
	int counts = 0;
	int i;
	for (i = 0; i < k; i++)
		sum += arr[i];

	int diff = target - sum;
	int old = diff;
	if (diff <= 0) counts++;
	i = 1;
	while (i  < arrSize - (k-1))
	{
		if ((diff = arr[i+k-1] - arr[i - 1]) >= old ) counts++;
		old = old - diff;
		i++;
	}
	return counts;
}
struct People {
	char name[10];
	int age;
};
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
	int counts = 0;
	for (int i =0; i < numsSize; i++)
	{
		if (nums[abs(nums[i] - 1)] > 0) nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
	}
	int *ret = (int*)malloc(sizeof(int) * numsSize);
	counts = 0;
	int lsize = 0;
	for (int index = 0; index < numsSize; index++)
	{
		printf("%d ", nums[index]);
		if (nums[index] > 0) {
			ret[counts++] = index + 1;
			lsize++;
		}
	}
	*returnSize = lsize;
	return ret;

}

struct my_struct {
	char name[31];
	int num;            /* we'll use this field as the key */
	int numCopy;
	UT_hash_handle hh; /* makes this structure hashable */
};
struct my_struct *sp, *users = NULL;
int count = 0;
void add_item(char *str) {
	sp = (struct my_struct *)malloc(sizeof(struct my_struct));
	strcpy(sp->name, str);
	sp->num = 1;
	sp->numCopy = 0;
	HASH_ADD_STR(users, name, sp);
}
void delete_all() {
	struct my_struct *current_user, *tmp;

	HASH_ITER(hh, users, current_user, tmp) {
		HASH_DEL(users, current_user);  /* delete; users advances to next */
		free(current_user);             /* optional- if you want to free  */
	}
}
#define FIND_STR(dest, src, size) {\
	strncpy(dest, src, size);\
	HASH_FIND_STR(users, dest, sp);\
}
#define MAP_STR_ADD {\
	sp->numCopy++;\
	if (sp->numCopy <= sp->num) count++;\
}
#define MAP_STR_RED {\
	sp->numCopy--;\
	if (sp->numCopy < sp->num) count--;\
}
int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
	int l = strlen(s);
	int itemSize = strlen(words[0]);
	int totalWordsLength = itemSize * wordsSize;
	char temp[itemSize + 1];
	int *ret = NULL;
	int num = 0;
	count = 0;

	temp[itemSize] = '\0';

	for (int i = 0; i < itemSize; i++) {
		for (int left = i, right = i;  left <= l - totalWordsLength; ) {
			while (right <= left + totalWordsLength - itemSize) {

				//case 1: left 到 left + totalWordslength中的单词全部在words中，该情况下，让整个窗口往右滑动一个单词
				//同时将滑过的左侧单词从map中清除（如果存在的话）, 将右侧新入窗的单词加入map(如果存在的话)
				//case 2: 子串中存在单词不在words中，那么直接将left平移到指针指向的单词的下一位,同时将left滑过的单词从map
				//中清除
				FIND_STR(temp, s + right, itemSize);
				if (sp) {
					MAP_STR_ADD;
					if (count == wordsSize) {
						ret = realloc(ret, (num + 1) * sizeof(int));
						ret[num++] = left;
					}
				}
				else {
					for (; left < right; left += itemSize) {
						FIND_STR(temp, s + left, itemSize);
						if (sp) MAP_STR_RED;
					}
					right += itemSize;
					break;
				}
			}
			FIND_STR(temp, s + left, itemSize);
			if (sp) MAP_STR_RED;
			left += itemSize;
		}
	}
	delete_all();
	*returnSize = num;
	return ret;
}
*
**
***
***
	x * y
(x - 1) (y + 1)
	//case 1: 
	// min(height[k], height[i]) * (k - i) 
#define MIN(x, y) ((x) < (y) ? (x) : (y))
	int maxArea(int* height, int heightSize){
		int total;
		int max = INT_MIN;
		for (int i = 0, j = heightSize - 1; i < j; ) {
			total = MIN(height[i], height[j]) * (j - i);
			if (max < total) max = total;
			if (height[i] > height[j]) j--;
			else i++;
		}
		return max;
	}
char * intToRoman(int num){
	char *ret = calloc(21, sizeof(char));
	char tb4[][2] = {{'I', 'V'}, {'X', 'L'}, {'C', 'D'}};
	char tb9[][2] = {{'I', 'X'}, {'X', 'C'}, {'C', 'M'}};
	int index = 0;
	int temp = num;
	int digit[4];
	int cur = -1;

	while (temp > 0) {
		digit[++cur] = temp % 10;
		temp /= 10;
	}
	while (cur >= 0) {
		if (digit[cur] == 4) {
			ret[index++] = tb4[cur][0];
			ret[index++] = tb4[cur][1];
		}
		else if (digit[cur] == 9) {
			ret[index++] = tb9[cur][0];
			ret[index++] = tb9[cur][1];
		}
		else {
			if (cur == 3) {
				while (digit[cur]) {
					ret[index++] = 'M';
					digit[cur]--;
				}
			}
			else if (cur == 2) {
				while (digit[cur]) { 
					if (digit[cur] >= 5) {
						ret[index++] = 'D';
						digit[cur] -= 5;
					}
					else {
						ret[index++] = 'C';
						digit[cur]--;
					}
				}
			}
			else if (cur == 1) {
				while (digit[cur]) {
					if (digit[cur] >= 5) {
						ret[index++] = 'L';
						digit[cur] -= 5;
					}
					else {
						ret[index++] = 'X';
						digit[cur]--;
					}
				}
			}
			else {
				while (digit[cur]) {
					if (digit[cur] >= 5) {
						ret[index++] = 'V';
						digit[cur] -= 5;
					}
					else {
						ret[index++] = 'I';
						digit[cur]--;
					}
				}
			}
		}
		cur--;
	}
	return ret;
}

int romanToInt(char * s){
	const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	const char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

	int sum = 0;
	char temp[3] = {'\0'};

	for (int i = 0, index = 0; i < 13; i++) {
		int l = strlen(symbols[i]);
		strncpy(temp, s[index], l);
		while (strncmp(temp, symbols[i])) {
			index += l;
			sum += values[i];
			strncpy(temp, s[index], l);
		}
	}
	return sum;
}

int j = 0;
int l;
char *temp;
void gen(char *str, int index, int count, int flag, char ***ret) {
	if (!count) {
		printf("str: %s \n", str);
		*ret = realloc(*ret, sizeof(char*) * (j + 1));
		temp = malloc(sizeof(char) * (l + 1));
		strncpy(temp, str, l + 1);
		(*ret)[j++] = temp;
		return;
	}
	if (flag == 0) {
		str[index] = '(';
		//printf("left: %d  right: %d %s\n", left, right, str);
		gen(str, index + 1, count - 1, flag + 1, ret);
	}
	else  {
		if (flag < co / 2) {
			str[index] = '(';
			//printf("left: %d  right: %d %s\n", left, right, str);
			gen(str, index + 1, count - 1, flag + 1, ret);
		}

		str[index] = ')';

		gen(str, index + 1, count - 1, flag - 1, ret);
	}
}
char ** generateParenthesis(int n, int* returnSize){
	int count = 2 * n;
	int flag = 0;

	char **ret = NULL;

	l = 2 * n;
	j = 0;
	char str[l + 1];
	str[ l ] = '\0';
	gen(str, 0, count, flag, &ret);

	*returnSize = j;
	return ret;

}
bool isValid(char * s){
	int n = strlen(s);
	char stack[n];
	int top = -1;

	for (int i = 0; i < n; i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			stack[++top] = s[i];
		}
		else {
			if ((s[i] == ')' && pop >= 0 && stack[top] == '(') ||
				(s[i] == '}' && pop >= 0 && stack[top] == '{') ||
				(s[i] == ']' && pop >= 0 && stack[top] == '[') 
				) {
				top--;
			}
			else {
				return false;
			}
		}
	}
	if (top >= 0) return false;
	return true;
}
int main(void)
{
	int a;
	int *temp = &a;
	findDisappearedNumbers((int[]){1,1,2,2,3,4,5,6},8, temp);
	return 0;
}
