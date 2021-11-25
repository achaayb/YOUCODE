#include "misc.h"

int get_lines(){
	FILE *file = fopen("database.db", "r");
	int lines = 1;
	char c[100];
	while (fgets(c, 100 ,file)){
		lines++;
	}
	fclose(file);
	return lines;
}

void insert_one(compte_t foo){
	FILE *file = fopen("database.db", "a");
	int id = get_lines();
	fprintf(file, "%d|%s|%s|%s\n", id ,foo.np, foo.cin, foo.montant);
	fclose(file);
	clear();
	h
		printf("Le compte %s a ete cree avec id : %d\n", foo.np, id);
}

void update_fund(int id, float amount){
	// turn file data into array;
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
	//
	//find array
	i = 0;
	char search[find_digits(id) + 1];
	sprintf(search,"%d|", id);

	while (array[i][i] != '\0'){
		if (strncmp(array[i],search,find_digits(id) + 1 ) == 0){
			break;
		}
		i++;
	}
	//update array

	// i = selected array
	// new2 = new clone array
	char new[100];
	char new2[100]; // clone array that we dont mind losing its pointer
	int b = 0;

	while (b<100){
		new2[b] = array[i][b];
		b++;
	}
	new[b] = '\0';

	char *id_get = strtok(new2, "|");
	char *name_get = strtok(NULL, "|");
	char *cin_get = strtok(NULL, "|");
	char *bal_get = strtok(NULL, "|");
	float new_bal = atof(bal_get) - amount;
	char *new_bal_c;
	char foo[50];
	sprintf(foo, "%.3f", new_bal);
	new_bal_c = &foo[0];


	//fill new array
	b = 0;
	while (*id_get){
		new[b] = *id_get;
		b++;
		id_get++;
	}
	new[b] = '|';
	b++;
	while(*name_get){
		new[b] = *name_get;
		b++;
		name_get++;
	}
	new[b] = '|';
	b++;
	while (*cin_get){
		new[b] = *cin_get;
		b++;
		cin_get++;
	}
	new[b] = '|';
	b++;
	while (*new_bal_c){
		new[b] = *new_bal_c;
		b++;
		new_bal_c++;
	}
	new[b] = '\0';
	//new arr filled
	//replace old array with new array
	
	b = 0;

	while (new[b]){
		array[i][b] = new[b];
		b++;
	}
	array[i][b] = '\0';

	b = 0;

// now we empty our file and repush the array

	fclose(fopen("database.db", "w"));

	f = fopen("database.db", "a");
		while (array[b][0] != '\0'){
			fputs(array[b], f);
			fputs("\n", f);
			b++;
		}
	fclose(f);
// le message
	clear();
	h
		printf("Operation avec success\n");
}
