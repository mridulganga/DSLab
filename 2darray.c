#include<stdio.h>
#include<stdlib.h>

void main()
{
	int *a,*b,c,r,i,j,option;
	int s1,s2,tmp;

	printf("Enter the number of Rows and Columns : \n");
	scanf("%d%d",&r,&c);

	a = (int *) malloc(sizeof(int)*c*r);

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
	
	printf("Enter your choice \n1.Swap two rows\n2.Swap two columns\n");
	scanf("%d",&option);
	
	if(option==1)	//swap rows
	{
		printf("What two row numbers do you want to swap ? \n");
		scanf("%d%d",&s1,&s2);
		
		for (i=0;i<c;i++)
		{
			tmp = *(a+s1*r+i);
			*(a+s1*r+i) = *(a+s2*r+i);
			*(a+s2*r+i) = tmp;
		}	
	}
	 else if(option==2)   //swap cols
        {
                printf("What two column numbers do you want to swap ? \n");
                scanf("%d%d",&s1,&s2);

                
		for (i=0;i<r;i++)
                {
                        tmp = *(a+i*r+s1);
                        *(a+i*r+s1) = *(a+i*r+s2);
                        *(a+i*r+s2) = tmp;
                }
        }
 
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
			printf(" %d ",*(a + i*c + j));
		printf("\n");
	}
}
