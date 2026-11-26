#include <stdlib.h>

static int ft_num_len(long nb)
{
    int count = 1;

    if (nb < 0)
    {
        nb = -nb;
        count++;
    }
    while (nb >= 10)
    {
        nb /= 10;
        count++;
    }
    return (count);
}

char *ft_itoa(int n)
{
    char *str;
    long nb;
    int len;
    int neg;

    nb = n;
    neg = (nb < 0);
    len = ft_num_len(nb);
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    str[len] = '\0';
    if (neg)
        nb = -nb;
    while (len-- > 0)
    {
        str[len] = (nb % 10) + '0';
        nb /= 10;
        if (neg && len == 0)
            str[0] = '-';
    }
    return (str);
}