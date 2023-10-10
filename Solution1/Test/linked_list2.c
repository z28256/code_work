#define _CRT_SECURE_NO_WARNINGS 1

//1. 回文链表
//2. 环形链表
//3. 二叉树的最大深度


// 回文链表

// 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。


#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
 
// 反转链表
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr)
    {
        struct ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

// 通过快慢指针找到链表的中间节点

struct ListNode* endOfFirstHalf(struct ListNode* head)
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

bool isPalindrome(struct ListNode* head)
{
    if (!head)
    {
        return true;
    }

    // 中间节点1(一共有两个中间节点, 这是前一个)
    struct ListNode* firstHalfEnd = endOfFirstHalf(head);
    //反转后半部分链表, 此时有两个指针指向后半部分的最后一个节点(也就是中间节点2),而该结点指向NULL
    struct ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

    struct ListNode* p1 = head;
    struct ListNode* p2 = secondHalfStart;
    bool result = true;
    // p2不为NULL就证明后半部分链表没有结束
    while (result && p2)
    {
        if (p1->val != p2->val)
        {
            result = false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    // 将后半部分链表恢复原状
    firstHalfEnd->next = reverseList(secondHalfStart);
    return result;
}



// 环形链表

//给你一个链表的头节点 head ，判断链表中是否有环。
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
//为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
//注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
//如果链表中存在环 ，则返回 true 。 否则，返回 false 。


bool hasCycle(struct ListNode* head) 
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}



// 二叉树的最大深度

// 给定一个二叉树 root ，返回其最大深度。
//二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    
};


int maxDepth(struct TreeNode* root)
{
    if (!root)
    {
        return 0;
    }
    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);
    return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
}
