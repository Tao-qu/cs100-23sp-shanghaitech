#include <stdio.h>
#include <math.h>

#define EPSILON 0.001

int main()
{
    int a, b, c;
    double x1, x2, delta;
    scanf("%d%d%d", &a, &b, &c);

    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                printf("x\\in\\mathbb{R}");
            }
            else
            {
                printf("No solution.");
            }
        }
        else
        {
            printf("x = %.3f", (double)-c / b);
        }
    }
    else
    {
        delta = b * b - 4 * a * c;
        if (fabs(delta) < EPSILON)
        {
            x1 = x2 = -b / (2.0 * a);
            printf("x1 = x2 = %.3f", x1);
        }
        else if (delta > 0)
        {
            x1 = (-b + sqrt(delta)) / (2.0 * a);
            x2 = (-b - sqrt(delta)) / (2.0 * a);
            if (x1 < x2)
            {
                printf("x1 = %.3f, x2 = %.3f", x1, x2);
            }
            else
            {
                printf("x1 = %.3f, x2 = %.3f", x2, x1);
            }
        }
        else
        {
            printf("No solution.");
        }
    }

    return 0;
}
