#include <stdio.h>
#include <stdlib.h>
struct ball_info {
	struct {
		char first[20];
		char last[20];
	};
	int action_num;
	int hit;
	int base;
	int points;
	double rate;
};

int main(void)
{
	FILE *fp;
	struct ball_info arr[19] = {
		{
			{{'\0'},{'\0'}},
			0, 0, 0, 0, 0.0
		}
	};
	struct ball_info item;
	int play_number;
	fp = fopen("player.txt","r");
	while (!feof(fp))
	{
		fscanf(fp, "%d", &play_number);
		fscanf(fp, "%s", item.first);
		fscanf(fp, "%s", item.last);
		fscanf(fp, "%d", &item.action_num);
		fscanf(fp, "%d", &item.hit);
		fscanf(fp, "%d", &item.base);
		fscanf(fp, "%d", &item.points);
		arr[play_number] = item;
	}
	fclose(fp);
	for (int i = 0; i < 4; i++)
		printf("%s %s: %d %d %d %d\n",
				arr[i].first,
				arr[i].last,
				arr[i].action_num,
				arr[i].hit,
				arr[i].base,
				arr[i].points);

	return 0;
}
