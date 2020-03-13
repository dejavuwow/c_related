#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int issort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2))
{
	char *a = data;
	void *key;
	int i, j;

	if ((key = (char *)malloc(esize)) == NULL)
		return -1;

	for (j = 1; j < size; j++)
	{
		memcpy(key, &a[j * esize], esize);
	}
}

int main(void)
{

	return 0;
}
