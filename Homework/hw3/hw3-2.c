#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define KEYWORD_SIZE 102
#define CIPHERTEXT_SIZE 1000002

int main()
{
    char keyword[KEYWORD_SIZE], ciphertext[CIPHERTEXT_SIZE];

    fgets(keyword, KEYWORD_SIZE, stdin);
    fgets(ciphertext, CIPHERTEXT_SIZE, stdin);

    int keyword_len = strlen(keyword) - 1;
    keyword[keyword_len] = '\0';

    for (int i = 0; i < keyword_len; i++)
    {
        keyword[i] = tolower(keyword[i]);
    }

    int freq[26];
    for (int i = 0; i < keyword_len; i++)
    {
        freq[keyword[i] - 'a']++;
    }

    char encoding[27];
    int j = 0;
    for (int i = 0; i < keyword_len; i++)
    {
        if (freq[keyword[i] - 'a'] > 0)
        {
            encoding[j] = keyword[i];
            freq[keyword[i] - 'a'] = -1;
            j++;
        }
    }

    int encoding_len = strlen(encoding);
    int k = (encoding[encoding_len - 1] - 'a' + 1) % 26;
    for (int i = encoding_len; i < 26; i++)
    {
        while (freq[k] < 0)
        {
            k = (k + 1) % 26;
        }
        encoding[i] = k + 'a';
        k = (k + 1) % 26;
    }

    int ciphertext_len = strlen(ciphertext);
    for (int i = 0; i < ciphertext_len; i++)
    {
        char c = ciphertext[i];
        if (isalpha(c))
        {
            char offset = isupper(c) ? 'A' : 'a';
            for (j = 0; j < 26; j++)
            {
                if (encoding[j] == tolower(ciphertext[i]))
                {
                    printf("%c", j + offset);
                    break;
                }
            }
        }
        else
        {
            printf("%c", ciphertext[i]);
        }
    }

    return 0;
}