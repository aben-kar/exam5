#include <unistd.h>

int main(int argc, char **argv)
{
	char	av;
	int		i;

	if(argc == 2)
	{
		i = 0;
		while(argv[1][i])
		{
			av = argv[1][i];
			if (av == 'z' || av == 'Z')
			{
				av -= 25;
				write(1, &av, 1);
			}
			else if ((av >= 'a' && av <= 'y') || (av >= 'A' && av <= 'Y'))
			{
				av++;
				write(1, &av, 1);
			}
			else
				write(1, &av, 1);
			i++;
		}
		write(1, "\n", 1);
	}
}
