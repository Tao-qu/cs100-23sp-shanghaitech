#include <stdio.h>
#include <string.h>

int is_palindrome(int date)
{
    if (date / 10000000 == date % 10 && date / 1000000 % 10 == date / 10 % 10 && date / 100000 % 10 == date / 100 % 10 && date / 10000 % 10 == date / 1000 % 10)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int m, d[100];
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &d[i]);
    }

    int start, end;
    scanf("%d%d", &start, &end);

    int start_year = start / 10000;
    int end_year = end / 10000;
    int count = 0;
    for (int i = start_year; i <= end_year; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 1; k <= d[j - 1]; k++)
            {
                int date = 10000 * i + 100 * j + k;
                if (date >= start && date <= end)
                {
                    if (is_palindrome(date))
                    {
                        count++;
                    }
                }
            }
        }
    }
    printf("%d", count);
    return 0;
}