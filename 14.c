#include <stdio.h>
#include <stdlib.h>

#define MIN_AGE 13

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("ERROR: expected ./<executable> <input filename> <output filename>");
        exit(1);
    }

    FILE* in_file = fopen(argv[1],"r");
    FILE* out_file = fopen(argv[2],"w");

    int id;
    float age;

    while (fscanf(in_file, "%d %f", &id, &age)==2) {
        fprintf(out_file, "%d. %g%s\n", id, age, age < MIN_AGE ? " - too young!" : "");
    }

    return 0;
}


