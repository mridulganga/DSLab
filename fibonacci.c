#include<stdio.h>

int Fibonacci(int n)
{
   if ( n == 0 )
      return 0;
   else if ( n == 1 )
      return 1;
   else
      return ( Fibonacci(n-1) + Fibonacci(n-2) );
} 
 
int main()
{
   int n, i ;
   printf("Enter the number of terms\n");
   scanf("%d",&n);
   printf("Fibonacci series\n");
 
   for ( i = 1 ; i <= n ; i++ )
      printf("%d\n", Fibonacci(i));
 
   return 0;
}
 

