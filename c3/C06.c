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

    printf("donner le nombre : ");
    scanf("%d", &nbr);
    

    for (int i = 2; i < nbr; i ++){

        if (is_prime(i))
            printf("%d est prime\n", i);

    }



    return 0;
}