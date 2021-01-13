#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct number{
 int a ;
 int b;
 int sum;

};
void add_num(struct number e1){
     e1.sum=e1.a+e1.b;
     printf("The sum is %d",e1.sum);
}
int main(){
    
    struct number e1[5];
   
       
        
            printf("The numbers are:- ");
            scanf("%d",&e1[1].b);
            scanf("%d ",&e1[1].a);
            add_num(e1[1]);
        
        return 0;
}