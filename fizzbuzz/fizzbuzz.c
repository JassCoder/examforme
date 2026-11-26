#include <unistd.h>

void	printchar(char c)
{
	write(1, &c, 1);
}

void	printstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		printchar(str[i]);      /* str[i], not i */
		i++;
	}
	/* no newline here — let the caller decide */
}

void	ft_putnb(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		printchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnb(nb / 10);
	printchar(nb % 10 + '0');
}

int	main(void)
{
	int i = 1;
	while (i <= 100)
	{
		if (i % 15 == 0)
			printstr("fizzbuzz");
		else if (i % 3 == 0)
			printstr("fizz");
		else if (i % 5 == 0)
			printstr("buzz");
		else
			ft_putnb(i);
		printchar('\n');
		i++;
	}
	return (0);
}