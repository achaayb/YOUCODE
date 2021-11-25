#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv){
    
    char temp;

    printf("Caractere : \n");
    scanf("%c", &temp);

    switch (temp) {
        case ('a'):
            printf("voyelle\n");
            break;
        case ('e'):
            printf("voyelle\n");
            break;
        case ('i'):
            printf("voyelle\n");
            break;
        case ('o'):
            printf("voyelle\n");
            break;
        case ('u'):
            printf("voyelle\n");
            break;
        case ('y'):
            printf("voyelle\n");
            break;
        default:
            printf("Non voyelle\n");
            break;
    }

    return 0;
}