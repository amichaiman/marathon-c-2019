#include <stdio.h>

void replace(char *s, char c1, char c2) {
    if (!s || !(*s)) {
        return;
    }
    if (*s == c1) {
        *s = c2;
    }
    replace(s+1, c1, c2);
}

int main() {
    char s[] = "seventeen";
    printf("before: %s\n", s);
    replace(s, 'e', 'a');
    printf("after: %s\n", s);
    return 0;
}

