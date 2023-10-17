#include "std_h.h"

#define USER "Hamada"
#define PASS 1234
#define TRIALS 3

void login_system(void){

    int trials = 3;

    for(int i = 0; i < TRIALS; i++){
        char name[20];
        printf("Enter Name: ");
        fflush(stdin);
        gets(name);


        int x;
        printf("Enter num: ");
        scanf("%d", &x);

        if(strcmp(name, "Hamada") == 0 && x == 1234){
            printf("Welcome to NTI!\n");
            break;
        }
        else{
            trials--;
            printf("Wrong cred\n");
            printf("You have %d trials left\n", trials);
        }
    }
}