#include <stdio.h>
#include <stdbool.h>

bool checkOneNumber(int (*board)[9], int row, int col);

int main()
{
    int board[9][9];

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (!checkOneNumber(board, i, j))
            {
                printf("0\n");
                return 0;
            }
        }
    }

    printf("1\n");
    return 0;
}

bool checkOneNumber(int (*board)[9], int row, int col)
{
    int num = board[row][col];

    for (int j = 0; j < 9; j++)
    {
        if (j != col && board[row][j] == num)
        {
            return false;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if (i != row && board[i][col] == num)
        {
            return false;
        }
    }

    int palaceRow = row / 3 * 3;
    int palaceCol = col / 3 * 3;
    for (int i = palaceRow; i < palaceRow + 3; i++)
    {
        for (int j = palaceCol; j < palaceCol + 3; j++)
        {
            if (i != row && j != col && board[i][j] == num)
            {
                return false;
            }
        }
    }

    if (row < 7 && col > 0 && board[row + 2][col - 1] == num)
    {
        return false;
    }
    if (row < 7 && col < 8 && board[row + 2][col + 1] == num)
    {
        return false;
    }
    if (row < 8 && col > 1 && board[row + 1][col - 2] == num)
    {
        return false;
    }
    if (row > 0 && col > 1 && board[row - 1][col - 2] == num)
    {
        return false;
    }

    return true;
}
