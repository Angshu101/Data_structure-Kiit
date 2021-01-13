#include<stdio.h>
#include<stdlib.h>
int main()
 {
    int *arr,i,n,count=0;
    printf("Enter the size of the dynamic array");
     scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
     for(i=0;i<n;i++)
     {
         scanf("%d",arr+i);
      }
   int left = 0, right = n-1,temp=0; 
    while (left < right) 
    { 
        
        while (arr[left]%2 == 0 && left < right) 
            left++; 
  

        while (arr[right]%2 == 1 && left < right) 
            right--; 
  
        if (left < right) 
        { 
        
            temp=arr[left];
            arr[left]=arr[right];
            arr[right]=temp;
            left++; 
            right--; 
        } 
    } 
    for(i=0;i<n;i++)
     {
         printf("%d ",*(arr+i));
     }
     return 0;
 }