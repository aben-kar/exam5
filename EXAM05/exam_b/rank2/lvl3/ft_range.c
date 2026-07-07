#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*arr;
	int	i;
	int	len;

	len = end - start;
	if (len < 0)
		len *= -1;
	i = 0;
	arr = (int *)malloc(sizeof(int) * (len + 1));
	if (start > end)
	{
		while (i < len + 1)
		{
			arr[i] = start;
			start--;
			i++;
		}
	}
	else
	{
		while (i < len + 1)
		{
			arr[i] = start;
			start++;
			i++;
		}
	}

	return (arr);
}
