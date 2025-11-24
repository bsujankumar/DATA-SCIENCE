#include <stdio.h>
#include <stdlib.h>

struct Employee{
    int id;
    char name[50];
    float salary;
};

int main(){
    struct Employee *ptr;
    int n,sum = 0;
    printf("Enter the number of employees:\n");
    scanf("%d",&n);
    ptr = (struct Employee *)malloc(n*sizeof(struct Employee));
    printf("The size of the structure is %d bytes\n",(int)sizeof(struct Employee));
    printf("Enter the details:\n");
    for(int i = 0;i<n;i++){
        printf("Enter id:\n");
        scanf("%d",&(ptr + i)->id);
        printf("Enter name:\n");
        scanf("%s",(ptr + i)->name);
        printf("Enter salary:\n");
        scanf("%f",&(ptr + i)->salary);
    }
    for(int i = 0;i<n;i++){
        sum+=(ptr+i)->salary;
    };
    printf("The sum of salary of %d Employees is: %d\n",n,sum);
    free(ptr);
}