#define _CRT_SECURE_NO_WARNINGS 1

// 1.ͼ������ I
// 2.ɾ������ڵ�
// 3.ֻ����һ�ε����� 


#include <stdlib.h>

// ͼ������ I
// ����Ա��һ��������ʽ���鵥��ÿ���ڵ����һ���飬�ڵ��е�ֵ��ʾ��ı�š�Ϊ������������ܣ�
// ��Ա��Ҫ���鵥���������У��Ϳ��Դ����һ���鿪ʼ������һ����Żص�����ϡ��뵹�򷵻�����鵥����


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


// ɾ������ڵ�
//�������������ͷָ���һ��Ҫɾ���Ľڵ��ֵ������һ������ɾ���ýڵ㡣
//����ɾ����������ͷ�ڵ㡣


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


// ֻ����һ�ε����� 

//����һ���������� nums������ǡ��������Ԫ��ֻ����һ�Σ���������Ԫ�ؾ��������Ρ� 
//�ҳ�ֻ����һ�ε�������Ԫ�ء�����԰� ����˳�� ���ش𰸡�
//�������Ʋ�ʵ������ʱ�临�Ӷȵ��㷨�ҽ�ʹ�ó�������ռ�����������⡣


//ʹ�ð�λ�������&��-x��ȡx�����1λ��ԭ��,���ڶ����Ʋ����ȡ��������λ�����ϵĹ���ԭ��
//�ڶ����Ʋ�����ȡ��һ������, ʵ�����ǡ���ת������λ������ - x����x�Ķ����Ʋ��롣
//�ٸ�����, ���x��1010(ʮ����10), ��ô - x����0101(ʮ���� - 10)��
//����, ������Ƕ�һ�����ֺ����Ĳ�����а�λ�����, ����͵�1λ��, ��������λ����Ϊ0��
//������Ϊ�ڰ�λ�������, ����λ������Ϊ1���ܲ���1��Ϊ����������1λ��, ����λ��������������������һ��λ��Ϊ0��
//����x & -x������x�����Ĳ����й�ͬӵ�е����1λ����ʹ����ͨ���򵥵İ�λ������Ϳ���������ȡx�����1λ��

int* singleNumber(int* nums, int numsSize, int* returnSize)
{
    int xorsum = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        xorsum ^= nums[i];
    }
    
    // ����һ
    // INT_MIN: 100000...0
    int lsb = (xorsum == INT_MIN ? xorsum : xorsum & (-xorsum));

    // ������
    //long long lsb = 1; // int��Խ��
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

