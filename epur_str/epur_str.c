#include <unistd.h>

static int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

int main(int argc, char **argv)
{
    char *s;
    int i;
    int first;

    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    s = argv[1];
    i = 0;
    first = 1;
    while (s[i])
    {
        while (s[i] && is_space(s[i]))
            i++;
        if (!s[i])
            break ;
        if (!first)
            write(1, " ", 1);
        while (s[i] && !is_space(s[i]))
        {
            write(1, &s[i], 1);
            i++;
        }
        first = 0;
    }
    write(1, "\n", 1);
    return (0);
}