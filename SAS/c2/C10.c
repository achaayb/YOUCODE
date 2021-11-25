#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv){
    
    float temp;

    printf("La temparature : \n");
    scanf("%f", &temp);

    if (temp <= 0)
        printf("Glace\n");
    else if (temp > 0 && temp <= 100)
        printf("Eau\n");
    else if (temp > 100)
        printf("Vapeur\n");


    return 0;
}