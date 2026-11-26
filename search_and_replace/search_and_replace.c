// #include <unistd.h>

// void printchar(char c)
// {
//     write(1, &c, 1);
// }

// void printstr(char *c)
// {
//     int i = 0;
//     while (c[i])
//     {
//         printchar(c[i]);
//         i++;
//     }
// }

// int check_char(char a, char b)
// {
//     if (a == b)
//         return 1;
//     return 0;
// }

// int main(int c, char **v)
// {

//     if (c != 4)
//     {
//         printchar('\n');
//         return 0;
//     }
//     if (!v[2][0] || !v[3][0])
//     {
//         printstr(v[1]);
//         printchar('\n');
//         return 0;
//     }

//     // char find = v[2][0];
//     // char rep = v[3][0];
//     int i = 0;
//     // printchar(rep);
//     // printchar(find);

//     while (v[1][i])
//     {
//         // char xyz = v[1][i];
//         if (check_char(v[1][i], v[2][0]) == 1)
//             printchar(v[3][0]);
//         else
//             printchar(v[1][i]);
//         ++i;
//     }
//     printchar('\n');
//     return 0;
// }

#include <unistd.h>

void printchar(char c)
{
    write(1, &c, 1);
}

int main(int c, char **v)
{
    if (c != 4)
    {
        printchar('\n');
        return 0;
    }

    if (!v[2][0] || !v[3][0])
    {
        printchar('\n');
        return 0;
    }
    if (v[2][1] || v[3][1])
    {
        printchar('\n');
        return 0;
    }

    int i = 0;
    while (v[1][i])
    {
        if (v[1][i] == v[2][0])
            printchar(v[3][0]);
        else
            printchar(v[1][i]);
        i++;
    }
    printchar('\n');
    return 0;
}