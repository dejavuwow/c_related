#include <stdio.h>
#define MAX 81
typedef struct {
	int array[MAX];
	int length;
} Heap;

void balNode(Heap *data, int index)
{
	int left = 2 * index + 1,
		right = 2 * index + 2;
	int max = index;
	int temp;
	if (left <= data->length - 1 && data->array[index]  < data->array[left]) max = left; 
	if (right <= data->length - 1 && data->array[max] <  data->array[right]) max = right;

	temp = data->array[max];
	data->array[max] = data->array[index];
	data->array[index] = temp;
	if (max != index) balNode(data, max);
	return;
}
//     1
//   2   3 
//  4 
void heapInit(Heap *data)
{
	int index = data->length / 2 - 1;

	while (index >= 0)
	{
		balNode(data, index);
		index--;
	}
	return;

}
void heapSort(Heap *data)
{
	int temp;
	while (data->length > 1)
	{
		temp = data->array[0];
		data->array[0] = data->array[data->length - 1];
		data->array[data->length - 1] = temp;
		data->length--;
		balNode(data, 0);
	}
}

{
	if (node == NULL)
		node.left;
		node.right;
		node.value
	
	
}

int main(void)
{
	Heap data;
	data.length  = 6;
	data.array[0] = 25;
	data.array[1] = 15;
	data.array[2] = 85;
	data.array[3] = 16;
	data.array[4] = 5;
	data.array[5] = 35;

	heapInit(&data);
	heapSort(&data);
	for (int *temp = data.array; temp < data.array + 6; temp++)
		printf("%d ", *temp);

	return 0;
}
//					25
//				15		85
//			  16  5   35
//` 5 15 35 16 25 85
//     
//     5
//   15  35
//  16 25 85
//			  
