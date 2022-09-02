//{
// 1->
//}/** [ */
/** 1->4->5, */
/** 1->3->4, */
/** 2->6 */
/** ] */
void insertSort(int array[], int start, int end) {
	for (int i = start + 1; i <= end;) {
		int j = i;
		while (j > start) {
			if (array[j] < array[j - 1]) {
				temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
				j--;
			}
			else break;
		}
	}
}
void nextPermutation(int* nums, int numsSize){

}
// a = 2n   	m <= n / 2
// a = 2n + 1	m <= n / 2
//  {
//   n = 2 * x  + 1      x <=  n / 2   n 
//   n = 2 * x   x < n / 2
//  }
//  0 0
//  1 5
//  2 4
//  3 3
//  ...
//  6 0
//   x % 6
//
//  0 ~ n;
//  ((n + 1) % (n + 1) -  x % (n + 1)) % (n + 1) 
//  (n + 1 - x % (n + 1)) % (n + 1) ~  (n + 1 - x % (n + 1) + n) % (n + 1)
//										(n - x % (n + 1)) % (n + 1)
//
//	 (n - x) % (n + 1)
//	n ~ 0   
//	n ~ n - (x - 1) % (n + 1), n - x % (n + 1) ~ 0
//	n - (x - 1) % (n + 1) ~ n, 0 ~ n - x % (n + 1)
//		0							6 n
//012345  543210
//210543
//345012
//450123
//345012
int cmpfunc (const void * a, const void * b)
{
	if (!*a) return - 1;
	if (!*b) return 1;
	return (*(struct ListNode**)a)->val- (*(struct ListNode**)b)->val;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
	int size = listsSize;
	struct ListNode *array[listsSize], **current, *head;
	int head = 0;
	for (int i = 0; i < listsSize; i++) {
		array[i] = lists[i];
	}
	qsort(array, listsSize, sizeof(struct ListNode*), cmpfunc);
	head = array[head];
	array[head] = array[head]->next;
	if (array[head] == NULL) head++;
	current = &(head->next);

	while (head < size) {
		insertSort(array, size, head);
		*current = array[head];
		array[head] = array[head]->next;
		if (array[head] == NULL) head++;
		current = &(*current)->next;
	}
	return head;
}
//起始位置开始遍历,一直遍历到完整的括号对，并记录末尾索引，和括号对的长度
//下一个索引处开始，继续查找括号对，如果非括号对则另起下一个索引继续判断，如果是则重复上面一步，并且通过
//对比当前括号对的起始索引和上一个括号对的末尾索引是否相邻，如相邻的话，则将括号对的长度更新，并将末尾索引更新
//直到字符串末尾
//(()())
//(((())
int validateStr(char *s, int start) {
	int flag = 1;
	int rightFlag = 0;
	while (flag > 0 && s[++start] != '\0') {
		if (s[start] == '(' && !rightFlag) {
			flag++;
		} else flag--;
	}
	return flag > 0 ? -1 : (flag < 0 ? start - 1 : start);
}
int longestValidParentheses(char * s){
	int max = 0,
		l = strlen(s);

	int total;
	int x;
	int preEnd = -1;

	for (int p = 0; i < l;) {
		if (s[p] == '('  && (x = validateStr(s, p)) != -1) {
			if (p == preEnd + 1) {
				total += x - p + 1;
			}
			else {
				total = x - p + 1;
			}
			preEnd = x;
			max = total > max ? total : max;
			p = x + 1;
		}
		else p++;
	}
	return max;
}
//(()())
//(((())
//dp[n] = {
//	 2,
//	 dp[n + 1]
//}
//
int validateStr(char *s, int start) {
	int flag = 1;
	int rightFlag = 0;
	while (flag > 0 && s[++start] != '\0') {
		if (s[start] == '(' && !rightFlag) {
			flag++;
		} else flag--;
	}
	return flag > 0 ? -1 : (flag < 0 ? start - 1 : start);
}
int longestValidParentheses(char * s){
	int max = 0,
		l = strlen(s);

	int *dp = calloc(sizeof(int) * l);

	int total;
	int x;
	int preEnd = -1;

	for (int p = 0; i < l;) {
		if (s[p] == '('  && (x = validateStr(s, p)) != -1) {
			if (p == preEnd + 1) {
				total += x - p + 1;
			}
			else {
				total = x - p + 1;
			}
			preEnd = x;
			max = total > max ? total : max;
			p = x + 1;
		}
		else p++;
	}
	return max;
}
//
//
//	
//  *
//  *
//	*
//  *
//4567123
//[1,3,6,6,6,7,8]
int search(int* nums, int numsSize, int target){
	for (int left = 0, right = numsSize - 1, mid; left > right;) {
		mid = (left + right) / 2;
		if (nums[mid] == target) return mid;
		else {
			if (nums[left] < nums[mid]) {
				if (nums[mid] > target && nums[left] <= target) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
			else {
				if (nums[mid] < target && nums[right] >= target) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
		} 	
	}
	return -1;
}
/** [5,5,5,6,7,7,8,8,8,8,10,12,13] */
/** 11 */
//case 1: 正常在数组范围内  num ^ [min, max] = num
//case 2: 不在数组中， num > max
//case 3: 不在数组中， num < min
//case 4: 不在数组中， min < num < max && num ^ [min, max] = 0
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
	int *ret = malloc(sizeof(int)),
		start = numsSize, end = numsSize;

	ret[0] = -1;
	ret[1] = -1;
	*returnSize = 2;
	int i = 0, j = numsSize - 1, mid;
	
	for (; i <= j;) {
		mid = (i + j) / 2;
		if (nums[mid] > target) {
			j = mid - 1;
			end = mid;
		}
		else {
			i = mid + 1;
		}
	}

	for (; i <= j ;) {
		mid = (i + j) / 2;
		if (nums[mid] >= target) {
			j = mid - 1;
			start = mid;
		}
		else {
			i = mid + 1;
		}
	}
	if (end != start) {
		ret[0] = start;
		ret[1] = end - 1;
	}
	return ret;
}
//[1,2,5,7]
int searchInsert(int* nums, int numsSize, int target){
	int left, right, mid;
	for (left = 0, right = numsSize - 1; left <= right;) {
		mid = (left + right) / 2;
		if (nums[mid] == target) return mid;
		if (nums[mid] > target) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return left == numsSize ? numsSize : right == -1 ? 0 : left;
}

