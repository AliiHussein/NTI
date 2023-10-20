
#include <stdio.h>

void main(){
    short int i = 20;
    char c = 97;

    printf("%d %d %d\n", sizeof(i),sizeof(c),sizeof(c+i));
}


