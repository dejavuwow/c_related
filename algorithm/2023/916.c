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

//链表实现 (时间复杂度不行)
typedef struct LinkItem {
	int value;
	int snapId;
	struct LinkItem *next;
} LinkItem;
typedef struct Item {
	LinkItem *head;
	LinkItem *end;
} Item;

typedef struct {
	Item **snap;
	int curId;
	int length;
} SnapshotArray;


SnapshotArray* snapshotArrayCreate(int length) {
	SnapshotArray *ret = malloc(sizeof(SnapshotArray));
	ret->snap = malloc(sizeof(Item*) * length);
	ret->length = length;
	ret->curId = -1;
	for (int i = 0; i < length; i++) {
		ret->snap[i] = malloc(sizeof(Item));
		LinkItem *cur = malloc(sizeof(LinkItem));
		cur->value = 0;
		cur->snapId = -1;
		cur->next = NULL;
		(ret->snap[i])->head = (ret->snap[i])->end = cur;
	}
	return ret;
}

void snapshotArraySet(SnapshotArray* obj, int index, int val) {
	Item *item = obj->snap[index];
	if (item->end && item->end->snapId == -1) {
		item->end->value = val;
	}
	else {
		LinkItem *cur = malloc(sizeof(LinkItem));
		cur->value = val;
		cur->snapId = -1;
		cur->next = NULL;
		if (!item->end) {
			item->head = item->end = cur; 
		} else {
			if (val != item->end->value) {
				item->end->next = cur;
				item->end = cur;
			}
		}
	}
}

int snapshotArraySnap(SnapshotArray* obj) {
	for (int i = 0; i < obj->length; i++) {
		if (obj->snap[i]->end) {
			obj->snap[i]->end->snapId = obj->curId + 1;
		}
	}
	return ++obj->curId;
}

int snapshotArrayGet(SnapshotArray* obj, int index, int snap_id) {
	Item *item = obj->snap[index];
	LinkItem *cur = item->head;
	int pre = -1;
	while (cur != NULL) {
		if (snap_id > pre && snap_id <= cur->snapId) {
			return cur->value;
		}
		pre = cur->snapId;
		cur = cur->next;
	}
	return 0;
}

void snapshotArrayFree(SnapshotArray* obj) {
	for (int i = 0; i < obj->length; i++) {
		LinkItem *cur = obj->snap[i]->head;
		for (; cur != NULL; ) {
			LinkItem *pre = cur;
			cur = cur->next;
			free(pre);
			pre = NULL;
		}
		(obj->snap[i])->head = NULL;
		(obj->snap[i])->end = NULL;
	}
	obj->curId = -1;
}
#define EXTEND_SIZE 500
//数组实现
typedef struct {
	int snapId;
	int value;
} Item;
typedef struct {
	Item **table;
	int realLength;
	int allLength;
} ItemTable;

typedef struct {
	ItemTable *snap;
	int curId;
	int length;
} SnapshotArray;


SnapshotArray* snapshotArrayCreate(int length) {
	SnapshotArray *ret = malloc(sizeof(SnapshotArray));
	ret->snap = malloc(sizeof(ItemTable) * length);
	ret->length = length;
	ret->curId = -1;
	for (int i = 0; i < length; i++) {
		ItemTable talbe = ret->snap[i];
		table.table = malloc(sizeof(Item*) * EXTEND_SIZE);
		table.allLength = EXTEND_SIZE;
		table.realLength = 1;
		table.table[0] = malloc(sizeof(Item));
		table.table[0]->snapId = -1;
		table.table[0]->value = 0;
	}
	return ret;
}

void snapshotArraySet(SnapshotArray* obj, int index, int val) {
	ItemTable table = obj->snap[index];
	if (table.table[realLength - 1]->snapId == -1) {
		table.table[realLength - 1]->value = val;
	} else if (val != table.table[realLength - 1]->val) {
		if (table.realLength >= table.allLength) {
			table.table = realloc(table.table, table.allLength += EXTEND_SIZE);
		}
		table.table[realLength] = malloc(sizeof(Item));
		table.table[realLength]->value = val;
		table.table[realLength]->snapId = -1;
		realLength++;
	}
}

int snapshotArraySnap(SnapshotArray* obj) {
	for (int i = 0; i < obj->length; i++) {
		ItemTable table = obj->snap[i];
		table.table[table.realLength - 1]->snapId = obj->curId + 1
	}
	return ++obj->curId;
}
int snapshotArrayGet(SnapshotArray* obj, int index, int snap_id) {
	ItemTable table = obj->snap[index];
	if (table.realLength == 1) return table.table[0]->val;
	int ret;
	for (int left = 0, right = table.realLength - 1; left <= right;) {
		int mid = (left + right) >> 1;
		if (table.table[mid]->snapId >= snap_id && table.table[mid - 1]->snapId < snap_id) {
			ret = table.table[mid]->value;
			break;
		}
	}
	return ret;
}

void snapshotArrayFree(SnapshotArray* obj) {
	for (int i = 0; i < obj->length; i++) {
		ItemTable table = obj->snap[i];
		table.table[0]->snapId = -1;
		table.table[0]->value = 0;
		for (int j = 1; j < talbe.realLength; j++) {
			free(table.table[j]);
		}
		table.realLength = 1;
	}
	obj->curId = -1;
}
