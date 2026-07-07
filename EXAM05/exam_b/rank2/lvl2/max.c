int	max(int *tab, unsigned int len)
{
	int	i;
	int	j;

	if (len == 0)
		return (0);
	i = 0;
	j = tab[i];
	while (i < len)
	{
		if (tab[i] > j)
			j = tab[i];
		i++;
	}
	return (j);
}
