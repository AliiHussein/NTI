#include "std_h.h"

void scan_employee(Employee * e, int n){
    for(int i = 0; i < n; i++){
        fflush(stdin);
        printf("Enter name: ");
        gets((&e[i])->name);
        printf("Enter salary: ");
        scanf("%f", &((&e[i])->salary));
        printf("Enter phone: ");
        scanf("%d", &((&e[i])->phone));
    }

}

void print_employee(Employee * e, int n){
    for(int i = 0; i < n; i++){
        printf("E%d: Name= %s, Salary= %.1f, phone= %d\n",i, (&e[i])->name, (&e[i])->salary, (&e[i])->phone);
    }


}
