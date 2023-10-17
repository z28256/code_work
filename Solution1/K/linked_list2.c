#define _CRT_SECURE_NO_WARNINGS 1

// 1.�������
// 2.������
// 3.������n���ڵ�

// �������
//����һ�������� n ����������� [1��n] ��Χ���ܱ� 3��5��7 ��������������֮�͡�
//����һ�����������ڱ�ʾ������Χ����������Լ������������֮�͡�

// ����һ��ö��

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


// ���������ݳ�ԭ��
// ����3,5,7�ı���,3��5,5��7,3��7������������,������Ҫ�ټ�ȥһ��,
// ��3,5,7�Ĺ�ͬ����������3��,Ҳ������3��,������Ҫ�ټ�һ��


// n = 14
// 3 6 9 12
// 3 * (1 + 2 + 3 + 4)

int f(int m, int n) {
    return m * ((1 + n / m) * (n / m) / 2);
}

int sumOfMultiples(int n) {
    return f(3, n) + f(5, n) + f(7, n) - f(3 * 5, n) - f(3 * 7, n) - f(5 * 7, n) + f(3 * 5 * 7, n);
}


// ������
// ����һ��ͷ�ڵ�Ϊ head �ĵ��������ڼ�¼һϵ�к��ļ�Ⱥѵ����ţ��뽫��ϵ��ѵ����� ���� ��¼���������ء�

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// ���������ݹ�

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

//����һ��������˫ָ�룩

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


// ������n���ڵ�
// ����һ��ͷ�ڵ�Ϊ head ���������ڼ�¼һϵ�к��ļ�Ⱥѵ����Ŀ��ţ�����Ҳ����ص����� cnt ��ѵ����Ŀ��š�


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
