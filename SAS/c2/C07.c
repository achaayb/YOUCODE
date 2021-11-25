#include <unistd.h>
#include <stdio.h>


int main(int argc, char **argv){
    
    int year;

    printf("Donner L'annee\n");
    scanf("%d", &year);

    printf("Choisire : \n1) Mois\n2) Jours\n3) Heures\n4) Minutes\n5) Secondes\n");

    int option;

    printf("Donner L'option\n");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("%d\n", 12);
            break;
        case 2:
            printf("%d\n", 12 * 365);
            break;
        case 3:
            printf("%d\n", 12 * 365 * 24);
            break;
        case 4:
            printf("%d\n", 12 * 365 * 24 * 60);
            break;
        case 5:
            printf("%d\n", 12 * 365 * 24 * 60 * 60);
            break;
        default:
            break;
    }

    

}