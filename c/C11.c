#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv){
    
    float lan;
    float lar;

    printf("Saisire longeur : \n");
    scanf("%f", &lan);
    
    printf("Saisire largeur : \n");
    scanf("%f", &lar);



    printf("circonférence  : %f\n", 2 * (lan + lar));

    return 0;
}
