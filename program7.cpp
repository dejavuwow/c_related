#include <bits/stdc++.h>
using namespace std;

typedef struct{
	int max;  // 最大关键字 
	int pos;  // 起始地址 
} index;

int a[] = { 22, 12, 13, 8, 9, 20, 33, 42,
    44, 38, 24, 48, 60, 58, 74, 49, 86, 53};
int n = sizeof(a)/sizeof(a[0]);
index b[3];

// 分块
void getBlock(index b[], int a[], int blockCnt){
	int k = n / blockCnt;
	for (int i = 0; i < k; i++)
	{
		b[i].pos = i*blockCnt;
		int curmax = -0x7fffffff;
		for (int j = b[i].pos; j < b[i].pos+blockCnt; j++)
		{
			curmax = max(a[j], curmax);
		}
		b[i].max = curmax;
	}
} 
// 分块查找
void Search_Idx(index b[], int a[], int blockCnt, int x){
	int block, index, mid;
	int low = 0, high = 2;
	while (low <= high)
	{
		mid = low+(high-low)/2;
		if (x > b[mid].max)
		    low = mid + 1;
		else
		    high = mid - 1;
	}
	block = high + 1;
	if (block < 0 || block > 2)
	{
	    printf("%d：没有对应的数据块\n", x);
	    return;
	}
	int i = b[block].pos;
	while (i < b[block].pos+blockCnt-1 && a[i] != x)
	{
		i++;
	} 
	if (i <= b[block].pos+blockCnt-1)
	    index = i-b[block].pos+1;
	else
	{
	    index = -1;
		printf("%d：没有对应的数据块\n", x);
	    return;
	}
	printf("%d：数据块%d中的第%d个数据\n", x, block+1, index);
} 

// 顺序查找
int Search_Seq(int a[], int x){
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		    return i+1;
	}
	return -1;
} 

// 折半查找 
int Search_Bin(int a[], int x){
	sort(a, a+n);
	printf("排序后的数组：\n");
	for (int i = 0; i < n; i++)
	    printf("%d ", a[i]);
	printf("\n");
    int low = 0, high = n-1;
    while (low <= high)
    {
    	int mid = low+(high-low)/2;
    	//cout << a[mid] << endl;
    	if (a[mid] == x)
		    return mid+1;
		else if (a[mid] > x)
		    high = mid - 1;
    	else if (a[mid] < x)
    		low = mid + 1;
	}
	return -1;
} 

int main(){
	int x;
	// 分块查找
    printf("分块查找：\n");
    printf("待查找的数据（22，33，86，8，48，58，100）\n");
    int num[] = {22, 33, 86, 8, 48, 58, 100};
	getBlock(b, a, 6);
	for (int i = 0; i < sizeof(num)/sizeof(num[0]); i++)
	    Search_Idx(b, a, 6, num[i]);
	// 顺序查找
    printf("\n顺序查找：请输入要查找的数：\n");
	cin >> x; 
    printf("%d\n", Search_Seq(a, x));
    // 折半查找  
    printf("\n折半查找：请输入要查找的数：\n"); 
	cin >> x; 
    printf("%d\n", Search_Bin(a, x));
	return 0;
} 
