#include <unistd.h>
#include <stdio.h>


int main(void){

    int nbr;
    int reverse = 0;

    printf("donner le nombre : ");
    scanf("%d", &nbr);
    
    while (nbr) {
        reverse *= 10;
        reverse += nbr % 10;
        nbr /= 10;
    }

    printf("%d\n", reverse);

    return 0;
}