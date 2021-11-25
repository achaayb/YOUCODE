#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv){
    
    float temp;

    printf("La note : \n");
    scanf("%f", &temp);

    if (temp >= 16)
        printf("Tres bien\n");
    else if (temp >= 10 && temp < 12)
        printf("passable\n");
    else if (temp >= 12 && temp < 14)
        printf("Assez bien\n");
    else if (temp >= 14 && temp < 16)
        printf("Bien\n");
    else if (temp < 0)
        printf("NUL\n");

    return 0;
}