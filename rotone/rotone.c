

#include <unistd.h>
#include <stdio.h>

int is_upper(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}
int is_lower(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}
int is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

int pos_check(char c)
{
    int pos = 0;
    if (is_upper(c) == 1)
    {
        pos = c - (90 - 26);
        return pos;
    }
    if (is_lower(c) == 1)
    {
        pos = c - (122 - 26);
        return pos;
    }
    return 0;
}

void printchar(char c)
{
    write(1, &c, 1);
}

int main(int c, char **v)
{
    if (c != 2)
    {
        printchar('\n');
        return 1;
    }
    int i = 0;
    while (v[1][i] != '\0')
    {
        char n = v[1][i];
        if ((n >= 'a' && n <= 'y') || (n >= 'A' && n <= 'Y'))
        {
            n = n + 1;
            printchar(n);
        }
        else if (n == 'z' || n == 'Z')
        {
            n = n - 25;
            printchar(n);
        }
        else
        {
            printchar(n);
        }
        i++;
    }
    printchar('\n');
    return 0;
}