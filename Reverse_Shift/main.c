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

// Reverse Auxiliary 
void Reverse(struct Array *arr) {
    int *B;
    int i, j;
    B = (int *)malloc(arr->length * sizeof(int));
    for (i = arr->length-1, j = 0; i >= 0; i--, j++)
        B[j] = arr->A[i];
    
    for (i = 0; i < arr->length; i++)
        arr->A[i] = B[i];   
}

//
void Reverse2(struct Array *arr) {
    int i, j;
    for (i = 0, j = arr->length-1; i < j; i++, j--)
        Swap(&arr->A[i], &arr->A[j]);
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
    Reverse(&arr);
    Display(arr);
    printf("\n");
    Reverse2(&arr);
    Display(arr);
    return 0;
}
