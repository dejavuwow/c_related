#include <stdio.h>
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
void showBoard(void)
{
	putchar('\n');
	for (int i = 0; i < ROW; i++)
	{
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
int main(void)
{
	showBoard();
	return 0;

}
