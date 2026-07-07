#include <stdlib.h>
int	*ft_rrange(int start, int end)
{
	int	i;
	int	*arr;
	int	len;

	len = end - start;
	if (len < 0)
		len *= -1;
	len++;
	i = 0;
	arr = (int *)malloc(sizeof(int) * (len));
	if (end < start)
	{
		while (i < len)
		{
			arr[i] = end;
			end++;
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			arr[i] = end;
			end--;
			i++;
		}
	}
	return (arr);
}
