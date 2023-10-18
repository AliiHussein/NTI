#include <stdio.h>
#include "std_types.h"
#include "Bit_math.h"
#include <string.h>

void playWithPointers(void);
void playWithArray(void);
void calculator(void);
Std_ReturnType login_system(void);

int main()
{
    /* Variables */
    int options = 0;

    if(!login_system()){
        return 0;
    }

    while(options != 4){
        printf("\nChoose a number from the List\n");
        printf("1. Calculator\n");
        printf("2. Play with Array\n");
        printf("3. Play with Pointers\n");
        printf("4. Exit\n");

        printf("Your Choice: ");
        scanf("%d", &options);


            switch(options){
            case 1: calculator(); break;
            case 2: playWithArray(); break;
            case 3: playWithPointers(); break;
            case 4: break;
            default: printf("Invalid option!\n"); break;
            }

    }

    printf("\n THANK YOU!");

    return 0;
}
