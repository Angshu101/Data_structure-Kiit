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
void search(){
        int n,k=1;
        printf("Enter the element to be searched :-");
        scanf("%d",&n);
        struct node *temp,*prev;
        temp=head;
        prev=NULL;
        while(temp!=NULL){
                temp=temp->next;
                if(temp->data==n){
                        
                        printf("element is found");
                        k=0;
                     if(head==NULL){
        printf("List is Empty");
        return;

    }
    temp=head;
    if(temp!=NULL && temp->data==n){
        temp=temp->next;
    }
    while(temp !=NULL && temp->data !=n){
           prev=temp;
           temp=temp->next;
       }

    prev->next=temp->next;
                 
        struct node *yt;
          yt=(struct node *)malloc(sizeof(struct node));
        if(yt==NULL)
        {
                printf("nOut of Memory Space:n");
                return;
        }
        //printf("nEnter the data value for the node:t" );
        yt->data=n;
        yt->next=NULL;
        if(head==NULL){
            head=yt;
        }
        else{
            yt->next=head;
            head=yt;
        }
              break;
        }
        }
        if(k==1){
                printf("Element not found");
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
void main(){

int choice;
        while(1){
               
                printf("n                MENU                             \n");
                printf("n 1.Create     \n");
                printf("n 2.Display    \n");
                printf("n 3.Insert at the beginning    \n");
                printf("n 4.Search the element  \n");
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
                                        search();
                                        break;
                        case 5:
                                        exit(0);
                                        break;
                        default:        printf("wrong choice");
                                        break;
                }
        }
}