#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_R 500
#define MAX_C 500
#define MAX_Q 100000

int main()
{
    int row, col, hint;
    scanf("%d %d %d", &row, &col, &hint);
    getchar();

    char dir[MAX_R][MAX_C];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%c", &dir[i][j]);
            getchar();
        }
    }

    int row_leading, col_leading;
    scanf("%d %d", &row_leading, &col_leading);
    getchar();

    char hint_word[MAX_Q][6];
    int hint_num[MAX_Q];
    for (int i = 0; i < hint; i++)
    {
        scanf("%s %d", hint_word[i], &hint_num[i]);
        getchar();
    }

    for (int i = 0; i < hint; i++)
    {
        if (dir[row_leading - 1][col_leading - 1] == 'L')
        {
            if (strcmp(hint_word[i], "Left") == 0)
            {
                dir[row_leading - 1][col_leading - 1] = 'P';
                row_leading += hint_num[i];
            }
            else if (strcmp(hint_word[i], "Right") == 0)
            {
                dir[row_leading - 1][col_leading - 1] = 'P';
                row_leading -= hint_num[i];
            }
            else if (strcmp(hint_word[i], "Front") == 0)
            {
                dir[row_leading - 1][col_leading - 1] = 'P';
                col_leading -= hint_num[i];
            }
            else if (strcmp(hint_word[i], "Back") == 0)
            {
                dir[row_leading - 1][col_leading - 1] = 'P';
                col_leading += hint_num[i];
            }
            else
            {
                printf("Hint_word Error: %s in step %d", hint_word[i], i + 1);
                break;
            }
        }
        else if (dir[row_leading - 1][col_leading - 1] == 'R')
        {
            if (strcmp(hint_word[i], "Left") == 0)
            {
                dir[row_leading - 1][col_leading - 1] = 'P';
                row_leading -= hint_num[i];
            }
            else if (strcmp(hint_word[i], "Right") == 0)
            {
                dir[row_leading - 1][col_leading - 1] = 'P';
                row_leading += hint_num[i];
            }
            else if (strcmp(hint_word[i], "Front") == 0)
            {
                dir[row_leading - 1][col_leading - 1] = 'P';
                col_leading += hint_num[i];
            }
            else if (strcmp(hint_word[i], "Back") == 0)
            {
                dir[row_leading - 1][col_leading - 1] = 'P';
                col_leading -= hint_num[i];
            }
            else
            {
                printf("Hint_word Error: %s in step %d", hint_word[i], i + 1);
                break;
            }
        }
        else if (dir[row_leading - 1][col_leading - 1] == 'U')
        {
            if (strcmp(hint_word[i], "Left") == 0)
            {
                dir[row_leading - 1][col_leading - 1] = 'P';
                col_leading -= hint_num[i];
            }
            else if (strcmp(hint_word[i], "Right") == 0)
            {
                dir[row_leading - 1][col_leading - 1] = 'P';
                col_leading += hint_num[i];
            }
            else if (strcmp(hint_word[i], "Front") == 0)
            {
                dir[row_leading - 1][col_leading - 1] = 'P';
                row_leading -= hint_num[i];
            }
            else if (strcmp(hint_word[i], "Back") == 0)
            {
                dir[row_leading - 1][col_leading - 1] = 'P';
                row_leading += hint_num[i];
            }
            else
            {
                printf("Hint_word Error: %s in step %d", hint_word[i], i + 1);
                break;
            }
        }
        else if (dir[row_leading - 1][col_leading - 1] == 'D')
        {
            if (strcmp(hint_word[i], "Left") == 0)
            {
                dir[row_leading - 1][col_leading - 1] = 'P';
                col_leading += hint_num[i];
            }
            else if (strcmp(hint_word[i], "Right") == 0)
            {
                dir[row_leading - 1][col_leading - 1] = 'P';
                col_leading -= hint_num[i];
            }
            else if (strcmp(hint_word[i], "Front") == 0)
            {
                dir[row_leading - 1][col_leading - 1] = 'P';
                row_leading += hint_num[i];
            }
            else if (strcmp(hint_word[i], "Back") == 0)
            {
                dir[row_leading - 1][col_leading - 1] = 'P';
                row_leading -= hint_num[i];
            }
            else
            {
                printf("Hint_word Error: %s in step %d", hint_word[i], i + 1);
                break;
            }
        }
        else
        {
            printf("Direction Error: dir[%d][%d] = \'%c\'", row_leading, col_leading, dir[row_leading - 1][col_leading - 1]);
            break;
        }

        if (dir[row_leading - 1][col_leading - 1] != 'P'&&row_leading <= row && row_leading > 0 && col_leading <= col && col_leading > 0)
        {
            printf("(%d, %d)\n", row_leading, col_leading);
        }
        else
        {
            printf("Mistake!");
            break;
        }
    }

    return 0;
}