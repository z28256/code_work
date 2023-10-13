#define _CRT_SECURE_NO_WARNINGS 1

// 1.搜索二维矩阵 II
// 2.颜色分类
// 3.两整数之和


//搜索二维矩阵 II
//编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
//
//每行的元素从左到右升序排列。
//每列的元素从上到下升序排列。

#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int row = 0, col = *matrixColSize - 1;
    while (row < matrixSize && col >= 0)
    {
        if (matrix[row][col] > target)
        {
            --col;
        }
        else if (matrix[row][col] < target)
        {
            ++row;
        }
        else
        {
            return true;
        }
    }
    return false;
}


bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    for (int i = 0; i < matrixSize; ++i)
    {
        if (matrix[i][0] <= target && matrix[i][*matrixColSize - 1] >= target)
        {
            int left = 0, right = *matrixColSize - 1;
            while (left <= right)
            {
                int mid = (left + right) / 2;
                if (matrix[i][mid] == target)
                {
                    return true;
                }
                else if(matrix[i][mid] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
    }
    return false;
}



//颜色分类
//
//给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
//我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
//必须在不使用库内置的 sort 函数的情况下解决这个问题。

//n == nums.length
//1 <= n <= 300
//nums[i] 为 0、1 或 2


void swap(int* nums, int n1, int n2)
{
    int temp = nums[n1];
    nums[n1] = nums[n2];
    nums[n2] = temp;
}

void sortColors(int* nums, int numsSize)
{
    int left = 0, right = numsSize - 1;
    for (int i = 0; i <= right; ++i)
    {
        if (nums[i] == 0)
        {
            swap(nums, left, i);
            left++;
        }
        if (nums[i] == 2)
        {
            swap(nums, i, right);
            right--;
            i--;
        }
    }
}


void sortColors(int* nums, int numsSize)
{
    int color[3] = {0};
    for (int i = 0; i < numsSize; ++i)
    {
        color[nums[i]]++;
    }
    int index = 0;
    for (int i = 0; i < 3; ++i)
    {
        while(color[i]--)
        {
            nums[index++] = i;
        }
    }
}


//两整数之和
//给你两个整数 a 和 b ，不使用 运算符 + 和 - ​​​​​​​，计算并返回两整数之和。

// 使用(unsigned int)是将操作数a和b转换为无符号整数。这样可以确保在a & b的运算中，结果不会受到符号位的影响。
// 因为&运算符对符号位也进行逻辑与运算，可能会导致结果的符号位与预期不符。

// 不能使用long long, 因为long long是有符号整数，所以在进行a & b运算时，可能会受到符号位的影响

int getSum(int a, int b)
{
    if (!a)
    {
        return b;
    }
    return getSum((unsigned int)(a & b) << 1, a ^ b);
}


 int getSum(int a, int b)
 {
     while (b)
     {
         int temp = (unsigned int)(a & b) << 1;
         a ^= b;
         b = temp;
     }
     return a;
 }

