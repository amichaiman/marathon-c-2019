#include <stdio.h>

int print_digits(int n) {
    if (n<=0) {
        return 0;
    }
    int sum = print_digits(n/10);
    printf("%d ", n%10);
    return sum + n%10;
}

int main() {
    printf("\nsum : %d\n", print_digits(76854));
    return 0;
}