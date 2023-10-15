#define _CRT_SECURE_NO_WARNINGS 1

// 1.Excel表列序号
// 2.多数元素
// 3.只出现一次的数字 II


// Excel表列序号
// 给你一个字符串 columnTitle ，表示 Excel 表格中的列名称。返回 该列名称对应的列序号 。

//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28
//...


int titleToNumber(char* columnTitle)
{
    int ret = 0;
    int index = 0;
    while (columnTitle[index])
    {
        ret = columnTitle[index++] - 'A' + 1 + ret * 26;
    }
    return ret;
}


// 多数元素

//给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n / 2 ⌋ 的元素。
//你可以假设数组是非空的，并且给定的数组总是存在多数元素。


int cmp(const void* n1, const void* n2)
{
    return *(int*)n1 - *(int*)n2;
}

int majorityElement(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    return nums[numsSize / 2];
}


// 只出现一次的数字 II

// 给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。
//你必须设计并实现线性时间复杂度的算法且使用常数级空间来解决此问题。

// 答案的第 i 个二进制位就是数组中所有元素的第 i 个二进制位之和除以 3 的余数。

int singleNumber(int* nums, int numsSize)
{
    int ans = 0;
    for (int i = 0; i < 32; ++i)
    {
        int total = 0;
        for (int j = 0; j < numsSize; ++j)
        {
            total += (nums[j] >> i) & 1;
        }
        if (total % 3)
        {
            ans |= (1u << i);
        }
    }
    return ans;
}

