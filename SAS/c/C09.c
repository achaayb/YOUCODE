#include <unistd.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv){
    
    float x1;
    float x2;
    float y1;
    float y2;

    printf("Saisire x1 : \n");
    scanf("%f", &x1);

    printf("Saisire y1 : \n");
    scanf("%f", &y1);

    printf("Saisire x2 : \n");
    scanf("%f", &x2);

    printf("Saisire y2 : \n");
    scanf("%f", &y2);

    float distance = sqrt( ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)) );

    printf("Distance : %f\n", distance);

    return 0;
}