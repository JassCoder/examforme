

#include <unistd.h>
#include <stdio.h>

int is_upper(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}
int is_lower(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

int pos_check(char c)
{
    int pos = 0;
    if (is_upper(c) == 1)
    {
        pos = c - (90 - 26);
        return pos;
    }
    if (is_lower(c) == 1)
    {
        pos = c - (122 - 26);
        return pos;
    }
    return 0;
}

void printchar(char c)
{
    write(1, &c, 1);
}

int main(int c, char **v)
{
    if (c != 2)
    {
        printchar('\n');
        return 1;
    }
    int i = 0;
    while (v[1][i])
    {
        char ch = v[1][i];
        int posi = pos_check(ch);

        if (posi > 0)                  // letter: repeat posi times
        {
            while (posi > 0)
            {
                printchar(ch);
                posi--;
            }
        }
        else                           // non-letter: print once
        {
            printchar(ch);
        }
        i++;
    }
    printchar('\n');
    return 0;
}