#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;
/************************************
函数名称：int BinFind1(int *num, int size ,int data)
函数功能：实现二分查找
输入参数：int *num——被查找数组
		 int size——数组长度
		 int data——查找元素
输出参数：元素在数组中的位置
特殊测试：1.最左边元素的查找
		 2.最右边元素的查找
		 3.中间元素的查找
		 4.不在数组中元素的查找
注意事项：1.注意循环边界的控制
		 2.注意查找区间边界的控制
		 3.注意求mid位置时的溢出问题
		 4.本函数使用闭区间
		 5.移位运算比除法运算更加高效
*****************************************/
int BinFind1(int *num, int size ,int data)
{
	assert(NULL != num);
	int left = 0;
	int right = size - 1;//闭区间
	int mid = left + ((right - left) >> 1);
	while (left <= right)
	{
		mid = left + ((right - left) >> 1);
		if (num[mid] < data)
			left = mid + 1;
		else if (num[mid] > data)
			right = mid - 1;
		else if (num[mid] == data)
			return mid;
	}
	return -1;
}
/************************************
函数名称：int BinFind2(int *num, int size ,int data)
函数功能：实现二分查找
输入参数：int *num——被查找数组
		 int size——数组长度
		 int data——查找元素
输出参数：元素在数组中的位置
特殊测试：1.最左边元素的查找
		 2.最右边元素的查找
		 3.中间元素的查找
		 4.不在数组中元素的查找
注意事项：1.注意循环边界的控制
		 2.注意查找区间边界的控制
		 3.注意求mid位置时的溢出问题
		 4.本函数中边界使用半开半闭区间
		 5.移位运算比除法运算更加高效
*****************************************/
int BinFind2(int *num, int size, int data)
{
	assert(NULL != num);
	int left = 0;
	int right = size;//半闭半开区间
	while (left < right)
	{
		int mid = left + ((right - left) >> 1);
		if (num[mid] < data)
			left = mid + 1;
		else if (num[mid] > data)
			right = mid;//半闭半开区间
		else
			return mid;
	}
	return -1;
}
int Test()
{
	int num[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int pos1 = BinFind1(num, sizeof(num) / sizeof(num[0]), 0);//最左边
	int pos2 = BinFind1(num, sizeof(num) / sizeof(num[0]), 9);//最右边
	int pos3 = BinFind1(num, sizeof(num) / sizeof(num[0]), 4);//中间元素
	int pos4 = BinFind1(num, sizeof(num) / sizeof(num[0]), 10);//查找不存在元素


	int pos5 = BinFind2(num, sizeof(num) / sizeof(num[0]), 0);//最左边
	int pos6 = BinFind2(num, sizeof(num) / sizeof(num[0]), 9);//最右边
	int pos7 = BinFind2(num, sizeof(num) / sizeof(num[0]), 6);//中间元素
	int pos8 = BinFind2(num, sizeof(num) / sizeof(num[0]), 10);//查找不存在元素
	return 0;
}

int main()
{
	Test();
	return 0;
}