#include <stdio.h>

#define MAX_SIZE 100

int main()
{
    int n, a, count = 0;
    scanf("%d", &n);
    long arr[MAX_SIZE];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if (a > 0)
        {
            arr[count] = 1l * a * a;
            count++;
        }
    }
    for (int i = count - 1; i >= 0; i--)
    {
        printf("%ld\n", arr[i]);
    }
    printf("%d", count);
    return 0;
}
