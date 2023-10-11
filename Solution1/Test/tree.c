#define _CRT_SECURE_NO_WARNINGS 1

// 1.��֤����������
// 2.�Գƶ�����
// 3.����������ת��Ϊ����������


// ��֤����������
// 
//����һ���������ĸ��ڵ� root ���ж����Ƿ���һ����Ч�Ķ�����������

//��Ч �����������������£�
//�ڵ��������ֻ���� С�� ��ǰ�ڵ������
//�ڵ��������ֻ���� ���� ��ǰ�ڵ������
//�������������������������Ҳ�Ƕ�����������

#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool helper(struct TreeNode* root, long long lower, long long upper)
{
    if (!root)
    {
        return true;
    }
    if (root->val <= lower || root->val >= upper)
    {
        return false;
    }
    return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);

}


bool isValidBST(struct TreeNode* root)
{
    return helper(root, LONG_MIN, LONG_MAX);
}


//�Գƶ�����
//����һ���������ĸ��ڵ� root �� ������Ƿ���Գơ�

bool isSymmetricHelper(struct TreeNode* left, struct TreeNode* right)
{
    if (!left && !right)
    {
        return true;
    }
    if (!left || !right || left->val != right->val)
    {
        return false;
    }
    return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root)
{
    if (!root)
    {
        return true;
    }
    return isSymmetricHelper(root->left, root->right);

}


// ����������ת��Ϊ����������

//����һ���������� nums ������Ԫ���Ѿ��� ���� ���У����㽫��ת��Ϊһ�� �߶�ƽ�� ������������
//�߶�ƽ�� ��������һ�����㡸ÿ���ڵ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ���Ķ�������

struct TreeNode* helper(int* nums, int left, int right)
{
    if (left > right)
    {
        return NULL;
    }

    // ����ѡ���м�λ����ߵ�������Ϊ���ڵ�
    // int mid = (left + right) / 2;

    // ����ѡ���м�λ���ұߵ�������Ϊ���ڵ�
    // int mid = (left + right + 1) / 2;

    // ѡ������һ���м�λ��������Ϊ���ڵ�
    int mid = (left + right + rand() % 2) / 2;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = helper(nums, left, mid - 1);
    root->right = helper(nums, mid + 1, right);

    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    return helper(nums, 0, numsSize - 1);
}

