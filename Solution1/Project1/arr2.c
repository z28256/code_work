#define _CRT_SECURE_NO_WARNINGS 1

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// 1.存在重复元素 (排序)
// 2.旋转数组 (交换/临时数组)
// 3.有效的字母异位词(hash)


// 存在重复元素

// 给你一个整数数组nums,如果任一值在数组中出现至少两次,返回true;如果数组中每个元素互不相同,返回false

// 先进行排序,如果有重复的值,一定会是相邻的,比较相邻的数组元素

#include <stdbool.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

bool containsDuplicate(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 1; i < numsSize; ++i)
    {
        if (nums[i] == nums[i - 1])
        {
            return true;
        }
    }
    return false;
}



// 旋转数组

// 给定一个整数数组nums,将数组中的元素向右轮转k个位置,其中k是非负数


//将数组的元素向右移动k次后,尾部k % n个元素会移动至数组头部,其余元素向后移动k % n个位置。
//可以先将所有元素翻转,这样尾部的k % n个元素就被移至数组头部,然后再翻转[0,k % n-1]区间的元素和[k % n,n-1]区间的元素

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void reverse(int* nums, int start, int end)
{
    while (start < end)
    {
        // swap函数的参数为指针类型, 所以需要取地址
        swap(&nums[start], &nums[end]);
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k)
{
    //翻转numsSize个字符等于没变,也就是每翻转numsSize个为一个循环,当k大于numsSize时等价于k%numsSize
    k %= numsSize; 
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);

}



//遍历原数组,将原数组下标为i的元素放至新数组下标为(i + k) mod n的位置,最后将新数组拷贝至原数组即可。

#include <stdlib.h>

void rotate(int* nums, int numsSize, int k) {
    int* arr = (int*)malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; ++i)
    {
        arr[(i + k) % numsSize] = nums[i];
    }
    for (int i = 0; i < numsSize; ++i)
    {
        nums[i] = arr[i];
    }
}



// 有效的字母异位词

//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
//注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。


bool isAnagram(char* s, char* t)
{
    if (strlen(s) != strlen(t))
    {
        return false;
    }

    int arr[26] = { 0 }; 
    for (int i = 0; i < strlen(s); ++i)
    {
        arr[s[i] - 'a']++;
    }
    for (int i = 0; i < strlen(t); ++i)
    {
        arr[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != 0)
        {
            return false;
        }
    }
    return true;
}
