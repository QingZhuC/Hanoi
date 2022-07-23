#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int con = 0;
void move(char x,char y)
{
	con++;//����
	//printf("��%c�Ƶ�%c\n", x, y);//�����Ƕ��ƶ����̽�������
}

void hanoi(int n,char a,char b,char c)//n��ʾ���Ӹ���,abc��ʾ��������
{
	if (n == 1)
		move(a, c);//ֻ��һ�����ӣ�ֱ�ӽ�a-->c����
	else//����n�����ӣ�n>1),���ǲ�������ֳ�n(�ײ�)��n-1(�ϲ�)������,����ֻ��Ҫ������������˼������
	{
		hanoi(n - 1, a, c, b);//�˲��輴���ϲ�����(n-1)��A-->B
		move(a, c);//�˲��輴���ײ�����(n)��A-->C
		hanoi(n - 1, b, a, c);//�˲��輴���ϲ�����(n-1)��B-->C
	}
}

int Sqrt(int con)//����
{
	if (con / 2 != 1)
		return 1 + Sqrt(con / 2);
	else
		return 1;
}

int main()
{
	int n = 0;
	printf("������������");
	scanf("%d", &n);
	hanoi(n,'A','B','C');
	printf("��%d��\n��2^%d-1��",con, Sqrt(con+1));
	return 0;
}

