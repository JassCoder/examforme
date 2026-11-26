#include <stdio.h>

int main(int c, char **v)
{
    if (c != 3)
    {
        printf("\n");
        return 0;
    }
    int i = 0;
    int j = 0;

    while (v[1][i] && v[2][j])
    {
        if (v[1][i] == v[2][j])
            i++;
        j++;
    }
    if (v[1][i] == '\0')
    {
        i = 0;
        while (v[1][i] != '\0')
        {
            printf("%c", v[1][i]);
            i++;
        }
    }
    printf("\n");
    return 0;
}