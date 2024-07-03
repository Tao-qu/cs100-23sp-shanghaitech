#include <stdio.h>
#include <string.h>

#define MAX_SIZE 51

int ctn(char c)
{
    if (c < 'a')
    {
        return c - '0';
    }
    else
    {
        return c + 10 - 'a';
    }
}

int ntc(int n)
{
    if (n < 10)
    {
        return n + '0';
    }
    else
    {
        return n - 10 + 'a';
    }
}

void del0(char *p, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        if (*p == '0')
        {
            for (int j = 0; j < len - i; j++)
            {
                *(p + j) = *(p + j + 1);
            }
            *(p + len - i - 1) = '\0';
        }
        else
        {
            break;
        }
    }
}

int main()
{
    char op;
    char a[MAX_SIZE], b[MAX_SIZE], r[MAX_SIZE] = "0";
    int lena, lenb, lenr, len, carry, temp;

    scanf("%c", &op);
    scanf("%s\n%s", a, b);

    lena = strlen(a);
    lenb = strlen(b);

    if (lena < lenb)
    {
        for (int i = lena - 1; i >= 0; i--)
        {
            a[i + lenb - lena] = a[i];
        }
        for (int i = 0; i < lenb - lena; i++)
        {
            a[i] = '0';
        }
        len = lenb;
    }
    else
    {
        for (int i = lenb - 1; i >= 0; i--)
        {
            b[i + lena - lenb] = b[i];
        }
        for (int i = 0; i < lena - lenb; i++)
        {
            b[i] = '0';
        }
        len = lena;
    }

    if (op == '+')
    {
        carry = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            temp = ctn(a[i]) + ctn(b[i]) + carry;
            r[i] = ntc(temp % 16);
            carry = temp / 16;
        }
    }
    else
    {
        carry = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            temp = ctn(a[i]) - ctn(b[i]) - carry;
            if (temp < 0)
            {
                temp += 16;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            r[i] = ntc(temp);
        }
    }

    del0(&a[0], len);
    del0(&b[0], len);
    del0(&r[0], len);

    lena = strlen(a);
    lenb = strlen(b);
    lenr = strlen(r);

    for (int i = 0; i < len - lena + 1; i++)
    {
        printf(" ");
    }
    printf("%s\n%c", a, op);
    for (int i = 0; i < len - lenb; i++)
    {
        printf(" ");
    }
    printf("%s\n", b);
    for (int i = 0; i < len + 1; i++)
    {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < len - lenr + 1; i++)
    {
        printf(" ");
    }
    printf("%s", r);

    return 0;
}
