#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv){

    int nbr;
    
    printf("donner un entier :\n");
    scanf("%d", &nbr);

    if (nbr < 0)
        printf("le nbr %d est negatif\n", nbr);
    else {
        if (nbr > 0)
            printf("le nbr %d est positif\n", nbr);
        else
            printf("le nbr %d est nul\n", nbr);
    }

    return 0;
}