#ifndef STD_H_H
#define	STD_H_H

#include <stdio.h>
#include "std_types.h"
#include "Bit_math.h"

typedef struct{
    char name[20];
    float salary;
    int phone;

}Employee;

enum months{jan=1, feb, mar, april, may, jun, july, aug, sep, oct, nov, dec};

void print_employee(Employee * e, int n);
void scan_employee(Employee * e, int n);

#endif	/* STD_H_H */
