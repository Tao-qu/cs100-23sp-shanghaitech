#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CIPHERTEXT_SIZE 1000001

int main()
{
    long long n;
    char ciphertext[CIPHERTEXT_SIZE];
    scanf("%lld\n", &n);
    fgets(ciphertext, CIPHERTEXT_SIZE, stdin);

    int length = strlen(ciphertext);
    for (int i = 0; i < length; i++)
    {
        char c = ciphertext[i];
        if (isalpha(c))
        {
            char offset = isupper(c) ? 'A' : 'a';
            long long temp = (c - offset + 1 - n) % 26;
            c = (temp > 0) ? temp - 1 + offset : temp + 25 + offset;
        }
        else if (isdigit(c))
        {
            char offset = '0';
            long long temp = (c - offset - n) % 10;
            c = (temp >= 0) ? temp + offset : temp + 10 + offset;
        }
        printf("%c", c);
    }

    return 0;
}