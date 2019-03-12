static int mode;
void set_mode(int mode_s)
{
	if (modes != 1 && mode_s != 0)
		printf("Invalid mode specified.Mode %d(%s)used", mode, mode == 1 ? "US" : "metric");
	else
		mode = mode_s;
}
