
#ifndef STD_TYPES_H
#define	STD_TYPES_H

#define NUL_PTR  ((void*)0)

typedef struct{
    char name[20];
    char Address[20];
    float salary;
    int ID;

}Employee;

/*.............section:data type declaration.......... */

typedef unsigned char       uint8;
typedef unsigned short      uint16;
typedef unsigned long       uint32;
typedef unsigned long long  uint64;

typedef signed char         int8;
typedef signed short        int16;
typedef signed long         int32;
typedef signed long long    int64;

typedef float               float32;
typedef double              float64;


typedef uint8     Std_ReturnType;



#endif	/* STD_TYPES_H */
