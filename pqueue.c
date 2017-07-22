#include<stdio.h>

struct pqueue
{
    int data[20];
    int f,r;
    int count;              //counter variable
}pq;
void initialize(struct pqueue *pq)
{
    pq->f=-1;
    pq->r=-1;
    pq->count=0;
}
void insert(struct pqueue *pq,int ele)
{
    int i=pq->r;
    if(pq->count==20)
        printf("Overflow\n");
    else if((pq->f==-1)&&(pq->r==-1))
    {
        pq->f=0;
        pq->r=0;
        pq->data[pq->r]=ele;
        pq->count++;
    }
    else
    {
        while(ele>pq->data[i])
        {
            pq->data[(i+1)%20]=pq->data[i];
            i=(i-1+20)%20;
            
            if(pq->f==(i+1)%20)
                break;
        }
        i=(i+1)%20;
        pq->data[i]=ele;
        pq->r=(pq->r+1)%20;
        pq->count++;
    }
}
void display(struct pqueue *pq)
{
    int i;
    
    for(i=pq->f; i!=pq->r; i=(i+1)%20)
        printf("%d ", pq->data[i]);
    printf("%d\n", pq->data[i]);
}
    
void main()
{
    initialize(&pq);
    int ele,a;
    while(1)
    {
        printf("Enter Choice:\n 1.Insert\t 2.Display\n");
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
