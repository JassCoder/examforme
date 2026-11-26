#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int c, char **v)
{
    if (c != 4)
    {
        printf("\n");
        return 0;
    }
    int num1 = atoi(v[1]);
    int num2 = atoi(v[3]);
    char sign = v[2][0];
    int ans = 0;

    if (sign == '+')
        ans = num1 + num2;
    else if (sign == '-')
        ans = num1 - num2;
    else if (sign == '*')
        ans = num1 * num2;
    else if (sign == '/')
    {
        if (num2 == 0)
            return 1;
        ans = num1 / num2;
    }
    else if (sign == '%')
    {
        ans = num1 % num2;
    }
    printf("%d", ans);
    printf("\n");

    return 0;
}