#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putstr(char *str)
{
    int i = 0;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}

int ft_putnbr(int nb)
{
    long nbr = nb;
    int count = 0;

    if (nbr < 0)
    {
        nbr *= -1;
        count += ft_putchar('-');
    }
    if (nbr > 9)
        count += ft_putnbr(nbr / 10);
    count += ft_putchar(nbr % 10 + 48);
    return (count);
}

int ft_puthexa(unsigned int nbr)
{
    char    *base = "0123456789abcdef";
    int count = 0;

    if (nbr == 0)
        return (ft_putchar('0'));
    if (nbr >= 16)
        count += ft_puthexa(nbr / 16);
    count += ft_putchar(base[nbr % 16]);
    return (count);
}

int ft_printf(const char *str, ...)
{
    int i = 0;
    va_list args;
    int count = 0;

    va_start(args, str);
    while (str[i])
    {
        if (str[i] == '%' && str[i + 1])
        {
            i++;
            if (str[i] == 's')
                count += ft_putstr(va_arg(args, char *));
            else if (str[i] == 'd')
                count += ft_putnbr(va_arg(args, int));
            else if (str[i] == 'x')
                count += ft_puthexa(va_arg(args, unsigned int));
            i++;
        }
        else
        {
            count += ft_putchar(str[i]);
            i++;
        }
    }
    va_end(args);
    return (count);
}

int main()
{
    printf("\n%d\n", printf("%s, %d, %x", "fatheddine", -21334, -29420));
    ft_printf("\n%d\n", ft_printf("%s, %d, %x", "fatheddine", -21334, -29420));
}
