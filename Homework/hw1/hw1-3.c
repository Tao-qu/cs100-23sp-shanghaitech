#include <stdio.h>

// function to convert 1-9 to English
void print_ones(int num)
{
    switch (num)
    {
    case 1:
        printf("one");
        break;
    case 2:
        printf("two");
        break;
    case 3:
        printf("three");
        break;
    case 4:
        printf("four");
        break;
    case 5:
        printf("five");
        break;
    case 6:
        printf("six");
        break;
    case 7:
        printf("seven");
        break;
    case 8:
        printf("eight");
        break;
    case 9:
        printf("nine");
        break;
    }
}

// function to convert 10-19 to English
void print_teens(int num)
{
    switch (num)
    {
    case 10:
        printf("ten");
        break;
    case 11:
        printf("eleven");
        break;
    case 12:
        printf("twelve");
        break;
    case 13:
        printf("thirteen");
        break;
    case 14:
        printf("fourteen");
        break;
    case 15:
        printf("fifteen");
        break;
    case 16:
        printf("sixteen");
        break;
    case 17:
        printf("seventeen");
        break;
    case 18:
        printf("eighteen");
        break;
    case 19:
        printf("nineteen");
        break;
    }
}

// function to convert 20-99 to English
void print_tens(int num)
{
    switch (num)
    {
    case 2:
        printf("twenty");
        break;
    case 3:
        printf("thirty");
        break;
    case 4:
        printf("forty");
        break;
    case 5:
        printf("fifty");
        break;
    case 6:
        printf("sixty");
        break;
    case 7:
        printf("seventy");
        break;
    case 8:
        printf("eighty");
        break;
    case 9:
        printf("ninety");
        break;
    }
}

// function to convert 0-999 to English
void print_number(int num)
{
    if (num == 0)
    {
        printf("zero");
    }
    else
    {
        int hundreds = num / 100;
        int tens = (num / 10) % 10;
        int ones = num % 10;

        if (hundreds > 0)
        {
            print_ones(hundreds);
            printf(" hundred");
            if (tens > 0 || ones > 0)
            {
                printf(" and ");
            }
        }

        if (tens == 1)
        {
            print_teens(tens * 10 + ones);
        }
        else if (tens > 1)
        {
            print_tens(tens);
            if (ones > 0)
            {
                printf("-");
                print_ones(ones);
            }
        }
        else if (ones > 0)
        {
            print_ones(ones);
        }
    }
}

int main()
{
    int num;
    scanf("%d", &num);
    
    //convert 0-999 to English
    if (num < 1000)
    {
        print_number(num);
    }
    
    //convert 1000 to English
    else if (num == 1000)
    {
        printf("one thousand");
    }
    
    //convert 1001-999999 to English
    else
    { 
        print_number(num / 1000);
        printf(" thousand ");
        if ((num % 1000) == 0)
        {
        }
        else if((num % 1000) > 99)
        {
            print_number(num % 1000);
        }
        else
        {
            printf("and ");
            print_number(num % 1000);
        }
    }
    return 0;
}