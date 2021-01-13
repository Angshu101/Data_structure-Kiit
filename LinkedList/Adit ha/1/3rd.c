#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
   struct node *next;
};
struct node *head=NULL;
void create(){
    struct node *ptr,*temp;
    temp=(struct node*)malloc(sizeof(struct node));
     if(temp==NULL)
        {
                printf("no space");
                exit(0);
        }
     printf("nEnter the data value for the node:t");
        scanf("%d",&temp->data);
     temp->next=NULL;
     if(head==NULL){
         head=temp;
     }
    else
        {
                ptr=head;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=temp;
        }

}
void insert_beg(){
   
    struct node *temp;
     temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("nOut of Memory Space:n");
                return;
        }
        printf("nEnter the data value for the node:t" );
        scanf("%d",&temp->data);
        temp->next=NULL;
        if(head==NULL){
            head=temp;
        }
        else{
            temp->next=head;
            head=temp;
        }

}
void display()
{
        struct node *ptr;
        if(head==NULL)
        {
                printf("nList is empty:n");
                return;
        }
        else
        {
                ptr=head;
                printf("nThe List elements are:n");
                while(ptr!=NULL)
                {
                        printf("%d----->",ptr->data );
                        ptr=ptr->next ;
                }
        }
}
 struct node reverse_list(){
//     struct node *prev,*next,*curr,*temp;
//     temp=head;
//     prev=NULL;
//     next=NULL;
//     curr=head;
//     int k,c=1;
//     printf("Enter the kth element till  where you want to reverse :-");
//     scanf("%d",&k);
//      while(c<k){
//          temp=temp->next;
//          c++;

//      }
//      struct node *join=temp->next;
//      temp->next=NULL;  //break point;
//      while(curr!=NULL){
//          next=curr->next;
//          curr->next=prev;
//          prev=curr;
//          curr=next;
         
//      }
//      head=prev;
//      curr=head;
//     while(curr!=NULL)
//         curr=curr->next;
//    curr->next=join;
//    return  node head;
 //joining two linked list
 int n;
 printf("Enter the kth term");
 scanf("%d",&n);
 struct node *p, *q, *r, *rear;
 
    p = q = r = head;
    if (n == 0)
    {
        q = q->next;
        p->next = q->next;
        q->next = p;
        head = q;
    }
    else
    {
        p = p->next->next;
        q = q->next;
        r->next = NULL;
        rear = r;
        q->next = r;
 
        while (n > 0 && p != NULL)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
            n--;
        }
        head = q;
        rear->next = p;
    }
}
   

int main(){
    int choice;
        while(1){
               
                printf("n                MENU                             \n");
                printf("n 1.Create     \n");
                printf("n 2.Display    \n");
                printf("n 3.Insert at the beginning    \n");
                printf("n 4.calculate total_node  \n");
                 printf("n 5. exit(0) \n");
                printf("n--------------------------------------n");
                printf("Enter your choice:- ");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        create();
                                        break;
                        case 2:
                                        display();
                                        break;
                        case 3: 
                                        insert_beg();
                                        break;
                        case 4:
                                       reverse_list();
                                        break;
                        case 5:
                                        exit(0);
                                        break;
                        default:        printf("wrong choice");
                                        break;
                }
        }
}