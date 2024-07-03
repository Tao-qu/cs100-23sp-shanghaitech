#include <stdio.h>

int main() 
{
    int x1, y1, x2, y2;
    double k, b;

    // Input the coordinates of the two points
    scanf("(%d, %d)\n", &x1, &y1);
    scanf("(%d, %d)", &x2, &y2);

    // Calculate the slope (k) and y-intercept (b)
    if (x1 == x2) 
    {
        // The line is vertical
        printf("x = %.2f\n", x1 + 0.0);
    } 
    else 
    {
        k = (y2 - y1 + 0.0) / (x2 - x1);
        b = y1 - k * x1 + 0.0;
        if (b >= 0) 
        {
            printf("y = %.2fx + %.2f\n", k, b);
        } 
        else 
        {
            printf("y = %.2fx - %.2f\n", k, -b);
        }
    }

    return 0;
}
