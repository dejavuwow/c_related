/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */
struct my_struct {
	struct Node *node;
	int val;
	UT_hash_handle hh;         /* makes this structure hashable */
};
struct my_struct *cur, *tmp, *users = NULL;
struct Node *cloneNode(struct Node *s) {
	if (s == NULL) return NULL;
	struct Node *ret;
	HASH_FIND_INT(users, &s->val, cur);
	if (cur) {
		ret = cur->node;
	} else {
		ret = malloc(sizeof(struct Node));
		ret->val = s->val;
		ret->numNeighbors = s->numNeighbors;
		ret->neighbors = malloc(sizeof(struct Node *) * ret->numNeighbors);
		cur = malloc(sizeof(struct my_struct));
		cur->node = ret;
		cur->val = ret->val;
		HASH_ADD_INT(users, val, cur);
		for (int i = 0; i < s->numNeighbors; i++) {
			ret->neighbors[i] = cloneNode(s->neighbors[i]);
		}
	}
	return ret;
}
struct Node *cloneGraph(struct Node *s) {
	users = NULL;
	return cloneNode(s);

}

//gas = [1,2,3,4,5], cost = [3,4,5,1,2]
//rem = [-2, -2, -2, 3, 3];
//
//gas = [4,5,2,6,5,3], cost = [3,2,7,3,2,9];
//rem = [1,3,-5,3,3,-6];
//[-3,7, -4, 2]
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
	int l = gasSize;
	int remain[l];
	int total = 0;
    int last = -1;

	for (int i = 0; i < l; i++) {
		remain[i] = gas[i] - cost[i]; 
	}

	for (int i = 0; i < 2 * l - 1; i++) {
		if (remain[i % l] + total < 0) {
           
			total = 0;
			last = -1;
		}
		else {
			total += remain[i % l];
			if (last == -1 && i < l) {
				last = i % l;
			}
		}
	}
	return last;
}
