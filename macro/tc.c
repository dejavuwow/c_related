#include <stdio.h>
#define COMP(queue) (queue##x > queue##y)
int main(void) {
	int queue_x = 3;
	int queue_y = 2;
	int x = 5;
	int y = 7;
	int queue_5 = 9;
	int queue_7 = 91;
	printf("%d", COMP(queue));
}
