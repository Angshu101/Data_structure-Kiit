#include<stdio.h>
#include<stdlib.h>
int main()
{
  int *arr,n,i,lower_lim,upper_lim,min=999,counter;
   printf("Enter the size of the array");
   scanf("%d",&n);
  arr=(int*)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
   {
      scanf("%d",arr+i);
   }
  printf("Enter the lowerbound:-");
   scanf("%d",&lower_lim);
  printf("Enter the upperbound:-");
   scanf("%d",&upper_lim);
  for(i=0;i<n;i++)
   {
      if(*(arr+i)==lower_lim)
       { 
           int j=i;
           while(*(arr+j)!=upper_lim){
             counter++;
             j++;
             }
             if(counter<min){
                min=counter;
             }
               
       }
       counter=0;
   }
   printf("The minimum distance between %d & %d is:- %d",upper_lim,lower_lim,min);
    return 0;
 }
  