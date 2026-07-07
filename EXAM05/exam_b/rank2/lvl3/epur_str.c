#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] == 32 || argv[1][i] == 9)
			i++;
		while (argv[1][i])
		{
			if (argv[1][i] == 32 || argv[1][i] == 9)
			{
				if (argv[1][i + 1] >= 33 && argv[1][i + 1] <= 126)
					write (1, &argv[1][i], 1);
			}
			else if (argv[1][i] >= 33 && argv[1][i] <= 126)
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
