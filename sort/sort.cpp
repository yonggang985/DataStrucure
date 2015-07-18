//filename:sort.cpp
#include "sort.h"

void print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d]=%d  ",i,a[i]);
	}
	printf("\n\n\n");
}

void InsetSort(int A[],int N)
{
	int j;
	for(int i=1;i<N;i++)
	{
		if(A[i]<A[i-1])
		{
			int temp = A[i];
			for(j=i-1;j>=0&&temp<A[j];j--)
			{
				A[j+1] = A[j];
			}
			A[j+1] = temp;
		}
	}
}

void BubbleSort(int A[],int N)
{
	for(int i=0;i<N-1;i++)
	{
		bool flag = false;
		for(int j=N-1;j>i;j--)
		{
			if(A[j-1]>A[j])
			{
				int temp = A[j-1];
				A[j-1] = A[j];
				A[j] = temp;
				flag = true;
			}
		}
		if(flag==false)
		{
			return;
		}
	}
}
				
void SelectSort(int A[],int N)
{
	for(int i=0;i<N-1;i++)
	{
		int min = i;
		for(int j=i+1;j<N;j++)
		{
			if(A[j]<A[min])
			{
				min = j;
			}
		}
		if(min!=i)
		{
			int temp = A[i];
			A[i] = A[min];
			A[min] = temp;
		}
	}
}
	
void ShellSort(int A[],int N)
{
	int j;
	for(int dk=N/2;dk>=1;dk=dk/2)
	{
		for(int i=dk;i<N;i++)
		{
			if(A[i]<A[i-dk])
			{
				int temp = A[i];
				for(j=i-dk;j>=0&&temp<A[j];j-=dk)
				{
					A[j+dk] = A[j];
				}
				A[j+dk] = temp;
			}
		}
	}
}

void Merge(int A[],int B[],int low,int mid,int high)
{
	for(int i=low;i<=high;i++)
	{
		B[i] = A[i];
	}
	int i;
	int j;
	int k;
	for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++)
	{
		if(B[i]<B[j])
		{
			A[k] = B[i++];
		}
		else
		{
			A[k] = B[j++];
		}
	}
	while(i<=mid)
	{
		A[k++] = B[i++];
	}
	while(j<=high)
	{
		A[k++] = B[j++];
	}
}
void MergeSort(int A[],int B[],int low,int high)
{
	if(low<high)
	{
		int mid = (low+high)/2;        
		MergeSort(A,B,low,mid);
		MergeSort(A,B,mid+1,high);
		Merge(A,B,low,mid,high);
	}
}


void AdjustDown(int A[],int i,int N)
{
	int temp = A[i];
	for(int k=2*i+1;k<N;k=k*2+1)
	{
		if(k+1<N&&A[k]<A[k+1])
		{
			k++;
		}
		if(temp>=A[k])
		{
			break;
		}
		else
		{
			A[i] = A[k];
			i = k;
		}
	}
	A[i] = temp;
}
void BuildMaxHeap(int A[],int N)
{
	for(int i = (N-1)/2;i>=0;i--)
	{
		AdjustDown(A,i,N);
	}
}
void HeapSort(int A[],int N)
{
	BuildMaxHeap(A,N);
	for(int i=N-1;i>0;i--)
	{
		int temp = A[i];
		A[i] = A[0];
		A[0] = temp;
		AdjustDown(A,0,i);
	}
}

int Partition(int A[],int low,int high)
{
	int pivot = A[low];
	while(low<high)
	{
		while(low<high && A[high]>=pivot)
		{
			high--;
		}
		A[low] = A[high];
		while(low<high && A[low]<=pivot)
		{
			low++;
		}
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;
}
void QuickSort(int A[],int low,int high)
{
	if(low<high)
	{
		int pivotpos = Partition(A,low,high);
		QuickSort(A,low,pivotpos-1);
		QuickSort(A,pivotpos+1,high);
	}
}
			

