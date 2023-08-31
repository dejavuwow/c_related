int* lexicalOrder(int n, int* returnSize){
	int ret = malloc(sizeof(int) * n);	
	int max = n;
	int pre = 1;
	int idx = 0;
	ret[idx++] = pre;
	while (--n) {
		if (pre * 10 <= max) {
			current = pre * 10;
		}
		else {
			if (pre + 1 <= max) {
				pre = pre + 1;
			}
			else {
				pre = pre / 10 + 1;
			}
			while (pre % 10 == 0) {
				pre /= 10;
			}
		}	
		ret[idx++] = pre;
	}
	*returnSize = n;
	return ret;
}

int minDeletionSize(char ** strs, int strsSize){
	int l = strlen(strs[0]);
	int n = 0;
	for (int i = 0; i < l; i++) {
		int isAsc = 1;
		for (int k = 1; k < strsSize; k++) {
			if (strs[k][i] < strs[k - 1][i]) {
				isAsc = 0;
				break;
			} 
		}
		if (!isAsc) {
			n++;
		}
	}
	return n;
}

bool lemonadeChange(int* bills, int billsSize){
	int map[21];
	memset(map, 0, sizeof(map));
	for (int i = 0; i < billsSize; i++) {
		if (bills[i] == 5) {
			map[5]++;
		}
		else if (bills[i] == 10) {
			if (map[5] < 1) return false;
			map[10]++;
			map[5]--;
		}
		else {
			if (map[5] < 1) return false;
			if (map[10] > 1) {
				map[10]--;
				map[5]--;
			}
			else {
				if (map[5] < 3) {
					return false;
				}
				map[5] -= 3;
			}
		} 
	}
	return true;
}
//dp[i] = 2 * dp[i - 1] + cur
//1, 12
//2
//
//13,123, 23, 3
//1,2,3,4,5
//
//1
//12
//123
//1234
//12345
//1235
//1245
//12
//max[x][y]：(x <= y)
//max[0][y] > max[0][x] ? max[0][y] : max[7,8, 79] 
//max[x][y - 1], max[y, y]
//a1 * a1
//
//a1, a2, a3, a4
// a3
// max^2 * min
// sum1 设为最小值之和,  cur 为当前数
//
//cur^2(min1 + ... + m cur)
//
// max^2(min1 + ... + minn)
int sum = 0;
void run(int *res, int l1, int *nums, int start, int l2, int max, int min) {
	for (int i = start; i < l2; i++) {
		res[l1] = nums[i];
		max = fmax(max, nums[i]);
		min = fmin(min, nums[i]);
		sum += (max * max * min);
		run (res, l1 + 1, nums, i, l2, max, min);
	}
}

int sumOfPower(int* nums, int numsSize){
	int res[numsSize];
	sum = 0;
	run(res, 0, nums, 0, numsSize, INT_MAX, INT_MIN);
}
int cmp(int *a, int *b) {
	return *a - *b;
}
int sumOfPower(int* nums, int numsSize){
	qsort(nums, numsSize, sizeof(int), cmp);
	long long res = nums[0] * nums[0] * nums[0];
	int sumMin = nums[0];
	for (int i = 1; i < numsSize; i++) {
		sumMin = (sumMin - nums[i - 1]) * 2 + nums[i - 1] + nums[i];
		res += nums[i] * nums[i] * sumMin;
		printf("%d %ld\n", sumMin, res);
	}
	return res % (long long)(1e9 + 7);
}
int cmp(int *a, int *b) {
	return *a - *b;
}
int sumOfPower(int* nums, int numsSize){
	qsort(nums, numsSize, sizeof(int), cmp);
	long long mod = 1e9 + 7;
	long long res = 0;
	long long dp = 0;
	long long preSum = 0;
	for (int i = 0; i < numsSize; i++) {
		dp = (preSum + nums[i]) % mod;
		preSum = (preSum + dp) % mod;
		res += nums[i] * nums[i] % mode * dp % mod;
	}
	return res % mod;
}

