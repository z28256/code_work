#define _CRT_SECURE_NO_WARNINGS 1

// 1.整数反转
// 2.验证回文串
// 3.最长公共前缀


// 整数反转

// 给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

//如果反转后整数超过 32 位的有符号整数的范围 [−231, 231 − 1] ，就返回 0。
//假设环境不允许存储 64 位整数（有符号或无符号）。


// 32位范围: [-2^31, 2^31 - 1], 也就是 ret * 10 + x % 10  的范围

// x > 0

// INT_MAX : 2147483647
// INT_MAX = INT_MAX / 10 * 10 + INT_MAX % 10
// INT_MAX = INT_MAX / 10 * 10 + 7

// ret * 10 + x % 10 <= INT_MAX / 10 * 10 + 7
// (ret - INT_MAX / 10) * 10 <= 7 - x % 10

//1. ret > INT_MAX / 10 : 此时左侧大于10, 一定不成立
//2. ret = INT_MAX / 10 : x % 10 <= 7 时,成立
//3. ret < INT_MAX / 10 : 此时左侧小于-10, 成立

// 因为INT_MAX最大值为2147483647, 如果出现反转后越界的情况, x的位数一定与INT_MAX相同, 
//也就是在ret = INT_MAX / 10 的情况下, x % 10 的取值一定会小于等于2,也就是ret <= INT_MAX/10,一定成立

// x < 0, 同理


#include <limits.h>

int reverse(int x)
{
    int ret = 0;
    while (x)
    {
        if (ret < INT_MIN / 10 || ret > INT_MAX / 10)
        {
            return 0;
        }
        ret = ret * 10 + x % 10;
        x /= 10;
    }
    return ret;
}



// 验证回文串

//如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。

//字母和数字都属于字母数字字符。
//给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。


#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isPalindrome(char* s)
{
    int left = 0, right = strlen(s) - 1;
    while (left < right)
    {
        while (!isalnum(s[left]) && left < right)
        {
            left++;
        }
        while (!isalnum(s[right]) && left < right)
        {
            right--;
        }
        if (tolower(s[left]) == tolower(s[right]))
        {
            left++;
            right--;
        }
        else
        {
            return false;
        }
    }
    return true;
}


// 最长公共前缀

//编写一个函数来查找字符串数组中的最长公共前缀。
//如果不存在公共前缀，返回空字符串 ""。


char* longestCommonPrefix(char** strs, int strsSize)
{
    if (strsSize == 0)
    {
        return "";
    }
    int len = strlen(strs[0]);
    for (int i = 1; i < strsSize; ++i)
    {
        len = len > strlen(strs[i]) ? strlen(strs[i]) : len;
    }

    char* pre = (char*)calloc(len + 1, sizeof(char));
    for (int i = 0; i < len; ++i)
    {
        pre[i] = strs[0][i];
    }

    for (int i = 1; i < strsSize; ++i)
    {
        for (int j = 0; j < len; ++j)
        {
            if (pre[j] != strs[i][j])
            {
                pre[j] = '\0';
                break;
            }
        }
        if (pre[0] == '\0')
        {
            return "";
        }
    }
    return pre;

}