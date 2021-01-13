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
void insert_end(){
    struct node *new_node,*ptr;
     new_node=(struct node *)malloc(sizeof(struct node));
      if(new_node==NULL)
        {
                printf("nOut of Memory Space:n");
                return;
        }
     printf("Enter the data:-");
     scanf("%d",&new_node->data);
     ptr=head;
     if(head==NULL){
         head=new_node;
     }
     else{
         while(ptr!=NULL){
             ptr=ptr->next;
         }
         new_node->next=ptr->next;
         

         
     }
}
void insert_pos(){
    struct node *new_node,*ptr;
    int pos,i;
    new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node=NULL){
        printf("No space");
        exit(0);
    }
    printf("Enter the positon you want to enter the node");
    scanf("%d",&pos);
    printf("Enter the value in node:");
    scanf("%d",&new_node->data);

     if(pos==0){
         new_node->next=head;
        head=new_node;
    }
   else{
      
       for( i=0, ptr=head;i<(pos-1);i++){
           ptr=ptr->next;
           if(ptr==NULL){
               printf("position  not found");
           }
       }
       new_node->next=ptr->next;
       ptr->next=new_node;
   }

}
void delete_begin()
{
        struct node *ptr;
        if(ptr==NULL)
        {
                printf("nList is Empty:n");
                return;
        }
        else
        {
                ptr=head;
                head=head->next ;
                printf("nThe deleted element is :%dt",ptr->data);
                free(ptr);
        }
}
void delete_end()
{
        struct node *temp,*ptr;
        if(head==NULL)
        {
                printf("nList is Empty:");
                exit(0);
        }
        else if(head->next ==NULL)
        {
                ptr=head;
                head=NULL;
                printf("nThe deleted element is:%dt",ptr->data);
                free(ptr);
        }
        else
        {
                ptr=head;
                while(ptr->next!=NULL)
                {
                        temp=ptr;
                        ptr=ptr->next;
                }
                temp->next=NULL;
                printf("nThe deleted element is:%dt",ptr->data);
                free(ptr);
        }
}
void delete_pos()
{
        int i,pos;
        struct node *temp,*ptr;
        if(head==NULL)
        {
                printf("nThe List is Empty:n");
                exit(0);
        }
        else
        {
                printf("nEnter the position of the node to be deleted:t");
                scanf("%d",&pos);
                if(pos==0)
                {
                        ptr=head;
                        head=head->next ;
                        printf("nThe deleted element is:%dt",ptr->data  );
                        free(ptr);
                }
                else
                {
                        ptr=head;
                        for(i=0;i<pos;i++) { temp=ptr; ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("nPosition not Found:n");
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        printf("nThe deleted element is:%dt",ptr->data );
                        free(ptr);
                }
        }
}
void del_key(){
    int k;
    printf("the number to be deleted");
    scanf("%d",&k);
    struct node *temp,*prev;
    prev=NULL;
    if(head==NULL){
        printf("List is Empty");
        return;

    }
    temp=head;
    if(temp!=NULL && temp->data==k){
        temp=temp->next;
    }
    while(temp !=NULL && temp->data !=k){
           prev=temp;
           temp=temp->next;
       }

    prev->next=temp->next;
}
void total_nod(){
    struct node *temp;
    temp=head;
    int ctr=0;
    while(temp!=NULL){
        temp=temp->next;
        ctr++;
    }
   printf("The number of nodes in the list is %d ",ctr);
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
void search(){
        int n,k=1;
        printf("Enter the element to be searched :-");
        scanf("%d",&n);
        struct node *temp;
        temp=head;
        while(temp!=NULL){
                if(temp->data==n){
                        printf("element is found");
                        k=0;
                        break;
                }
        }
        if(k==1){
                printf("Element not found");
        }
}

int main()     
{
        int choice;
        while(1){
               
                printf("n                MENU                             \n");
                printf("n 1.Create     \n");
                printf("n 2.Display    \n");
                printf("n 3.Insert at the beginning    \n");
                printf("n 4.Insert at the end  \n");
                printf("n 5.Insert at specified position       \n");
                printf("n 6.Delete from beginning      \n");
                printf("n 7.Delete from the end        \n");
                printf("n 8.Delete from specified position     \n");
                printf("n 9.delete particular element \n");
                printf("n 10.calculate total number of nodes \n");
                printf("n 11.search an element in linked list \n");
                 printf("n 12. exit(0) \n");
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
                                        insert_end();
                                        break;
                        case 5:
                                        insert_pos();
                                        break;
                        case 6:
                                        delete_begin();
                                        break;
                        case 7:
                                        delete_end();
                                        break;
                        case 8:
                                        delete_pos();
                                        break;
                        case 9:
                                       del_key();
                                       break;
                        case 10:      total_nod();
                                      break;
                                       
                        case 11:
                                       search();
                                        break;
                        case 12:
                                        exit(0);
                                        break;
                             
                        default:
                                        printf("n Wrong Choice:n");
                                        break;
                }
        }
        return 0;
        free(head);
       //free(struct node);
}