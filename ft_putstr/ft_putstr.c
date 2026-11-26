
#include <unistd.h>

void printchar(char c)
{
    write(1, &c, 1);
}
void ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
    {
        printchar(str[i]);
        i++;
    }
}
