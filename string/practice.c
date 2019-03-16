#include <stdio.h>
#include <string.h>
unsigned get_size(char *str);
char *s_gets(char *inp, int n);
char *get_space(char *inp);
int main(void)
{
	char inp[] = "myfavouradehabbit";
	printf("%p", get_space(inp));
	getchar();

	return 0;
}
unsigned get_size(char *str)
{
	unsigned n = 0;
	while(*str++)
		n++;
	return n;
}
char *s_gets(char *inp, int n)
{
	char *ret_val;
	int i = 0;
	ret_val = fgets(inp, n, stdin);
	if (ret_val)
	{
		/* while (inp[i] != '\0' && inp[i] != '\n') */
		/* i++; */
		/* if (inp[i] == '\n') */
		/* inp[i] = '\0'; */
		/* else */
		/* while(getchar() != '\n') */
		/* continue; */
		char *find = strchr(inp, '\n');
		if (find)
			*find = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	return ret_val;
}
char *get_space(char *inp)
{
	return strchr(inp, ' ');
}
