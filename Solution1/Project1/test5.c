#define _CRT_SECURE_NO_WARNINGS 1


// 1.λ1�ĸ���
// 2.ɾ������õ���
// 3.��ͬ·��


// λ1�ĸ���

// ��дһ��������������һ���޷����������Զ����ƴ�����ʽ��������������Ʊ��ʽ������λ��Ϊ '1' �ĸ�����Ҳ����Ϊ������������

#include <stdint.h>

// ��C�����У�uint32_t��һ���޷���32λ�������ͣ���������ͷ�ļ�stdint.h�С�

int hammingWeight(uint32_t n)
{
    int count = 0;
    for (int i = 0; i < 32; ++i)
    {
        if (n >> i & 1)
        {
            count++;
        }
    }
    return count;
}


// ɾ������õ���

//����һ���������� nums ������Զ�������һЩ������
//ÿ�β����У�ѡ������һ�� nums[i] ��ɾ��������� nums[i] �ĵ�����֮�������ɾ�� ���� ���� nums[i] - 1 �� nums[i] + 1 ��Ԫ�ء�
//��ʼ��ӵ�� 0 ����������������ͨ����Щ������õ���������


int rob(int* nums, int numsSize)
{
    int first = nums[0], second = nums[0] > nums[1] ? nums[0] : nums[1];
    for (int i = 2; i < numsSize; ++i)
    {
        int temp = second;
        second = first + nums[i] > second ? first + nums[i] : second;
        first = temp;
    }
    return second;
}


int deleteAndEarn(int* nums, int numsSize)
{
    int maxVal = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        maxVal = maxVal > nums[i] ? maxVal : nums[i];
    }
    int* sum = (int*)calloc(maxVal + 1, sizeof(int));
    for (int i = 0; i < numsSize; ++i)
    {
        sum[nums[i]] += nums[i];
    }
    return rob(sum, maxVal + 1);
}


// ��ͬ·��

// һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ ��Start�� ����
//������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ ��Finish�� ����
//���ܹ��ж�������ͬ��·����

int uniquePaths(int m, int n)
{
    // (m + n - 2)! / (m - 1)!(n - 1)!
    // (m + n - 2)(m + n - 3)...n / (m - 1)!
    long long ans = 1;
    for (int x = n, y = 1; y < m; ++x, ++y)
    {
        ans = ans * x / y;
    }
    return ans;
}


int uniquePaths(int m, int n)
{
    int f[m][n];
    for (int i = 0; i < m; ++i)
    {
        f[i][0] = 1;
    }
    for (int j = 0; j < n; ++j)
    {
        f[0][j] = 1;
    }
    for (int i = 1; i < m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    return f[m - 1][n - 1];
}

