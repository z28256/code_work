#define _CRT_SECURE_NO_WARNINGS 1

// 1.图书整理 I
// 2.删除链表节点
// 3.只出现一次的数字 


#include <stdlib.h>

// 图书整理 I
// 书店店员有一张链表形式的书单，每个节点代表一本书，节点中的值表示书的编号。为更方便整理书架，
// 店员需要将书单倒过来排列，就可以从最后一本书开始整理，逐一将书放回到书架上。请倒序返回这个书单链表。


struct ListNode {
    int val;
    struct ListNode* next;
};

int* reverseBookList(struct ListNode* head, int* returnSize)
{
    *returnSize = 0;
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp = head;
    while (temp)
    {
        temp = temp->next;
        (*returnSize)++;
    }
    int* ans = (int*)malloc(sizeof(int) * *returnSize);
    for (int i = *returnSize - 1; i >= 0; --i)
    {
        ans[i] = head->val;
        head = head->next;
    }
    return ans;
}


// 删除链表节点
//给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
//返回删除后的链表的头节点。


struct ListNode* deleteNode(struct ListNode* head, int val)
{
    struct ListNode* prev = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* ans = (struct ListNode*)malloc(sizeof(struct ListNode));
    prev->next = head;
    ans = prev;
    while (prev->next->val != val)
    {
        prev = prev->next;
    }
    prev->next = prev->next->next;
    return ans->next;
}


// 只出现一次的数字 

//给你一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 
//找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。
//你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。


//使用按位与运算符&与-x提取x的最低1位的原因,在于二进制补码的取反操作在位级别上的工作原理。
//在二进制补码中取反一个数字, 实际上是“翻转”所有位。所以 - x将是x的二进制补码。
//举个例子, 如果x是1010(十进制10), 那么 - x将是0101(十进制 - 10)。
//现在, 如果我们对一个数字和它的补码进行按位与操作, 除最低的1位外, 其他所有位将变为0。
//这是因为在按位与操作中, 两个位都必须为1才能产生1作为结果。除最低1位外, 其他位在两个操作数中至少有一个位将为0。
//所以x & -x仅保留x和它的补码中共同拥有的最低1位。这使我们通过简单的按位与操作就可以轻松提取x的最低1位。

int* singleNumber(int* nums, int numsSize, int* returnSize)
{
    int xorsum = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        xorsum ^= nums[i];
    }
    
    // 方法一
    // INT_MIN: 100000...0
    int lsb = (xorsum == INT_MIN ? xorsum : xorsum & (-xorsum));

    // 方法二
    //long long lsb = 1; // int会越界
    //while ((lsb & xorsum) == 0) {
    //    lsb <<= 1;
    //}

    int type1 = 0, type2 = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        if (nums[i] & lsb)
        {
            type1 ^= nums[i];
        }
        else
        {
            type2 ^= nums[i];
        }
    }
    int* ans = (int*)malloc(sizeof(int) * 2);
    ans[0] = type1;
    ans[1] = type2;
    *returnSize = 2;
    return ans;
}

