#define _CRT_SECURE_NO_WARNINGS 1

// 1. 缺失数字
// 2. 3的幂
// 3. 字符串中的第一个唯一字符


// 缺失数字

//给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。

int missingNumber(int* nums, int numsSize)
{
    int sum = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        sum += nums[i];
    }
    return (1 + numsSize) * numsSize / 2 - sum;
}


//3的幂

//给定一个整数，写一个函数来判断它是否是 3 的幂次方。如果是，返回 true ；否则，返回 false 。
//整数 n 是 3 的幂次方需满足：存在整数 x 使得 n == 3x

#include <stdbool.h>

bool isPowerOfThree(int n)
{
    if (n <= 0)
    {
        return false;
    }
    long i;
    for (i = 1; i < n; i *= 3)
    {
        ;
    }
    return i == n ? true : false;
}


// 字符串中的第一个唯一字符

// 给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。

int firstUniqChar(char* s)
{
    int hash[26] = { 0 };
    for (int i = 0; i < strlen(s); ++i)
    {
        hash[s[i] - 'a']++;
    }

    for (int i = 0; i < strlen(s); ++i)
    {
        if (hash[s[i] - 'a'] == 1)
        {
            return i;
        }
    }
    return -1;
}