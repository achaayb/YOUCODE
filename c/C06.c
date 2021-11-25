#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv){
    
    float temp;

    printf("Temperature en F : \n");
    scanf("%f", &temp);

    temp = (temp - 32) * 5/9;

    printf("Temperature en C : %f\n", temp);

    return 0;
}