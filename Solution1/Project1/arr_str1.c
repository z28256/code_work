#define _CRT_SECURE_NO_WARNINGS 1

// 1.ɾ�����������е��ظ��� (����ָ��)
// 2.ֻ����һ�ε����� (���)
// 3.��ת�ַ��� (����)



// ɾ�����������е��ظ���
//����һ���������е����� nums ������ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ��ֻ����һ�� ������ɾ����������³��ȡ�
//Ԫ�ص� ���˳�� Ӧ�ñ��� һ�� ��Ȼ�󷵻� nums ��ΨһԪ�صĸ�����


int removeDuplicates(int* nums, int numsSize)
{
    // ��������Ԫ�ظ���Ϊ0����1, һ���������ظ���,ֱ�ӷ���numSize
    if (numsSize == 0 || numsSize == 1)
    {
        return numsSize;
    }
    //����ָ��,��left��right�ĳ�ʼֵ����Ϊ1,��right��right-1��������ֵ���бȽ�
    int left = 1, right = 1;
    while (right < numsSize)
    {
        //���nums[right]��nums[right - 1]����ͬ,�ͽ�nums[right]��ֵ����nums[left],����left++
        if (nums[right] != nums[right - 1])
        {
            nums[left++] = nums[right];
        }
        //right��ֵ�����Ƿ���ǰһ����ͬ����Ҫ++
        right++;
    }
    //���right==numsSize��ʱ��,��ʱleft�ƶ���ΨһԪ�ص���һλ,Ҳ����nums��ΨһԪ�صĸ���
    return left;
}



//ֻ����һ�ε�����

//����һ�� �ǿ� �������� nums ������ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�

//���

//a^ a = 0���Լ����Լ�������0
//a ^ 0 = a���κ����ֺ�0��򻹵������Լ�
//a ^ b ^ c = a ^ c ^ b�����������н�����

int singleNumber(int* nums, int numsSize)
{
    int ret = 0;
    for (int i = 0; i < numsSize; i++)
    {
        ret ^= nums[i];
    }
    return ret;
}


//��ת�ַ���

//��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� s ����ʽ������

void reverseString(char* s, int sSize)
{
    char temp ;
    int left = 0, right = sSize - 1;

    while (left < right)
    {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}



