typedef struct Node {
	char key[5];
	char value[5];
	Node *next;
} Node;

typedef struct HashTable {
	Node **list;
	int length;
} HashTable;

int hashLize(HashTable *table, char *key) {
	int res = 0;
	while(key) {
		res = res << 5 + *key++;
	}
	return res % table->length;
}
HashTable *initHashTable(void) {
	int size = 34;
	HashTable *table = malloc(sizeof(HashTable));
	table->length = size;
	table->list = malloc(sizeof(Node*) * 34);
	while (size--) {
		table->list[size] = NULL;
	}
	return table;
}
void insert(HashTable *table, char *key, char *value) {
	int index = hashLize(table, key);
	Node *cur =  = malloc(sizeof(Node));
	strcpy(cur->key, key);
	strcpy(cur->value, value);
	Node *temp = table->list[index];
	cur->next = temp;
	table-list[index] = cur;
}
char *find(HashTable *table, char *key) {
	int index = hashLize(table, key);
	Node *cur = table->list[index];
	while (cur != NULL) {
		if (strcmp(key, cur->key) == 0) {
			return cur->val;
		}
	}
	return NULL;
}
int *getLen(char *start) {
	int i = 0;
	while (*start != ' ' && *start != '\0') {
		start++;
		i++;
	}
	return i;
}
char * reformatDate(char * date){
	char *ret = malloc(sizeof(char) * 11);
	int day = getLen(date);
	int month = getLen(date + day + 1);
	int year = getLen(date + day +  month + 2);
	char *daySet[] = {"1st", "2nd", "3rd", "4th", "5th", "6th", "7th", "8th", "9th", "10th",
		"11th", "12th", "13th", "14th", "15th", "16th", "17th", "18th", "19th", "20th",
		"21st", "22nd", "23rd", "24th", "25th", "26th", "27th", "28th", "29th", "30th", "31st"};

	char *monthSet[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	HashTable *dayTable = initHashTable();
	HashTable *mothTable = initHashTable();

	for (int i = 0; i < 31; i++) {
		char n[3];
		n[0] = (i + 1) < 9 ? '0' : (i / 10) + '0';
		n[1] = i % 10 + '0';
		n[2] = '\0';
		insert(dayTable, daySet[i], n);
	}
	for (int i = 0; i < 12; i++) {
		char n[3];
		n[0] = (i + 1) < 9 ? '0' : (i / 10) + '0';
		n[1] = i % 10 + '0';
		n[2] = '\0';
		insert(monthTable, monthSet[i], n);
	}

	strcpy(ret, date + day + month + 2);
	ret[4] = '-';
	date[day + 1 + month] = '\0'
		strcpy(ret + 4, find(monthTable, date[day + 1]));
	date[day + 1 + month] = ' ';
	ret[7] = '-';
	date[day] = '\0'
		strcpy(ret, find(dayTable, date));
	date[day] = ' ';

	return ret;
}

//xyz
//abc
//f(0, x):
//1: f(0, x - 1) == 1 && a[x] >= b[x] 
//-1: f(0, x - 1) == -1 && a[x] <= b[x]
//for (i in x) {
//	f(0, i) && f(i + 1, x)
//}
int cmp(int *a, int *b) {
	return *a - *b;
}
bool checkIfCanBreak(char * s1, char * s2){
	int l = strlen(s1);
	qsort(s1, l, sizeof(char), cmp);
	qsort(s2, l, sizeof(char), cmp);

	int direction = s1[0] >= s2[0];
	for (int i = 1; i < l; i++) {
		if (direction != (s1[i] >= s2[i])) return false;
	}
	return true;
}

bool checkIfCanBreak(char * s1, char * s2){
	bool d1 = true,
		 d2 = true;
	int c1[26], c2[26];
	int l = strlen(s1);
	int pre = 0;
	memset(c1, 0, sizeof(int));
	memset(c2, 0, sizeof(int));

	for (int i = 0; i < l; i++) {
		c1[s1[i] - 'a']++;
		c2[s2[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		if (c1[i] + pre < c2[i] ) {
			d1 = false;
		}
		if (c2[i] - pre < c1[i]) {
			d2 = false;
		}
		pre += c1[i] - c2[i];
	}
	return d1 || d2;

}

int countOrders(int n){
	int res = 1;
	for (int i = 2; i < n; i++) {
		int t = (n - 1) * 2 + 1;
		res = res * ((t + 1) * t / 2);
	}
	return res
}
//f(1) = 1              1
//f(3) = 4             4 * 1
//f(5) = 8			   4 * 2
//f(7) = 12            4 * 3
//f(9) = 16
//f(m) =  m / 2 * 4
//f(n / 2 + 1) = f((n - 1)/ 2 + 1)
//		 ^
//	 	^&^
//	   ^&*&^
//	  ^&*$*&^
//	   ^&*&^
//   	^&^
//   	 ^
//[
//[0,1,0,0],
//[1,0,1,1],
//[1,0,0,1],
//[0,0,1,0]
//]
//[
//[0,0,0,0,0,0,0,0,0,0],
//[0,1,1,1,1,1,1,1,1,0],
//[0,1,0,0,0,0,0,0,0,0],
//[0,1,0,1,1,1,1,1,1,1],
//[0,1,0,0,0,0,0,0,0,0],
//[0,1,1,1,1,1,1,1,1,0],
//[0,1,0,0,0,0,0,0,0,0],
//[0,1,0,1,1,1,1,1,1,1],
//[0,1,0,1,1,1,1,0,0,0],
//[0,1,0,0,0,0,0,0,1,0],
//[0,1,1,1,1,1,1,0,1,0],
//[0,0,0,0,0,0,0,0,1,0]]
#define EN_QUEUE(queue, x, y, r, step) {\
	queue[++end % QUEUE_SIZE][0] = x;\
	queue[end % QUEUE_SIZE][1] = y;\
	queue[end % QUEUE_SIZE][2] = r;\
	queue[end % QUEUE_SIZE][3] = step;\
}
#define DE_QUEUE(queue) (queue[head++ % QUEUE_SIZE])
#define IS_EMPTY (head > end)
int directions[][2] = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0}
};
int shortestPath(int** grid, int gridSize, int* gridColSize, int k){
	int m = gridSize,
		n = gridColSize[0];
	int QUEUE_SIZE =  fmax(m, n) * 2;
	int visited[m][n];
	int queue[QUEUE_SIZE][4];
	int head = 0,
		end = -1;
	if (m == 1 && n == 1) {
		if (grid[0][0] == 0 || (grid[0][0] == 1 && k > 0)) return 0;
		return -1;
	}
	EN_QUEUE(queue, 0, 0, k, 0);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = k;
		}
	}

	while (!IS_EMPTY) {
		int *item = DE_QUEUE(queue);
		int x = item[0],
		y = item[1],
		r = item[2],
		step = item[3];
		for (int i = 0; i < 4; i++) {
			int cr = r;
			int cx = x + directions[i][0],
			cy = y + directions[i][1];
			if (cx >= 0 && cx < m && cy >= 0 && cy < n) {
				if (grid[cx][cy] == 1) {
					if (cr > 0) cr--;
					else continue;

				} 
				if (visited[cx][cy] < cr) continue;
				if (cx == m - 1 && cy == n - 1) return step + 1;
				visited[cx][cy] = cr;
				EN_QUEUE(queue, cx, cy, cr, step + 1);
			}
		}
	}
	return -1;
}
//12345
//12325
//12345
int m, n;
int max = 0;
int directions[][2] = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0}
};
void dfs(int **grid, int x, int y, int sum) {
	for (int i = 0; i < 4; i++) {
		int cx = x + directions[i][0],
		cy = y + directions[i][1];
		if (cx >= 0 && cx < m && cy >= 0 && cy < n && grid[cx][cy] > 0) {
			int temp = grid[cx][cy]
			grid[cx][cy] = 0;
			max = fmax(max, sum + grid[cx][cy]);
			dfs(grid, cx, cy, sum + grid[cx][cy]);
			grid[cx][cy] = temp;
		}
	}
}
int getMaximumGold(int** grid, int gridSize, int* gridColSize){
	max = 0;
	m = gridSize;
	n = gridColSize[0];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] > 0) {
				max = fmax(max, grid[i][j]);
				int temp = grid[i][j];
				grid[i][j] = 0;
				dfs(grid, i, j, grid[i][j]);
				grid[i][j] = temp;
			}
		}
	}
	return max;
}
typedef struct {

} SnapshotArray;


