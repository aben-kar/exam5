#include <unistd.h>

int main(int argc, char **argv)
{
	int	i;
	int	count;

	if (argc == 2)
	{
		i = 0;
		while(argv[1][i])
		{
			if ((argv[1][i] >= 'a' && argv[1][i] <= 'z'))
			{
				count = argv[1][i] - 96;
				while (count > 0)
				{
					write(1, &argv[1][i], 1);
					count -= 1;
				}
			}
			else if((argv[1][i] >= 'A' && argv[1][i] <= 'Z'))
			{
				count = argv[1][i] - 64;
				while (count > 0)
				{
					write(1, &argv[1][i], 1);
					count -= 1;
				}
			}
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
