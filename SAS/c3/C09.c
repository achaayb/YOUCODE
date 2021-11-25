#include <unistd.h>
#include <stdio.h>



int main(void){

    int nb;
    int pow;

    printf("donner x : \n");
    scanf("%d",&nb);

    printf("donner puissance : \n");
    scanf("%d",&pow);

    int total = nb;
    
    while ( pow > 1 ){
        total *= nb;
        pow--;
    }

    printf("%d\n", total);


    return 0;
}