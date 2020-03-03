#include <stdio.h>
int includes(int *list, int size, int value)
{
    if (size == 0) return 0;
    int *first = list;
    while (first < list + size)
    {

        if (*first++ == value) return 1;
    }
    return 0;
}

int removeDuplicates(int* nums, int numsSize){
    int temp[100] = {0};
    int size = 0;
    int index = 0;
    int j;
    while (index < numsSize)
    {
        if (includes(temp, size, nums[index]))
        {
            for (j = index; j < numsSize - 1; j++)
            {
                nums[j] = nums[j+1];
            }
            numsSize--;
			index--;
           
        }      
		else {
			temp[size++] = nums[index];
		}
		index++;
    }
    return numsSize;
}
int main(void)
{
	int temp[] = {0,0,1,1,1,2,2,3,3,4};
	removeDuplicates(temp, 10);

	for (int *first = temp; first < temp + 10; first++)
		printf("%d", *first);

	return 0;
}
