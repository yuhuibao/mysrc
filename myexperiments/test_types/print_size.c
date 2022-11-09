#include <stdio.h>
#include <limits.h>
#include <math.h>
int main(){
    printf("range of type char is from %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("size of a type char variable is %ld\n", sizeof(char));

    printf("range of type short is from %d to %d\n", SHRT_MIN, SHRT_MAX);
    unsigned long int size = sizeof(short);
    printf("size of a type short variable is %ld\n", size);
    printf("range of short is from %g to %g by compute\n",-pow(2,size*8-1), pow(2,size*8-1)-1);
    
    printf("range of type int is from %d to %d\n",INT_MIN,INT_MAX);
    printf("size of a type int variable is %ld\n",sizeof(int));

    printf("range of type long is from %ld to %ld\n",LONG_MIN,LONG_MAX);
    printf("size of a type long variable is %ld\n",sizeof(long));

    printf("range of type unsigned char is from %d to %d\n", 0, UCHAR_MAX);
    printf("size of a type unsigned char variable is %ld\n", sizeof(unsigned char));

    printf("range of type unsigned short is from %d to %d\n", 0, USHRT_MAX);
    unsigned long int size_u = sizeof(unsigned short);
    printf("size of a type unsigned short variable is %ld\n", size);
    printf("range of unsigned short is from %d to %g by compute\n", 0, pow(2,size_u*8)-1);
    
    printf("range of type unsigned int is from %d to %u\n", 0, UINT_MAX);
    printf("size of a type unsigned int variable is %ld\n",sizeof(unsigned int));

    printf("range of type unsigned long is from %d to %lu\n", 0, ULONG_MAX);
    size_t size_ul = sizeof(unsigned long);
    printf("size of a type unsigned long variable is %ld\n", size_ul);
    printf("range of unsigned long is from %d to %g\n", 0, pow(2, size_ul*8)-1);
    return 0;
}
