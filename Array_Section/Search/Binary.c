#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// Search Binary
int Binary(struct Array arr, int key) {
    int l, mid, h;
    l = 0;
    h = arr.length-1;
    while (l <= h) {
        mid = (l+h)/2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
// Recursive Binary Search
int RBinary(int a[], int l, int h, int key) {
    int mid;
    if (l <= h) {
        mid = (l+h)/2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return RBinary(a, l, mid-1, key);
        else
            return RBinary(a, mid+1, h, key);
    }
    return -1;
}

void Display(struct Array arr) {
    int i;
    printf("Show all implement: \n");
    for (i=0; i < arr.length; i++) {
        printf("%d", arr.A[i]);
    }
}

int main() {
    struct Array arr = {{1, 2, 3, 4, 5, 6}, 10, 6};
    //printf("%d\n", Binary(arr, 6));
    printf("%d\n", RBinary(arr.A, 0, arr.length, 10));
    Display(arr);
    return 0;
}
