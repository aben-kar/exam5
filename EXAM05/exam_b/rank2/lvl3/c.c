#include <unistd.h>

int	ft_lcm(unsigned int a, unsigned int b)
{
	int	n;
	
	if (a > b)
		n = a;
	else
		n = b;
	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return(n);
		n++;
	}
}
