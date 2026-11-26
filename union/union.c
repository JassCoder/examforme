#include <unistd.h>
#include <stdio.h>

void printchar(char c)
{
    write(1, &c, 1);
}
int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
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
    int i = 0;
    char *first = v[1];
    char *second = v[2];
    while (first[i])
    {
        if (!seen(first, i, first[i]))
            printchar(first[i]);
        i++;
    }
    int end = ft_strlen(first);
    int j = 0;
    while (second[j])
    {
        if (!seen(first, end, second[j]) && !seen(second, j, second[j]))
            printchar(second[j]);
        j++;
    }

    printchar('\n');
    return 0;
}