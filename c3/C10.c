#include <unistd.h>
#include <stdio.h>



int main(void){

    int nb;
    int index = 1;
    int somme = 0;

    while (index <= 10){
        printf("donner nombre %d\n",index);
        scanf("%d", &nb);
        if (nb > 0)
            somme += nb;
        index++;
    }

    printf("somme : %d\n", somme);

    return 0;
}