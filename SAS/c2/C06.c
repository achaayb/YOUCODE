#include <unistd.h>
#include <stdio.h>
#include <math.h>


int main(int argc, char **argv){
    
    float x1, x2, delta, a, b, c;

    printf("entrez a, b et c :\n");
    scanf("%f %f %f", &a, &b, &c);

    delta = (b*b)-(4*a*c);

    if (delta == 0.0){
        x1 = -b/(2*a);
        printf("solution unique = %.2f\n", x1);
    } else if (delta > 0.0){
        x1 = (-b - sqrt(delta))/(2*a);
        x2 = (-b + sqrt(delta))/(2*a);
        printf("les deux solutions sont : x1 = %.2f et x2 = %.2f \n",x1, x2);
    } else
        printf("l'equation n'as aucune solution\n");

    return 0;
}