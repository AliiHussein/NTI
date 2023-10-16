#include <stdio.h>

struct student{
    char name[20];
    int id;
    float degree;
};

void main(){
    struct student st1 = {"Ali", 20, 5.5};
    struct student st2;

    gets(st2.name);
    scanf("%d", &st2.id);
    scanf("%f", &st2.degree);

    printf("St1: Name= %s, id= %d, degree= %f\n", st1.name, st1.id, st1.degree);
    printf("St2: Name= %s, id= %d, degree= %f\n", st2.name, st2.id, st2.degree);

}
