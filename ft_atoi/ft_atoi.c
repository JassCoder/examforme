
#include <stdio.h>

int ft_atoi(const char *str)
{
    int res = 0;
    int i = 0;
    int sign = 1;

    if (str[i] == '-' || str[0] == '+')
    {
        if (str[i] == '-')
            sign = -sign;
        i++;
    }

    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }

    return res * sign;
}
// int main(int c, char **v)
// {
//     if (c != 2)
//     {
//         return 0;
//     }
//     char *abc = v[1];
//     printf("%d", ft_atoi(abc));
//     printf("\n");
// }