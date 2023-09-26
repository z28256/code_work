#define _CRT_SECURE_NO_WARNINGS 1

// 1.字符串转换整数 (atoi)
// 2.计数质数
// 3.递枕头



//字符串转换整数

// 请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。
// 
// 1.读入字符串并丢弃无用的前导空格
// 2.检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
// 3.读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
// 4.将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
// 5.如果整数数超过 32 位有符号整数范围[−231, 231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
// 6.返回整数作为最终结果。


// 本题中的空白字符只包括空格字符 ' ' 。
// 除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。


#include <limits.h>
#include <string.h>
#include <ctype.h>

int myAtoi(char* s)
{
    int flag = 1;
    int i;
    for (i = 0; i < strlen(s); ++i)
    {
        if (s[i] != ' ')
        {
            break;
        }
    }
    if (s[i] == '-')
    {
        flag = 0;
        i++;
    }
    else if (s[i] == '+')
    {
        i++;
    }

    long num = 0;
    while (isdigit(s[i]))
    {
        num = num * 10 + s[i++] - '0';
        if (num > INT_MAX && flag)
        {
            return INT_MAX;
        }
        else if (!flag && -1 * num < INT_MIN)
        {
            return INT_MIN;
        }
    }
    if (flag)
    {
        return num;
    }
    else
    {
        return num * -1;
    }
}



//计数质数(埃氏筛)

// 给定整数 n ，返回 所有小于非负整数 n 的质数的数量

// 如果x是质数,那么大于x的x的倍数2x,3x,...一定不是质数


int countPrimes(int n)
{
    int count = 0;
    int* arr = (int*)calloc(n, sizeof(n));
    for (int i = 2; i < n; ++i)
    {
        if (arr[i])
        {
            continue;
        }
        count++;
        for (int j = i; j < n; j += i)
        {
            arr[j] = 1;
        }
    }
    return count;
}


//递枕头

//n 个人站成一排，按从 1 到 n 编号。
//最初，排在队首的第一个人拿着一个枕头。每秒钟，拿着枕头的人会将枕头传递给队伍中的下一个人。一旦枕头到达队首或队尾，传递方向就会改变，队伍会继续沿相反方向传递枕头。
//
//例如，当枕头到达第 n 个人时，TA 会将枕头传递给第 n - 1 个人，然后传递给第 n - 2 个人，依此类推。
//给你两个正整数 n 和 time ，返回 time 秒后拿着枕头的人的编号。


/*int passThePillow(int n, int time)
{
    int index1 = time / (n - 1);
    int index2 = time % (n - 1);
    return index1 % 2 ? n - index2 : 1 + index2;
}*/


// 每经过 2×(n−1)2 \times (n - 1)2×(n−1) 的时间，枕头会被传递回起点，所以我们可以直接用 time对 2×(n−1)取模求余数。

//如果 time < n, 枕头没有传递到队尾，传递到 time + 1。
//如果 time≥n，枕头已经传递过队尾，传递到 n−(time−(n−1)) = n×2−time−1。
//最后返回结果即可。


int passThePillow(int n, int time)
{
    time %= (n - 1) * 2;
    return time < n ? time + 1 : n - (time - (n - 1));
}
