void echange(int a, int b){
    printf("a = %d, b = %d\n", a , b);
    int c;
    c = a;
    a = b;
    b = c;
    printf("a = %d, b = %d\n", a , b);
}