SnapshotArray* snapshotArrayCreate(int length) {

}

void snapshotArraySet(SnapshotArray* obj, int index, int val) {

}

int snapshotArraySnap(SnapshotArray* obj) {

}

int snapshotArrayGet(SnapshotArray* obj, int index, int snap_id) {

}

void snapshotArrayFree(SnapshotArray* obj) {

}

int cmp(int *a, int *b) {
	return *b - *a;
}
int search(int *task, int l, int r, int target) {
	int left = l,
		right = r;

	while (left <= right) {
		int mid = left + right >> 1;
		if (task[mid] > target) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return left;
}
int maxTaskAssign(int* tasks, int tasksSize, int* workers, int workersSize, int pills, int strength){
	int m = tasksSize,
		n = workersSize;
	int map[m];
	int size = n / 2 <= 0 ? 1 : n / 2;
	int repeat[size];
	int rpIndex = 0;
	memset(map, 0, sizeof(map));
	qsort(tasks, m, sizeof(int), cmp);
	qsort(workers, n, sizeof(int), cmp);
	int i, j;
	int find = 0;
	for (i = 0, j = 0; i < n && j < m; i++) {
		int up = search(tasks, j, m - 1, workers[i]);
		if (up >= m) {
			break;

		} else {
			if (largest == -1) {
				largest = up;
			}
			map[up] = i + 1;
			j = up + 1;
			find++;
		}
	}
	if (find == m) return m;
	int remainMax = fmin(m - find, fmin(n - i, pills));
	int p, k;
	int secondFind = 0;
	for (k = 0, p = 0; k < remainMax; k++) {
		int up = search(tasks, p, m - 1, workers[i + k] + strength);
		if (up >= m) {
			break;
		} else {
			p = up + 1;
			secondFind++;
		}
	}
	int findMin = fmax(secondFind, find);
	int findMax = secondFind + find;
	int taskEnd = fmax(j, p);
	     

	  
	return find - (rpIndex - i);
}
