#include <unistd.h>

int main(int argc, char **argv)
{
	int		i;
	char	hash[256] = {0};

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			hash[(unsigned char)argv[1][i]] = 1;
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			hash[(unsigned char)argv[2][i]] = 1;
			i++;
		}
		i = 0;
		while (argv[1][i])
		{
			if (hash[(unsigned char)argv[1][i]] == 1)
			{
				write(1, &argv[1][i], 1);
				hash[(unsigned char)argv[1][i]] = 0;
			}
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			if (hash[(unsigned char)argv[2][i]] == 1)
			{
				write(1, &argv[2][i], 1);
				hash[(unsigned char)argv[2][i]] = 0;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
