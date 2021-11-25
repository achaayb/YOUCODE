#include <unistd.h>
#include <stdio.h>


int main(void){

    int nbr;
    int somme = 0;
    int max = 0;

    while (1) {
        printf("donner le nombre : ");
        scanf("%d", &nbr);
        if (nbr <= 100 && nbr > 0)
            somme += nbr;
            if (nbr > max && nbr <= 100)
                max = nbr;
        else if (nbr == 0){
            printf("somme = %d\n", somme);
            printf("max = %d\n", max);
            break;
        }

    }

    return 0;
}