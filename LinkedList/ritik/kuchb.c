#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr;
    ptr=(int *)malloc(10);
    printf("%d",sizeof(ptr));
    free(ptr);
    return 0;
}