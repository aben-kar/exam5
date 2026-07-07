#include <unistd.h>

int	main(int argc, char **argv)
{
	int	hash1[256] = {0};
	int	hash2[256] = {0};
	int	i;

	if (argc == 3)
	{
		i = 0;
		while (argv[2][i])
		{
			hash2[(unsigned char)argv[2][i]] = 1;
			i++;
		}
		i = 0;
		while (argv[1][i])
		{
			if (hash1[(unsigned char)argv[1][i]] == 0 && hash2[(unsigned char)argv[1][i]] == 1)
			{
				hash1[(unsigned char)argv[1][i]] = 1;
				write(1, &argv[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
