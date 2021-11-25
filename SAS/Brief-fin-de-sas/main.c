
#include "misc.h"

void clear(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

void s_purge(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        __fpurge(stdin);
    #endif
    #if defined(_WIN32) || defined(_WIN64)
        fflush(stdin);
    #endif
}

long unsigned int find_digits(int a){
	long unsigned int i = 0;
	while (a != 0){
		i++;
		a /= 10;
	}
	return i;
}


float get_bal(char *array){
    char arr[50];
    int i = 0;

    while (*array)
    {
        arr[i] = *array;
        array++;
        i++;
    }
    arr[i] = '\0';
    // TEST|TEST|4784378
    char *id_get = strtok(arr, "|");
	char *name_get = strtok(NULL, "|");
	char *cin_get = strtok(NULL, "|");
	char *bal_get = strtok(NULL, "|");
    return atof(bal_get);
}

char *get_name(char *array){
    char arr[50];
    int i = 0;

    while (*array)
    {
        arr[i] = *array;
        array++;
        i++;
    }
    arr[i] = '\0';
    char *id_get = strtok(arr, "|");
	char *name_get = strtok(NULL, "|");
    return name_get;
}

int get_id(char *arr){
	int id = 0;
	while (*arr != '|'){
		id *= 10;
		id += *arr - '0';
        arr++;
	}
	return id;
}

int has_cin(char *array, char *cin){
        char arr[50];
        int i = 0;

        while (*array)
        {
            arr[i] = *array;
            array++;
            i++;
        }
        arr[i] = '\0';
        char *id_get = strtok(arr, "|");
        char *name_get = strtok(NULL, "|");
        char *cin_get = strtok(NULL, "|");
        if (strcmp(cin_get,cin) == 0)
            return 1;
        else
            return 0;
}


void print_hasCIN(){
    
    char cin[50];

    //get cin

    do{
        printf("Donner le cin : ");
        gets(cin);
    } while (!(*cin));

    char array5[500][100];
    FILE *f5 = fopen("database.db", "r");
    int i5 = 0;
    while(fgets(array5[i5], 100 , f5)){
        array5[i5][strlen(array5[i5]) - 1] = '\0';
        i5++;
    }
    while (i5 < 500){
        array5[i5][i5] = '\0';
        i5++;
    }
    fclose(f5);

    //print element if contains cin
    printf("ID|NOM COMPLET|CIN|MONTANT\n");
    i5 = 0;
    while (array5[i5][0] != '\0'){
        if (has_cin(array5[i5], cin))
            printf("%s\n", array5[i5]);
        i5++;
    }

}

void option_1() { // creation compte
    h
    printf("## Menu Principale/Introduire un compte\n");
    h
    char np[50];
    char cin[50];
    char montant2[50];
    float montant;
        do{
            printf("Donner le nom complet : ");
            gets(np);
        } while (!(*np));
        do{
            printf("Donner le cin : ");
            gets(cin);
        } while (!(*cin));
        do{
            printf("Donner le montant : ");
            scanf("%f",&montant);
            s_purge();
        } while (montant < 0);

    sprintf(montant2,"%f",montant);
    compte_t test = {np, cin, montant2};
    insert_one(test);
}

void option_2() { // insert many
    int option;
    do {
        clear();
        if (option == 1)
            option_1();
        h
        printf("## Menu Principale/Introduire plusieur comptes\n");
        h
        printf("1) Introduire un compte\n");
        printf("99) Retour\n");
        h
        printf("=> Operation : ");
        scanf("%d", &option);
        s_purge();
    }while (option != 99);
    clear();
}

void option_3() { //operations
    int option;
    int id;
    float somme;
    do {
        clear();
        switch(option) {
            case 1:
                h
                printf("## Menu Principale/Operations/Retrait\n");
                h
                do {
                    if (get_lines() - 1 == 0){
                        printf("!! aucun id n'existe !! ajouter un compte\n");
                        option_1();
                    }else
                        printf("!! nombre max des id = %d\n",get_lines() - 1);
                    printf("=> id : ");
                    scanf("%d", &id);
                    s_purge();
                }  while (id >= get_lines() || id == 0);
                do{
                    printf("=> somme : ");
                    scanf("%f", &somme);
                    s_purge();
                }   while (somme <= 0);
                update_fund(id , somme);
                break;
            case 2:
                h
                printf("## Menu Principale/Operations/Depot\n");
                h
                do {
                    if (get_lines() - 1 == 0){
                        printf("!! aucun id n'existe !! ajouter un compte\n");
                        option_1();
                    }else
                        printf("!! nombre max des id = %d\n",get_lines() - 1);
                    printf("=> id : ");
                    scanf("%d", &id);
                    s_purge();
                }  while (id >= get_lines() || id == 0);
                do{
                    printf("=> somme : ");
                    scanf("%f", &somme);
                    s_purge();
                }   while (somme <= 0);
                update_fund(id , somme * -1);
                break;
        }
        h
        printf("## Menu Principale/Operations\n");
        printf("## !!Nous offrons des prêts gratuits!!\n");
        h
        printf("1) Retrait\n");
        printf("2) Depot\n");
        printf("99) Retour\n");
        h
        printf("=> Operation : ");
        scanf("%d", &option);
        s_purge();
    }while (option != 99);
    clear();
}


void option_4() { //affichage
    int option;
    int id;
    float somme;
    do {
        clear();
        switch(option) {
            case 1:
                clear();
                h
                printf("## Menu Principale/Affichage/Par Ordre Ascendant\n");
                h
                // turn file into array
                char array[500][100];
                FILE *f = fopen("database.db", "r");
                int i = 0;
                while(fgets(array[i], 100 , f)){
                    array[i][strlen(array[i]) - 1] = '\0';
                    i++;
                }
                while (i < 500){
                    array[i][i] = '\0';
                    i++;
                }
                fclose(f);
                //sort array
                i = 0;
                char swap[100];
                int b;
                int k= 0;

                while ((array[k][0] != '\0')){
                    i = 0;
                    while (array[i][0] != '\0'){
                        if (array[i+1][0] && get_bal(array[i]) > get_bal(array[i + 1])){
                            b = 0;
                            while (array[i + 1][b]){
                                swap[b] = array[i + 1][b];
                                b++;
                            }
                            swap[b] = '\0';
                            b = 0;
                            while (array[i][b]){
                                array[i + 1][b] = array[i][b];
                                b++;
                            }
                            array[i + 1][b] = '\0';
                            b = 0;
                            while (swap[b]){
                                array[i][b] = swap[b];
                                b++;
                            }
                            array[i][b] = '\0';
                        }
                        i++;
                    }
                    k++;
                }

                //print sorted 
                printf("ID|NOM COMPLET|CIN|MONTANT\n");
                i = 0;
                while (array[i][0] != '\0'){
                    printf("%s\n", array[i]);
                    i++;
                }
                break;
            case 2:
                clear();
                h
                printf("## Menu Principale/Affichage/Par Ordre Descendant\n");
                h
                // turn file into array
                char array2[500][100];
                FILE *f2 = fopen("database.db", "r");
                int i2 = 0;
                while(fgets(array2[i2], 100 , f2)){
                    array2[i2][strlen(array2[i2]) - 1] = '\0';
                    i2++;
                }
                while (i2 < 500){
                    array2[i2][i2] = '\0';
                    i2++;
                }
                fclose(f2);
                //sort array2
                i2 = 0;
                char swap2[100];
                int b2;
                int k2= 0;

                while ((array2[k2][0] != '\0')){
                    i2 = 0;
                    while (array2[i2][0] != '\0'){
                        if (array2[i2+1][0] && get_bal(array2[i2]) < get_bal(array2[i2 + 1])){
                            b2 = 0;
                            while (array2[i2 + 1][b2]){
                                swap2[b2] = array2[i2 + 1][b2];
                                b2++;
                            }
                            swap2[b2] = '\0';
                            b2 = 0;
                            while (array2[i2][b2]){
                                array2[i2 + 1][b2] = array2[i2][b2];
                                b2++;
                            }
                            array2[i2 + 1][b2] = '\0';
                            b2 = 0;
                            while (swap2[b2]){
                                array2[i2][b2] = swap2[b2];
                                b2++;
                            }
                            array2[i2][b2] = '\0';
                        }
                        i2++;
                    }
                    k2++;
                }                

                //print sorted array2
                printf("ID|NOM COMPLET|CIN|MONTANT\n");
                i2 = 0;
                while (array2[i2][0] != '\0'){
                    printf("%s\n", array2[i2]);
                    i2++;
                }
                break;
            case 3:
                clear();
                h
                printf("## Menu Principale/Affichage/Par Ordre Ascendant Plus de n\n");
                h
                /////
                // turn file into array
                char array3[500][100];
                FILE *f3 = fopen("database.db", "r");
                int i3 = 0;
                while(fgets(array3[i3], 100 , f3)){
                    array3[i3][strlen(array3[i3]) - 1] = '\0';
                    i3++;
                }
                while (i3 < 500){
                    array3[i3][i3] = '\0';
                    i3++;
                }
                fclose(f3);
                //sort array
                i3 = 0;
                char swap3[100];
                int b3;
                int k3= 0;

                while ((array3[k3][0] != '\0')){
                    i3 = 0;
                    while (array3[i3][0] != '\0'){
                        if (array3[i3+1][0] && get_bal(array3[i3]) > get_bal(array3[i3 + 1])){
                            b3 = 0;
                            while (array3[i3 + 1][b3]){
                                swap3[b3] = array3[i3 + 1][b3];
                                b3++;
                            }
                            swap3[b3] = '\0';
                            b3 = 0;
                            while (array3[i3][b3]){
                                array3[i3 + 1][b3] = array3[i3][b3];
                                b3++;
                            }
                            array3[i3 + 1][b3] = '\0';
                            b3 = 0;
                            while (swap3[b3]){
                                array3[i3][b3] = swap3[b3];
                                b3++;
                            }
                            array3[i3][b3] = '\0';
                        }
                        i3++;
                    }
                    k3++;
                }

                //get n
                float n;
                printf("Donner n : ");
                scanf("%f",&n);
                s_purge();

                //print sorted array if > n
                printf("ID|NOM COMPLET|CIN|MONTANT\n");
                i3 = 0;
                while (array3[i3][0] != '\0'){
                    if (get_bal(array3[i3]) > n)
                        printf("%s\n", array3[i3]);
                    i3++;
                }
                break;
            case 4:
                clear();
                h
                printf("## Menu Principale/Affichage/Par Ordre Descendant Plus de n\n");
                h
                /////
                // turn file into array
                char array4[500][100];
                FILE *f4 = fopen("database.db", "r");
                int i4 = 0;
                while(fgets(array4[i4], 100 , f4)){
                    array4[i4][strlen(array4[i4]) - 1] = '\0';
                    i4++;
                }
                while (i4 < 500){
                    array4[i4][i4] = '\0';
                    i4++;
                }
                fclose(f4);
                //sort array
                i4 = 0;
                char swap4[100];
                int b4;
                int k4= 0;

                while ((array4[k4][0] != '\0')){
                    i4 = 0;
                    while (array4[i4][0] != '\0'){
                        if (array4[i4+1][0] && get_bal(array4[i4]) < get_bal(array4[i4 + 1])){
                            b4 = 0;
                            while (array4[i4 + 1][b4]){
                                swap4[b4] = array4[i4 + 1][b4];
                                b4++;
                            }
                            swap4[b4] = '\0';
                            b4 = 0;
                            while (array4[i4][b4]){
                                array4[i4 + 1][b4] = array4[i4][b4];
                                b4++;
                            }
                            array4[i4 + 1][b4] = '\0';
                            b4 = 0;
                            while (swap4[b4]){
                                array4[i4][b4] = swap4[b4];
                                b4++;
                            }
                            array4[i4][b4] = '\0';
                        }
                        i4++;
                    }
                    k4++;
                }

                //get n
                float n2;
                printf("Donner n : ");
                scanf("%f",&n2);
                s_purge();

                //print sorted array if > n
                printf("ID|NOM COMPLET|CIN|MONTANT\n");
                i4 = 0;
                while (array4[i4][0] != '\0'){
                    if (get_bal(array4[i4]) > n)
                        printf("%s\n", array4[i4]);
                    i4++;
                }
                break;
            case 5:
                clear();
                h
                printf("## Menu Principale/Affichage/Recherche par cin\n");
                h
                /////
                print_hasCIN();
                break;
        }
        h
        printf("## Menu Principale/Affichage\n");
        h
        printf("1) Par Ordre Ascendant\n");
        printf("2) Par Ordre Descendant\n");
        printf("3) Par Ordre Ascendant Plus de n\n");
        printf("4) Par Ordre Descendant Plus de n\n");
        printf("5) Recherche par cin\n");
        printf("99) Retour\n");
        h
        printf("=> Operation : ");
        scanf("%d", &option);
        s_purge();
    }while (option != 99);
    clear();
}

void option_5() { // Fedilisation
    clear();
    // turn file into array
    char array[500][100];
    FILE *f = fopen("database.db", "r");
    int i = 0;
    while(fgets(array[i], 100 , f)){
        array[i][strlen(array[i]) - 1] = '\0';
        i++;
    }
    while (i < 500){
        array[i][i] = '\0';
        i++;
    }
    fclose(f);
    //sort array
    i = 0;
    char swap[100];
    int b;
    int k= 0;

    while ((array[k][0] != '\0')){
        i = 0;
        while (array[i][0] != '\0'){
            if (array[i+1][0] && get_bal(array[i]) < get_bal(array[i + 1])){
                b = 0;
                while (array[i + 1][b]){
                    swap[b] = array[i + 1][b];
                    b++;
                }
                swap[b] = '\0';
                b = 0;
                while (array[i][b]){
                    array[i + 1][b] = array[i][b];
                    b++;
                }
                array[i + 1][b] = '\0';
                b = 0;
                while (swap[b]){
                    array[i][b] = swap[b];
                    b++;
                }
                array[i][b] = '\0';
            }
            i++;
        }
        k++;
    }
    // update first 3
    if (array[0][0]){
        update_fund(get_id(array[0]), ((get_bal(array[0]) / 100) * 1.3) * -1);
    }

    if (array[1][0]){
        update_fund(get_id(array[1]), ((get_bal(array[1]) / 100) * 1.3) * -1);
    }
    if (array[2][0]){
        update_fund(get_id(array[2]), ((get_bal(array[2]) / 100) * 1.3) * -1);
    }
    //push array into file;
}

void option_6() { // bonus 1 somme
    clear();
    // turn file into array
    char array[500][100];
    FILE *f = fopen("database.db", "r");
    int i = 0;
    while(fgets(array[i], 100 , f)){
        array[i][strlen(array[i]) - 1] = '\0';
        i++;
    }
    while (i < 500){
        array[i][i] = '\0';
        i++;
    }
    fclose(f);
    // calculate somme
    float somme = 0;
    i = 0;
    while (array[i][0]){
        somme += get_bal(array[i]);
        i++;
    }
    h
    printf("## La somme des montants -> %f\n", somme);
}

void option_7() { // bonus 2 moyenne
    clear();
    // turn file into array
    char array[500][100];
    FILE *f = fopen("database.db", "r");
    int i = 0;
    while(fgets(array[i], 100 , f)){
        array[i][strlen(array[i]) - 1] = '\0';
        i++;
    }
    while (i < 500){
        array[i][i] = '\0';
        i++;
    }
    fclose(f);
    // calculate somme
    float somme = 0;
    i = 0;
    while (array[i][0]){
        somme += get_bal(array[i]);
        i++;
    }
    somme /= get_lines() - 1;
    h
    printf("## La somme des montants -> %f\n", somme);
}

void option_7_8(char c) { // bonus 2 moyenne
    clear();
    h
    // turn file into array
    char array[500][100];
    FILE *f = fopen("database.db", "r");
    int i = 0;
    while(fgets(array[i], 100 , f)){
        array[i][strlen(array[i]) - 1] = '\0';
        i++;
    }
    while (i < 500){
        array[i][i] = '\0';
        i++;
    }
    fclose(f);
    // loop through array and find c
    i = 0;
    int k = 0;
    while (array[i][0]){
        if (get_name(array[i])[0] == c)
            printf("%s\n", array[i]);
        i++;
    }
}

int main() {
    int option;
    do{
        clear();
        switch(option) {
            case 1:
                option_1();
                break;
            case 2:
                option_2();
                break;
            case 3:
                option_3();
                break;
            case 4:
                option_4();
                break;
            case 5:
                option_5();
                break;
            case 6:
                option_6();
                break;
            case 7:
                option_7();
                break;
            case 8:
                option_7_8('A');
                break;
            case 9:
                option_7_8('B');
                break;
        }
        h
        printf("## Menu Principale\n");
        h
        printf("1) Introduire un compte\n");
        printf("2) Introduire plusieurs comptes\n");
        printf("3) Operations\n");
        printf("4) Affichage\n");
        printf("5) Fedilisation\n");
        h
        printf("6) BONUS 1 (la somme)\n");
        printf("7) BONUS 2 (la moyenne)\n");
        printf("8) BONUS 3 {A}\n");
        printf("9) BONUS 4 (B)\n");
        h
        printf("99) Quitter l\'application\n");
        h
        printf("=> Operation : ");
        scanf("%d", &option);
        s_purge();
    } while (option != 99);
    printf("Merci pour votre utilisation\n");
    return 0;
}