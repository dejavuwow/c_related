#include <stdio.h>
#include <math.h>
#include <limits.h>
typedef struct{
	int max;  // 最大关键字 
	int pos;  // 起始地址 
} index;

int a[] = { 22, 12, 13, 8, 9, 20, 33, 42,
	44, 38, 24, 48, 60, 58, 74, 49, 86, 53};
int n = sizeof(a)/sizeof(a[0]);
index b[3] = {{22,1},{48,7},{86,13}};

void setBlock(index b[], int a[], int blockCnt) {
	int k = n / blockCnt;
	for (int i = 0; i < k; i++)
	{
		b[i].pos = i*blockCnt;
		int curmax = INT_MIN;
		for (int j = b[i].pos; j < b[i].pos+blockCnt; j++)
		{
			curmax = fmax(a[j], curmax);
		}
		b[i].max = curmax;
	}
}

void search(index b[], int a[], int blockCnt, int target) {
	int left = 0,
		right = 2;
	while (left <= right) {
		int mid = left + right >> 1;
		if (b[mid].max < target) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	for (int i = left * blockCnt; i < left * blockCnt + 6; i++) {
		if (a[i] == target) {
			printf("%d block: %d  order: %d\n", target, left + 1, i - blockCnt * left + 1);
			return;
		}
	}
	
	printf("%d no\n", target);
	return;
}
int main(void) {
	setBlock(b, a, 6);
	int list[] = {22, 33, 86, 8, 48, 58, 100};
	for (int *i = list; i < list + 7; i++) {
		search(b, a, 6, *i);
	}
	return 0;
}
