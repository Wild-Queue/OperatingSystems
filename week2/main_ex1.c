#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    printf("Integer = %i \n", INT_MAX);
    printf("Float = %f \n", FLT_MAX);
    printf("Double = %f \n", DBL_MAX);
    
    int intType;
    float floatType;
    double doubleType;
    printf("Sizeof Integer = %li \n", sizeof(intType));
    printf("Sizeof Float = %li \n", sizeof(floatType));
    printf("Sizeof Double = %li \n", sizeof(doubleType));
    return 0;
}
