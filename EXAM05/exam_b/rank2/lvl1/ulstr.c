#include <unistd.h>

int main(int argc, char **argv)
{
	int		i;
	char	av;
	char	c;

	if (argc == 2)
	{
		i = 0;
		while(argv[1][i])
		{
			av = argv[1][i];
			if (av >= 'a' && av <= 'z')
			{
				c = av - 32;
				write(1, &c, 1);
			}
			else if (av >= 'A' && av <= 'Z')
			{
				c = av + 32;
				write(1, &c, 1);
			}
			else
				write(1, &av, 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
