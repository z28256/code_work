#define _CRT_SECURE_NO_WARNINGS 1

// 1.汉明距离
// 2.颠倒二进制位
// 3.杨辉三角
// 4.找出数组的串联值


// 汉明距离

//两个整数之间的 汉明距离 指的是这两个数字对应二进制位不同的位置的数目。
//给你两个整数 x 和 y，计算并返回它们之间的汉明距离。

int hammingDistance(int x, int y)
{
    int count = 0;
    int n = x ^ y;
    while (n)
    {
        n &= n - 1;
        ++count;
    }
    return count;
}


// 颠倒二进制位

//颠倒给定的 32 位无符号整数的二进制位。

#include <stdint.h>  

uint32_t reverseBits(uint32_t n)
{
    uint32_t ret = 0;
    for (int i = 0; i < 32; ++i)
    {
        ret |= (n & 1) << (31 - i);
        n >>= 1;
    }
    return ret;
}


// 杨辉三角

//给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
//在「杨辉三角」中，每个数是它左上方和右上方的数的和。

int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    *returnSize = numRows;
    int** ret = (int**)malloc(sizeof(int*) * numRows);
    *returnColumnSizes = (int*)malloc(sizeof(int) * numRows);
    for (int i = 0; i < numRows; ++i)
    {
        (*returnColumnSizes)[i] = i + 1;
        ret[i] = (int*)malloc(sizeof(int*) * (i + 1));
        ret[i][0] = ret[i][i] = 1;
        for (int j = 1; j < i; ++j)
        {
            ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
        }
    }
    return ret;
}



//找出数组的串联值

// 给你一个下标从 0 开始的整数数组 nums 。
//现定义两个数字的 串联 是由这两个数值串联起来形成的新数字。
//
//例如，15 和 49 的串联是 1549 。
//nums 的 串联值 最初等于 0 。执行下述操作直到 nums 变为空：
//
//如果 nums 中存在不止一个数字，分别选中 nums 中的第一个元素和最后一个元素，将二者串联得到的值加到 nums 的 串联值 上，然后从 nums 中删除第一个和最后一个元素。
//如果仅存在一个元素，则将该元素的值加到 nums 的串联值上，然后删除这个元素。
//返回执行完所有操作后 nums 的串联值。


// 1 <= nums.length <= 1000
//1 <= nums[i] <= 10^4


long long add(int n, int m)
{
    n *= 10;
    int temp = m;
    while (temp /= 10)
    {
        n *= 10;
    }
    return n + m;
}

/*long long add(int n, int m)
{
    if (m < 10)
        return n * 10 + m;
    else if (m < 100)
        return n * 100 + m;
    else if (m < 1000)
        return n * 1000 + m;
    else if (m < 10000)
        return n * 10000 + m;
    else
        return n * 100000 + m;
}*/

long long findTheArrayConcVal(int* nums, int numsSize)
{
    long long ret = 0;
    int left = 0, right = numsSize - 1;
    while (left < right)
    {
        ret += add(nums[left], nums[right]);
        ++left;
        --right;
    }
    if (left == right)
    {
        ret += nums[left];
    }
    return ret;
}







