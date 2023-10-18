#define _CRT_SECURE_NO_WARNINGS 1

// 1.����ϲ�
// 2.������
// 3.�������ż����

struct ListNode {
    int val;
    struct ListNode* next;
};


// ���������� �������� ��ʽ��¼��ѵ���ƻ� l1��l2���ֱ��¼�����׺��ļ�Ⱥѵ����Ŀ��ţ���ϲ�������ѵ���ƻ���
// ��ѵ����Ŀ��� ���� ��¼���������ء�
// ע�⣺��������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�

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


// ĳ����ͬʱ������λѧԱ���ֱ������� l1��l2 ��¼�����׺��ļ�Ⱥѵ���ƻ����ڵ�ֵΪѵ����Ŀ��š�
// ���׼ƻ�����ǰ�벿��������Ŀ��ͬ��������ʽѵ����Ŀ��ͬ�������һ�������ҳ������ص�һ����ʽѵ����Ŀ��š�
// ����������������ཻ�ڵ㣬���� null ��

// l1: ǰ����a-c���ڵ�,�ཻ����c���ڵ�
// l2: ǰ����b-c���ڵ�,�ཻ����c���ڵ�

// p1��·��: a+(b-c)
// p2��·��: b+(a-c)

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* p1 = headA, * p2 = headB;
    while (p1 != p2)
    {
        p1 = p1 ? p1->next : headB;
        p2 = p2 ? p2->next : headA;
    }
    return p1;
}

// ����ʹ���������� actions ��¼һϵ�к��ļ�Ⱥѵ����Ŀ��š�
// Ϊ��ǿѵ��Ȥζ�ԣ���Ҫ�������������ѵ����Ŀ������ż�����ѵ����Ŀ֮ǰ��
// �뽫�������ѵ����Ŀ����� ���� ��ʽ���ء�


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

