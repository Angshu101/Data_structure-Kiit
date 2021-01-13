#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
  int coeff;
  int exp;
  struct node *next;
};
struct node *head=NULL;
void create_node(int x,int y,struct node **temp){
    struct node *r,*z;
    z=*temp;
    if(z==NULL){
        r=(struct node*)malloc(sizeof(struct node));
        r->coeff=x;
        r->exp=y;
        *temp=r;
        r->next=(struct Node*)malloc(sizeof(struct node));
        r=r->next;
        r->next=NULL;
    }
    else{
        r->coeff=x;
        r->exp=y;
        r->next=(struct node*)malloc(sizeof(struct node));
        r=r->next;
        r->next=NULL;

    }
}
void polyadd(struct node *poly1,struct node *poly2,struct node *poly){
    while(poly1->next && poly2->next){
       if(poly1->exp>poly2->exp){
           poly->exp=poly1->exp;
           poly->coeff=poly1->coeff;
           poly1=poly1->next;

       }
       else if(poly1->exp<poly2->exp){
           poly->exp=poly2->exp;
           poly->coeff=poly2->coeff;
           poly2=poly2->next;
       }
       else{
           poly->exp=poly1->exp;
           poly->coeff=poly1->coeff+poly2->coeff;
           poly1=poly1->next;
           poly2=poly2->next;
       }
       poly->next=(struct node*)malloc(sizeof(struct node));
       poly=poly->next;
       poly->next=NULL;
    }
    while(poly1->next || poly2->next){
        if(poly1->next){
            poly->exp=poly1->exp;
            poly->coeff=poly1->coeff;
            poly1=poly1->next;
        }
         if(poly2->next) 
        { 
            poly->exp = poly2->exp; 
            poly->coeff = poly2->coeff; 
            poly2 = poly2->next; 
        } 
        poly->next=(struct node*)malloc(sizeof(struct node));
        poly=poly->next;
        poly->next=NULL;
    }
}
void show(struct node *expe){
    while(expe->next!=NULL){
        printf(" %dx^%d",expe->coeff,expe->exp);
        expe=expe->next;
        if(expe!=NULL){
            printf("+");
        }
    }
}
int main() 
{ 
    struct node *poly1 = NULL, *poly2 = NULL, *poly = NULL; 
      int n;
      printf("Enter the number of nodes for polynomial 1");
       scanf("%d",&n);
       for(int i=0;i<n;i++){
           int num,pow;
           printf("Enter number:-");
           scanf("%d",&num);
           printf("\n");
           printf("Enter power");
           scanf("%d",&pow);

         create_node(num,pow,&poly1); 
       }
    
    // create_node(4,1,&poly1); 
    // create_node(2,0,&poly1); 
      
    // Create second list of 5x^1 + 5x^0 
    // create_node(5,1,&poly2); 
    // create_node(5,0,&poly2); 
    printf("Enter the number of nodes for polynomial 2");
       scanf("%d",&n);
       for(int i=0;i<n;i++){
           int num,pow;
           printf("Enter number:-");
           scanf("%d",&num);
           printf("\n");
           printf("Enter power");
           scanf("%d",&pow);

         create_node(num,pow,&poly2); 
       }

    printf("1st polynomial:-  ");  
    show(poly1); 
      
    printf("\n2nd Number:  "); 
    show(poly2); 
      
    poly = (struct Node *)malloc(sizeof(struct node)); 
      
    // Function add two polynomial numbers 
    polyadd(poly1, poly2, poly); 
      
    // Display resultant List 
    printf("\nAdded polynomial: "); 
    show(poly); 
  
return 0; 
} 