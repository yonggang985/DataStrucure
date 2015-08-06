#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
enum {NUM=7};

//查表法，从下至上计算最优解
void matrix_chain_order(int n,int p[],int m[][NUM],int s[][NUM])
{
	for(int i=1;i<n;i++)
	{
		m[i][i] = 0; //长度为1时候
	}
	for(int l=2;l<n;l++)//l 的长度 2--->n(不包括)
	{
		for(int i=1;i<n-l+1;i++)//i 的位置 1--->n-l（不包括）
		{
			int j=i+l-1;//j 的位置 i+l-1
			m[i][j] = INT_MAX;
			for(int k=i;k<=j-1;k++)//k 的位置 i---->j(不包括)
			{
				int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(q < m[i][j])
				{
					m[i][j] = q; //当前最小值q存表
					s[i][j] = k; //记录m[i][j]取最小值时，断开的位置k
				}
			}
		}
	}
}

void print_optimal_matrix(int n,int s[][NUM],int i,int j)
{
	if(i==j)
	{
		printf("A%d",i);
	}
	else
	{
		printf("(");
		print_optimal_matrix(n,s,i,s[i][j]);
		print_optimal_matrix(n,s,s[i][j]+1,j);
		printf(")");
	}
}

int main()
{
	int n=NUM;
	int p[NUM] = {30,35,15,5,10,20,25};
	int m[NUM][NUM] = {{0}};
	int s[NUM][NUM] = {{0}};
	matrix_chain_order(n,p,m,s);
	printf("最优加全部括号\n");
	print_optimal_matrix(n,s,1,6);
	printf("\n");
	printf("输出m数组的值\n");
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			printf("%5d ",m[i][j]);
		}
		printf("\n");
	}
	printf("输出s数组的值\n");
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			printf("%5d ",s[i][j]);
		}
		printf("\n");
	}
	return 0;
}
