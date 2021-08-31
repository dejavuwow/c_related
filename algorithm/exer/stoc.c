#include <stdio.h>
int maxProfit(int* prices, int pricesSize){
	int own = 0;
	int start;
	int buy = 0;
	for (int *cursor = prices; cursor < prices + pricesSize; cursor++)
	{
		if (cursor + 2 <= prices + pricesSize && *cursor < *(cursor+1)) {
			if (!buy) {
				buy = 1;
				start  = *cursor;
			} 
		}
		else if(buy && ((cursor + 2  <= prices + pricesSize && *cursor > *(cursor+1)) || cursor + 1 == prices + pricesSize)){
			own += *cursor - start;
			buy = 0;
		}
	}
	return own;
}

void swap(int* a, int* b) {
	int t = *a;
	*a = *b, *b = t;
}

void reverse(int* nums, int start, int end) {
	while (start < end) {
		swap(&nums[start], &nums[end]);
		start += 1;
		end -= 1;
	}
}

/** void rotate(int* nums, int numsSize, int k) { */
/** k %= numsSize; */
/** reverse(nums, 0, numsSize - 1); */
/** reverse(nums, 0, k - 1); */
/** reverse(nums, k, numsSize - 1); */
/** } */

void rotate(int* nums, int numsSize, int k){
	k =  k % numsSize;
	int trys = 0;
	int start = -1;
	int temp;
	int temp2;
	int end;
	while (trys < numsSize) {
		temp = nums[++start];
		end = start;
		do {
			temp2 = nums[(end + k) % numsSize];
			end = (end + k) % numsSize;
			nums[end] = temp;
			temp = temp2;
			trys++;
			printf("%d\n", temp);
			printf("**%d**\n", trys);
		} while (end != start );
	}
}

int main(void) {
	const int p = 10;
	int prices[][2] = {
		{-1,100},
		{3,39}
	};
	/** rotate(prices, 4, 2); */
	/** for (int *i = prices; i < prices + 4; i++) */
	/** { */
	/**     printf("%d\t", *i); */
	/** } */
	printf("%d", -1[prices][1]);
	return 0;
}
