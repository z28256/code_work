#define _CRT_SECURE_NO_WARNINGS 1

// 1.验证二叉搜索树
// 2.对称二叉树
// 3.将有序数组转换为二叉搜索树


// 验证二叉搜索树
// 
//给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

//有效 二叉搜索树定义如下：
//节点的左子树只包含 小于 当前节点的数。
//节点的右子树只包含 大于 当前节点的数。
//所有左子树和右子树自身必须也是二叉搜索树。

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


//对称二叉树
//给你一个二叉树的根节点 root ， 检查它是否轴对称。

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


// 将有序数组转换为二叉搜索树

//给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
//高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。

struct TreeNode* helper(int* nums, int left, int right)
{
    if (left > right)
    {
        return NULL;
    }

    // 总是选择中间位置左边的数字作为根节点
    // int mid = (left + right) / 2;

    // 总是选择中间位置右边的数字作为根节点
    // int mid = (left + right + 1) / 2;

    // 选择任意一个中间位置数字作为根节点
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

