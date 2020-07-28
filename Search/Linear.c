#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// Swap Function
void Swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Search Linear and 
int Linear(struct Array *arr, int key) {
    int i;
    for (i = 0; i < arr->length; i++) {
        if (key == arr->A[i]) {
            // Transposition
            //Swap(&arr->A[i], &arr->A[i-1]);

            // Move the frontend/head
            Swap(&arr->A[i], &arr->A[0]);
            return i;
        }
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
    printf("%d", Linear(&arr, 3));
    Display(arr);
    return 0;
}
