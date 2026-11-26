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
    int new_word;
    char c;

    i = 0;
    new_word = 1;
    while (s[i])
    {
        c = s[i];
        if (c == ' ' || c == '\t')
        {
            write(1, &c, 1);
            new_word = 1;
        }
        else
        {
            if (new_word)
            {
                if (is_alpha(c))
                    c = to_upper(c);
                new_word = 0;
            }
            else if (is_alpha(c))
                c = to_lower(c);
            write(1, &c, 1);
        }
        i++;
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