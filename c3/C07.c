#include <unistd.h>
#include <stdio.h>


int main(void){

    int nbr;
    int index = 0;

    int number;
    int first = 1;
    int second = 0;
    int third;

    printf("donner le nombre : ");
    scanf("%d", &nbr);
    

    while (index != nbr){
        third = first + second;
        first = second;
        second = third;
        index ++;
    }

    printf("%d\n", first);


    return 0;
}