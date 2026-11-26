#include <stdlib.h>

int *ft_range(int start, int end)
{
    int *res;
    long size;
    long i;
    int step;

    if (start <= end)
    {
        size = (long)end - (long)start + 1;
        step = 1;
    }
    else
    {
        size = (long)start - (long)end + 1;
        step = -1;
    }
    res = (int *)malloc(sizeof(int) * (size_t)size);
    if (!res)
        return (NULL);
    i = 0;
    while (i < size)
    {
        res[i] = start + (int)(step * i);
        i++;
    }
    return (res);
}