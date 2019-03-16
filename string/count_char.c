#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 20
char *s_gets(char *st, int n);
int main(void)
{
	char str[] = "213123";
	int n = strlen(str);
	int number = 0;
	for (int i = 0; i < n; i++)
	{
		if (!isdigit(str[i]))
			return 0;
		number = number * 10 + (str[i] - '0');
	}
	printf("%d",number);
	/* double n1 = atof(str[1]); */
	// int ex = atoi(str[2]);
	// double res = n1;
	// while (--ex)
		// res = res * n1;
	/* printf("%f", res); */
	/* char *cpy[args - 1]; */
	// for (int i = 1; i < args; i++)
		// cpy[args - 1 - i] = str[i];
	// for (int i = 0; i< args -1; i++)
		/* printf("%s ", cpy[i]); */
	/* int words =[>  0, <] */
		/* upper_words = 0, */
		/* lower_words = 0, */
		/* punctuations = 0, */
		/* numbers = 0; */
	/* char str[SIZE]; */
	/* while (!s_gets(str, SIZE)) */
		/* continue; */
	/* char *ptr = str; */
	/* while (*ptr) */
	/* { */
		/* if (!isspace(*ptr)) */
			/* words++; */
		/* if (isupper(*ptr)) */
			/* upper_words++; */
		/* if (islower(*ptr)) */
			/* lower_words++; */
		/* if (ispunct(*ptr)) */
			/* punctuations++; */
		/* if (isalnum(*ptr) && !isalpha(*ptr)) */
			/* numbers++; */
		/* ptr++; */
	/* } */
	/* printf("%d, %d, %d, %d, %d", words, upper_words, lower_words, punctuations, numbers); */
	getchar();

	return 0;
}
char *s_gets(char *st, int n)
{
	char *ret_val;

	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		while(*st != '\n' && *st != '\0')
			st++;
		if(*st == '\n')
			*st = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	return ret_val;
}
