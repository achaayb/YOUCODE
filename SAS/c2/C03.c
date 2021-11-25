#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv){
    
    int temp;

    printf("Nombre : \n");
    scanf("%d", &temp);

    printf("%s", temp % 2 == 1 ? "impair\n" : "pair\n");

    return 0;
}