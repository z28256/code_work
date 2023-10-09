#define _CRT_SECURE_NO_WARNINGS 1

// 1.删除链表中的节点
// 2.删除链表的倒数第N个节点
// 3.反转链表
// 4.合并两个有序链表


// 删除链表中的节点

//有一个单链表的 head，我们想删除它其中的一个节点 node。
//给你一个需要删除的节点 node 。你将 无法访问 第一个节点  head。
//链表的所有值都是 唯一的，并且保证给定的节点 node 不是链表中的最后一个节点。
//删除给定的节点。注意，删除节点并不是指从内存中删除它。这里的意思是：

//给定节点的值不应该存在于链表中。
//链表中的节点数应该减少 1。
//node 前面的所有值顺序相同。
//node 后面的所有值顺序相同。


struct ListNode {
    int val;
    struct ListNode *next;
};
 

void deleteNode(struct ListNode* node)
{
    node->val = node->next->val;
    node->next = node->next->next;
}



// 删除链表的倒数第N个节点

// 方法一：双指针

#include <stdlib.h>

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    dummy->val = 0;
    struct ListNode* first = head;
    struct ListNode* second = dummy;
    for (int i = 0; i < n; ++i)
    {
        first = first->next;
    }
    while (first)
    {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    struct ListNode* ans = dummy->next;
    free(dummy);
    return ans;
}



// 方法二: 计算链表长度

int getLength(struct ListNode* head)
{
    int length = 0;
    while (head)
    {
        ++length;
        head = head->next;
    }
    return length;
}


struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    dummy->val = 0;
    int length = getLength(head);
    struct ListNode* cur = dummy;
    for (int i = 1; i < length - n + 1; ++i)
    {
        cur = cur->next;
    }
    cur->next = cur->next->next;
    struct ListNode* ans = dummy->next;
    free(dummy);
    return ans;
}



// 反转链表

// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。


// 递归

struct ListNode* reverseList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}


// 迭代

struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr)
    {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


// 合并两个有序链表

// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 


// 迭代
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode* preHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* prev = preHead;
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            prev->next = list1;
            list1 = list1->next;
        }
        else
        {
            prev->next = list2;
            list2 = list2->next;
        }
        prev = prev->next;
    }
    prev->next = list1 ? list1 : list2;
    return preHead->next;

}


// 递归
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if (!list1)
    {
        return list2;
    }
    else if(!list2)
    {
        return list1;
    }
    else if(list1->val < list2->val)
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

