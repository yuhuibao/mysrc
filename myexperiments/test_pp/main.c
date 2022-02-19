#include <stdio.h>
#include <stdlib.h>

/* This function is to change a*/
void func(int** a){
	*a=malloc(4*sizeof(int));
}

void func2(int** a){
	int *b=*a; /* assign *a to b both are pointer values */
	b=malloc(4*sizeof(int));
}

int main(){
	int *a=NULL;
	printf("%p\n",a);

	//func(&a);

	func2(&a);

	printf("%p\n",a);
	return 0;
}
