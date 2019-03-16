#include <stdio.h>
#include <string.h>

#define NLEN 30
struct namect {
	char fname[NLEN];
	char lname[NLEN];
	int letters;
};

void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(const struct namect *);
char *s_gets(char *st, int n);
int get_value(int const *);

int main(void)
{
	int *ptr;
	printf("%#o", get_value(ptr));
	getchar();

	struct namect person;

	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	return 0;
}

void getinfo(struct namect *pst)
{
	printf("Please enter your first name.\n");
	s_gets(pst->fname,NLEN);
	printf("Please enter your last name.\n");
	s_gets(pst->lname,NLEN);
}

void makeinfo(struct namect *pst)
{
	pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect *pst)
{
	printf("%s %s,your name contains %d letters.\n",
			pst->fname,pst->lname,pst->letters);
}

char *s_gets(char *st, int n)
{
	char *ret_val, *find;
	
	ret_val = fgets(st,n,stdin);
	if (ret_val)
	{
		find = strchr(st,'\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
int get_value(int const *ptr)
{
	int va = 00000016;
	ptr = &va;
	return *ptr;
}
