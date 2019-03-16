#include <stdio.h>
/* #include <stdlib.h> */
/* #define MYTYPE(X) _Generic((X),\ */
/* int: "int",\ */
/* float: "float",\ */
/* double: "double",\ */
/* default: "other"\ */
/* ) */

inline static void eatline(void)
{
	while (getchar() != '\n')
		continue;
}
int main(void)
{

	eatline();
	
	return 0;
}

// 24,1,24,44,65,23,2,24,19     [5]
// 
