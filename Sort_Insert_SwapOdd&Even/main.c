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

// Check array is sort or not
int isSort(struct Array arr) {
    int i;
    for (i = 0; i < arr.length-1; i++)
        if (arr.A[i] > arr.A[i+1])
            return 0;
    
    return 1;
}

// Insert and sort array
void InsertBySort(struct Array *arr, int value) {
    int i = arr->length -1;

    while (i >= 0 && arr->A[i] > value)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = value;
    arr->length++;  
}

// Re-Arrange Odd and Even
void SwapOddEven(struct Array *arr) {
    int i = 0;
    int j = arr->length-1;
    while (i < j) {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] >= 0)
            j--;
        if (i < j)
            Swap(&arr->A[i], &arr->A[j]);
    }
}

void Display(struct Array arr) {
    int i;
    printf("\nShow all implement: \n");
    for (i=0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
}

int main() {
    struct Array arr = {{1, 6, 5, 7, 9, 11}, 10, 6};
    struct Array arr2 = {{-2, 1, -3, -8, -10, -9, 6, 5}, 10, 8};
    InsertBySort(&arr, 4);
    printf("%d\n", isSort(arr));
    Display(arr);

    SwapOddEven(&arr2);
    Display(arr2);
    return 0;
}
