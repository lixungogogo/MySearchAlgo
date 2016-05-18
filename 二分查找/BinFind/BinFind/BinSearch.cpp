#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;
/************************************
�������ƣ�int BinFind1(int *num, int size ,int data)
�������ܣ�ʵ�ֶ��ֲ���
���������int *num��������������
		 int size�������鳤��
		 int data��������Ԫ��
���������Ԫ���������е�λ��
������ԣ�1.�����Ԫ�صĲ���
		 2.���ұ�Ԫ�صĲ���
		 3.�м�Ԫ�صĲ���
		 4.����������Ԫ�صĲ���
ע�����1.ע��ѭ���߽�Ŀ���
		 2.ע���������߽�Ŀ���
		 3.ע����midλ��ʱ���������
		 4.������ʹ�ñ�����
		 5.��λ����ȳ���������Ӹ�Ч
*****************************************/
int BinFind1(int *num, int size ,int data)
{
	assert(NULL != num);
	int left = 0;
	int right = size - 1;//������
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
�������ƣ�int BinFind2(int *num, int size ,int data)
�������ܣ�ʵ�ֶ��ֲ���
���������int *num��������������
		 int size�������鳤��
		 int data��������Ԫ��
���������Ԫ���������е�λ��
������ԣ�1.�����Ԫ�صĲ���
		 2.���ұ�Ԫ�صĲ���
		 3.�м�Ԫ�صĲ���
		 4.����������Ԫ�صĲ���
ע�����1.ע��ѭ���߽�Ŀ���
		 2.ע���������߽�Ŀ���
		 3.ע����midλ��ʱ���������
		 4.�������б߽�ʹ�ð뿪�������
		 5.��λ����ȳ���������Ӹ�Ч
*****************************************/
int BinFind2(int *num, int size, int data)
{
	assert(NULL != num);
	int left = 0;
	int right = size;//��հ뿪����
	while (left < right)
	{
		int mid = left + ((right - left) >> 1);
		if (num[mid] < data)
			left = mid + 1;
		else if (num[mid] > data)
			right = mid;//��հ뿪����
		else
			return mid;
	}
	return -1;
}
int Test()
{
	int num[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int pos1 = BinFind1(num, sizeof(num) / sizeof(num[0]), 0);//�����
	int pos2 = BinFind1(num, sizeof(num) / sizeof(num[0]), 9);//���ұ�
	int pos3 = BinFind1(num, sizeof(num) / sizeof(num[0]), 4);//�м�Ԫ��
	int pos4 = BinFind1(num, sizeof(num) / sizeof(num[0]), 10);//���Ҳ�����Ԫ��


	int pos5 = BinFind2(num, sizeof(num) / sizeof(num[0]), 0);//�����
	int pos6 = BinFind2(num, sizeof(num) / sizeof(num[0]), 9);//���ұ�
	int pos7 = BinFind2(num, sizeof(num) / sizeof(num[0]), 6);//�м�Ԫ��
	int pos8 = BinFind2(num, sizeof(num) / sizeof(num[0]), 10);//���Ҳ�����Ԫ��
	return 0;
}

int main()
{
	Test();
	return 0;
}