#define _CRT_SECURE_NO_WARNINGS 1

// 1.x 的平方根
// 2.只出现一次的数字
// 3.Pow(x, n)
// 4.快乐数


//x 的平方根
// 
//给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
//由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
//注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x** 0.5


int mySqrt(int x)
{
    long long n = 0;
    while (n * n <= x)
    {
        ++n;
    }
    return n - 1;
}

// 二分查找

int mySqrt(int x)
{
    int left = 0, right = x;
    int ans;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        if (mid * mid <= x)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}

//只出现一次的数字

//给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
//你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。

int singleNumber(int* nums, int numsSize)
{
    for (int i = 1; i < numsSize; ++i)
    {
        nums[0] ^= nums[i];
    }
    return nums[0];
}


// Pow(x, n)

// 方法一：快速幂 + 递归

double quickMul(double x, long long n)
{
    if (n == 0 || x == 1.0)
    {
        return 1.0;
    }
    double y = quickMul(x, n / 2);
    return n % 2 == 0 ? y * y : y * y * x;
}

double myPow(double x, int n)
{
    long long num = n;
    return num >= 0 ? quickMul(x, num) : 1.0 / quickMul(x, -num);
}

// 方法二：快速幂 + 迭代

 double quickMul(double x, long long n)
 {
     double ans = 1.0;
     double x_contribute = x;
     while (n > 0)
     {
         if (n % 2 == 1)
         {
             ans *= x_contribute;
         }
         x_contribute *= x_contribute;
         n /= 2;
     }
     return ans;
 }


 double myPow(double x, int n)
 {
     long long num = n;
     return num >= 0 ? quickMul(x, num) : 1.0 / quickMul(x, -num);   
 }


// 快乐数

// 编写一个算法来判断一个数 n 是不是快乐数。
//「快乐数」 定义为：
//对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
//然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
//如果这个过程 结果为 1，那么这个数就是快乐数。
//如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

 // 快慢指针法

 int bitSqareSum(int n)
 {
     int sum = 0;
     while (n > 0)
     {
         int bit = n % 10;
         sum += bit * bit;
         n /= 10;
     }
     return sum;
 }

 bool isHappy(int n)
 {
     int slow = n, fast = n;
     do {
         slow = bitSqareSum(slow);
         fast = bitSqareSum(fast);
         fast = bitSqareSum(fast);
     } while (slow != fast);
     return slow == 1;
 }

 // 用哈希集合检测循环

  int getSum(int n)
  {
      int sum = 0;
      while (n)
      {
          int temp = n % 10;
          sum += temp * temp;
          n /= 10;
      }
      return sum;
  }

  bool isHappy(int n)
  {
      int sum = getSum(n);
      int hash[1000] = {0};
      while(sum != 1)
      {
          if (hash[sum])
          {
              return false;
          }
          else
          {
              hash[sum]++;
          }
          sum = getSum(sum);
      }
      return true;
  }
