int	ft_atoi(char *str)
{
	int	i;
	long	nb;
	int	sign;

	i = 0;
	sign = 1;

	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
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
	nb *= sign;
	return (nb);
}
