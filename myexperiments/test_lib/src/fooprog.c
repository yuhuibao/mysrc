#include <stdlib.h>
#include <stdio.h>

extern bar(char*);

int main(){
    bar("hello world\n");
    return 0;
}
