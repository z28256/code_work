#define _CRT_SECURE_NO_WARNINGS 1

// 1.删除有序数组中的重复项 (快慢指针)
// 2.只出现一次的数字 (异或)
// 3.反转字符串 (交换)



// 删除有序数组中的重复项
//给你一个升序排列的数组 nums ，请你原地删除重复出现的元素，使每个元素只出现一次 ，返回删除后数组的新长度。
//元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。


int removeDuplicates(int* nums, int numsSize)
{
    // 如果数组的元素个数为0或者1, 一定不存在重复项,直接返回numSize
    if (numsSize == 0 || numsSize == 1)
    {
        return numsSize;
    }
    //快慢指针,将left和right的初始值都设为1,让right与right-1处的数组值进行比较
    int left = 1, right = 1;
    while (right < numsSize)
    {
        //如果nums[right]与nums[right - 1]不相同,就将nums[right]的值赋给nums[left],并将left++
        if (nums[right] != nums[right - 1])
        {
            nums[left++] = nums[right];
        }
        //right的值无论是否与前一个相同都需要++
        right++;
    }
    //最后当right==numsSize的时候,此时left移动到唯一元素的下一位,也就是nums中唯一元素的个数
    return left;
}



//只出现一次的数字

//给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

//异或

//a^ a = 0；自己和自己异或等于0
//a ^ 0 = a；任何数字和0异或还等于他自己
//a ^ b ^ c = a ^ c ^ b；异或运算具有交换律

int singleNumber(int* nums, int numsSize)
{
    int ret = 0;
    for (int i = 0; i < numsSize; i++)
    {
        ret ^= nums[i];
    }
    return ret;
}


//反转字符串

//编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。

void reverseString(char* s, int sSize)
{
    char temp ;
    int left = 0, right = sSize - 1;

    while (left < right)
    {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}



