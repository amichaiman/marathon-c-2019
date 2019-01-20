#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* str_inert(char* str1, char* str2, char* at) {
    if (at < str1 || (str1 + strlen(str1)) < at) {
        return NULL;
    }
    char* res = (char*) malloc((strlen(str1)+strlen(str2)+1)*sizeof(char));
    strncpy(res, str1, at-str1);
    strcat(res, str2);
    strcat(res, at);
    return res;
}
int main() {
    char str[] = "i like ice cream";

    puts(str_inert(str, "do not ", str+2));

    return 0;
}

