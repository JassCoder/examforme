#include <unistd.h>

void print_char(char c)
{
    write(1, &c, 1);
}

int main(int c, char **v)
{
    if (c != 2)
    {
        print_char('\n');
        return 0;
    }
    int i = 0;

    while (v[1][i])
    {
        char abc = v[1][i];
        if (abc == '_')
        {
            i++;
            abc = v[1][i] - 32;
            print_char(abc);
        }
        else
            print_char(abc);
        i++;
    }
    print_char('\n');
    return 0;
}