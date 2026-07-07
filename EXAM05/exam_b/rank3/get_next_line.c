#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100
#endif

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

void	ft_strlcpy(char *src, char *dst, int n)
{
	int	i = 0;

	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

char *ft_strdup(char *src)
{
	char	*result = malloc(ft_strlen(src) + 1);
	int	i = 0;

	while (src[i])
	{
		result[i] = src[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	int	i = 0;

	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	int	j = 0;
	while (s2[j])
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = 0;
	return (result);
}

char	*ft_strchr(char *str)
{
	int	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (&str[i]);
		i++;
	}
	return (0);
}

char *get_next_line(int fd)
{
	static char *container;
	char *line;
	int	b_read;
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
		return(NULL);

	if (!container)
		container = ft_strdup("");

	buffer = malloc(BUFFER_SIZE + 1);
	if (!ft_strchr(container))
	{
		b_read = 1;
		while (b_read > 0)
		{
			b_read = read(fd, buffer, BUFFER_SIZE);
			if (b_read == -1)
				return (free(buffer), free(container), NULL);
			buffer[b_read] = 0;
			char *tmp2 = ft_strjoin(container, buffer);
			free(container);
			if (!tmp2)
				return (free(buffer), NULL);
			container = tmp2;
			if (ft_strchr(container))
				break ;
		}
		free(buffer);
		if (b_read == 0 && (!container || !*container))
			return (free(container), NULL);
	}
	char *newline_ptr = ft_strchr(container);
	char *tmp;

	if (newline_ptr) {
		tmp = ft_strdup(newline_ptr + 1);
	} else {
		tmp = ft_strdup("");
	}
	int	i = 0;
	while (container[i] && container[i] != '\n')
		i++;
	if (container[i] == '\n')
		i++;
	line = malloc(i + 1);
	i = 0;
	while (container[i] && container[i] != '\n')
	{
		line[i] = container[i];
		i++;
	}
	if (container[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	free (container);
	container = tmp;
	return (line);
}

int	main()
{
	int	fd = open("file.txt", O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);

}
