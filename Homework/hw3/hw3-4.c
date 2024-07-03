#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

int main()
{
    int n;
    scanf("%d", &n);
    int price[MAX_SIZE]; 
    int type[MAX_SIZE];
    for (int i = 0; i < n; i++)
    {
        scanf("\n(%*[^,],%d,%d)", &price[i], &type[i]);
    }

    int total = 0;
    for (int j = 0; j < n; j++)
    {
        total += price[j];
    }

    int sum[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
    {
        sum[i] = 0;
    }
    for (int i = 0; i < MAX_SIZE; i++)
    {
        sum[type[i]] += price[i];
    }

    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (sum[i] > (total / 2))
        {
            printf("%d", i);
        }
    }
    return 0;
}