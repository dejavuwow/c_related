#include <stdio.h>

int getLongestSubSequenceSum(int array[], int start, int end)
{
	if (start == end) return array[start];
	int mid = (start + end) / 2;
	int sum1 = getLongestSubSequenceSum(array, start, mid);
	int sum2 = getLongestSubSequenceSum(array, mid + 1, end);
	if (array[mid] <=)
	return array[mid] <= array[mid + 1] ? sum1 + sum2 : sum1 >= sum2 ? sum1 : sum2;

}

int main(void)
{
	int array[]  = {3, 1, 4, 9, 34, 12, 156};
	printf("%d", getLongestSubSequenceSum(array, 0, 6));
	return 0;

}

