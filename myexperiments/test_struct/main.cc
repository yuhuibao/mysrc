#include <iostream>

int main(){
	int a[10];
	struct sic {
		int x;
		char y;
		int* ptr;
	};
    std::cout<<a[0]<<"\n";
    sic mySic;
    printf("address of mySic is %p\n",mySic);
	sic b[5];
    std::cout<<&b[0]<<"\n";
    std::cout<<b[0].y<<"\n";
    std::cout<<b[0].x<<"\n";
    std::cout<<b[0].ptr<<"\n";
	return 0;
}

