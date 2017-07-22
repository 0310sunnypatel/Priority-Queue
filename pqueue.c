#include<stdio.h>
struct pqueue
{
    int data[20];
    int f,r;
    int k;              //counter variable
}pq;
void initialize(struct pqueue *pq)
{
    pq->f=-1;
    pq->r=-1;
    pq->k=0;
}
void insert(struct pqueue *pq,int ele)
{
    int i=pq->r;
    if(pq->k==5)
        printf("Overflow\n");
    else if((pq->f==-1)&&(pq->r==-1))
    {
        pq->f=0;
        pq->r=0;
        pq->data[pq->r]=ele;
        pq->k++;
    }
    else
    {

        while(ele>(pq->data[i]))
        {
            pq->data[(i+1)%5]=pq->data[i];
            i=(i-1+5)%5;
            if(pq->f==(i+1)%5)
                break;
        }
    }
        i=(i+1)%5;
        pq->data[i]=ele;
        (pq->r+1)%5;
        pq->k++;

}
void display(struct pqueue *pq)
{
    int i;
    if(pq->k==0)
        printf("Underflow\n");
    else
        {
            printf("The Priority Queue is as follows : ");
            for(i=pq->f;i!=pq->r;(i+1)%5)
                printf("%d ",pq->data[i]);
            printf("%d\n",pq->data[i]);
        }
}
void main()
{
    initialize(&pq);
    int ele,a;
    while(1)
    {
        printf("Enter Choice:\n 1.Insert\n 2.Display\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1:printf("ENTER THE ELEMENT: ");
                   scanf("%d",&ele);
                   insert(&pq,ele);
                   break;
            case 2:display(&pq);
                   break;
            default:printf("Invalid Entry\n");
        }
    }
}
