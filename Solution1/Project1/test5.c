#define _CRT_SECURE_NO_WARNINGS 1


// 1.位1的个数
// 2.删除并获得点数
// 3.不同路径


// 位1的个数

// 编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为汉明重量）。

#include <stdint.h>

// 在C语言中，uint32_t是一个无符号32位整数类型，它定义在头文件stdint.h中。

int hammingWeight(uint32_t n)
{
    int count = 0;
    for (int i = 0; i < 32; ++i)
    {
        if (n >> i & 1)
        {
            count++;
        }
    }
    return count;
}


// 删除并获得点数

//给你一个整数数组 nums ，你可以对它进行一些操作。
//每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素。
//开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。


int rob(int* nums, int numsSize)
{
    int first = nums[0], second = nums[0] > nums[1] ? nums[0] : nums[1];
    for (int i = 2; i < numsSize; ++i)
    {
        int temp = second;
        second = first + nums[i] > second ? first + nums[i] : second;
        first = temp;
    }
    return second;
}


int deleteAndEarn(int* nums, int numsSize)
{
    int maxVal = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        maxVal = maxVal > nums[i] ? maxVal : nums[i];
    }
    int* sum = (int*)calloc(maxVal + 1, sizeof(int));
    for (int i = 0; i < numsSize; ++i)
    {
        sum[nums[i]] += nums[i];
    }
    return rob(sum, maxVal + 1);
}


// 不同路径

// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
//问总共有多少条不同的路径？

int uniquePaths(int m, int n)
{
    // (m + n - 2)! / (m - 1)!(n - 1)!
    // (m + n - 2)(m + n - 3)...n / (m - 1)!
    long long ans = 1;
    for (int x = n, y = 1; y < m; ++x, ++y)
    {
        ans = ans * x / y;
    }
    return ans;
}


int uniquePaths(int m, int n)
{
    int f[m][n];
    for (int i = 0; i < m; ++i)
    {
        f[i][0] = 1;
    }
    for (int j = 0; j < n; ++j)
    {
        f[0][j] = 1;
    }
    for (int i = 1; i < m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    return f[m - 1][n - 1];
}

