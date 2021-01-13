#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employe{
int id,basic;
float hr,da,gross;
char name[32];
char gen;
};

void printSalary(struct employe e1) {
        printf("Salary Slip of  %s:\n", e1.name);
        printf("Employee ID: %d\n", e1.id);
        printf("Basic Salary: %d\n", e1.basic);
        printf("House Rent Allowance: %d\n", e1.hr);
        printf("Dearness Allowance: %d\n", e1.da);
        printf("Gross Salary: %.2f Rupees\n", e1.gross);
        return;
  }
int main(){
     int i, ch, num, flag, empID;
        struct employe e1[90];

        /* get the number of employees from the user  */
        printf("Enter the number of employees:");
        scanf("%d", &num);
       

     for (i = 0; i < num; i++) {
                printf("Employee ID: ");
                scanf("%d", &(e1[i].id));
                getchar();
                printf("Employee Name: ");
                fgets(e1[i].name, 32, stdin);
                e1[i].name[strlen(e1[i].name) - 1] = '\0';
                printf("Basic Salary:- ");
                scanf("%d", &(e1[i].basic));
     }
     //calculation of da,hra and gross
      for(i=0;i<num;i++){
          e1[i].da=0.75 * e1[i].basic;
          e1[i].hr=0.5 * e1[i].basic;
          e1[i].gross=e1[i].da+e1[i].hr+e1[i].basic;
      }
    while (1) {
                printf("Enter employee ID to get payslip:");
                scanf("%d", &empID);
                flag = 0;
                for (i = 0; i < num; i++) {
                        if (empID == e1[i].id) {
                                printSalary(e1[i]);
                                flag = 1;
                        }
                }

                if (!flag) {
                        printf("No Record Found!!\n");
                }

                printf("Do You Want To Continue(1/0):");
                scanf("%d", &ch);

                if (!ch) {
                        break;
                }
        }
        return 0;

}
