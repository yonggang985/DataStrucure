#include <stdio.h>
#include <stdlib.h>
enum { NUM = 6 };

void fastest_way(int n,int a[][NUM], int t[][NUM - 1],
		 int e[], int x[], int f[][NUM], int l[][NUM],
		 int *fastest_time, int *last_line)
{
	f[0][0] = e[0] + a[0][0];
	f[1][0] = e[1] + a[1][0];
	for (int j = 1; j < n; j++) 
	{
		if (f[0][j - 1] <= f[1][j - 1] + t[1][j - 1]) 
		{
			f[0][j] = f[0][j - 1] + a[0][j];
			l[0][j] = 0;
		} 
		else 
		{
			f[0][j] = f[1][j - 1] + t[1][j - 1] + a[0][j];
			l[0][j] = 1;
		}

		if (f[1][j - 1] <= f[0][j - 1] + t[0][j - 1]) 
		{
			f[1][j] = f[1][j - 1] + a[1][j];
			l[1][j] = 1;
		}
		else 
		{
			f[1][j] = f[0][j - 1] + t[0][j - 1] + a[1][j];
			l[1][j] = 0;
		}
	}

	if (f[0][n - 1] + x[0] <= f[1][n - 1] + x[1]) 
	{
		*fastest_time = f[0][n - 1] + x[0];
		*last_line = 0;
	} 
	else 
	{
		*fastest_time = f[1][n - 1] + x[1];
		*last_line = 1;
	}
}

void print_stations(int n,int line[][NUM], int last_line)
{
	int i = last_line;
	printf("line %d, station %d\n", i + 1, n);
	for (int j = n - 1; j > 0; j--) 
	{
		i = line[i][j];
		printf("line %d, station %d\n", i + 1, j);
	}
}

int main()
{
	int n=NUM; // number of station
	int f[2][NUM]; //fast road
	int l[2][NUM]; //assemble line
	int a[2][NUM] = { {7, 9, 3, 4, 8, 4}, {8, 5, 6, 4, 5, 7} }; //assemble time
	int t[2][NUM - 1] = { {2, 3, 1, 3, 4}, {2, 1, 2, 2, 1} }; //transport time
	int e[2] = { 2, 4 };//entry time
	int x[2] = { 3, 2 };//exit time
	int fastest_time; //fastest time of the line
	int last_line;//last line of the fast road

	fastest_way(n,a, t, e, x, f, l, &fastest_time, &last_line);
	printf("%d %d\n", fastest_time, last_line + 1);
	
	printf("输出F数组:\n");
	printf("f[0][j] ");
	for (int i = 0; i < n; ++i) 
	{
		printf("%2d ", f[0][i]);
	}
	printf("\n");
	printf("f[1][j] ");
	for (int i = 0; i < n; ++i) 
	{
		printf("%2d ", f[1][i]);
	}
	printf("\n\n");

	printf("输出L数组:\n");
	printf("线路1：");
	for (int i = 1; i < n; ++i) 
	{
		printf("%2d ", l[0][i] + 1);
	}
	printf("\n");
	printf("线路2：");
	for (int i = 1; i < n; ++i) 
	{
		printf("%2d ", l[1][i] + 1);
	}
	printf("\n\n");

	printf("最终选择的线路:\n");
	print_stations(n,l, last_line);
	return 0;
}
