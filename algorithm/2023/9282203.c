struct my_struct {
	char name[301];             /* key (string is WITHIN the structure) */
	int count;
	UT_hash_handle hh;         /* makes this structure hashable */
};
int maxEqualRowsAfterFlips(int** matrix, int matrixSize, int* matrixColSize){
	struct my_struct *s, *tmp, *users = NULL;
	int max = 1;
	int m = matrixSize,
		n = matrixColSize[0];
	for (int i = 0; i < m; i++) {
		int needFlip =  matrix[i][0] == 0;
		char str[301];
		int index = 0;
		for (int j = 0; j < n ; j++) {
			matrix[i][j] = needFlip ? !matrix[i][j] : matrix[i][j];
			str[index++] = matrix[i][j] + '0';
		}
		str[index] = '\0';
		HASH_FIND_STR(users, str, s);
		if (s != NULL) {
			s->count++;
		} else {
			s = malloc(sizeof(struct my_struct));
			s->count = 1;
			strcpy(s->name, str);
			HASH_ADD_STR(users, name, s);
		}
	}
	HASH_ITER(hh, users, s, tmp) {
		max = fmax(max, s->count);
		free(s);
	}
	return max;
}
int minSequenceSum(int array, int length) {
	int min = INT_MAX;
	int cur = 0;
	for (int i = 0; i < length; i++) {
		cur = fmin(array[i] + cur, array[i])
			min = fmin(cur, min);
	}
}

int minPositiveSumOfSequence(int array, int length) {
	int min = INT_MAX;
	int cur = 0;
	for (int i = 0; i < length; i++) {
		int s = cur + array[i];
		cur = s  < cur && s > 0 ? s : cur;
		min = fmin(cur, min);
	}
}

int pow(int number, int n) {
	int counts = n / 2;
	int ret = number;
	int rem = n - counts * 2;

	while (counts--)
		ret *= ret;

	ret *= rem ? number : 1;
	return  ret;
}
