#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv){
    
    float temp;

    printf("Distance Mile : \n");
    scanf("%f", &temp);

    temp *= 1609.334;

    printf("Distance Metre : %f\n", temp);

    return 0;
}