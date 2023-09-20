#define _CRT_SECURE_NO_WARNINGS 1


// 1.买卖股票的最佳时机
// 2.两数之和
// 3.移动零


// 买卖股票的最佳时机

// 给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
// 在每一天，你可以决定是否购买和 / 或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
// 返回 你能获得的 最大 利润 。


// 当后一天大于前一天的股票价格时,进行累加

int maxProfit(int* prices, int pricesSize)
{
    int profit = 0;
    for (int i = 1; i < pricesSize; ++i)
    {
        if (prices[i] > prices[i - 1])
        {
            profit += prices[i] - prices[i - 1];
        }
    }
    return profit;
}



// 两数之和

//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
//你可以按任意顺序返回答案。


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    for (int i = 0; i < numsSize - 1; ++i)
    {
        for (int j = i + 1; j < numsSize; ++j)
        {
            if (nums[j] == target - nums[i])
            {
                ret[0] = i;
                ret[1] = j;
            }
        }
    }
    return ret;
}


// 移动零

//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//请注意 ，必须在不复制数组的情况下原地对数组进行操作。


void moveZeroes(int* nums, int numsSize)
{
    int i = 0, j = 0;
    while (j < numsSize)
    {
        if (nums[j] != 0)
        {
            nums[i++] = nums[j];
        }
        ++j;
    }
    while (i < numsSize)
    {
        nums[i++] = 0;
    }
}












