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
void remove_dups(){
   struct node *p, *q, *prev, *temp;
 
    p = q = prev = head;
    q = q->next;
    while (p != NULL)
    {
        while (q != NULL && q->data != p->data)
        {
            prev = q;
            q = q->next;
        }
        if (q == NULL)
        {
            p = p->next;
            if (p != NULL)
            {
                q = p->next;
            }
        }
        else if (q->data == p->data)
        {
            prev->next = q->next;
            temp = q;
            q = q->next;
            
        }
    }
    
}
int main(){
    
    int choice;
        while(1){
               
                printf("n                MENU                             \n");
                printf("n 1.Create     \n");
                printf("n 2.Display    \n");
                printf("n 3.Insert at the beginning    \n");
                printf("n 4.remove duplicate  \n");
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
                                       remove_dups();
                                        break;
                        case 5:
                                        exit(0);
                                        break;
                        default:        printf("wrong choice");
                                        break;
                }
        }
}
