

// int max(int *tab, unsigned int len)
// {
//     unsigned int i = 0;
//     int big = 0;

//     while (i <= len)
//     {
//         if (tab[i] > big)
//             big = tab[i];
//         i++;
//     }
//     return big;
// }

int max(int *tab, unsigned int len)
{
    unsigned int i;
    int big;

    if (len == 0 || tab == 0)
        return (0);
    big = tab[0];
    i = 1;
    while (i < len)
    {
        if (tab[i] > big)
            big = tab[i];
        i++;
    }
    return (big);
}
