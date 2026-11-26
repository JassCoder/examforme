#include <stdlib.h>

static int is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

static int count_words(char *s)
{
    int count = 0;
    int in_word = 0;
    int i = 0;

    while (s[i])
    {
        if (!is_space(s[i]) && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (is_space(s[i]))
            in_word = 0;
        i++;
    }
    return (count);
}

static char *dup_word(char *s, int start, int len)
{
    char *w;
    int i = 0;

    w = (char *)malloc(sizeof(char) * (len + 1));
    if (!w)
        return (NULL);
    while (i < len)
    {
        w[i] = s[start + i];
        i++;
    }
    w[len] = '\0';
    return (w);
}

char **ft_split(char *str)
{
    char **res;
    int words;
    int k;
    int i;
    int start;

    if (!str)
        str = "";
    words = count_words(str);
    res = (char **)malloc(sizeof(char *) * (words + 1));
    if (!res)
        return (NULL);
    res[words] = NULL;
    i = 0;
    k = 0;
    while (str[i])
    {
        while (str[i] && is_space(str[i]))
            i++;
        start = i;
        while (str[i] && !is_space(str[i]))
            i++;
        if (i > start)
        {
            res[k] = dup_word(str, start, i - start);
            if (!res[k])
            {
                // cleanup on failure
                while (k > 0)
                    free(res[--k]);
                free(res);
                return (NULL);
            }
            k++;
        }
    }
    return (res);
}