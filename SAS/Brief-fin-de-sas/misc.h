#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#define h printf("|#############################>\n");
typedef struct compte{
    char *np;
    char *cin;
    char *montant;
} compte_t;
void insert_one(compte_t foo);
long unsigned int find_digits(int a);
int get_lines();
void clear();
void update_fund(int id, float amount);
float get_bal(char *array);