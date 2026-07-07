#include <stdlib.h>

// 1337 -> 4

int	ft_nbr_len(int nb)
{
	long	nbr;
	int		res;

	nbr = nb;
	res = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		res++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int nbr)
{
	char	*res;
	int		i;
	char	*tmp;
	int		j;

	i = ft_nbr_len(nbr) + 1;
	res = malloc(sizeof(char) * i);
	i = 0;
	j = 0;
	if (nbr < 0)
	{
		res[j++] = '-';
		nbr *= -1;
	}
	// 1337
	while (nbr > 0)
	{
		tmp[i] = (nbr % 10) + 48;
		nbr /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		res[j] = tmp[i];
		j++;
		i--;
	}
	res[j] = 0;
	return (res);
}
