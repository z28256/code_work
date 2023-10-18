#define _CRT_SECURE_NO_WARNINGS 1

// 1.链表合并
// 2.链表交点
// 3.数组的奇偶分离

struct ListNode {
    int val;
    struct ListNode* next;
};


// 给定两个以 有序链表 形式记录的训练计划 l1、l2，分别记录了两套核心肌群训练项目编号，请合并这两个训练计划，
// 按训练项目编号 升序 记录于链表并返回。
// 注意：新链表是通过拼接给定的两个链表的所有节点组成的。

#include <stdlib.h>

struct ListNode* trainningPlan(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* ans = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* temp = ans;

    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            temp->next = l1;
            l1 = l1->next;
        }
        else
        {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }

    temp->next = l1 ? l1 : l2;
    return ans->next;
}


// 某教练同时带教两位学员，分别以链表 l1、l2 记录了两套核心肌群训练计划，节点值为训练项目编号。
// 两套计划仅有前半部分热身项目不同，后续正式训练项目相同。请设计一个程序找出并返回第一个正式训练项目编号。
// 如果两个链表不存在相交节点，返回 null 。

// l1: 前面有a-c个节点,相交后有c个节点
// l2: 前面有b-c个节点,相交后有c个节点

// p1的路程: a+(b-c)
// p2的路程: b+(a-c)

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* p1 = headA, * p2 = headB;
    while (p1 != p2)
    {
        p1 = p1 ? p1->next : headB;
        p2 = p2 ? p2->next : headA;
    }
    return p1;
}

// 教练使用整数数组 actions 记录一系列核心肌群训练项目编号。
// 为增强训练趣味性，需要将所有奇数编号训练项目调整至偶数编号训练项目之前。
// 请将调整后的训练项目编号以 数组 形式返回。


int* trainingPlan(int* actions, int actionsSize, int* returnSize)
{
    int* ans = (int*)malloc(sizeof(int) * actionsSize);
    *returnSize = actionsSize;
    int index1 = 0, index2 = actionsSize - 1;
    for (int i = 0; i < actionsSize; ++i)
    {
        if (actions[i] % 2)
        {
            ans[index1++] = actions[i];
        }
        else
        {
            ans[index2--] = actions[i];
        }
    }
    return ans;
}

