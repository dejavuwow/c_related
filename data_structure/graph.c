#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int x;
	int y;
	int step;
} Rect;
#define SIZE 1000
#define ADD_QUEUE(val) (queue[++queue_end % SIZE] = val)
#define OUT_QUEUE (queue[(queue_head++) % SIZE])
#define IS_EMPTY (queue_head > queue_end)
#define FLUSH_QUEUE {\
	while (!IS_EMPTY) {\
		free(OUT_QUEUE);\
	}\
	queue_head = 0;\
	queue_end = -1;\
}
#define CREATE_ITEM(a,b,c) {\
	item = (Rect*)malloc(sizeof(Rect));\
	item->x = a;\
	item->y = b;\
	item->step = c;\
}
#define MEM_SET {\
	for (int i = 0; i < gridSize; i++) {\
		for (int j = 0; j < gridColSize[i]; j++) {\
			map[i][j] = 0;\
		}\
	}\
}

int maxDistance(int (*grid)[100], int gridSize, int* gridColSize){
	Rect *queue[SIZE];
	int queue_head = 0;
	int queue_end = -1;
	int maxDistance = -1;
	int distance;
	int find;
	Rect *item;

	int map[gridSize][gridColSize[0]];
	int count = 0;

	//reset
	MEM_SET;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridColSize[i]; j++) {
			if (grid[i][j] == 0) {
				MEM_SET;
				FLUSH_QUEUE;
				CREATE_ITEM(i,j,0);
				ADD_QUEUE(item);
				map[item->x][item->y] = 1;
				find = 0;
				while (!IS_EMPTY) {
					item = OUT_QUEUE;
					int step = item->step;
					int x = item->x;
					int y = item->y;
					if (grid[item->x][item->y] == 1) {
						distance = step;
						find = 1;
						break;
					} 
					if (x - 1 >= 0 && !map[x-1][y]) {
						CREATE_ITEM(x - 1,y,step + 1);
						ADD_QUEUE(item);
				map[item->x][item->y] = 1;
					}
					if (y + 1 < gridColSize[x] && !map[x][y+1]) {
						CREATE_ITEM(x,y+1,step + 1);
						ADD_QUEUE(item);
				map[item->x][item->y] = 1;
					}
					if (x + 1 < gridSize && !map[x+1][y]) {
						CREATE_ITEM(x+1,y,step + 1);
						ADD_QUEUE(item);
				map[item->x][item->y] = 1;
					}
					if (y - 1 >=  0 && !map[x][y-1]) {
						CREATE_ITEM(x,y-1,step + 1);
						ADD_QUEUE(item);
				map[item->x][item->y] = 1;
					}
				}
				distance = find == 1 ? distance : -1;
			printf("%d ", distance);
				maxDistance = distance > maxDistance ? distance : maxDistance;
			}
		}
	}
	printf("return: %d", maxDistance);
	return maxDistance;
}

//					4
//				   434
// 				  43234	
//				 4321234 
// 				  43234
// 				   434
//					4
//1 3 5  7  9  11   100 + 2
//4 8 12 16 20 24
//
//
//
//				2
//				1
#define ROW 100
#define COL 100
int main(void) {
	
	int grid2[10][10];
	int rowSize = 10;
	int **grid = (int**)malloc(sizeof(int*) * rowSize);
	int count = 0;
	for (int i = 0; i < rowSize; i++) {
		grid[i] = malloc(sizeof(int) * 10);
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			grid[i][j] = count++;
		}
	}

	printf("%#p %#p\n", &grid2[0], &grid2[0] + 1);
	printf("%#p %#p", &grid[0][9] + 1, &grid[1][0]);
	int a = 15;
	printf("**%d 88");


	/** int colSize[100]; */
	/** for (int i = 0; i < 100; i++) colSize[i] = 100; */
	/** for (int i = 0; i < ROW; i++) { */
	/**     for (int j = 0; j < COL; j++) { */
	/**         if (i == 0 || i == ROW - 1 || j == 0 || j == COL - 1) { */
	/**             grid[i][j] = 1; */
	/**         } */
	/**     } */
	/** } */
	/** maxDistance(grid, ROW, colSize); */
}
