#include<stdio.h>

#define max 5

/*
 *    Stacks Program
 *    Author - Mridul Ganga
 *
 *    Single Stack Implementation
 *    using structures and fixed 
 *    maximum value.
 *
 *    functions - push,pop,isFull,isEmpty
 *
 * */


struct stack{
	int item[max];
	int top;
};
typedef struct stack STACK;

//empty top=-1
// full top=max-1

int push(STACK,int);
int pop (STACK,int);
int isEmpty(STACK);
int isFull(STACK);

//success = 1
//failure = 0
//other = -1

int push(STACK *s,int itm){
	if (isFull(*s)) return 0;//stack full
	
	s->top++;		//increment top
	s->item[s->top] = itm;	//then add item to new position
	return 1;
}

int pop(STACK *s, int *itm)
{
	if (isEmpty(*s)) return 0;//stack empty
	
	*itm = s->item[s->top];		//retrive current top
	s->top--;			//decrement top
	if (s->top==-1) return -1;
	return 1;
}

int isEmpty(STACK *s)
{
	if (s->top==-1) return 1;//if empty send 1
	return 0;
}

int isFull(STACK *s)
{
	if(s->top==max-1) return 1; //if full send 1
	return 0;
}

int main()
{
	STACK s1;
	int option,item,i;
	//initialise top value
	s1.top = -1;
	option=1;

  while(option){
	printf("Enter the Operation to do : \n1. Push Element\n2. Display Elements\n3. Pop Element\n0. Exit\n ");
	scanf("%d",&option);
	switch(option)
	{
		case 0:	//exit program
		break;
		case 1:	//push item
			printf("Enter the Item to push\n");
			scanf("%d",&item);
			if(push(&s1,item))
				printf("The Item was Successfully Pushed\n");
			else	//push fails when stack is full
				printf("Stack Overflow\n");
		break;
		case 2:	//display items
			if (isEmpty(&s1))
			{printf("Stack Empty\n");break;}
			printf("The Elements of the stack are : \n");
			for (i=0;i<=s1.top;i++)
				printf("%d\n",s1.item[i]);
		break;
		case 3:	//pop items
			i = pop(&s1,&item);
			if(i==-1)	//last element popped, returns -1
				{
					printf("%d has been popped\n",item);
					printf("Stack Empty\n");
				}
			else if(i==0)	//stack is already empty
				printf("Stack Underflow\n");
			else
				printf("%d has been popped\n",item);
		break;
	}
  }//while ends here

return 0;
}
