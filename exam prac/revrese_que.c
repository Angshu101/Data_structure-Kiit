#include<stdio.h>
#include<stdlib.h>
#define FULL 10
int top=-1;
int stack[FULL];
typedef struct Node{
    int data;
    struct Node *next;
}node;
typedef struct queue{
    int count;
    node *front;
    node *rear;
}queue;
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
void push(int n){
    if(top==FULL-1){
        printf("Stack is FULL");
     }
     else{
           top++;
           stack[top]=n;
          
        }
}

void enqueue(queue *q, int value)
{
    if (q->count < FULL)
    {
        node *tmp;
        tmp = malloc(sizeof(node));
        tmp->data = value;
        tmp->next = NULL;
         push(value);
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
int pop(){
    if(top==-1){
        printf("Underflow");
        // return;
    }
    int e;
    e=stack[top];
    top--;
    return e;
}
void reverse_que(node *q){
    printf("The actual list is:- \n");
    node *temp=q;
    while(temp!=NULL){
        printf("%d---->",temp->data);
       
        temp=temp->next;
    }
    printf("\n");
    printf("The reverse Que is:-\n");
    for(int i=top;i>=0;i--){
        printf("%d---->",stack[i]);
        }
     printf("\n");
    
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
        printf("3 Reverse \n");
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
                 reverse_que(q->front);
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