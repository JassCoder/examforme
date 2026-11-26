#include <unistd.h>

static void put_nbr(int n)
{
    char c;

    if (n >= 10)
        put_nbr(n / 10);
    c = '0' + (n % 10);
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int n;

    (void)argv;
    n = argc - 1;
    put_nbr(n);
    write(1, "\n", 1);
    return (0);
}