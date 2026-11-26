#include <unistd.h>

void printchar(char c)
{
    write(1, &c, 1);
}
int iss_space(char c)
{
    if (c == ' ')
        return 1;
    return 0;
}

void print_str(char *str)
{
    int i = 0;
    while (str[i])
    {
        printchar(str[i]);
        i++;
    }
}

int slen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}
int main(int c, char **v)
{
    if (c != 2)
    {
        printchar('\n');
        return 0;
    }
    int last = slen(v[1]) - 1;
    int w_start;
    int w_end;

    while (last >= 0)
    {
        while (last >= 0 && iss_space(v[1][last]))
            last--;
        if (last < 0)
            break;
        w_end = last;
        while (last >= 0 && !iss_space(v[1][last]))
            last--;
        w_start = last + 1;
        while (w_start <= w_end)
        {
            printchar(v[1][w_start]);
            w_start++;
        }
        if (last > 0)
            printchar(' ');
    }
    printchar('\n');
    return 0;
}