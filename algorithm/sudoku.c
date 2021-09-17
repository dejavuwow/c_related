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
//
// Node temp = node->left;
// node->left = node->right;
// node->right = temp;
//
// reverse(node->left);
// reverse(node->right);
// 5  1  9  11 | 15 13 2  5
// 2  4  8  10 | 14 3  8  4
// 13 3  6  7  | 12 10 6  9
// 15 14 12 16 | 16 7  10 11
//
// 1 2 3 4  | 4 3 2 1 
// 2 1 4 3	| 3 4 1 2
// 3 4 2 1	| 1 2 4 3
// 4 3 1 2	| 2 1 3 4
//
// logn * 4 *
//011111111111
// i:0, size - 1  (i, j) -> (j, size  - 1)  
// j:0, size - 1 (00 01 11     10    )
//				 (0j j1 1(1-j) (1-j)0)    (i, size - 1)
//                                        (i, size - 1)
//  start = 0;		 1 - 1	
//  max = size - 1;  3  - 1  (n - 1)
//  				4 - 2
//
//  int nums; !!    2 3 7 45 2017
//  			     
//                 1 * 2   1 * 3  1 * 7  5 * 9
//   (n - 1) + (n - 3) + ... +  2  odd  6
//   (n - 1) + (n - 3) + ... +  1  even
//    
//    (n + 1) ( ( n - 1)/ 4)   
//  int temp1, temp2;
//  do {
//		int j = start;
//		
//		while (j < max) {
//         
//			n = 4;
//			temp1 = matrix[start][j];
//			while (n > 0) {
//				if (n == 4) {
//					temp2 = matrix[j][max];
//					matrix[j][max] = temp1;
//				}
//				else if (n == 3) {
//					temp2 = matrix[max][max - j]
//					matrix[max][max - j] = temp1;
//				}
//				else if (n == 2) {
//					temp2 = matrix[max - j][start];
//					matrix[max - j][start] = temp1;
//				}
//				else {
//					temp2 = matrix[start][j];
//					matrix[max - j][start] = temp1;
//
//				}
//					temp1 = temp2;
//					n--;
//			}
//			j++;
//		}
//
//  } while(++start <= ((size - 1) / 2);

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
// 100000000000000000000000000000000000
// 011101111 11111111 11111111 11111111
// 100000000000000000000000000000000001
// 011111111111111111111111111111111111
// 011111111111111111111111111111111111
// 0100000000000000000000000000000000000
// 101111111111111111111111111111111111
// 2^32 - 2^31
//  7f         ff   ff        ff
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
	
	int test;
	test = 10;
	printf("\n***%d", test + -0x7fffffff);

}

