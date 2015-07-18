/***************************************************************/
/*Copyright (C) SSE-USTC,2015-2016  	                       */
/*															   */
/*	FILE NAME          		:	sort_main.cpp				   */
/*	PRINCIPAL AUTHOR    	:   Zeng Yonggang				   */
/*	SUBSYSTEM NAME			:   sort.h  					   */
/*	MODULE NAME				:								   */
/*	LANGUAGE				:	C++							   */
/*	TARGET ENVIRONMENT  	:	Linux						   */
/*	DATE OF FIRST RELEASE   :	2015/07/16				       */
/*	DESCRIPTION				:	sort algorithm				   */
/***************************************************************/

/*
 * Revision log:
 *
 * Created by Zeng Yonggang,2015/07/16
 * Debug and Test by Zeng Yonggang,2015/07/16
 *
 */

#include "sort.h"

int main()
{
	int N = 10;
	int A[10] = {8,2,3,7,1,9,6,5,4,3};
	int quit = 0;
	while(!quit)
	{
		printf("********************** The main menu ********************\n");
		printf("****		1.Inset Sort	2.Bubble Sort      ****\n");
		printf("****		3.Select Sort	4.Shell Sort 	   ****\n");
		printf("****		5.Merge Sort	6.Heap Sort        ****\n");
		printf("****		7.Quick Sort	8.Bucket Sort	   ****\n");
		printf("****		0.Exit                             ****\n");
		printf("*********************************************************\n");
		printf("\n\n---->>Please input your option: ");
		int d;
		scanf("%d",&d);
		switch(d)
		{
			case 1:
				{
					InsetSort(A,N);
					printf("Inset Sort:\n");
					print(A,N);
				}
				break;
			case 2:
				{
					BubbleSort(A,N);
					printf("Bubble Sort:\n");
					print(A,N);
				}
				break;
			case 3:
				{
					SelectSort(A,N);
					printf("Select Sort:\n");
					print(A,N);
				}
				break;
			case 4:
				{
					ShellSort(A,N);
					printf("Shell Sort:\n");
					print(A,N);
				}
				break;
			case 5:
				{
					int *B = (int*)malloc(sizeof(int)*N);
					if(B==NULL)
					{
						exit(1);
					}
					MergeSort(A,B,0,9);
					printf("Merge Sort:\n");
					print(A,N);
					free(B);
					B = NULL;
				}
				break;
			case 6:
				{
					HeapSort(A,N);
					printf("Heap Sort:\n");
					print(A,N);
				}
				break;
			case 7:
				{
					QuickSort(A,0,9);
					printf("Quick Sort:\n");
					print(A,N);
				}
				break;
			case 8:
				{
				}
				break;
			case 0:
				{
					quit =1;
				}
				break;
			default:
				{
					break;
				}
		}//end of switch()
	}//end of while()
	return 1;
}//end of main()


