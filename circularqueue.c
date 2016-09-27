#include<stdio.h>
#define max 3

struct queue{
    int item[max];
    int front,rear;
};

typedef struct queue CQ;

//empty queue front=0 rear=-1
//full queue rear+1 = front || (front=0 && rear=max-1)
//one element front==rear

int insert(CQ *q,int item){
    if(((q->rear+1 == q->front)&& q->rear!=-1) || (q->front==0 && q->rear==max-1)) return 0;

    //Properly increment rear and add the item
    q->rear = (q->rear+1)%max;
    q->item[q->rear] = item;
    return 1;
}

int delete(CQ *q,int *item){
    if(q->rear==-1) return 0;  //queue empty
    if(q->front==q->rear){      //one element in queue
        *item = q->item[q->front];
        q->front=0;q->rear=-1;     //queue is empty
        return -1;
    }
    else {
        *item = q->item[q->front];
        q->front = (q->front + 1)%max;  //properly increment front
        return 1;
    }
}

int display(CQ *q){
    int i;
    if(q->rear==-1) return 0;  //queue empty
    if(q->rear < q->front){
        for (i = 0; i <= q->rear; i++)  //0 to rear
            printf("%d\n",q->item[i]);
        for (i = q->front; i<max;i++)   //front to max-1
            printf("%d\n",q->item[i]);
    } else
    {
        for (i = q->front; i <= q->rear; i++)   //front to rear
            printf("%d\n",q->item[i]);
    }
    return 1;
}


int main()
{
    int ch,item,ret;
    CQ c1;
    c1.front=0;c1.rear=-1; //initialise circular queue

    printf("\nCircular Queue Operations\n");

    while(1)
    {   printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter the Item to Insert\n");
                scanf("%d",&item);
                if(insert(&c1,item))
                    printf("Item Was Inserted\n");
                else
                    printf("Queue is Full\n");
            break;

            case 2:
                ret = delete(&c1,&item);
                if(ret==1)
                    printf("%d was removed\n",item);
                else if(ret==-1)
                    printf("%d was removed\nQueue is now empty\n",item);
                else
                    printf("Queue is empty\n");
            break;

            case 3:
                if(display(&c1)==0)
                    printf("Queue is empty\n");
            break;

            case 4:
                return 0;

            default:printf("Invalid option\n");
        }
    }
    return 0;
}

