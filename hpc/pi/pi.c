#include <stdio.h>
#define INTERVAL 1000
int main(){
    int circle_points =0,square_points=0;
    int iterations = INTERVAL*INTERVAL;
    int x,y,pos;
    float pi;

    srand(time(0));
    for(int i=0; i< iterations; i++){
        x = rand()%(INTERVAL+1);
        y = rand()%(INTERVAL+1);
        pos = x*x + y*y;
        if(pos<INTERVAL*INTERVAL){
            circle_points++;
        }
        square_points++;
        pi = (float)(4*circle_points)/square_points;
        printf("x=%d y=%d cp=%d sp=%d pi=%g\n",x,y,circle_points,square_points,pi);
    }
    printf("final estimation of pi=%g\n",pi);
    return 0;
}
