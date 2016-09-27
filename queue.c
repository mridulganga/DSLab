#include<stdio.h>
#include<stdlib.h>

#define max 10

struct queue{
	int front,rear;
	int item[max];

};

typedef struct queue QUEUE;

//queue empty rear < first
//queue full rear = max-1

int enque(QUEUE *q,int item){
	if (q->rear==max-1) return 0;	//queue full
	
	q->item[++(q->rear)] = item;
	return 1;
}

int deque(QUEUE *q,int *item){
	if (q->rear < q->front) return 0;	//queue underflow
	
	*item = q->item[q->front];
	q->front = q->front+1;
	if (q->rear < q->front)
	{	q->front=0;q->rear=-1;
		return -1;	//queue empty
	}
	return 1;
}

int display(QUEUE *q){
	int i;
	if (q->front>q->rear) return 0;	//display elemets from front to rear
	
	for (i=q->front;i<=q->rear;i++)
		printf("%d\n",q->item[i]);
	return 1;
}

int main(){

	QUEUE q1;
	int option,item;
	//initialise front and rear
	q1.front=0;
	q1.rear=-1;
	
	option=1;
   while(option){
	printf("Select an option\n1. Enque\n2. Deque\n3. Display\n0. Exit\n");
	scanf("%d",&option);
	
	switch(option)
	{
		case 1:	//add item
			printf("Enter the element to enque\n");
			scanf("%d",&item);
			if (enque(&q1,item))
				printf("Item Successfullty Enqued\n");
			else
				printf("Queue is full\n");
		break;
	
		case 2:	//remove item
			if (deque(&q1,&item))
				printf("%d was dequed\n",item);
			else
				printf("Queue is empty\n");
		break;
	
		case 3:	//display items
			display(&q1);	
		break;
	
		case 0:	//exit program
		break;
	}
   }
	return 0;
}
