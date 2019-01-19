#include <stdio.h>

int highest_digit(int n) {
    if (n<=0) {
        return 0;
    }
    int highest = highest_digit(n/10);
    return n%10 > highest ? n%10 : highest;
}

int main() {
    printf("highest digit: %d\n", highest_digit(76854));
    return 0;
}