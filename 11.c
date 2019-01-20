#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zconf.h>

#define MAX_NAME_LEN 30
#define IS_ENDANGERED_PARAMETER_LEN 5

typedef struct {
    char *name;
    float life_length;
    int is_endangered;
} Animal;

void print_animal_array(Animal** animal_array, int len) {
    int i;
    for (i=0; i<len; i++) {
        printf("---------\n%s\n%f\n%d\n---------\n", animal_array[i]->name, animal_array[i]->life_length, animal_array[i]->is_endangered);
    }
}

int lives_longer(Animal *a1, Animal* a2) {
    return (a1->life_length < a2->life_length) ? -1 : ((a1->life_length > a2->life_length) ? 1 : 0);
}

Animal* create_animal(char *animal_name, float life_len, int is_endangered) {
    if (is_endangered != 0 && is_endangered != 1) {
        return NULL;
    }

    Animal *animal = (Animal*) malloc (sizeof(Animal));
    animal->name = (char*) malloc ((strlen(animal_name)+1)*sizeof(char));
    strcpy(animal->name, animal_name);
    animal->life_length = life_len;
    animal->is_endangered = is_endangered;

    return animal;
}

int get_is_endangered() {
    char input[IS_ENDANGERED_PARAMETER_LEN];
    fgets(input, IS_ENDANGERED_PARAMETER_LEN, stdin);
    input[strcspn(input,"\n")] = '\0';
    return !strcmp(input, "yes");
}
Animal** get_animals(int n) {
    int i;
    char name[MAX_NAME_LEN];
    float life_len;
    int is_endangered;
    Animal **animal_array = (Animal**) malloc (sizeof(Animal*)*n);
    int max_animal_index = 0;
    float max_life_len = -1;

    for (i=0; i<n; i++) {
        /* get name*/
        fgets(name, MAX_NAME_LEN, stdin);
        name[strcspn(name, "\n")] = '\0';

        /* get life len */
        scanf("%f", &life_len);

        /* check if life len is bigger than current max */
        if (life_len > max_life_len) {
            max_life_len = life_len;
            max_animal_index = i;
        }

        /* clean buffer between integer/float to string */
        while(getchar() != '\n');

        /* get is_endangered */
        is_endangered = get_is_endangered();

        /* add to array */
        animal_array[i] = create_animal(name, life_len, is_endangered);
    }
    printf("max animal: %s!\n", animal_array[max_animal_index]->name);

    return animal_array;
}

int main() {
    Animal** animal_array = get_animals(2);
    print_animal_array(animal_array, 2);
    return 0;
}


