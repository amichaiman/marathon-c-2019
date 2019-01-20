#include <stdio.h>
#include <string.h>

void sort_strings(char **strings, int number_of_strings) {
    int i,j;
    for (i=number_of_strings; i>1; i--) {
        for (j=1; j<i-1; j++) {
            if (strlen(strings[j]) > strlen(strings[j+1]) || strlen(strings[j]) == strlen(strings[j+1])) {
                char *temp = strings[j];
                strings[j] = strings[j+1];
                strings[j+1] = temp;
            }
        }
    }
}

int main(int argc, char **argv) {
    int i;
    sort_strings(argv, argc);
    for (i=0; i<argc; i++) {
        puts(argv[i]);
    }
    return 0;
}

