#include <unistd.h>
#include <stdio.h>

int main(void){

    int nb;
    int i = 1;

    printf("entrer nombre :\n");
    scanf("%d", &nb);



    while (i++ < 10){
        printf("%d\n", nb * i);
    }

    return 0;
}