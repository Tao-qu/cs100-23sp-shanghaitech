#include <stdio.h>

int lowbit(unsigned long long x)
{
    for (int i = 0; i != 64; i++)
    {
        if (x % 2 == 1)
        {
            return i;
        }
        else
        {
            x /= 2;
        }
    }
    return -1;
}

int main()
{
    unsigned long long x;
    int m;

    scanf("%llu %d", &x, &m);

    unsigned long long temp = x;
    int n = 0;
    while (temp > 0)
    {
        n++;
        temp >>= 1;
    }

    unsigned long long p = x & ((1ll << (m + 1)) - 1);
    unsigned long long q = x >> (m + 1);

    unsigned long long y = (p << (n - m - 1)) + q;

    printf("%llu %d", y, lowbit(y));

    return 0;
}