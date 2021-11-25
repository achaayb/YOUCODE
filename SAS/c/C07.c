#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv){
    
    int a;
    int b;

    printf("Saisire a : \n");
    scanf("%d", &a);

    printf("Saisire b : \n");
    scanf("%d", &b);

    printf("a + b : %d\na - b : %d\na * b : %d\na / b : %d\na %% b : %d\n", a+b,a-b,a*b,a/b,a%b);

    return 0;
}