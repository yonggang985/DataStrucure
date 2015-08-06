#include <iostream>
#include <limits.h>
using namespace std;

const int MaxVal = INT_MAX;
enum {NUM =5};

double p[NUM+1] = {-1,0.15,0.1,0.05,0.1,0.2};
double q[NUM+1] = {0.05,0.1,0.05,0.05,0.05,0.1};

int root[NUM+1][NUM+1];
double w[NUM+2][NUM+2];
double e[NUM+2][NUM+2];

void optimalBST(double* p,double* q,int n)
{
	for(int i=1;i<=n+1;i++)
	{
		w[i][i-1] = q[i-1];
		e[i][i-1] = q[i-1];
	}

	for(int len =1;len<=n;len++)
	{
		for(int i=1;i<=n-len+1;i++)
		{
			int j = i+len-1;
			e[i][j] = MaxVal;
			w[i][j] =w[i][j-1] + p[j] +q[j];

			for(int k=i;k<=j;k++)
			{
				double temp = e[i][k-1] + e[k+1][j] + w[i][j];
				if(temp < e[i][j])
				{
					e[i][j] =temp;
					root[i][j] =k;
				}
			}
		}
	}
}

void printRoot()
{
	cout << "各子树的根： "<< endl;
	for(int i =1;i<=NUM;i++)
	{
		for(int j=1;j<=NUM;j++)
		{
			cout << root[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void printOptimalBST(int i,int j,int r)
{
	int rootChild = root[i][j];
	if(rootChild == root[1][NUM])
	{
		cout << "k" << rootChild << "是根" << endl;
		printOptimalBST(i,rootChild-1,rootChild);
		printOptimalBST(rootChild+1,j,rootChild);
		return;
	}

	if(j<i-1)
	{
		return ;
	}
	else if(j==i-1)
	{
		if(j<r)
		{
			cout << "d" << j << "是" << "k" << r << "的左孩子" << endl;
		}
		else
		{
			cout << "d" << j << "是" << "k" << r << "的右孩子" << endl;
		}
		return ;
	}
	else
	{
		if(rootChild <r )
		{
			cout << "k" << rootChild << "是" << "k" << r << "的左孩子" << endl;
		}
		else
		{
			cout << "k" << rootChild << "是" << "k" << r << "的右孩子" << endl;
		}
	}
	printOptimalBST(i,rootChild-1,rootChild);
	printOptimalBST(rootChild+1,j,rootChild);
}

int main()
{
	int n =NUM;
	optimalBST(p,q,n);
	printRoot();
	cout << "最优二叉树结构: " << endl;
	printOptimalBST(1,n,-1);
}


