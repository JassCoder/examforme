#include <unistd.h>

void printchar(char c)
{
    write(1, &c, 1);
}
int is_space(char c)
{
    if (c == ' ')
        return 1;
    return 0;
}

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

int main(int c, char **v)
{
    if (c != 2)
    {
        printchar('\n');
        return 0;
    }
    int last = ft_strlen(v[1]) - 1;
    int start = 0;
    int end = 0;
    while (last > 0 && is_space(v[1][last]))
        last--;
    end = last + 1;
    while (last > 0 && !is_space(v[1][last]))
        last--;
    start = last + 1;
    while (start < end)
    {
        printchar(v[1][start]);
        start++;
    }
    printchar('\n');
    return 0;
}
