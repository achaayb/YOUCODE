#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv){
    
    float temp;

    printf("Temperature en F : \n");
    scanf("%f", &temp);

    temp = (temp - 32) * 5/9;

    printf("Temperature en C : %f\n", temp);
    if (temp < 0)
        printf("Temperature très froid\n");
    else if (temp < 20)
        printf("Temperature froid\n");
    else if (temp < 30)
        printf("Temperature chaud\n");
    else
        printf("Temperature très chaud\n");

    return 0;
}