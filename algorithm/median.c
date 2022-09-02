#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
void jj(int, int);
void jj(int a, int j) {
	return;
}

// k / 2   + k /2  -
int getKthNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {
	printf("%d **\n", k);
	int s1 = 0;
	int s2 = 0;
	int i1, i2;

	while (1) {
		if (s1 == nums1Size) {
			return nums2[s2 + k - 1];
		}
		if (s2 == nums2Size) {
			return nums1[s1 + k - 1];
		}
		if (k == 1) {
			return MIN(nums1[s1], nums2[s2]);
		}
		i1 = MIN(s1 + k / 2 - 1, nums1Size - 1);
		i2 = MIN(s2 + k / 2 - 1, nums2Size - 1);


		if (nums1[i1] > nums2[i2]) {
			printf(">:%d %d %d %d\n",i1, i2, nums1[i1], nums2[i2]);
			k -= (i2 - s2 + 1);
			s2 = i2 + 1;
		} else {
			printf("<:%d %d %d %d\n",i1, i2, nums1[i1], nums2[i2]);
			k -= (i1 - s1 + 1);
			s1 = i1 + 1;
		}
	}

}
// k / 2 +
// k   - 2
// i + j =  m +n - i - j
// i + j = (m + n + 1) / 2;
// j = (m + n + 1) / 2 - i
// j = (n + 1 - m) / 2;
//  A[i - 1] <= B[j] && B[j - 1] <= A[i];
//
/** double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){ */
/** int l = nums1Size + nums2Size; */
/** printf("%d %d %d\n", l, nums1Size, nums2Size); */
/** if (l % 2 == 0) { */
/**     return (getKthNumber(nums1, nums1Size, nums2, nums2Size, l / 2) + getKthNumber(nums1, nums1Size,  nums2,  nums2Size, l / 2 + 1)) / 2.0; */
/** } */
/** else { */
/**     return getKthNumber(nums1, nums1Size, nums2, nums2Size, (l + 1) / 2); */
/** } */
/** } */
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
	int l = 0;
	int r = nums1Size;
	int i1, i2;
	int median1, median2;
	int k1, km1, k2, km2;
	while(l <= r) {
		i1 = (r + l) / 2; 
		i2 = (nums1Size  + nums2Size + 1) / 2 - i1;
		km1 = (i1 == 0 ? INT_MIN : nums1[i1 - 1]);
		km2 = (i2 == 0 ? INT_MIN : nums2[i2 - 1]);
		k1 = (i1 == nums1Size ? INT_MAX : nums1[i1]);
		k2 = (i2 == nums2Size ? INT_MAX : nums2[i2]);

		if (km1 <= k2) {
			median1 = MAX(km1,km2);
			median2 = MIN(k1, k2);
			l = i1 + 1;
		}
		else {
			r = i1 - 1;
		}
	}
}
//12321
//12312 1001
// 556, 5566*
bool isPalindrome(int x){
	if (x < 0 || (x > 0 && x % 10 == 0)) return false;
	int reverse = 0;
	while (reverse < x) {
		reverse += reverse * 10 + x % 10;
		x /= 10;
	}
	return reverse == x || reverse / 10 == x;
}
//56
// . *
// 5*
// 3*
//
bool isMatch(char * s, char * p){
#define MATCH(i, j) (i == 0 ? false : (p[j - 1] == '.' ? true : s[i - 1] == p[j - 1]))
	int m = strlen(s);
	int n = strlen(p);
	bool map[m+1][n+1];
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			map[i][j] = false;
		}
	}
	map[0][0] = true;

	for (int i = 0; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (p[j-1] == '*') {
				map[i][j] = map[i][j-2];
				if (MATCH(i, j - 1)) {
					if (i == 1 && j == 5) {
						printf("***\n");
					}
					map[i][j] = map[i - 1][j];
				}

			} else {
				if (MATCH(i, j)) {
					map[i][j] = map[i - 1][j - 1];
				}
			}
		}
	}
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			printf("%d %d %d\n", i, j, map[i][j]);
		}
	}
	return map[m][n];
}
/** bool isPalindrome(int x){ */
/** int count = 1; */
/** int num = x; */
/** int i, j; */
/** int k = 1; */
/** int n = 1; */
/** while ((num /= 10) >= 1) count++; */
/** printf("%d \n", count); */
/** while (k <= count / 2) { */
/**     i = x / (int)pow(10, count - k) % 10; */
/**     n *= 10; */
/**     j = x % n / (n / 10); */
/**     printf("%d %d\n", i, j); */
/**     if (i != j) return false; */
/**     k++; */
/** } */
/** return true; */
/** } */
//0: 1
//1: 1

