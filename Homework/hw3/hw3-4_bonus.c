#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int price, type;
    int count = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("\n(%*[^,],%d,%d)", &price, &type);
        if (type == ans)
        {
            count += price;
        }
        else if (price < count)
        {
            count -= price;
        }
        else if (price > count)
        {
            count = price - count;
            ans = type;
        }
    }

    printf("%d", ans);

    return 0;
}