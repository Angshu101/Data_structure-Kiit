#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
struct student
{
    int roll_no,marks;
    char name[25];
}stud[100],t;
 
void main()
{
    int i,j,n;
    printf("Enter the no of students\n");
    scanf("%d",&n);
    printf("enter student info as roll_no , name , marks\n");
    for(i=0;i<n;i++)
    {
        scanf("%d %s %d",&stud[i].roll_no,stud[i].name,&stud[i].marks);
    }
    
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(stud[i].name,stud[j].name)>0)
            {
                t=stud[i];
                stud[i]=stud[j];
                stud[j]=t;

            }
        }
    }
    
    printf("\nStudent info in terms of marks from highest to lowest\n");
    printf("\nROLL_NO\t\tNAME\t\tMARKS\n");
    printf("-------------------------------------------------------------------------------\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t\t%s\t\t\t%d\n",stud[i].roll_no,stud[i].name,stud[i].marks);
    }
}