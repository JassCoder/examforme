#include <unistd.h>

static int is_alpha(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

static char to_upper(char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

static char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}

static void process(char *s)
{
    int i;
    int start;
    int end;
    int last;
    int k;
    char c;

    i = 0;
    while (s[i])
    {
        if (s[i] == ' ' || s[i] == '\t')
        {
            write(1, &s[i], 1);
            i++;
            continue ;
        }
        start = i;
        while (s[i] && s[i] != ' ' && s[i] != '\t')
            i++;
        end = i;
        last = end - 1;
        if (!is_alpha(s[last]))
            last = -1;
        k = start;
        while (k < end)
        {
            c = s[k];
            if (is_alpha(c))
            {
                if (k == last)
                    c = to_upper(c);
                else
                    c = to_lower(c);
            }
            write(1, &c, 1);
            k++;
        }
    }
}

int main(int argc, char **argv)
{
    int i;

    if (argc < 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = 1;
    while (i < argc)
    {
        process(argv[i]);
        write(1, "\n", 1);
        i++;
    }
    return (0);
}