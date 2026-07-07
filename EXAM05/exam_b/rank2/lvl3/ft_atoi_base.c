int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	sign;
	int	c;
	int	res;

	i = 0;
	sign = 1;
	c = 0;
	res = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			c = str[i] - 48;
		else if (str[i] >= 'a' && str[i] <= 'f')
			c = str[i] + 10 - 'a';
		else if (str[i] >= 'A' && str[i] <= 'F')
			c = str[i] + 10 - 'A';
		else
			break ;
		res = res * str_base + c;
		i++;
	}
	return (res * sign);
}
