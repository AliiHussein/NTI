#include <stdio.h>

void swap(int * x, int * y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

long int fact(int n) {
    if (n>=1)
        return n*fact(n-1);
    else
        return 1;
}

void scan_array(int * arr, int size){

    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
}

void print_array(int * arr, int size){

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

int* sort_array_by_value(int * arr, int size){
    static int arr2[4];
    for(int i = 0; i < size; i++){
        arr2[i] = arr[i];
    }

    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(arr2[j] < arr2[i]){
                swap(&arr2[j], &arr2[i]);
            }
        }
    }
    return arr2;
}

void string_name_pass(void){

    int trials = 3;

    for(int i = 0; i < 3; i++){
        char name[20];
        printf("Enter Name: ");
        fflush(stdin);
        gets(name);


        int x;
        printf("Enter num: ");
        scanf("%d", &x);

        if(strcmp(name, "NTI") == 0 && x == 1122){
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

void void_ptr_test(void){
    void *ptr;
    int * ptr2;

    int num1 = 5;
    char ch1 = 'A';
    float num2 = 5.5;
    double num3 = 6.3;

    ptr = &num1;
    printf("num1 = %d\n", *((int*)ptr));

    ptr = &ch1;
    printf("ch1 = %c\n", *((char*)ptr));

    ptr = &num2;
    printf("num2 = %.1f\n", *((float*)ptr));

    ptr = &num3;
    printf("num3 = %.1lf\n", *((double*)ptr));

    printf("size of ptr is %d\n", sizeof(ptr));
    printf("size of ptr2 is %d\n", sizeof(ptr2));
}
