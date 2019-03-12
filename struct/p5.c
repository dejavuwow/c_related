#include <stdio.h>
#include <string.h>
#include "p5.h"
#define CSIZE 4

void eatline(void);
char *s_gets(char *str, int n);
void getGrades(struct student data[], int size);
void getAverage(struct student *item);

int main(void)
{
	struct student data[CSIZE];
	float f1 = 82.023;
	printf("%.f %.1f %.0f", f1, f1, f1);

	/* data[0].name = {"Ler", "Grace"}; */
	/* data[1].name = {"Oier", "Suier"}; */
	/* data[2].name = {"Pier", "Mijer"}; */
	/* data[3].name = {"Nkdf", "Kioe"}; */
	getGrades(data, CSIZE);
	for (int i = 0; i < CSIZE; i++)
		getAverage(&data[i]);
	for (int i = 0; i < CSIZE; i++)
		printf("%s %s: %f %f %f %f\n",
				data[i].name.first,
				data[i].name.last,
				data[i].grades[0],
				data[i].grades[1],
				data[i].grades[2],
				data[i].average);

	return 0;
}
void getAverage(struct student *item)
{
	item->average = (item->grades[0] + item->grades[1] + item->grades[2]) / 3;
}

void getGrades(struct student data[], int size)
{
	for (int i = 0; i < size; i++)
	{
		fputs("Enter the student first name: ", stdout);
		s_gets(data[i].name.first, 20);
		fputs("Enter last name: ", stdout);
		s_gets(data[i].name.last, 20);
		fputs("Enter grades: ", stdout);
		scanf("%lf %lf %lf",
				&data[i].grades[0],
				&data[i].grades[1],
				&data[i].grades[2]);
		eatline();
	}
}
void eatline(void)
{
	while (getchar() != '\n')
		continue;
}
char *s_gets(char *str, int n)
{
	char *ret_val,
		 *find;

	ret_val = fgets(str,n,stdin);
	if (ret_val)
	{
		find = strchr(ret_val,'\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
