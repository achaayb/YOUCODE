#include <unistd.h>
#include <stdio.h>

int is_prime(int nb){
    int n = nb;
    int div = 0;

    while (n > 1) {
        if (nb % n == 0)
            div++;
        n--;
    }
    if (div != 1)
        return 0;
    else
        return 1;
}


int main(void){

    int nbr;

    printf("nombre :\n");
    scanf("%d", &nbr);

    if (is_prime(nbr)){
        printf("is prime\n");
    } else
        printf("Non prime\n");

    return 0;
}