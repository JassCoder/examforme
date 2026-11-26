unsigned char reverse_bits(unsigned char octet)
{
    unsigned char result = 0;
    int i = 0;
    int bit;

    while (i < 8)
    {
        bit = (octet >> i) & 1;             // extract bit i
        result = result | (bit << (7 - i)); // place at mirrored position
        i++;
    }
    return (result);
}