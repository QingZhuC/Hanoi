#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int con = 0;
void move(char x,char y)
{
	con++;//计数
	//printf("从%c移到%c\n", x, y);//仅仅是对移动过程进行描述
}

void hanoi(int n,char a,char b,char c)//n表示盘子个数,abc表示三根柱子
{
	if (n == 1)
		move(a, c);//只有一个盘子，直接将a-->c即可
	else//若有n个盘子（n>1),我们不妨将其分成n(底层)和n-1(上层)两部分,这样只需要按照两个盘子思考即可
	{
		hanoi(n - 1, a, c, b);//此步骤即将上层盘子(n-1)由A-->B
		move(a, c);//此步骤即将底层盘子(n)由A-->C
		hanoi(n - 1, b, a, c);//此步骤即将上层盘子(n-1)由B-->C
	}
}

int Sqrt(int con)//计算
{
	if (con / 2 != 1)
		return 1 + Sqrt(con / 2);
	else
		return 1;
}

int main()
{
	int n = 0;
	printf("请输入总数：");
	scanf("%d", &n);
	hanoi(n,'A','B','C');
	printf("共%d步\n即2^%d-1步",con, Sqrt(con+1));
	return 0;
}

