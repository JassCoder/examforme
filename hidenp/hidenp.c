#include <unistd.h>

int main(int argc, char **argv)
{
    char *s1;
    char *s2;
    int i;
    int j;

    if (argc != 3)
    {
        write(1, "\n", 1);
        return (0);
    }
    s1 = argv[1];
    s2 = argv[2];
    i = 0;
    j = 0;
    while (s2[j] && s1[i])
    {
        if (s1[i] == s2[j])
            i++;
        j++;
    }
    if (!s1[i])
        write(1, "1\n", 2);
    else
        write(1, "0\n", 2);
    return (0);
}