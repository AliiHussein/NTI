#include <stdio.h>
#include "Bit_math.h"
#include "std_types.h"

#define EMPLOYEE_SIZE 5

void print_employee(Employee * e, int n);
void scan_employee(Employee * e, int n);
void search_largest_salary(Employee * e, int n);
void search_by_id(Employee * e, int n);
void search_by_name(Employee * e, int n);

void main(){
    Employee e1;
    Employee e2;
    Employee e3;
    Employee e4;
    Employee e5;

    Employee *e[EMPLOYEE_SIZE] = {&e1, &e2, &e3, &e4, &e5}; 

    /* Variables */
    int options = 0;    

    while(options != 6u){
        printf("\nChoose a number from the List\n");
        printf("1. Scan Employees\n");
        printf("2. Print Employees\n");
        printf("3. Search for the largest Salary\n");
        printf("4. Search by ID\n");
        printf("5. Search by Name\n");
        printf("6. Exit\n");

        printf("Your Choice: ");
        scanf("%d", &options);


            switch(options){
            case 1: scan_employee(e, EMPLOYEE_SIZE); break;
            case 2: print_employee(e, EMPLOYEE_SIZE); break;
            case 3: search_largest_salary(e, EMPLOYEE_SIZE); break;
            case 4: search_by_id(e, EMPLOYEE_SIZE); break;
            case 5: search_by_name(e, EMPLOYEE_SIZE); break;
            case 6: break;
            default: printf("Invalid option!\n"); break;
            }

    }

    printf("\n THANK YOU!");
}