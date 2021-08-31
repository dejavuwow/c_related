#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int includes(const char *string, char letter)
{
	int i = 0;
	while (*string != '\0') {
		if (*string == letter) {
			i++;
		}
		string++;
	}
	return i;
}

char *getWord(char *str, count)
{

}

char * toGoatLatin(char * S){
	char *new_str = (char*)malloc(sizeof(char), 100);
	char *word = (char*)malloc(sizeof(char), 20);
	const char vowel[] = "aeiou";
	char *start = S;
	char *word_head;
	int nums;
	int word_count = 0;

	while (*start != '\0') {
		if (start == S || *(word_head-1) == 0x16) {
			word_head = start;
			nums = 0;
		}
		if (*start == 0x16){
			
		}
	}
}

int main(void)
{

}
