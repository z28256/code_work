#define _CRT_SECURE_NO_WARNINGS 1

// 1.实现 strStr()
// 2.合并两个有序数组
// 3.第一个错误的版本 (二分)


// 1.实现 strStr()

//给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
//如果 needle 不是 haystack 的一部分，则返回  - 1 。

int strStr(char* haystack, char* needle)
{
    int index1 = 0;
    int index2 = 0;
    int reset = 0;
    while (haystack[index1])
    {
        // 如果一次失败,下一次index1可以从上一次的下一个元素开始, index2可以从0开始
        index1 = reset;
        index2 = 0;
        // 在index1没有越界访问的情况下,判断haystack[index1]与needle[index2]是否相同,如果不同,index1++
        while (haystack[index1] && haystack[index1] != needle[index2])
        {
            index1++;
        }
        // 将reset赋值为index1+1, 如果一次判断失败,下次可以从这次的下一个字母开始
        reset = index1 + 1;

        // 如果haystack剩下的长度小于needle, 直接返回-1
        if (strlen(haystack) - index1 < strlen(needle))
        {
            return -1;
        }
        while (haystack[index1] == needle[index2])
        {
            // 如果needle[index2 + 1]为结束字符,这证明找到了对应的字符串,下标为reset - 1
            if (!needle[index2 + 1])
            {
                return reset - 1;
            }
            index1++;
            index2++;
        }
    }
    return -1;
}


// 2.合并两个有序数组

//给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
//请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
//注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，
//其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    // 如果n == 0, 证明只有nums1有元素, 直接返回即可
    if (n == 0)
    {
        return;
    }
    int index1 = m - 1, index2 = n - 1;
    int index = m + n - 1;

    // 倒序将两个数组的较大值放入到nums1中的最后
    // 保证nums1和nums2不越界访问,index1,index2均应大于0
    while (index1 >= 0 && index2 >= 0)
    {
        // index一直减一,index1和index2哪个元素大,哪个减一
        nums1[index--] = nums1[index1] > nums2[index2] ? nums1[index1--] : nums2[index2--];
    }

    //因为是将元素放到nums1中,所以当index1 < 0 后, 还需要将nums2中的元素放到nums1中, 而不需要在index2小于0后,移动nums1中的元素

    while (index2 >= 0)
    {
        nums1[index--] = nums2[index2--];
    }
}


// 3.第一个错误的版本 (二分)

//假设你有 n 个版本[1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。
//你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。


// bool isBadVersion(int version);

int firstBadVersion(int n)
{
    int left = 1, right = n;
    int mid;
    // 如果第一个版本就是错误的,也就是mid = 1, mid - 1 = 0, 但mid - 1不可能为0,
    // 因为版本是从1开始的,所以需要在开头判断第一个版本是否错误
    if (isBadVersion(1))
    {
        return 1;
    }
    while (left <= right)
    {
        mid = (right - left) / 2 + left;
        if (isBadVersion(mid) && !isBadVersion(mid - 1))
        {
            break;
        }
        else if (isBadVersion(mid))
        {
            // right可以等于mid - 1, 如果mid - 1的版本是正确的,会进入上一个if语句
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return mid;
}



