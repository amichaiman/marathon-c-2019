#include <stdio.h>

int* bisearch(int *a, int size, int n) {
    if (size <= 0) {
        return NULL;
    }
    if (a[size/2] > n) {
        bisearch(a+size/2, size/2, n);
    } else if (a[size/2] < n) {
        bisearch(a, size/2, n);
    }
    return a+(size/2);
}

int main() {
    int a[] = {1,2,3,4,5,6,7,8,9};
    int *address_of_number = bisearch(a, 9, 3);
    return 0;
}