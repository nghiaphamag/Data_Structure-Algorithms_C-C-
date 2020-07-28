#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// Get
int Get(struct Array arr, int index) {
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

// Set
void Set(struct Array *arr, int index, int newValue) {
    if (index >= 0 && index < arr->length)
        arr->A[index] = newValue;
}

// Max
int Max(struct Array arr) {
    int max = arr.A[0];
    for (int i = 0; i < arr.length; i++) {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

// Min
int Min(struct Array arr) {
    int min = arr.A[0];
    for (int i = 0; i < arr.length; i++) {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

// Sum
int Sum(struct Array arr) {
    int total = 0;
    for (int i = 0; i < arr.length; i++)
        total += arr.A[i];
    
    return total;
}

// Avg
float Avg(struct Array arr) {
    return (float)Sum(arr)/arr.length;
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
    printf("Get: %d\n", Get(arr, 2));
    Set(&arr, 2, 10);
    printf("Max is: %d\n", Max(arr));
    printf("Min is: %d\n", Min(arr));
    printf("Sum is: %d\n", Sum(arr));
    printf("Avg is: %f\n", Avg(arr));
    Display(arr);
    return 0;
}
