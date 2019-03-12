#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000
int main(void)
{
	int nums;
	printf("How many words do you wish to enter? ");
	scanf("%d", &nums);
	char **arr = (char **)malloc(nums * sizeof(char *));
	printf("Enter %d words now", nums);
	for (int i = 0; i < nums; i++)
	{
		arr[i] = (char *)malloc(10 * sizeof(char));
		scanf("%s", arr[i]);
	}
	getchar();
	printf("I enjoyed doing this exercise");
	printf("Here are your words:");
	for (int i = 0; i < nums; i++)
	{
		printf("%s\n",arr[i]);
	}
	for (int i = 0; i < nums; i++)
	{
		free(arr[i]);
	}
	for (int i = 0; i < nums; i++)
	{
		printf("%s\n",arr[i]);
	}
	free(arr);



   /*  int nums[10] = {0}; */
	/* srand((unsigned)time(0)); */
	/* for (int i = 0; i < SIZE; i++) */
	/* { */
		/* if (i % 100 == 0) */
			/* srand((unsigned)time(0)); */
		/* int temp = rand() % 10 + 1; */
		/* nums[temp - 1]++;  */
	/* } */
	/* for (int i = 0; i < 10; i++) */
		/* printf("%3d appears %-4d times\n", i+1, nums[i]); */
   /*  int arr[SIZE]; */
	/* srand((unsigned)time(0)); */
	/* for (int i = 0; i < SIZE; i++) */
		/* arr[i] = rand() % 10 + 1; */
	/* for (int i = 0; i < SIZE - 1; i++) */
	/* { */
		/* for (int j = i + 1; j < SIZE; j++) */
		/* { */
			/* if (arr[i] < arr[j]) */
			/* { */
				/* int temp = arr[j]; */
				/* arr[j] = arr[i]; */
				/* arr[i] = temp; */
			/* } */
		/* } */
	/* } */
	/* for (int i = 0; i < SIZE; i++) */
		/* printf("%d\n", arr[i]); */
	getchar();
	return 0;
}



