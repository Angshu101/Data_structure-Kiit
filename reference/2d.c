#include<stdio.h>
#include<stdlib.h>
int main() 
{ 
    int r ,c;
    printf("Enter rows and coloumn");
    scanf("%d %d",&r,&c);
    int arr[r][c];
     int i, j, count ,n; 
    for (i = 0; i <  r; i++) 
      for (j = 0; j < c; j++) 
      {
          printf("Enter elements :-");
           scanf("%d", &arr[i][j]);
          
      }
      printf("The matrix is:-");
      for (i = 0; i <  r; i++) 
      for (j = 0; j < c; j++) 
      {
          printf("%d",arr[i][j]));
          
      }