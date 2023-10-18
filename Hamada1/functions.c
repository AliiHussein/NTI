
#include <stdio.h>
#include "std_types.h"
#include "Bit_math.h"
#include <string.h>

#define USER "Hamada"
#define PASS 1234
#define TRIALS 3

Std_ReturnType login_system(void){

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
            return 1u;
        }
        else{
            trials--;
            printf("\nWrong credentials!\n");
            printf("You have %d trials left\n\n", trials);
        }
    }
    return 0u;
}

void add(){
	uint16 a ,b;
	uint8 op;
    printf("ADD: ");
	scanf("%hi%c%hi", &a, &op,&b);

    printf("%d\n", a+b);

}

void sub(){
	uint16 a ,b;
	uint8 op;
    printf("Sub: ");
	scanf("%hi%c%hi", &a, &op,&b);

    printf("%d\n", a-b);
}

void multiply(){
	uint16 a ,b;
	uint8 op;
    printf("Multiply: ");
	scanf("%hi%c%hi", &a, &op,&b);

    printf("%d\n", a*b);
}

void divide(){
	uint16 a ,b;
	uint8 op;
    printf("Div: ");
	scanf("%hi%c%hi", &a, &op,&b);

    printf("%d\n", a/b);
}

void square(){
	uint16 a;
    printf("Square: ");
	scanf("%hi", &a);

    printf("%d\n", a*a);
}

void calculator(){
    printf("\nYou are now using the calculator\n");

    int options = 0;

    while(options != 6u){

        printf("\nChoose a number from the List\n");
        printf("1. Add\n");
        printf("2. Sub\n");
        printf("3. divide\n");
        printf("4. Multiply\n");
        printf("5. Square\n");
        printf("6. Exit\n");

        printf("Your Choice: ");
        fflush(stdin);
        scanf("%d", &options);

        switch(options){
            case 1: add(); break;
            case 2: sub(); break;
            case 3: divide(); break;
            case 4: multiply(); break;
            case 5: square(); break;
            case 6: break;
            default: printf("Invalid option!\n"); break;
        }

    }
}

void playWithArray(){
    printf("\nYou are now playing with array\n");

    int options = 0;
    while(options != 1u){
        printf("\nChoose a number from the List\n");
        printf("1. Scan Array\n");
        printf("2. Print Array\n");
        printf("3. Sort Array\n");
        printf("4. Max Element\n");
        printf("5. Min Element\n");
        printf("6. Exit\n");

        fflush(stdin);
        scanf("%d", &options);


        switch(options){
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 6: break;
            default: printf("Invalid option!\n"); break;
        }



    }
}

void playWithPointers(){
    printf("You are now playing with pointer\n");

}
