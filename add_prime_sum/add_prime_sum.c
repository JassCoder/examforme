#include <unistd.h>

static void put_nbr(long n)
{
    char c;

    if (n >= 10)
        put_nbr(n / 10);
    c = '0' + (n % 10);
    write(1, &c, 1);
}

static int is_prime(int n)
{
    int d;

    if (n < 2)
        return (0);
    d = 2;
    while (d * d <= n)
    {
        if (n % d == 0)
            return (0);
        d++;
    }
    return (1);
}

static int parse_positive(char *s)
{
    long n;
    int i;

    if (!s || !s[0])
        return (-1);
    n = 0;
    i = 0;
    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return (-1);
        n = n * 10 + (s[i] - '0');
        if (n > 2147483647L)
            return (-1);
        i++;
    }
    if (n <= 0)
        return (-1);
    return ((int)n);
}

int main(int argc, char **argv)
{
    int n;
    int i;
    long sum;

    if (argc != 2)
    {
        write(1, "0\n", 2);
        return (0);
    }
    n = parse_positive(argv[1]);
    if (n < 0)
    {
        write(1, "0\n", 2);
        return (0);
    }
    sum = 0;
    i = 2;
    while (i <= n)
    {
        if (is_prime(i))
            sum += i;
        i++;
    }
    put_nbr(sum);
    write(1, "\n", 1);
    return (0);
}