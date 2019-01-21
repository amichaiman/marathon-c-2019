#include <stdio.h>


int num_sums(int *a, int size, int n) {
    if (size<=0) {
        return 0;
    }
    if (*a > n) {
        return num_sums(a+1, size-1, n);
    }
    return *a == n ? 1+num_sums(a+1, size-1, n)
                   : num_sums(a+1, size-1, n-*a) + num_sums(a+1, size-1, n);
}

int main() {
    int a[] = {3,1,4,5,3,7,8,2};
    printf("%d", num_sums(a, sizeof(a)/sizeof(*a), 7));
    return 0;
}
