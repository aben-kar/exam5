#include <unistd.h>
//"   hereIsACamelCaseWord"

int main(int argc, char **argv)
{
	int		i;
	char	av;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			av = argv[1][i];
			if (av >= 'A' && av <= 'Z')
			{
				write(1, "_", 1);
				av += 32;
			}
			write(1, &av, 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
