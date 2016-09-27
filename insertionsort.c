#include<stdio.h>
#include<stdlib.h>
void printA(int *a,int len);

void main()
{
	int *a,i,j,n,min,tmp;

	printf("Enter the number of elements : ");
	scanf("%d",&n);

	a = (int *) malloc(n*sizeof(int));
	printf("Enter the elements : \n");
	for (i=0;i<n;i++)	//take input
		scanf("%d",a+i);

	printA(a,n);
	//Insertion sort
	for (i=0;i<n;i++)
	{
		min=i;
		for (j=i;j<n;j++)
		{
			if(*(a+min)>*(a+j))
			{
				min = j;
			}
		}
		if (min!=i)
		{
			tmp = *(a+i);
			*(a+i) = *(a+min);
			*(a+min) = tmp;
		}
		
		printA(a,n);
	
	}
}

void printA(int *a,int len)
{
	int i;
	for (i=0;i<len;i++)
		printf(" %d ,",*(a+i));
	printf("\n");
}
