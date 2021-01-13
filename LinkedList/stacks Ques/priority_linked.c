#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
     int data;
     int prr;
     struct Node *next;
}node;
// node *front=NULL;
// node *rear=NULL;
// node *head=NULL;
node *new_node (int a ,int b){
   node *temp=(node*)malloc(sizeof(node));
   temp->data=a;
   temp->prr=b;
   temp->next=NULL;
   
   return temp;

}
void enque(node** head){
    int data,prio;
    printf("ENter the data for the node:- ");
    scanf("%d",&data);
    printf("Enter the priority for the node");
    scanf("%d",&prio);
    node *temp=new_node(data,prio);
     node *start= (*head);
    if((*head)->prr>prio){
        temp->next=(*head);
        (*head)=temp;
    }
    else{
        while(start->next!=NULL && start->next->prr<prio){
            start=start->next;
        }
        temp->next=start->next;
        start->next=temp;

    }
}
void deque(node** head){
node *temp=(*head);
(*head)=(*head)->next;
// free(temp);
}
int peek(node** head){
 return ((*head)->data);
}
int isEmpty(node** head) 
{ 
    return (*head) == NULL; 
} 
// void display(){
//       node *temp=head;
//       while(temp->next!=NULL){
//           printf("%d---->",&temp->data);
//           temp=temp->next;
//       }
  
// }
int main(){
    int a,pr,ch;
    printf("Enter data and priority:- ");
    scanf("%d %d",&a,&pr);
    node *new=new_node(a,pr);
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
               enque(&new);
            break;
        case 2:
              deque(&new);
              break;
        case 3:
                 while (!isEmpty(&new)) { 
                     printf("%d--->",peek(&new)); 
                      deque(&new); 
                     }
                     printf("\n"); 
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