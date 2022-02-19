#include <stdio.h>

int main(){
    int arr[10];
    int *ptr_a;

    for(int i=0; i<10; i++){
        arr[i] = i;
    }
    ptr_a = &arr[0];
    printf("addr of the first element is %p and %p, the value is %d and %d\n",ptr_a,arr,*ptr_a,arr[0]);
    for(int i=0; i<10; i++){
        printf("%p\t%d\n",ptr_a+i,*(ptr_a+i));
    }
    return 0;
}
