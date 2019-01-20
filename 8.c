#include <stdio.h>
#include <string.h>

int strremove(char* str, const char* rem) {
    char* location = strstr(str, rem);

    if (!location) {
        return -1;
    }
    strcpy(location,location+strlen(rem));
    return (int) (location - str);
}

int strremoveAll(char *str, const char *rem) {
    int number_of_removed = 0;

    while (strremove(str,rem) != -1){
        number_of_removed++;
    }
    return number_of_removed;
}
int main() {
    char str[] = "the bigger the error the lower the grade";
    puts(str);
    printf("%d\n", strremoveAll(str, "er"));
    puts(str);
    return 0;
}

