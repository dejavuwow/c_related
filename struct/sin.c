#include <stdio.h>
#include <string.h>
struct name {
	char first[20];
	char last[20];
	char mid[20];
};

struct sse {
	char num[20];
	struct name name;
};

void prt(struct sse arr[], int cols);

int main(void)
{
	struct sse arr[5] = {
		{"m123",{"James","Lebron","Gid"}},
		{"g123",{"Rondo","Ded",""}},
		{"h123",{"Olie","Geal","Pid"}},
		{"v123",{"Loes","Rose",""}},
		{"s123",{"Derrick","Loer","Pid"}}
	};
	prt(arr,5);

	return 0;

}

void prt(struct sse arr[], int cols)
{
	for (int i = 0; i < cols; i++)
	{
		printf("%s,%s",
				arr[i].name.first,
				arr[i].name.last);
		if (arr[i].name.mid[0] != '\0')
			printf("%c.", arr[i].name.mid[0]);
		putchar('\n');
	}
}
	
