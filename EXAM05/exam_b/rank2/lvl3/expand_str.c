#include <unistd.h>
//"hello       fa"
int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i] == 32 || av[1][i] == 9)
			i++;
		while (av[1][i])
		{
			if (av[1][i] == 32 || av[1][i] == 9)
			{
				if (av[1][i + 1] >= 33 && av[1][i + 1] <= 126)
				{
					write(1, &av[1][i], 1);
					write(1, "  ", 2);
				}
			}
			else if (av[1][i] >= 33 && av[1][i] <= 126)
				write(1, &av[1][i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
}
