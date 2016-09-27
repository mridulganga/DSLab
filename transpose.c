#include<stdio.h>
#include<stdlib.h>

void main()
{
	int *a,*b,c,r,i,j;
	
	printf("Enter the number of Rows and Columns : \n");
	scanf("%d%d",&r,&c);

	a = (int *) malloc(sizeof(int)*c*r);
	b = (int *) malloc(sizeof(int)*r*c);	

	printf("Enter the Elements of Matrix : \n");
	for (i=0;i<r*c;i++)
		scanf("%d",a+i);

	printf("The Entered array is : \n");
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			printf(" %d ",*(a + i*c + j));
		}
		printf("\n");
	}
	
	printf("The Transpose : \n");
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			*(b+j*r+i) = *(a+i*c+j);
		}
	}
	for (i=0;i<c;i++)
	{
		for (j=0;j<r;j++)
			printf(" %d ",*(b + i*r + j));
		printf("\n");
	}
}
