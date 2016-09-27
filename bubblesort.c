#include<stdio.h>

void main()
{
	int *a,i,j,n;

	printf("Enter the number of elements : ");
	scanf("%d",&n);

	a = (int *) malloc(n*sizeof(int));
	printf("Enter the elements : \n");
	for (i=0;i<n;i++)	//take input
		scanf("%d",a+i);


}
