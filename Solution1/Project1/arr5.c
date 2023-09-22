#define _CRT_SECURE_NO_WARNINGS 1

// 1. 有效的数独
// 2. 旋转图像



// 1. 有效的数独

//数字 1 - 9 在每一行只能出现一次。
//数字 1 - 9 在每一列只能出现一次。
//数字 1 - 9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    int row[9][9] = { 0 };
    int col[9][9] = { 0 };
    int box[3][3][9] = { 0 };
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            char c = board[i][j];
            if (c != '.')
            {
                int index = c - '1';
                row[i][index]++;
                col[j][index]++;
                box[i / 3][j / 3][index]++;
                if (row[i][index] > 1 || col[j][index] > 1 || box[i / 3][j / 3][index] > 1)
                {
                    return false;
                }
            }
        }
    }
    return true;
}



// 2.旋转图像

//给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
//你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。


void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    for (int i = 0; i < matrixSize / 2; ++i)
    {
        for (int j = 0; j < (matrixSize + 1) / 2; ++j)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize - j - 1][i];
            matrix[matrixSize - j - 1][i] = matrix[matrixSize - i - 1][matrixSize - j - 1];
            matrix[matrixSize - i - 1][matrixSize - j - 1] = matrix[j][matrixSize - i - 1];
            matrix[j][matrixSize - i - 1] = temp;
        }
    }
}

