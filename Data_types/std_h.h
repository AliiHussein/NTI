#include <stdio.h>

typedef struct{
    char name[20];
    float salary;
    int phone;

}Employee;

void print_employee(Employee * e, int n);
void scan_employee(Employee * e, int n);
