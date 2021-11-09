#include <stdio.h>
typedef struct people {
	char name;
	int age;
	char is;
} People;

int abc(int x)
{
	int y = x >> 31;
	printf("&&%d\n", y);
	printf("^^%d\n",(x + y) ^ y);
	return  (x ^ y) - y;
}
int getMaxLength()
{
	
}
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
int maxProfit(int* prices, int pricesSize){
	int max = 0;
	int min = prices[0];
	for (int i = 1; i < pricesSize; i++) {
		min = MIN(prices[i], min);
		max = max(prices[i] - min, max);
	}
	return max;

}
int maxSubArray(int* nums, int numsSize){
	int sum = nums[0];
	int max = sum;
	for (int i = 1; i < numsSize; i++) {
		if (nums[i] + sum <= nums[i]) {
			sum = nums[i];
		} 
		else {
			sum += nums[i];
		}
		max = MAX(sum, max);
	}
	return max;
}
//00 00 00
//
int (*dp)[2];
int getMaxProfit(int *nums, int i, bool steal) {
	if (dp[i][steal ? 1 : 0] != -1) return dp[i][steal ? 1 : 0];
	if (i == 0) {
		return steal ? nums[i] : 0;
	} 
	if ()
	int lastNoStolen = dp[i - 1][0] = getMaxProfit(nums, i - 1, false);
	int lastStolen = dp[i - 1][1] = getMaxProfit(nums, i - 1, true);
	return steal ? lastNoStolen + nums[i]: MAX(lastNoStolen, lastStolen);
}
int rob(int* nums, int numsSize){
	dp = ((int*)[2])malloc(sizeof(int) * 2 * numsSize);
	for (int i = 0; i < numsSize; i++) {
		dp[i][0] = dp[i][1] = -1;
	}
	int stolen = getMaxProfit(nums, numsSize - 1, true);
	int noStolen = getMaxProfit(nums, numsSize - 1, false);
	return MAX(stolen, noStolen);
}
typedef struct {
	int *nums;
	int *copy;
	int numsSize;

} Solution;


Solution* solutionCreate(int* nums, int numsSize) {
	Solution *ret = (Solution*)malloc(sizeof(Solution));
	ret->nums = (int*)malloc(sizeof(int) * numsSize);
	ret->copy = nums;
	memcpy(obj->nums, obj->copy, numsSize * sizeof(int));
	ret->numsSize numsSize
	return ret;
}

int* solutionReset(Solution* obj, int* retSize) {
	memcpy(obj->nums, obj->copy, obj->numsSize * sizeof(int));
	*retSize = obj->numsSize;
	return obj->nums;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int random(int start, int end) {
	return (rand() % end + start) % end;
}
int* solutionShuffle(Solution* obj, int* retSize) {
	for (int i = 0; i < obj->numsSize; i++) {
		swap(&obj->nums[i], &obj->nums[random(i, obj->numsSize - 1)]);
	}
	*retSize = obj->numsSize;
	return obj->nums;
}

void solutionFree(Solution* obj) {
	obj->nums = obj->copy =  NULL;
	free(obj->nums);
	free(obj);
}
int main(void)
{
	int b = 25;
	char age = 0x61;
	char age2 = 13;
	int test[] = {1,2,3,4};
	int *current = test;
	/* printf("%d", ((People*)(&age))->age); */
	/* printf("\n %p, %p ,%p", &b, &age, &age2); */
	/* printf("\n %p, %p, %p", &((People*)(&age))->name, &((People*)(&age))->age, &((People*)(&age))->is); */
	/* printf("\n%d", sizeof(NULL)); */
	/* printf("%#p", *current); */
	/* printf("\n%#p", *++current); */
	printf("**%d", abc(-230));
	return 0;
}
// 115  1
//  57  1
//  28  0
//  14  0
//  7  1
//  3	1
//  1  1
I//1111 1111
//1111 1111
