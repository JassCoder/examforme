#include <stdlib.h>

static int slen(const char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char *ft_strdup(char *src)
{
    char *res;
    int len;
    int i;

    len = slen(src);
    res = malloc(sizeof(char) * (len + 1));
    if (!res)
        return (NULL);
    i = 0;
    while (src[i] != '\0')
    {
        res[i] = src[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}

// char *ft_strdup(char *src);
// #include <stdlib.h>
// #include <stdio.h>

// int main(int argc, char **argv)
// {
//     if (argc == 1)
//     {
//         printf("ft_strdup(\"\") = %s\n", ft_strdup(""));
//         return (0);
//     }
//     printf("ft_strdup(\"%s\") = %s\n", argv[1], ft_strdup(argv[1]));
//     free(ft_strdup(argv[1]));
//     return (0);
// }