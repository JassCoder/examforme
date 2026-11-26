#include <unistd.h>
#include <stdio.h>

void printchar(char c)
{
    write(1, &c, 1);
}

int to_upper(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}
int to_lower(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

int pos_check(char c)
{
    int pos = 0;
    if (to_upper(c) == 1)
    {
        pos = c - (90 - 26);
        return pos;
    }
    if (to_lower(c) == 1)
    {
        pos = c - (122 - 26);
        return pos;
    }
    return (int)c;
}
// int is_alpha(char c)
// {
//     if (to_upper(c) == 1 || to_lower(c) == 1)
//         return 1;
//     return 0;
// }

int main(int c, char **v)
{
    if (c != 2)
    {
        printchar('\n');
        return 0;
    }
    int i = 0;
    while (v[1][i])
    {
        char xyz = v[1][i];
        int pos = pos_check(xyz);
        if (to_upper(xyz) == 1)
        {
            xyz = 91 - pos;
            printchar(xyz);
        }
        else if (to_lower(xyz) == 1)
        {
            xyz = 123 - pos;
            printchar(xyz);
        }
        else
            printchar(xyz);
        i++;
    }
    printchar('\n');
    return 0;
}