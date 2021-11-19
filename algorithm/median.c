#include <stdio.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))
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
	int k1, km1, k1, km2;
	while(l <= r) {
		i1 = (r + l) / 2; 
		i2 = (nums1Size  + nums2Size + 1) / 2 - i1;
		km1 = (i1 == 0 ? INT_MIN : nums1[i1 - 1]);
		km2 = (i2 == 0 ? INT_MIN : nums2[i2 - 1]);
		k1 = (i1 == nums1Size ? INT_MAX : nums1[i1]);
		k2 = (i2 == nums2Size ? INT_MAX : nums2[i2]);

		if (km1 <= k2) {
			median1 = MAX(km1,);

		}


	}
}
int main(void) {
	int array1[2] = {1,3};
	int array2[] = {2};
	printf("%f", findMedianSortedArrays(array1, 2, array2, 1));
	return 0;
}
