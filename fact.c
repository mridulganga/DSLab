#include<stdio.h>

int fact(int n)
{
	if (n==0)
		return 1;
	return n*fact(n-1);
}

void main(){
	printf("factorial of 5 is %d",fact(5));
}
