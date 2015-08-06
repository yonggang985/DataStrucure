#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
enum {NUM=7};

//������������ϼ������Ž�
void matrix_chain_order(int n,int p[],int m[][NUM],int s[][NUM])
{
	for(int i=1;i<n;i++)
	{
		m[i][i] = 0; //����Ϊ1ʱ��
	}
	for(int l=2;l<n;l++)//l �ĳ��� 2--->n(������)
	{
		for(int i=1;i<n-l+1;i++)//i ��λ�� 1--->n-l����������
		{
			int j=i+l-1;//j ��λ�� i+l-1
			m[i][j] = INT_MAX;
			for(int k=i;k<=j-1;k++)//k ��λ�� i---->j(������)
			{
				int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(q < m[i][j])
				{
					m[i][j] = q; //��ǰ��Сֵq���
					s[i][j] = k; //��¼m[i][j]ȡ��Сֵʱ���Ͽ���λ��k
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
	printf("���ż�ȫ������\n");
	print_optimal_matrix(n,s,1,6);
	printf("\n");
	printf("���m�����ֵ\n");
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			printf("%5d ",m[i][j]);
		}
		printf("\n");
	}
	printf("���s�����ֵ\n");
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
