#include <unistd.h>

void printchar(char c)
{
    write(1, &c, 1);
}

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

int seen(char *s, int end, char c)
{
    int k = 0;
    while (k < end)
    {
        if (s[k] == c)
            return 1;
        k++;
    }
    return 0;
}

int main(int c, char **v)
{
    if (c != 3)
    {
        printchar('\n');
        return 0;
    }
    char *first = v[1];
    char *second = v[2];
    int len2 = ft_strlen(second);
    int i = 0;

    while (first[i])
    {
        if (!seen(first, i, first[i]) && seen(second, len2, first[i]))
            printchar(first[i]);
        i++;
    }
    printchar('\n');
    return 0;
}