#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define printArray(array) \
{\
	for (int i = 0; i < 9; i++) { \
		for (int j = 0; j < 9; j++) { \
			printf("%d", array[i][j]);\
			}\
		}\
}
// 1 2 3 4  | 4 3 2 1 
// 2 1 4 3	| 3 4 1 2
// 3 4 2 1	| 1 2 4 3
// 4 3 1 2	| 2 1 3 4
//
// i:0, size - 1  (i, j) -> (j, size  - 1)  
// j:0, size - 1 (00 01 11 10)
//
//
//

// (j / 3) * ()+(i / 3)
bool isValidSudoku(char (*board)[9], int boardSize, int* boardColSize){
	bool horStore[9][9] = {0};
	bool verStore[9][9] = {0};
	bool squareStore[9][9] = {0};
	int p;
	
	//printf("%c %d %d", board[0][0], boardSize, *boardColSize);
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < *boardColSize; j++) {
			p = board[i][j] - 0x31;
			printf("%d\n", p);
			if (p != -2) {
				if (horStore[i][p] || verStore[j][p] || squareStore[(i / 3) * 3 +  (j / 3)][p]) {
					return false;
				}
				horStore[i][p] = true;
				verStore[j][p] = true;
				squareStore[(i / 3) * 3 +  (j / 3)][p] = true;
			}
		}
	}
	return true;
}

int main(void) {
	/** int *arr[2] = { */
	/**     {1,3}, */
	/**     {1,3}, */
	/** }; */
	/** int (*ar3)[2] = arr; */
	int arr = 33;
	int *p = &arr;
		int **er = &p;
	printf("%p %p", er, er + 1);

	char sudoku[9][9] = {
		{'8','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'},
	};
	int boardColSize = 9;
	printf("%d", isValidSudoku(sudoku, 9, &boardColSize));
}

