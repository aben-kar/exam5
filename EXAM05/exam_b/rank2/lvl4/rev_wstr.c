#include <unistd.h>

// "first second third"

int main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i] && av[1][i + 1])
			i++;
		while (i >= 0)
		{
			if (av[1][i - 1] == 32 || i == 0)
			{
				j = i;
				while (av[1][i] && av[1][i] != 32)
				{
					write(1, &av[1][i], 1);
					i++;
				}
				i = j - 1;
				if (j != 0)
					write(1, " ", 1);
			}
			i--;
		}
	}
	write(1, "\n", 1);
}