int maxDistToClosest(int* seats, int seatsSize){
	int last = -1;
	int max = 0;
	for (int i = 0 ; i < seatsSize; i++) {
		if (nums[i] == 1) {
			if (last == -1) {
				max = i - 0;
			}
			else {
				max = fmax((i - last + 1) / 2, max);
			}
			last = i;
		}
	}
	return fmax(max, seatsSize - 1 - last);
}
bool canChange(char * start, char * target){
	int ownR = 0;
	int oweL = 0;
	int l = strlen(start);
	for (int i = 0; i < l; i++) {

		if (start[i] == '_') {
			if (target[i] == 'R') return false;
			if (target[i] == 'L' && ownR == 0) {
				oweL++;
			}
		}
		else if (start[i] == 'L') {
			if (target[i] == 'L' && ownR > 0) return false;
			if (target[i] == 'R') return false;
			if (target[i] == '_' && oweL > 0) {
				oweL--;
			}
		}
		else {
			if (target[i] == 'R' && oweL > 0) return false;
			if (target[i] == 'L') return false;
			if (target[i] == '_' && oweL == 0) {
				ownR++;
			}
		}

		if (start[i] == target[i]) {
			if ((start[i] == 'L' && ownR != 0) || (start[i] == 'R' && oweL != 0)) {
				return false;
			}
			continue;
		} 
		else {
			if (start[i] == '_') {
				if (target[i] == 'L') {
					if (ownR > 0) return false;
					oweL++;
				}
				else {
					if (ownR > 0) {
						ownR--;
					} else {
						return false;
					}
				}
			} else if (start[i] == 'R') {
				if (target[i] == '_') {
					if (oweL > 0) return false;
					ownR++;
				}
				else {
					return false;
				}
			}
			else { // start[i] == 'L'
				if (target[i] == '_') {
					if (oweL > 0) {
						oweL--;
					}
					else {
						return false;
					}
				}
				else {
					return false;
				}
			}
		}
	}
	return ownR == 0 && oweL == 0;
}
//+-----+---+---+
//| jir |	|	|
//+-----+---+---+
struct ListNode* insertionSortList(struct ListNode* head){
	for (struct ListNode *cur = head->next, *pre1 = head; cur != NULL;) {
		int flag = 0;
		for (struct ListNode *temp = head, *pre2 = NULL; temp != cur; temp = temp->next, pre2 = temp) {
			if (cur->val > temp->val) {
				struct ListNode *t1 = cur->next;
				pre1->next = t1;
				cur->next = temp;
				if (pre2) {
					pre2->next = cur;
				}
				else {
					head = cur;
				}
				pre1 = cur;
				cur = t1;
				flag = 1; 
				break;
			} 
		}
		if (!flag) {
			pre1 = cur;
			cur = cur->next;
		}
	}
	return head;
}
//31427698
//
//13 24 67 89
//
//31 42 7698
//13 24 76 98
//分割 1，2.。。。length的子数组
//两两合并
//1->3->5
//2->4->6->8->9
struct ListNode *merge(struct ListNode *h1, struct ListNode *h2) {
	struct ListNode *dummy, *pre;
	dummy = malloc(sizeof(struct ListNode));
	dummy->next = h1;
	pre = dummy;
	struct ListNode *cur1 = h1, *cur2 = h2;
	for (; cur1 != NULL && cur2 != NULL;) {
		if (cur1->val > cur2->val) {
			pre->next = cur2;
			pre = cur2;
			cur2 = cur2->next;
		} else {
			pre->next = cur1;
			pre = cur1;
			cur1 = cur1->next;
		}
	}
	if (cur1 != NULL) {
		pre->next = cur1;
	} else if (cur2 != NULL) {
		pre->next = cur2;
	}
	return dummy->next;
}
struct ListNode* sortList(struct ListNode* head){

	int length = 0;
	for (struct ListNode *cur = head; cur != NULL; cur = cur->next) {
		length++;
	}
	struct ListNode *dummy, *pre;
	dummy = malloc(sizeof(struct ListNode));
	dummy->next = head;
	for (int i = 1; i < length; i <<= 1) {
		struct ListNode *cur = dummy->next;
		pre = dummy;
		while (cur != NULL) {
			struct ListNode *h1 = cur;
			struct ListNode *cur1 = cur;
			struct ListNode *h2 = NULL;
			struct ListNode *cur2 = NULL;
			cur = NULL;
			for (int curLen = 1; curLen < i && cur1 != NULL; cur1 = cur1->next, curLen++);
			if (cur1 != NULL) {
				h2 = cur2 = cur1->next;
				cur1->next = NULL;
			}
			for (int curLen = 1; curLen < i && cur2 != NULL; cur2 = cur2->next, curLen++);
			if (cur2 != NULL) {
				cur = cur2->next;
				cur2->next =NULL;
			}

			pre->next = merge(h1, h2);
			for (; pre->next != NULL; pre = pre->next);
		}
	}
	return dummy->next;
}
//x=k1*d，y=k2*d
//
//-3 / -2e4   -2e4 / 3 (2e4 + 1)
//21 18
//  27   12
//  27   12 % 27
struct my_struct {
	int counts;
	int val;
	UT_hash_handle hh;
}
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
//gcd(12, 27)
//
//gcd(27, 12)-> gcd(12, 3)
//
int maxPoints(int** points, int pointsSize, int* pointsColSize){
	struct my_struct *repo = NULL, *s *tmp;
	int max = INT_MIN;
	for (int i = 0; i < pointsSize - 1; i++) {
		if (max >= pointsSize - i) continue;
		for (int j = i + 1; j < pointsSize; j++) {
			int dx = points[i][0] - points[j][0];
			int dy = points[i][1] - points[j][1];
			if (dx < 0) {
				dx = -dx;
				dy = -dy;
			} else if (dx == 0) {
				dy = 1;
			} else if (dy == 0) {
				dx = 1;
			}
			int g = gcd(abs(dx), abs(dy));
			dx = dx / g;
			dy = dy / g;
			int val = dx + 24001 * dy;
			HASH_FIND_INT(repo, &val, s);
			if (s != NULL) {
				s->counts++;
			} else {
				s = malloc(sizeof(struct my_struct));
				s->counts = 2;
				s->val = val;
				hash_add_int(repo, val, s);
			}
		}
		HASH_ITER(hh, repo, s, tmp) {
			max = fmax(s->counts, max);
			HASH_DEL(repo, s);  
			free(s);             
		}
	}
}
// 9, 99 / 2
//[[1,1],[2,10],[3,100],[4,1000],[1,0],[2,0],[3,0],[4,0],[1,-1],[2,-10],[3,-100],[4,-1000]]
//|-------
//|-------
//
//val = my + mx
// ^ *
// |         * *
// |      *	   	    *
// |   *       *
// | *
// +------------------------>
// \
// 
