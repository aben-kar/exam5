#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	sign = 1;
	nb = 0;
	while(str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * sign);
}

void	ft_put_hexa(int nb)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb > 15)
		ft_put_hexa(nb / 16);
	write(1, &str[nb % 16], 1);
}

int	main(int ac, char **av)
{
	int	a;

	if (ac == 2)
	{
		a = ft_atoi(av[1]);
		ft_put_hexa(a);
	}
	write(1, "\n", 1);
}
