#include <stdlib.h>
#include <stdio.h>

int	ft_find_pgcd(int a, int b)
{
	int	nb;

	if (a == 0 || b ==0)
		return (0);
	if (a > b)
		nb = b;
	else
		nb = a;

	while (1)
	{
		if ((a % nb == 0) && (b % nb == 0))
			return (nb);
		nb--;
	}
}

int	main(int ac, char **av)
{
	int	a;
	int	b;
	int	res;

	if (ac == 3)
	{
		a = atoi(av[1]);
		b = atoi(av[2]);
		if (a > 0 && b > 0)
		{
			res = ft_find_pgcd(a, b);
			printf("%d", res);
		}
	}
	printf("\n");
}
