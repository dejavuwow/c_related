#include <stdio.h>
const char *find_char(char const *source, char const *chars);
int del_substr(char *str, const char *substr);
int main(void)
{
	char source[] = "abcdefg";
	char target[] = "cdef";
	if (del_substr(source, target))
	{
		printf("%s\n%s", source, target);
	}

	return 0;
}
const char *find_char(char const *source, char const *chars)
{
	const char *source_pointer;
	const char *target_pointer;
	if (source == NULL || chars == NULL || *source == '\0' || *chars == '\0')
		source_pointer = NULL;
	else {
		for (target_pointer = chars; *target_pointer != '\0'; target_pointer++)
			for (source_pointer = source; *source_pointer != '\0'; source_pointer++)
				if (*target_pointer == *source_pointer)
				{
					printf("%p, %c\n",source_pointer,  *source_pointer);
						goto end;
				}
	}
end:
	return source_pointer;

}
int del_substr(char *str, const char *substr)
{
	char *pt1 = str;
	const char *pt2 = substr;
	char *start = str;
	while (*pt2 != '\0' && *pt1 != '\0')
	{
		if (*pt2 != *pt1)
		{
			start = pt1 + 1;
			pt2 = substr;
		}
		 else
			 pt2++;
		pt1++;
	}
	if (*pt2 != '\0')
		return 0;
	else {
		printf("%c\n", *start);
		for (; *pt1 != '\0'; pt1++, start++)
			*start = *pt1;
		*start = '\0';
		return 1;
	}
}
