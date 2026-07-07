#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int		i;
	int		j;
	char	av;
	char	c;

	if(argc == 2)
	{
		i = 0;
		while(argv[1][i])
		{
			av = argv[1][i];
			if (av >= 'a' && av <= 'z')
			{
				j = av - 96;
				c = 123 - j;
				write(1, &c, 1);
			}
			else if (av >= 'A' && av <= 'Z')
			{
				j = av - 64;
				c = 91 - j;
				write(1, &c, 1);
			}
			else
				write(1, &av, 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
