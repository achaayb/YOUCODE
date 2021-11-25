#include <unistd.h>
#include <stdio.h>

int is_prime(int nb){
    int n = nb;
    int div = 0;

    while (n > 1) {
        if (nb % n == 0)
            div++;
        n--;
    }
    if (div != 1)
        return 0;
    else
        return 1;
}

int nth_prime(int n){
    int index = 0;
    int number = 3;

    
    while (number){
        if (is_prime(number)){
            index++;
            if (index == n) {
                return number;
            }
        }
        number++;
    }
} 

int main(void){

    int lines;
    int i = 1;
    int l = 1;
    printf("ligne :\n");
    scanf("%d", &lines);

    int k = 0;
    int sp;
    int foo;

    while(i <= lines){

        

        sp = (nth_prime(lines) - nth_prime(i)) / 2;    
        while (k < sp){
            printf(" ");
            k++;
        }
        k = 0;

        while (l <= nth_prime(i)){
            printf("*");
            l++;
        }
        l = 1;

        printf("\n");

        foo = 0;

        if ( (nth_prime(i+1) - nth_prime(i)) > 2 ){
            while (foo < (nth_prime(i+1) - nth_prime(i)) / 2){
                printf("\n");
                foo++;
            }
        }

        i++;
    }

    return 0;
}