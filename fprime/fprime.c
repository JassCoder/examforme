#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    long n;
    long d;
    int first;

    if (argc != 2)
    {
        printf("\n");
        return (0);
    }
    n = atoi(argv[1]);
    if (n == 1)
    {
        printf("1\n");
        return (0);
    }
    first = 1;
    d = 2;
    while (d * d <= n)
    {
        while (n % d == 0)
        {
            if (!first)
                printf("*");
            printf("%ld", d);
            first = 0;
            n /= d;
        }
        d++;
    }
    if (n > 1)
    {
        if (!first)
            printf("*");
        printf("%ld", n);
    }
    printf("\n");
    return (0);
}
