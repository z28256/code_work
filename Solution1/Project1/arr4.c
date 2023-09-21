#define _CRT_SECURE_NO_WARNINGS 1

//1. 两个数组的交集(排序+双指针 / hash)
//2. 加一(倒序遍历,判断元素值是否为9)


#include <stdlib.h>

// 两个数组的交集 

//给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。
//返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。
//可以不考虑输出结果的顺序。


//1 <= nums1.length, nums2.length <= 1000
//0 <= nums1[i], nums2[i] <= 1000


//(1)通过 hash 数组先统计nums1中的数字出现次数,然后在遍历nums2数组时,将nums2中也出现的数字添加到ret中


int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) 
{
    int* ret = (int*)malloc(sizeof(int) * 1001);
    int* hash = (int*)calloc(1001, sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < nums1Size; ++i)
    {
        hash[nums1[i]]++;
    }

    for (int i = 0; i < nums2Size; ++i)
    {
        if (hash[nums2[i]] > 0)
        {
            ret[(*returnSize)++] = nums2[i];
            hash[nums2[i]]--;
        }
    }
    return ret;
}


//(2)先排序然后再使用双指针获得两个数组共同的元素

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    *returnSize = 0;
    int* ret = (int*)malloc(sizeof(int) * nums1Size);
    int index1 = 0, index2 = 0;
    while (index1 < nums1Size && index2 < nums2Size)
    {
        if (nums1[index1] < nums2[index2])
        {
            index1++;
        }
        else if (nums1[index1] > nums2[index2])
        {
            index2++;
        }
        else
        {
            ret[(*returnSize)++] = nums1[index1++];
            // index1向后移动之后,index2也要向后移动,不然会出现同一元素进行多次匹配
            index2++;
        }
    }
    return ret;
}



// 加一

//给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
//最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
//你可以假设除了整数 0 之外，这个整数不会以零开头。


//倒序遍历,如果最后一项不是9,也就是不用进位,直接加一,返回digit数组就行
//如果最后一项是9,但不是全都是9,也会返回digit数组
//如果数组元素全都是9,需要返回的数组比digit多一个元素,使用calloc创建全为0的数组,然后将ret[0]赋值为1

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    for (int i = digitsSize - 1; i >= 0; --i)
    {
        if (digits[i] != 9)
        {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        else
        {
            digits[i] = 0;
        }
    }
    *returnSize = digitsSize + 1;
    int* ret = (int*)calloc(*returnSize, sizeof(int));
    ret[0] = 1;
    return ret;
}


