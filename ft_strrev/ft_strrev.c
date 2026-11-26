int ft_strlen(char *c)
{
    int i = 0;
    while (c[i])
        i++;
    return i;
}

void ft_swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

char *ft_strrev(char *str)
{
    int i = 0;
    int j = ft_strlen(str) - 1;

    while (i < j)
    {
        ft_swap(&str[i], &str[j]);
        i++;
        j--;
    }
    return str;
}