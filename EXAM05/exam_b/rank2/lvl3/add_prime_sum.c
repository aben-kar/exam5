#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while(str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb *= sign);
}

void	ft_putnbr(int nb)
{
	long	nb_l;
	char	c;

	nb_l = nb;
	if (nb_l > 9)
		ft_putnbr(nb_l / 10);
	c = nb_l % 10 + 48;
	write(1, &c, 1);
}

int	ft_is_prime(int nb)
{
	int	x;

	x = 2;
	if (nb < 2)
		return (0);
	while (x * x <= nb)
	{
		if (nb % x == 0)
			return (0);
		x++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	nb;
	int	res;

	res = 0;
	if (argc == 2)
	{
		nb = ft_atoi(argv[1]);
		if (nb > 0 && ft_is_prime(nb) == 1)
		{
			res += nb;
			nb --;
			while (nb > 0)
			{
				if (ft_is_prime(nb) == 1)
					res += nb;
				nb--;
			}
		}
	}
	ft_putnbr(res);
	write(1, "\n", 1);
}
