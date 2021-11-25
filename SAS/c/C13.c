#include <unistd.h>
#include <stdio.h>


int main(int argc, char **argv){
    
    int nb;
    
    printf("Saisire Nombre : \n");
    scanf("%d", &nb);

    printf("Hexadecimal : %08x\n", nb);
    printf("Octale : %011o\n", nb);

    return 0;
}