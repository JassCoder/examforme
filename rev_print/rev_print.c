

#include <unistd.h>
#include <stdio.h>

void printchar(char c)
{
    write(1, &c, 1);
}

int main(int c, char **v)
{
    if (c != 2)
    {
        printf("\n");
        return (0);
    }
    int last = 0;

    while(v[1][last])
        last++;
    last = last - 1;

    while(last >= 0)
    {
        printchar(v[1][last]);
        last--;
    }
    printf("\n");
    return 0;
}