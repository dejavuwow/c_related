#include <stdio.h>
#define printArray(array, size) \
{\
	for (int i = 0; i < size; i++) {\
		printf("%d ", array[i]);\
		}\
}
void reverse(int *nums, int size) {
	int i = 0;
	int temp;
	while (i < size / 2) {
		temp = nums[i];
		nums[i] = nums[size - i - 1];
		nums[size - i - 1] = temp;
		i++;
	}
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	
	reverse(nums1, nums1Size);
	reverse(nums1, n);
	reverse(nums1 + n, m);
	/** printArray(nums1, nums1Size); */
	int temp;
	int i = 0;
	int p1 = n,
		p2 = 0;

	/** printArray(nums1, nums1Size); */
	while (p2 < nums2Size && p1 < nums1Size) {
		if (nums1[p1] > nums2[p2]) {
			nums1[i++] = nums2[p2];
			p2++;
		}
		else {
			nums1[i++] = nums1[p1];
			p1++;
		}
	}
	//printArray(nums1, nums1Size);
	while (p2 < nums2Size) {
		nums1[i++] = nums2[p2++];
	}
}
_Bool isBadVersion(int n) {
	return n == 1702766719;
}
int climbStairs(int n){
	int first = 1;
		second = 2;
	int temp;
	if (n <= 2) return n;
	for (int i = 3; i < n; i++) {
		temp = second;
		second = first + second;
		first = temp;
	}
	return second;
}
int firstBadVersion(int n) {
	int low = 1,
		high = n;
	int mid;
	int findBad = 1;

	while (low <= high) {
		mid = (long)(low + high) / 2;
		printf("%d \n", mid);
		if (isBadVersion(mid)) {
			if (!isBadVersion(mid - 1)) {
				findBad = mid;
				break;
			}
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return findBad;
}
void main(void) {
	/** TreeNode *root; */
	/** TreeNode *new = root = newTreeNode(50); */
	/** new->left = newTreeNode(43); */
	/** new->right = newTreeNode(43); */
	/** new = root->left; */
	/** new->left = newTreeNode(32); */
	/** new->right = newTreeNode(2); */
	/** new = root->right; */
	/** new->left = newTreeNode(21); */
	/** new->right = newTreeNode(32); */
    /**  */
	/** printf("%d ", isSymmetric(root)); */
	//traversePreorder(root);
	//traversePostorder(root);
	/** int ar1[] = {1,2,3,0,0,0}, */
	/**     ar2[] = {2, 5, 6}; */
    /**  */
	/** merge(ar1, 6, 3, ar2, 3, 3); */
	/** printArray(ar1, 6); */
	//int a = (int)((long long)2126753390 + 1702766719);
	firstBadVersion(2126753390);
	
}


