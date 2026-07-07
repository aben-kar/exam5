#include <stdio.h>
#include <stdlib.h>
int	ft_isprime(int n)
{
	int x;

	if (n < 2)
		return (0);
	x = 2;
	while (x < n)
	{
		if (n % x == 0)
			return (0);
		x++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	a;
	int	x;
	int	y;

	x = 2;
	y = 1;
	if (ac == 2)
	{
		a = atoi(av[1]);
		if (ft_isprime(a) == 1)
		{
			while (y != a)
			{
				if (ft_isprime(x) == 1)
				{
					printf("%d*", x);
					x++;
				}
				else
					x++;
			}
		}
	}
	printf("\n");
}
