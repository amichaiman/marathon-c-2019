#include <stdio.h>
#include <math.h>

typedef enum {false, true} boolean;
boolean is_prime(int n) {
    int i, sqrt_n;
    if (n == 2) {
        return true;
    }
    if (n < 2 || n%2 == 0) {
        return false;
    }
    sqrt_n = (int) sqrt(n);

    for (i=3; i<sqrt_n+1; i+=2) {
        if (!(n%i)) { // n%i == 0 || i divides n
            return false;
        }
    }
    return true;
}

int get_first_prime(int n) {
    int i;

    for (i=2; i<n; i++) {
        if (n%i == 0 && is_prime(i) == true) {
            return i;
        }
    }
    return n;
}

// 100 --------> 2*(50)... 2*2*(25)...... 2*2*5*(5) ...... 2*2*5*5
// 2+2+5+5

int get_sum_prime_dividers(int n) {
    if (n==1) {
        return 0;
    }
    int first_prime = get_first_prime(n);
    return first_prime + get_sum_prime_dividers(n/first_prime);
}


int main() {
    printf("sum: %d\n", get_sum_prime_dividers(100));
}

