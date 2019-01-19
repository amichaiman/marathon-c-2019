#include <stdio.h>

int num_nums(int a[], int size, int n) {
    if (size <= 0) {
        return 0;
    }
    if (a[0] > n) {
        return num_nums(a+1, size-1, n);
    } else if (a[0] < n) {
        return num_nums(a+1, size-1, n-a[0]) + num_nums(a+1, size-1, n);
    }
    return 1;
}

int main() {
    int a[] = {3,1,4,5,3,7,8,2};
    printf("%d\n", num_nums(a, 8, 7));
    return 0;
}