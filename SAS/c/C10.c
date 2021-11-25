#include <unistd.h>
#include <stdio.h>

#define PI 3.14

int main(int argc, char **argv){
    
    float rayon;

    printf("Saisire rayon : \n");
    scanf("%f", &rayon);


    printf("circonférence  : %f\n", 2 * PI * rayon);

    return 0;
}