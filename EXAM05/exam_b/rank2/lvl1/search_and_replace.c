#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	int		i;
	char	av;

	if (argc == 4 && (ft_strlen(argv[2]) == 1) && (ft_strlen(argv[3]) == 1))
	{
		i = 0;
		while(argv[1][i])
		{
			av = argv[1][i];
			if (av == argv[2][0])
				write(1, &argv[3][0], 1);
			else
				write(1, &av, 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
