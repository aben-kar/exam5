#include <stdlib.h>

//"    first   second     third     fourth   "

char	*ft_strncpy(char *dst, char *src, int size)
{
	int	i;

	i = 0;
	while (src[i] && i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	**ft_split(char *str)
{
	char	**arr;
	int		i;
	int		count;
	int		j;
	int		k;

	i = 0;
	k = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != 32 && str[i] != 9 && str[i] != '\n')
		{
			if (str[i + 1] == 32 || str[i + 1] == 9 || str[i + 1] == '\n' || str[i + 1] == 0)
				count++;
		}
		i++;
	}
	arr = malloc(sizeof(char *) * (count + 1));
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == 32 || str[i] == 9 || str[i] == '\n'))
			i++;
		j = i;
		while (str[i] && (str[i] != 32 && str[i] != 9 && str[i] != '\n'))
			i++;
		if (i > j)
		{
			arr[k] = malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(arr[k], &str[j], i - j);
			k++;
		}
	}
	arr[k] = NULL;
	return (arr);
}

int	main()
{
	char	**arr = ft_split("  first  second  third  ");
}
