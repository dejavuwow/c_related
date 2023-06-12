int averageValue(int* nums, int numsSize){
	int sum = 0;
	int count = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] % 6 == 0) {
			sum += (nums[i] % 6 == 0 ? nums[i] : 0);
			count++;
		}
	}
	return sum / count;

}
//从末尾开始依次向前遍历
//int start = -1;
//int end = -1;
//length = 0;
// for (i:nums) {
//  int last = length == 0 ? nums[numsSie - 1] : i + length;
// 	for (int j = i, j <) {
// 		dp[j] = dp[j] + nums[i]
//		if (ap[j] >= target) {
//			length = j - i + 1;
//		}
// 	}
// 	return length;
// }
int minSubArrayLen(int target, int* nums, int numsSize){
	int length = 0;
	int dp[numsSize];
	memset(dp, 0, sizeof(dp));
	for (int i = numsSize - 1; i >= 0; i--) {
		int last = length == 0 ? numsSize - 1 : i + length - 1;

		if ((dp[numsSize -1] = dp[numsSize - 1] + nums[i]) < target) {
			continue;
		} 

		if (length == 0 || numsSize - i < length) {
			length = numsSize - i;
		}
		for (int j = numsSize - 1; j >= i; j--) {
			dp
		}
		for (int j = i; j <= last; j++) {
			dp[j] = dp[j] + nums[i];
			if (dp[j] >= target && ( length == 0 || j - i + 1 < length)) {
				length = j - i + 1;
			}
		}
	}
	return length;
}
