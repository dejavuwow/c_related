#include <stdio.h>
#include <math.h>

const char *temp = "abc";
char getDiff(char prev) 
{
	char cur = '\0';
	for (char *current = temp; *current != '\0'; current++)
	{
		if (prev != *current)
			cur = *current;
	}
	return cur;
}

char * getHappyString(int n, int k){

	int index = 0;
	int max = pow(2, n-1) * 3;

	char *retChar = malloc(n * sizeof(char));
	retChar[index++] = 'a';
	while (index < k)
	{
		retChar[index] = retChar[index-1] == 'a' ? 'b' : 'a';
		index++;
	}
	
	index--;
	while (--k)
	{
		retChar[index] = 
	}
}

}
