
#include <stdio.h>
#include "std_types.h"
#include "Bit_math.h"
#include <string.h>

#define USER "Hamada"
#define PASS 1234
#define TRIALS 3
#define ARRAY_SIZE 5

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

void swap(int * x, int * y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void scan_array(int * arr, int size){

    for(int i = 0; i < size; i++){
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }
}

void print_array(int * arr, int size){
    printf("Array: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sort_array(int * arr, int size){
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(arr[j] < arr[i]){
                swap(&arr[j], &arr[i]);
            }
        }
    }
    print_array(arr, size);
}

void max_element(int * arr, int size){
    int max = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    printf("Max Element: %d\n", max);
}

void min_element(int * arr, int size){
    int min = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    printf("Min Element: %d\n", min);
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
    int array[ARRAY_SIZE];

    while(options != 6u){
        printf("\nChoose a number from the List\n");
        printf("1. Scan Array\n");
        printf("2. Print Array\n");
        printf("3. Sort Array\n");
        printf("4. Max Element\n");
        printf("5. Min Element\n");
        printf("6. Exit\n");

        printf("Your Choice: ");
        fflush(stdin);
        scanf("%d", &options);

        switch(options){
            case 1: scan_array(array, ARRAY_SIZE); break;
            case 2: print_array(array, ARRAY_SIZE); break;
            case 3: sort_array(array, ARRAY_SIZE); break;
            case 4: max_element(array, ARRAY_SIZE); break;
            case 5: min_element(array, ARRAY_SIZE); break;
            case 6: break;
            default: printf("Invalid option!\n"); break;
        }
    }
}

void playWithPointers(){
    printf("You are now playing with pointer\n");

    int options = 0;
    void* ptr = NULL;
    int num1;
    char ch1;
    float num2;

    while(options != 4u){
        printf("\nChoose a number from the List\n");
        printf("1. Pointer to int\n");
        printf("2. Pointer to char\n");
        printf("3. Pointer to float\n");
        printf("4. Exit\n");

        printf("Your Choice: ");
        fflush(stdin);
        scanf("%d", &options);
        fflush(stdin);
        switch(options){
            case 1: printf("Value: "); scanf("%d", &num1); ptr = &num1; printf("PTR= %d,  *PTR= %d\n", ptr, *(int*)ptr); break;
            case 2: printf("Value: "); scanf("%c", &ch1); ptr = &ch1;  printf("PTR= %d,  *PTR= %c\n", ptr, *(char*)ptr); break;
            case 3: printf("Value: "); scanf("%f", &num2); ptr = &num2; printf("PTR= %d,  *PTR= %.1f\n", ptr, *(float*)ptr); break;
            case 4: break;
            default: printf("Invalid option!\n"); break;
        }
    }
}