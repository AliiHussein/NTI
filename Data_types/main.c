#include "std_h.h"

void main(){
    Employee e1;
    Employee e2;
    Employee e3;

    Employee *ptr[3] = {&e1, &e2, &e3}; // array of pointers


    scan_employee(ptr, 3);

    print_employee(ptr, 3);


}
