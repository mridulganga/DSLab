#include<stdio.h>

void main()
{
	int i,n,j;
	long int op=1;
	printf("Enter the no of levels\n");
	scanf("%d",&n);	
	
	for (i=1;i<=n;i++)
	{
		for (j=0;j<(n-i)/2;j++)
			printf(" ");
		printf("%ld\n",op);
		op*=11;
	}

}
