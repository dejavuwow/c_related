#include <stdio.h>
#include <string.h>
#include <math.h>
#define ROW 8
#define COL 8
static char chessboard[8][8] = {
	"++++++++",
	"++++++++",
	"++++++++",
	"++++++++",
	"++++++++",
	"++++++++",
	"++++++++",
	"++++++++"
};
static int result_count = 0;
void resetBoard(void)
{
	char (*string)[COL] = chessboard;
	while (string < &chessboard[ROW])
	{
		memset(string++, '+', COL);
	}

}
void showBoard(int position[])
{
	resetBoard();
	putchar('\n');
	for (int i = 0; i < ROW; i++)
	{
		chessboard[i][position[i]] =  '@';
		for (int j = 0; j < COL; j++)
		{
			putchar(' ');
			putchar(' ');
			putchar(' ');
			putchar(chessboard[i][j]);
		}
		putchar('\n');
		putchar('\n');
	}
}
int checkConflict(int position[], int row)
{
	for (int i = 0; i < row; i++)
	{
		if (position[i] == position[row] ||
				abs(i - row)== abs(position[i] - position[row])
				)
			return 0;
	}
	return 1;
}

void moveQueen(int position[], int row)
{
	if (row == ROW)
	{
		showBoard(position);
		return;
	}
	for (int i = 0; i < COL; i++)
	{
	
		result_count++;
		position[row] = i;
		if (checkConflict(position, row))
		{
			moveQueen(position, row+1);
		}
	}
}
int main(void)
{
	int position[ROW] = {0};
	moveQueen(position, 0);
	printf("%d", result_count);
	return 0;

}
