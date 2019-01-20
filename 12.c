#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AGE_STR_LEN 10

typedef struct {
    char *first_name;
    char *last_name;
    int age;
} Person;

int get_num_of_digits(int n) {
    int num_of_digits=0;
    while (n != 0) {
        num_of_digits++;
        n/=10;
    }
    return num_of_digits;
}

void itoa(int n, char *s) {
    int num_of_digits = get_num_of_digits(n);
    int i;
    for (i=num_of_digits-1; i>=0; i--) {
        s[i] = (char) ('0' + n % 10);
        n/=10;
    }
    s[num_of_digits] = '\0';
}

char* person_to_string(Person* p) {
    char *person_str = (char*) malloc(sizeof(char)*(strlen(p->first_name) +
                                                    strlen(p->last_name) + get_num_of_digits(p->age) + 3));
    if (!person_str) {
        return NULL;
    }
    char age_str[MAX_AGE_STR_LEN];
    strcpy(person_str, p->first_name);
    strcat(person_str, " ");
    strcat(person_str, p->last_name);
    strcat(person_str, " ");
    itoa(p->age, age_str);
    strcat(person_str, age_str);
    return person_str;
}

char* join_persons(Person* person_array, int len) {
    char* all_person_str = (char*) malloc(sizeof(char));
    char* person_str;
    int i;

    for (i=0; i<len; i++) {
        person_str = person_to_string(&person_array[i]);
        all_person_str = (char*) realloc(all_person_str, sizeof(char)*(strlen(all_person_str) + strlen(person_str) + 3));
        if (!all_person_str) {
            return NULL;
        }
        strcat(all_person_str, person_str);
        if (i != len-1) {
            strcat(all_person_str, "; ");
        }
    }
    return all_person_str;

}
int main() {
    Person p={"amichai", "mantinband", 27};
    Person p2={"dani", "mantinband", 27};
    Person person_array[] = {p, p2};
    puts(join_persons(person_array, 2));
    return 0;
}


