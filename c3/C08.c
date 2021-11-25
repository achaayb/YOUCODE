#include <unistd.h>
#include <stdio.h>
#include <math.h>


float f(float x){
    return pow(x , 3) + (12 * pow(x, 2)) + 1;
}

float split_interval(float a, float b){
    return (a + b)/2;
}

int is_interval(float fa, float fb){
    if (fa * fb < 0)
        return 1; // if interval includes f(x) = 0
    else
        return 0; // else
}

int main(void){

    float a, b , m;


    a = -15;
    b = -10;

    m = split_interval(a, b);

    while (1) {
        if (is_interval(f(a), f(m)))
            b = m;
        else
            a = m;
        m = split_interval(a, b);
        if ((b-a) < 0.00001)
            break;
    }

    printf("interval %.5f -> %.5f\n", a, b);
    
    return 0;
}