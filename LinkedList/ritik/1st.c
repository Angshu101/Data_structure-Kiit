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
                        printf("               /n");
                        ptr=ptr->next ;
                }
        }
}
int main()     
{
        int choice;
        while(1){
               
                printf("n                MENU                             \n");
                printf("n 1.Create     \n");
                printf("n 2.Display    \n");
                printf("n 3 exit        \n");
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
                        case 3:         exit(0);
                                         break;
                        default:
                                        printf("n Wrong Choice:n");
                                        break;
                }
        }
        free(head);
    return 0;
}