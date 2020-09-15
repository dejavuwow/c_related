#include <stdio.h>
#include <stdlib.h>
#define CONTENT "<template>\n"\
	"</template>\n"\
	"<script>\n"\
	"export default {\n"\
	"}\n"\
	"</script>\n"\
	"<style lang=\"scss\">\n"\
	"</style>"
int main(int args, char *argv[])
{
	FILE *fp;
	fp = fopen(argv[1], "w");
	fprintf(fp, "%s", CONTENT);
	fclose(fp);

	return 0;

}
