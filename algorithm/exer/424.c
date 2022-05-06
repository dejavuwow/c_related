//
//123
//213  12
//231  23
//132  31
//312  12
//321  23
//
//1234
//
//
//
//
// i + k + 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
//231
//132
//312
//321
//
//1324
//1342
//2341
//2431
//
//1 * 2 * 3 * 4 * 5
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	int *p;
	int total = 1;
	int **ret = NULL;
	*returnColumnSizes = NULL;
	*returnSize = 0;
	int i = 0;
	int pre = i;
	int size = numsSize;
	int flag = size * (size - 1);

	for (int k = 2; k <= numsSize; k++) {
		total *= k;
	}

	for (int k = 0; k < total; k++) {
		swap(&nums[i % numsSize], &nums[(i + 1) % numsSize]);
		for (int j = 0; j < numsSize; j++) {
			printf("%d ", nums[j]);
		}
		putchar('\n');
		p = malloc(sizeof(int) * numsSize);
		ret = realloc(ret, (*returnSize + 1) * sizeof(int*));
		*returnColumnSizes = realloc(*returnColumnSizes, (*returnSize + 1) * sizeof(int));
		memcpy(p, nums, numsSize * sizeof(int));
		ret[*returnSize] = p;
		(*returnColumnSizes)[*returnSize] = numsSize;
		(*returnSize)++;
		if ((k + 1) % flag == 0) {
			i = pre++;
		}
		i++;
	}
	return ret;
}
//1234
/** int arr[6]; */
/** int size; */
/** void swap(int *a, int *b) { */
/**     int temp = *a; */
/**     *a = *b; */
/**     *b = temp; */
/** } */
/** void gen(int **nums, int ***ret, int **returnColumnSizes, int *returnSize, int index) { */
/**     if (index >= size) { */
/**         int *p = malloc(sizeof(int) * size); */
/**         (*ret) = realloc(*ret, (*returnSize + 1) * sizeof(int*)); */
/**         *returnColumnSizes = realloc(*returnColumnSizes, (*returnSize + 1) * sizeof(int)); */
/**         memcpy(p, nums, size * sizeof(int)); */
/**         (*ret)[*returnSize] = p; */
/**         (*returnColumnSizes)[*returnSize] = size; */
/**         (*returnSize)++; */
/**         return; */
/**     } */
/**     for (int i = k; k < numsSize; k++) { */
/**         arr[index] = nums[k]; */
/**         swap(&nums[k], &nums[i]); */
/**         gen(nums, ret, returnColumnSizes, returnSize, index + 1); */
/**         swap(&nums[k], &nums[i]); */
/**     } */
/** } */
/** int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){ */
/**     int **ret = NULL; */
/**     *returnColumnSizes = NULL; */
/**     *returnSize = 0; */
/**     size = numsSize; */
/**     gen(nums, &ret, returnColumnSizes, returnSize, 0); */
/**     return ret; */
/** } */
//112
int arr[8];
int l, size;
void gen(int list[][2], int ***ret, int **returnColumnSizes, int *returnSize, int index) {
	//     printf("%d ", arr[i]);
	// }
	// printf("\n");
	if (index >= size) {
		int *p = malloc(sizeof(int) * size);
		(*ret) = realloc(*ret, (*returnSize + 1) * sizeof(int*));
		*returnColumnSizes = realloc(*returnColumnSizes, (*returnSize + 1) * sizeof(int));
		memcpy(p, arr, size * sizeof(int));
		(*ret)[*returnSize] = p;
		(*returnColumnSizes)[*returnSize] = size;
		(*returnSize)++;
		return;
	}
	// for (int i = 0; i < l; i++) {
	//     printf("%d %d\n", list[i][0], list[i][1]);
	// }
	// printf("**\n");
	for (int i = 0; i < l; i++) {
		if (list[i][1] < 1) continue;
		arr[index] = list[i][0];
		list[i][1]--;
		gen(list, ret, returnColumnSizes, returnSize, index + 1);
		list[i][1]++;

		/** swap(&list[i], &list[k]); */
	}
}   
//
//0 1  2   4   8    16  33
//63 31 + 1   15 + 1   7 + 1   3 + 1  2 + 1
//2 4 8 16
//37 2 4 8 16                 4 + 1->9->18-> 36
double calculate(double x, int n) {
	
	if (n == 0) {
		return 1.0;
	}
	double r = calculate(x, n / 2);
	 return n % 2 == 0 ? r * r : r * r  x;
}
double cal(double x, int n) {
	double total = 1;
	int stack[32];
	int index = -1;
	while (n > 0) {
		stack[++index] = n >> 1;
		n >>= 1;
	}
	for (; index >= 0; index--) {
		 if (stack[index] == 1) {
			 total *= x;
		 }
		 total *= total;
	}
	return total;
}
double calcul(double x, long long n) {
	double total = 1.0;
	double xn = x;
	while (x > 0) {
		if (x & 1) {
			total *= xn;
		}
		xn *= xn;
		x >>= 1;
	}
	return total;
}
double myPow(double x, int n){
	return n >= 0 ? calculate(x, n) : 1 /calculate(x, -n);
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	int **ret = NULL; 
	*returnColumnSizes = NULL;
	*returnSize = 0;
	int map[21] = {0};
	int list[8][2];
	size = numsSize;
	l = 0;
	for (int i = 0; i < numsSize; i++) {
		map[nums[i] + 10]++;
	}
	for (int i = 0; i < 20; i++) {
		if (map[i]) {
			list[l][0] = i - 10;
			list[l++][1] = map[i];
		}
	}
	gen(list, &ret, returnColumnSizes, returnSize, 0);
	return ret;
}

int main(void) {
	int *returnColumnSizes;
	int length;
	permute((int []){1, 2, 3, 4}, 4, &length, &returnColumnSizes);
}
