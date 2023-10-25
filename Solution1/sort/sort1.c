#define _CRT_SECURE_NO_WARNINGS 1

#include <stdbool.h>
#include <stdio.h>

// 冒泡排序

void swap(int* n1, int* n2)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}


void bubbleSort(int* nums, int length)
{
	bool flag = false;
	for (int i = 0; i < length - 1; ++i)
	{
		for (int j = 0; j < length - i - 1; ++j)
		{
			if (nums[j] > nums[j + 1])
			{
				flag = true;
				swap(&nums[j], &nums[j + 1]);
			}
		}
		if (!flag)
		{
			break;
		}
	}
}


// 快速排序

void quickSort(int* nums, int l, int r)
{
	if (l >= r)
	{
		return;
	}
	int i = partition(nums, l, r);
	quickSort(nums, l, i - 1);
	quickSort(nums, i + 1, r);
}


int partition(int* nums, int l, int r)
{
	int i = l, j = r;

	//while (i < j)
	//{
	//	// 两个循环顺序不能更改, 因为是以nums[l]为基准,将nums[l]与nums[i]进行交换
	//	while (i < j && nums[j] >= nums[l])
	//	{
	//		--j;
	//	}
	//	while (i < j && nums[i] <= nums[l])
	//	{
	//		++i;
	//	}
	//	swap(&nums[i], &nums[j]);
	//}
	//swap(&nums[i], &nums[l]);

	while (i < j)
	{
		
		while (i < j && nums[i] <= nums[r])
		{
			++i;
		}
		while (i < j && nums[j] >= nums[r])
		{
			--j;
		}
		swap(&nums[i], &nums[j]);
	}
	swap(&nums[j], &nums[r]);
	return j;
}


int main()
{
	int nums[] = { 4, 1, 3, 2, 5 };
	int length = sizeof(nums) / sizeof(nums[0]);

	//bubbleSort(nums, length);
	quickSort(nums, 0, length - 1);

	for (int i = 0; i < 5; ++i)
	{
		printf("%d ", nums[i]);
	}
	return 0;
}