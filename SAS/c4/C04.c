#include <stdio.h>

int devidedby(int n, int a){
    return n/a;
}

int has_remainder(int a, int b){
    if (devidedby(a, b) != 0)
        return 1;
    else
        return 0;
}

int main(){

    int a;
    printf("donner a:\n");
    scanf("%d", &a);

    int b = a;
    int div = 0;

    while (b){
        if (has_remainder(a, b) == 0);
            div++;
        b--;
    }



    printf("%d\n",has_remainder(3,2));
    printf("%d\n",has_remainder(2,2));


    return 0;
}