#include <unistd.h>

void printchar(char c)
{
    write(1, &c, 1);
}

int is_upper(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}

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
        if (is_upper(xyz) == 1)
        {
            printchar('_');
            xyz = xyz + 32;
            printchar(xyz);
        }
        else
        {
            printchar(xyz);
        }
        i++;
    }
    printchar('\n');
    return 0;
}