int computeNum(int steps) {
	int i = 0,
		j = 0,
		k = 0,
		l = 1;


	for (int n = 1; n <= steps; n++) {
		i = j;
		j= k;
		k = l;
		l = i + j + k;
	}
	return l;
}
//f(x) = f(x-1) + f(x-2) + f(x-3)
//f(3) = f(2) + f(1) + f(0);
//f(4) = f(3) + f(2) + f(1);
// 0001 -> 0011 1
// 0011->  0112 2
// 0112-> 1124 4
// 1124 -> 1247 7
void rotate(int* nums, int numsSize, int k){

}
int divide(int dividend, int divisor){
	unsigned int d1 = labs((long)dividend),
				 d2 = labs((long)divisor);

	unsigned int max = d1,
				 count = 0,
				 tempCount = 0;

	int ret;
	while (max >= d2) {
		while ((max >> (tempCount + 1)) >= d2 && (max >> (tempCount + 1)) < (max >> tempCount)) {
			printf("%d >= %d\n",(max >> (tempCount + 1)), d2);
			tempCount++;
		} 
		max -= (d2 << tempCount);
		count += (1 << tempCount);
		tempCount = 0;
	}

	if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
		ret = -count;
	} else {
		ret = count >= 0x80000000 ? 0x7fffffff : count;
	}

	return ret;
}
//0x61 0x7a
//
//
#define GEN_DIFF(CHAR) ((CHAR) >= 0x7a ? 0x61 : (CHAR) + 1)
void setDifferentChar(char *s, int index, int max) {
	if (index <= 0) {
		if (s[index + 1] == '?') {
			s[index] = 0x61;
		} else {
			s[index] = GEN_DIFF(s[index + 1]);
		}
	}
	else {
		s[index] = GEN_DIFF(s[index - 1]);
		if (index < max) {
            if (s[index] == s[index + 1])
			s[index] = GEN_DIFF(s[index]);
		}
        printf("%c \n", s[index]);
	}
}
char * modifyString(char * s){
	int len = strlen(s);
	char *cpyStr = (char*)malloc(sizeof(char) * (len + 1));
	strncpy(cpyStr, s, len);
	for (int i = 0; i < len; i++) {
        printf("%d \n", i);
        if (cpyStr[i] == '?')
		setDifferentChar(cpyStr, i, len - 1);
	}
    printf(".... ");
	return cpyStr;

}
//aaabbb
//aaaaa
//bbbbb
//
int getNumberOneNums(char *s) {
	int ret = 0;
	for (char *temp = s; *temp != '\0'; temp++) {
		if (*temp == '1') ret++;
	}
	return ret;
}
bool checkString(char * s){
    int l = strlen(s);
    int i = 0;
    int count = 0;
    char temp = s[0];
    while (++i < l) {
		printf("%d \n", i);
        if (count >= 2) {
			printf("%%%%");
			return false;
		} 
        if (s[i] != s[i - 1]) count++;
    }
    if (count == 1 && s[0] == 'b') return false;
    return true;
}
int numberOfBeams(char ** bank, int bankSize){
	int pre = 0;
	int current = 0;
	int total = 0;
	for (int i = 0; i < bankSize; i++) {
		if ((current = getNumberOneNums(bank[i])) > 0) {
			total += current * pre;
			pre = current;
		}
	}
	return total;
}
//mass = 10, asteroids = [9,8,7,6,1]
// total >= x;
// 2x >= y
// x ~ 2x
// y -  x = {....};
//
/** bool asteroidsDestroyed(int mass, int* asteroids, int asteroidsSize){ */
	/** int comp(const int *a, const int *b) { */
	/**     return *a - *b; */
	/** } */
	/** qsort(asteroids, asteroidsSize, sizeof(int), &comp); */
	/** for (int i = 0; i < asteroidsSize; i++) { */
	/**     if (mass >= asteroids[i]) mass += asteroids[i]; */
	/**     else return false; */
	/** } */
	/** return true; */
/** } */
//1111 1111
//10000100
// 10000001
// 11111111
//100000001
#define NUMBER 17 //2的17次方大于10的5次方
bool asteroidsDestroyed(int mass, int* asteroids, int asteroidsSize){
    int min[NUMBER];
    long long sum[NUMBER];
    memset(min,-1,sizeof(int)*NUMBER);
    memset(sum,0,sizeof(long long)*NUMBER);
    for(int i=0;i<asteroidsSize;++i){
        int temp=31-__builtin_clz(asteroids[i]); //asteroids[i]      0 - 16
        //printf("number:%d,judge:%d\n",asteroids[i],temp);
        if(min[temp]==-1 || min[temp]>asteroids[i]){
            min[temp]=asteroids[i];
        }
        sum[temp]+=asteroids[i];
    }
    long long res=mass;
    for(int i=0;i<NUMBER;++i){//
        //printf("res:%d,min:%d\n",res,min[i]);
        if(res<min[i]){
            return false;
        }
        res+=sum[i];
    }
    return true;
}
int maxSubArray(int* nums, int numsSize){
	int sum = nums[0],
		max = nums[0];
	for (int i = 1; i < numsSize; i++) {
		if (sum < nums[i]) {
			printf("%d **\n", nums[i]);
			sum = nums[i];
		}
		else {
			printf("%d ##\n", nums[i]);
			sum += nums[i];
		}
		max = max < sum ? sum : max;
	}
	return max;
}
// 111  000
// 101	000
// 111	000
// 01 11 21
// 10 11 12
#define SET_ZERO_LINE(a, b) {\
	printf("%d %d\n", a, b);\
	for (int i = 0; i < matrixSize; i++) {\
		matrix[i][b] = 0;\
	}\
	for (int i = 0; i < *matrixColSize; i++) {\
		matrix[a][i] = 0;\
	}\
}
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixColSize[i]; j ++) {
			if (matrix[i][j] == 0) {
				SET_ZERO_LINE(i, j);
			}
		}
	}
}
int main(void) {
	/** int array1[2] = {1,3}; */
	/** int array2[] = {2}; */
	/** printf("%f", findMedianSortedArrays(array1, 2, array2, 1)); */
	//printf("%d", isMatch("aaa", "ab*a*c*a"));
	//printf("%d", computeNum(4));
	//printf("%d ", divide(-0x80000000, -1));
	//printf("%s", modifyString("?th?is?"));
	//printf("%d, ", checkString("aaba"));
	//printf("%d", __builtin_clz(0));
	//1111 1111 1111
	return 0;
}
