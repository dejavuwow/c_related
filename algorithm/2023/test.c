#include <string.h>
#include <stdio.h>

int main(void) {
	char *s[18];
	char *a = "123"; 
	s[0] = a;
	printf("%s\n%s", a, s[0]);
	return 0;
}
