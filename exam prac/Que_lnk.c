#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define FULL 10

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

struct queue
{
    int count;
    node *front;
    node *rear;
};
typedef struct queue queue;

void initialize(queue *q)
{
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}

int isempty(queue *q)
{
    return (q->rear == NULL);
}

void enqueue(queue *q, int value)
{
    if (q->count < FULL)
    {
        node *tmp;
        tmp = malloc(sizeof(node));
        tmp->data = value;
        tmp->next = NULL;
        if(!isempty(q))
        {
            q->rear->next = tmp;
            q->rear = tmp;
        }
        else
        {
            q->front = q->rear = tmp;
        }
        q->count++;
    }
    else
    {
        printf("List is full\n");
    }
}

int dequeue(queue *q)
{
    node *tmp;
    int n = q->front->data;
    tmp = q->front;
    q->front = q->front->next;
    q->count--;
    free(tmp);
    return(n);
}

void display(node *head)
{
    if(head == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%d--->", head -> data);
        display(head->next);
    }
}

int main()
{
    int ch,ele;
    queue *q;
    q = malloc(sizeof(queue));
    initialize(q);
    while(1){
        printf("-------MENU---------\n");
        printf("1. ENQUE \n");
        printf("2 DEQUE \n");
        printf("3 Display \n");
        printf("4.exit \n");
        printf("Enter your choice :-");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
                printf("Enter the data- ");
                scanf("%d",&ele);
               enqueue(q,ele);
            break;
        case 2:
             dequeue(q);
              break;
        case 3:
                 display(q->front);
                     break;
        case 4:
              exit(0);
              break;
        
        default:
                printf("Wrong choice");
                  break;
        }

    }
    return 0;
}