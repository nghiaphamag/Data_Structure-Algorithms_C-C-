#include <stdio.h>
#include <stdlib.h>

struct Array {
    int* A;
    int size;
    int length;
};

void Display(struct Array arr) {
    int i;
    printf("Show all implement: \n");
    for (i=0; i<arr.length; i++) {
        printf("%d", arr.A[i]);
    }
}

// Add/Append function
void Append(struct Array *arr, int x) {
    if (arr->size > arr->length)
        arr->A[arr->length++] = x;
}

// Insert function
void Insert(struct Array *arr, int index, int value) {
    if (index >= 0 && index <= arr->length) {
        int i;
        for (i = arr->length; i < index; i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = value;
        arr->length++;
    }
}

// Delete function
int Delete(struct Array *arr, int index) {
    int x = 0;
    int i;
    if (index >= 0 && index < arr->length) {
        x = arr->A[index];
        for (i = index; i < arr->length-1; i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
        return x;
    }
    return 0;
}

int main()
{
    int i,n;
    struct Array arr;

    printf("Enter a size of array: ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;

    printf("Enter number of numbers: ");
    scanf("%d", &n);
    arr.length = n;

    printf("Enter implement: ");
    for (i=0; i<n; i++) {
        scanf("%d", &arr.A[i]);
    }

    //Append(&arr, 10);
    //Insert(&arr, 4, 88);
    printf("\n Remove at: %d\n", Delete(&arr, 0));
    Display(arr);
    arr.A = NULL;
    return 0;
}
