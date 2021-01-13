#include<stdio.h>
void funnt(int *p);
main(){
    int a[]={10,20,30,40,50,60,70,80};
    funnt(a+3);
}
void funnt(int *p){
    int i,sum=0;
    for(i=3;i<5;i++)
    sum+=*(p+i);
    printf("Sum  -: %d",sum);
    return;
}