#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	int	i;
	int	hash[256] = {0};

	i = 0;
	while (s[i])
	{
		hash[(unsigned char) s[i]] = 1;
		i++;
	}
	i = 0;
	while (s[i])
	{
		if (hash[(unsigned char) s[i] == 0])
			return (i);
		i++;
	}
	return (i);
}
