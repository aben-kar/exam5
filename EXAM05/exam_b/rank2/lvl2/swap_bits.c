#include <stdio.h>

unsigned char	swap_bits(unsigned char octet)
{
	unsigned char	octet_cp;
	unsigned char	res;
	int				i;

	octet_cp = octet >> 4;
	res = octet << 1;
	i = 4;
	while (i)
	{
		res = res | (octet_cp & 1);
		octet_cp >>= 1;
		if (i > 1)
			res <<= 1;
		i--;
	}
	return (res);
}

int	main()
{
	int	i = swap_bits(65);
	printf("%d", i);
	i = 65;
	i = i << 4;
	printf("this is << %d", i);
}
