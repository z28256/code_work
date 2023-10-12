#define _CRT_SECURE_NO_WARNINGS 1

// 1.��������
// 2.�ߵ�������λ
// 3.�������
// 4.�ҳ�����Ĵ���ֵ


// ��������

//��������֮��� �������� ָ�������������ֶ�Ӧ������λ��ͬ��λ�õ���Ŀ��
//������������ x �� y�����㲢��������֮��ĺ������롣

int hammingDistance(int x, int y)
{
    int count = 0;
    int n = x ^ y;
    while (n)
    {
        n &= n - 1;
        ++count;
    }
    return count;
}


// �ߵ�������λ

//�ߵ������� 32 λ�޷��������Ķ�����λ��

#include <stdint.h>  

uint32_t reverseBits(uint32_t n)
{
    uint32_t ret = 0;
    for (int i = 0; i < 32; ++i)
    {
        ret |= (n & 1) << (31 - i);
        n >>= 1;
    }
    return ret;
}


// �������

//����һ���Ǹ����� numRows�����ɡ�������ǡ���ǰ numRows �С�
//�ڡ�������ǡ��У�ÿ�����������Ϸ������Ϸ������ĺ͡�

int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    *returnSize = numRows;
    int** ret = (int**)malloc(sizeof(int*) * numRows);
    *returnColumnSizes = (int*)malloc(sizeof(int) * numRows);
    for (int i = 0; i < numRows; ++i)
    {
        (*returnColumnSizes)[i] = i + 1;
        ret[i] = (int*)malloc(sizeof(int*) * (i + 1));
        ret[i][0] = ret[i][i] = 1;
        for (int j = 1; j < i; ++j)
        {
            ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
        }
    }
    return ret;
}



//�ҳ�����Ĵ���ֵ

// ����һ���±�� 0 ��ʼ���������� nums ��
//�ֶ����������ֵ� ���� ������������ֵ���������γɵ������֡�
//
//���磬15 �� 49 �Ĵ����� 1549 ��
//nums �� ����ֵ ������� 0 ��ִ����������ֱ�� nums ��Ϊ�գ�
//
//��� nums �д��ڲ�ֹһ�����֣��ֱ�ѡ�� nums �еĵ�һ��Ԫ�غ����һ��Ԫ�أ������ߴ����õ���ֵ�ӵ� nums �� ����ֵ �ϣ�Ȼ��� nums ��ɾ����һ�������һ��Ԫ�ء�
//���������һ��Ԫ�أ��򽫸�Ԫ�ص�ֵ�ӵ� nums �Ĵ���ֵ�ϣ�Ȼ��ɾ�����Ԫ�ء�
//����ִ�������в����� nums �Ĵ���ֵ��


// 1 <= nums.length <= 1000
//1 <= nums[i] <= 10^4


long long add(int n, int m)
{
    n *= 10;
    int temp = m;
    while (temp /= 10)
    {
        n *= 10;
    }
    return n + m;
}

/*long long add(int n, int m)
{
    if (m < 10)
        return n * 10 + m;
    else if (m < 100)
        return n * 100 + m;
    else if (m < 1000)
        return n * 1000 + m;
    else if (m < 10000)
        return n * 10000 + m;
    else
        return n * 100000 + m;
}*/

long long findTheArrayConcVal(int* nums, int numsSize)
{
    long long ret = 0;
    int left = 0, right = numsSize - 1;
    while (left < right)
    {
        ret += add(nums[left], nums[right]);
        ++left;
        --right;
    }
    if (left == right)
    {
        ret += nums[left];
    }
    return ret;
}







