char	*ft_strpbrk(const char *s1, const char *s2)
{
	int			i;
	int			hach[256] = {0};
	const char	*cp;

	i = 0;
	while (s2[i])
	{
		hach[(unsigned char)s2[i]] = 1;
		i++;
	}
	i = 0;
	while (s1[i])
	{
		if (hach[(unsigned char)s1[i]] == 1)
		{
			cp = &s1[i];
			return ((char *)cp);
		}
		i++;
	}
	return (0);
}
