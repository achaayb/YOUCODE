#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv){
    
    int foo;
    int bar;

    printf("Nombre 1 : \n");
    scanf("%d", &foo);

    printf("Nombre 2 : \n");
    scanf("%d", &bar);

    if (foo != bar)
        printf("%d\n",foo+bar);
    else
        printf("%d\n",(foo+bar)*3);

    return 0;
}