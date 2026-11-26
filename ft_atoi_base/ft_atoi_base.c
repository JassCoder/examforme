static int is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

static int digit_value(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10);
    if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10);
    return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
    int i;
    int sign;
    int result;
    int d;

    if (!str || str_base < 2 || str_base > 16)
        return (0);
    i = 0;
    sign = 1;
    result = 0;
    while (is_space(str[i]))
        i++;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;
    while (str[i])
    {
        d = digit_value(str[i]);
        if (d < 0 || d >= str_base)
            break;
        result = result * str_base + d;
        i++;
    }
    return (sign * result);
}