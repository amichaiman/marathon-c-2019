#include <stdio.h>
#include <string.h>

int strremove(char* str, char* rem) {
    char* location = strstr(str, rem);

    if (!location) {
        return -1;
    }
    strcpy(location,location+strlen(rem));
    return (int) (location - str);
}
int main() {
    char str[] = "the bigger the error the lower the grade";
    puts(str);
    strremove(str, "er");
    puts(str);
    return 0;
}

