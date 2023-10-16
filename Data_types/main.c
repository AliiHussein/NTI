#include <stdio.h>

/*
struct student{
    char name[20];
    int id;
    float degree;
};
*/

typedef struct{
    char name[20];
    int id;
    float degree;

}student;

void main(){
    student st1;
    student * p1 = &st1;

    student st2;
    student * p2 = &st2;

    strcpy(p1->name,"Ali");
    p1->id = 20;
    p1->degree = 5.5;

    gets(p2->name);
    scanf("%d", &(p2->id));
    scanf("%f", &(p2->degree));

    printf("St1: Name= %s, id= %d, degree= %f\n", p1->name, p1->id, p1->degree);
    printf("St2: Name= %s, id= %d, degree= %f\n", p2->name, p2->id, p2->degree);


}
