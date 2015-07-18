// filename:sort.h
#ifndef _SORT_H_
#define _SORT_H_
#include <stdio.h>
#include <stdlib.h>

void print(int a[],int n);
void InsetSort(int A[],int N);
void BubbleSort(int A[],int N);
void SelectSort(int A[],int N);
void ShellSort(int A[],int N);
void MergeSort(int A[],int B[],int low,int high);
void HeapSort(int A[],int N);
void QuickSort(int A[],int low,int high);
			
#endif
