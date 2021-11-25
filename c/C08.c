#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv){
    
    int a;
    int b;
    int c;
    int d;

    printf("Saisire a : \n");
    scanf("%d", &a);

    printf("Saisire b : \n");
    scanf("%d", &b);

    printf("Saisire c : \n");
    scanf("%d", &c);

    printf("Saisire d : \n");
    scanf("%d", &d);

    int somme = a + b + c + d;
    int moyenne = somme / 4;

    printf("Somme : %d, Moyenne : %d\n", somme, moyenne);

    return 0;
}