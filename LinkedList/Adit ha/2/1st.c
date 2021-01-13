//triangular matrix
#include<stdio.h>
#include<stdlib.h>
static int N=4;
int main(){
    int r,c;
    r=4;
    c=4;
    printf("The  row  is %d and coloumn is %d",r,c);
    int arr[r][c];
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            printf("Enter the value for a[%d][%d]",i,j);
            scanf("%d",&arr[i][j]);
            printf("\n");
        }
    }
    printf("The Matrix is :- \n");
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
  
             int i,j,flag=0;
                    for (i = 1; i < r; i++)
		            for (j = 0; j < i; j++)
			           if (arr[i][j] != 0)
				            flag = 0;
			           else
				          flag = 1;
  
      	            if (flag == 1){
		            printf("Upper Triangular Matrix");
                    return 0;
                    }
                      
	                 else
		            printf("Not an Upper Triangular Matrix");
                
                  int check=check_lower_triangular_matrix(arr);

           	      if (check){
		             printf("Lower Triangular Matrix");
                     return 0;}
	              else
		            printf("Not a Lower Triangular Matrix");
                   
	       
                      
    

  }
int check_lower_triangular_matrix(int mat[N][N])
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++)
			if (mat[i][j] != 0)
				return 0;
return 1;
}