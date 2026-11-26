#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int *res;
    long size;
    long i = 0;
    int step;

    if (start <= end)
    {
        size = (long)end - (long)start + 1;
        step = -1;
    }
    else
    {
        size = (long)start - (long)end + 1;
        step = 1;
    }
    res = (int *)malloc(sizeof(int) * (size_t)size);
    if (!res)
        return (NULL);
    while (i < size)
    {
        res[i] = end + (int)(step * i);
        i++;
    }
    return (res);
}