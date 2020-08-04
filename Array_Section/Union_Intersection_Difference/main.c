#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// Copy element without duplications and only execute with array sorted 
struct Array* Union(struct Array *arr1, struct Array *arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
        } else if (arr2->A[j] < arr1->A[i]) {
            arr3->A[k++] = arr2->A[j++];
        } else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }        
    }
    for (;i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (;j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

// Copy common element and only execute with array sorted 
struct Array* Intersection(struct Array *arr1, struct Array *arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j]) {
            i++;
        } else if (arr2->A[j] < arr1->A[i]) {
            j++;
        } else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }        
    }
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

// Copy difference element of array A and only execute with array sorted 
struct Array* Difference(struct Array *arr1, struct Array *arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
        } else if (arr2->A[j] < arr1->A[i]) {
           j++;
        } else {
            i++;
            j++;
        }        
    }
    for (;i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

void Display(struct Array arr) {
    int i;
    printf("\nShow all implement: \n");
    for (i=0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
}

int main() {
    struct Array arr1 = {{1, 3, 5, 7, 9, 11}, 10, 6};
    struct Array arr2 = {{2, 3, 4, 7, 8, 12}, 10, 6};   
    struct Array *arr3;
    //arr3 = Union(&arr1, &arr2);                       // Result: 1 2 3 4 5 7 8 9 11 12
    //arr3 = Intersection(&arr1, &arr2);                // Result: 3 7
    arr3 = Difference(&arr1, &arr2);                    // Result: 1 5 9 11
    Display(*arr3);
    return 0;
}
