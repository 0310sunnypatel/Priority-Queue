#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int data[20];
    int f,r;
    int count;
}q;
void initialize(struct queue *q)
{
    q->f=-1;
    q->r=-1;
    q->count=0;
}
void insert(struct queue *q,int ele)
{
    if(q->count==5)
        printf("Overflow\n");
    else
    {
        if(q->count==0)
        {
            q->f=q->r=0;                    //for empty queue
            q->data[q->r]=ele;
            q->count++;
        }
        else
        {
            q->r=(q->r+1)%5;                 //updation for queue index/address //5 is the size of the array/queue
            q->data[q->r]=ele;               // for non-empty queue
            q->count++;
        }
    }
}
void rem(struct queue *q)
{
    if(q->count==0)
        printf("Underflow\n");
    else if(q->r==q->f)                     //condition to check single element
    {
        printf("Removed Element is : %d\n",q->data[q->f]);
        q->f=q->r=-1;
        q->count--;
    }
    else
    {
        printf("Removed Element is : %d\n",q->data[q->f]);
        q->f=(q->f+1)%5;
        q->count--;
    }
}
void display(struct queue *q)
{
    int i;
    if(q->count==0)
        printf("Queue is empty\n");
    else
    {
        printf("The Queue is :\t");
        for(i=q->f;i!=q->r;i=(i+1)%5)
            printf("%d\t",q->data[i]);
        printf("%d\n",q->data[i]);
    }
}
void main()
{
    initialize(&q);
    int a,ele;
    while(1)
    {
        printf("Enter choice :\n 1.Insert\n 2.Remove\n 3.Display\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1:printf("ENTER THE ELEMENT:");
                   scanf("%d",&ele);
                   insert(&q,ele);
                   break;
            case 2:rem(&q);
                   break;
            case 3:display(&q);
                   break;
            case 4:exit(0);
                   break;
        }
    }
}
