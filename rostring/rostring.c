#include <unistd.h>

static int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

int main(int argc, char **argv)
{
    int i;
    int start;
    int end;
    int first;
    int first_end;
    int printed;

    if (argc < 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    if (!argv[1])
        return (0);

    // skip leading whitespace
    i = 0;
    while (is_space(argv[1][i]))
        i++;

    // identify first word [start, end)
    start = i;
    while (argv[1][i] && !is_space(argv[1][i]))
        i++;
    end = i;
    first = start;
    first_end = end;

    printed = 0;

    // print the rest of the words (after first)
    while (argv[1][i])
    {
        // skip whitespace
        while (is_space(argv[1][i]))
            i++;
        if (!argv[1][i])
            break;
        if (printed)
            write(1, " ", 1);
        // print word
        while (argv[1][i] && !is_space(argv[1][i]))
        {
            write(1, &argv[1][i], 1);
            i++;
        }
        printed = 1;
    }

    // if there was at least one word, print first word
    if (first < first_end)
    {
        if (printed)
            write(1, " ", 1);
        i = first;
        while (i < first_end)
        {
            write(1, &argv[1][i], 1);
            i++;
        }
    }

    write(1, "\n", 1);
    return (0);
}