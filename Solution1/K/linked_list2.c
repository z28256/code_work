#define _CRT_SECURE_NO_WARNINGS 1

// 1.倍数求和
// 2.链表倒序
// 3.倒数第n个节点

// 倍数求和
//给你一个正整数 n ，请你计算在 [1，n] 范围内能被 3、5、7 整除的所有整数之和。
//返回一个整数，用于表示给定范围内所有满足约束条件的数字之和。

// 方法一：枚举

int sumOfMultiples(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
        {
            sum += i;
        }
    }
    return sum;
}


// 方法二：容斥原理
// 加上3,5,7的倍数,3和5,5和7,3和7都被加了两次,所以需要再减去一次,
// 而3,5,7的共同倍数被加了3次,也被减了3次,所以需要再加一次


// n = 14
// 3 6 9 12
// 3 * (1 + 2 + 3 + 4)

int f(int m, int n) {
    return m * ((1 + n / m) * (n / m) / 2);
}

int sumOfMultiples(int n) {
    return f(3, n) + f(5, n) + f(7, n) - f(3 * 5, n) - f(3 * 7, n) - f(5 * 7, n) + f(3 * 5 * 7, n);
}


// 链表倒序
// 给定一个头节点为 head 的单链表用于记录一系列核心肌群训练编号，请将该系列训练编号 倒序 记录于链表并返回。

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// 方法二：递归

struct ListNode* recur(struct ListNode* cur, struct ListNode* prev)
{
    if (cur == NULL)
    {
        return prev;
    }
    struct ListNode* res = recur(cur->next, cur);
    cur->next = prev;
    return res;
}

struct ListNode* trainningPlan(struct ListNode* head)
{
    return recur(head, NULL);
}

//方法一：迭代（双指针）

struct ListNode* trainningPlan(struct ListNode* head)
{
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    while (cur)
    {
        struct ListNode* temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}


// 倒数第n个节点
// 给定一个头节点为 head 的链表用于记录一系列核心肌群训练项目编号，请查找并返回倒数第 cnt 个训练项目编号。


struct ListNode* trainingPlan(struct ListNode* head, int cnt)
{
    struct ListNode* former = head, * latter = head;
    for (int i = 0; i < cnt; ++i)
    {
        former = former->next;
    }
    while (former)
    {
        former = former->next;
        latter = latter->next;
    }
    return latter;
}


struct ListNode* trainingPlan(struct ListNode* head, int cnt)
{
    int num = 0;
    struct ListNode* temp = head;
    while (temp)
    {
        temp = temp->next;
        num++;
    }
    int n = num - cnt;
    temp = head;
    while (n--)
    {
        temp = temp->next;
    }
    return temp;
}
