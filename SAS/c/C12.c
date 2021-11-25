#include <unistd.h>
#include <stdio.h>


void print_reverse(int nb){
    printf("%d", nb % 10);
    if (nb >= 10)
        print_reverse(nb / 10);
}


int main(int argc, char **argv){
    
    int nb;
    
    printf("Saisire Nombre : \n");
    scanf("%d", &nb);

    print_reverse(nb);
    printf("\n");


    return 0;
}
