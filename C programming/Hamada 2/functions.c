#include <stdio.h>
#include "Bit_math.h"
#include "std_types.h"
#include <string.h>

void scan_employee(Employee * e, int n){
    for(int i = 0; i < n; i++){
        printf("\nEmployee %d\n", i+1);
        fflush(stdin);
        printf("Enter name: ");
        gets((&e[i])->name);
        printf("Enter Address: ");
        gets((&e[i])->Address);
        printf("Enter salary: ");
        scanf("%f", &((&e[i])->salary));
        printf("Enter ID: ");
        scanf("%d", &((&e[i])->ID));
    }

}

void print_employee(Employee * e, int n){
    for(int i = 0; i < n; i++){
        printf("E%d: Name= %s, Address= %s, Salary= %.1f, ID= %d\n",i+1, (&e[i])->name, (&e[i])->Address, (&e[i])->salary , (&e[i])->ID);
    }
}

void search_largest_salary(Employee * e, int n){
    int max_index = 0;
    int max = 0;
    for(int i = 0; i < n; i++){
        if((&e[i])->salary > max){
            max_index = i;
            max = (&e[i])->salary;
        }   
    }

    printf("Largest Salary is %.1f earned by %s\n", (&e[max_index])->salary, (&e[max_index])->name);
    
}

void search_by_id(Employee * e, int n){
    int id;
    printf("Enter ID: "); 
    scanf("%d", &id); 

    for(int i = 0; i < n; i++){
        if((&e[i])->ID == id){
            printf("Name= %s, Address= %s, Salary= %.1f, ID= %d\n", (&e[i])->name, (&e[i])->Address, (&e[i])->salary , (&e[i])->ID);
            return;
        }   
    }
    printf("Invalid ID!\n");
}

void search_by_name(Employee * e, int n){
    char na[20];
    fflush(stdin); printf("Enter Name: ");  
    gets(na); 
    for(int i = 0; i < n; i++){
        if(!strcmp((&e[i])->name , na)){
            printf("Name= %s, Address= %s, Salary= %.1f, ID= %d\n", (&e[i])->name, (&e[i])->Address, (&e[i])->salary , (&e[i])->ID);
            return;
        }   
    }
    printf("Invalid Name!\n");
}