#define _CRT_SECURE_NO_WARNINGS 1

// 动态规划
// 1. 买卖股票的最佳时机
// 2. 打家劫舍
// 3. 最大子数组和


// 买卖股票的最佳时机

//给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
//你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
//返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

#include <limits.h>

int maxProfit(int* prices, int pricesSize)
{
    int max = 0;
    int min = INT_MAX;
    for (int i = 0; i < pricesSize; ++i)
    {
        if (prices[i] < min)
        {
            min = prices[i];
        }
        else if (prices[i] - min > max)
        {
            max = prices[i] - min;
        }
    }
    return max;
}



// 打家劫舍

//如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。


int rob(int* nums, int numsSize)
{
    if (nums == NULL || numsSize == 0)
    {
        return 0;
    }
    if (numsSize == 1)
    {
        return nums[0];
    }

    // 数组模拟实现

    //int* dp = (int*)calloc(numsSize, sizeof(int));
    //dp[0] = nums[0];
    //dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
    //for (int i = 2; i < numsSize; ++i)
    //{
    //    dp[i] = dp[i - 1] > dp[i - 2] + nums[i] ? dp[i - 1] : dp[i - 2] + nums[i];
    //}

    //return dp[numsSize - 1];
    
    int first = nums[0];
    int second = nums[0] > nums[1] ? nums[0] : nums[1];
    for (int i = 2; i < numsSize; ++i)
    {
        int temp = second;
        second = second > first + nums[i] ? second : first + nums[i];
        first = temp;
    }

    return second;
}


// 最大子数组和

// 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//子数组 是数组中的一个连续部分。

int maxSubArray(int* nums, int numsSize)
{
    int* dp = (int*)calloc(numsSize, sizeof(int));
    dp[0] = nums[0];

    int max = dp[0];

    for (int i = 1; i < numsSize; ++i)
    {
        dp[i] = dp[i - 1] > 0 ? dp[i - 1] + nums[i] : nums[i];
        max = max > dp[i] ? max : dp[i];
    }

    return max;
}



