#include <stddef.h>

size_t	ft_strcspn(const char *s1, const char *s2)
{
	int	i;
	int	hash[256] = {0};

	i = 0;
	while (s2[i])
	{
		hash[(unsigned char)s2[i]] = 1;
		i++;
	}
	i = 0;
	while (s1[i])
	{
		if (hash[(unsigned char)s1[i]] == 1)
			return (i);
		i++;
	}
	return (i);
}
