#include <stdio.h>
#include <string.h>


void arrange_arguments(int size, char **strings);

void print_arguments(int size, char **strings);

int main(int argc, char **argv) {
    arrange_arguments(argc, argv);
    print_arguments(argc, argv);
    return 0;
}

void print_arguments(int size, char **strings) {
    int i;
    for (i=1; i<size; i++) {
        puts(strings[i]);
    }
}

void arrange_arguments(int size, char **strings) {
    int i,j;
    for (i=size; i>1; i--) {
        for (j=1; j<i-1; j++) {
            if (strlen(strings[j]) < strlen(strings[j+1]) ||        //if j is shorter j+1
                    (strlen(strings[j]) == strlen(strings[j+1]) &&  //if j == j+1
                    strcmp(strings[j], strings[j+1]) > 0)) {        //and j > j+1 in dictionary
                /* swap */
                char* temp = strings[j];
                strings[j] = strings[j+1];
                strings[j+1] = temp;
            }
        }
    }
}

