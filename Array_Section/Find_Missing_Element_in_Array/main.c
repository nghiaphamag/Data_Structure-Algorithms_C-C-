#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Find Max and Min in a single scan
int *findMaxAndMin(int arr[], int length) {
    int min, max;
    int *arrReturn = (int *)malloc(sizeof(int) * 2);
    min = max = arr[0];

    for (int i = 0; i < length; i++) {
        if (arr[i] < min)
            min = arr[i];
        else if (arr[i] > max)
            max = arr[i];
    }
    arrReturn[0] = min;
    arrReturn[1] = max;
    return arrReturn;
}
// Find single missing element in sorted array
void findSingleMiss(int arr[], int element) {
    int diff, low;
    low = arr[0];
    diff = low - 0;

    for (int i = 0; i < element; i++) {
        if ((arr[i] - i) != diff) {
            printf("[Sorted] simple missing number is: %d\n", (diff + i));
            break;
        }
    }
}

// Find multiple missing element in sorted array
void findMultipleMiss(int arr[], int element) {
    int diff, low;
    low = arr[0];
    diff = low - 0;

    for (int i = 0; i < element; i++) {
        if ((arr[i] - i) != diff) {
            while (diff < (arr[i]-i)) {
                printf("[Sorted] multiple missing number is: %d\n", (diff + i));
                diff++;
            }            
        }
    }
}

// Using hashtable/bitset find multiple missing element in unsorted array (best solution)
void findMultipleMissInUnsorted(int arr[], int element) {
    int low, high;
    int *arrMaxMin = findMaxAndMin(arr, element);
    low = arrMaxMin[0];
    high = arrMaxMin[1];
    int arrTemp[high];
    memset(arrTemp, 0, sizeof(arrTemp));
    
    for (int i = 0; i < element; i++) {
        arrTemp[arr[i]]++;
    }

    for (int i = low; i <= high; i++) {
        if (arrTemp[i] == 0)
            printf("[Unsorted] using hashtable find multiple missing number is: %d\n", i);
    }
    free(arrMaxMin);
}

// Finding duplicate elements in a sorted array
void findDuplicateElement(int arr[], int element) {
    int i, j;
    i = j = 0;
    for (i = 0; i < element; i++) {
        if (arr[i] == arr[i+1]) {
            j = i+1;
            while (arr[j] == arr[i])
                j++;

            printf("[Sorted] find duplicate miss elements: %d appearing %d times \n", arr[i], (j-i));
            i = j-1;
        }
    }
}

// Using hashtable/bitset finding duplicate elements in a sorted array (best solution)
void findDuplicateElementByHashTable(int arr[], int element) {
    int max = arr[element-1];
    
    int arrTemp[max+1];
    memset(arrTemp, 0, sizeof(arrTemp));
    
    for (int i = 0; i < element; i++) {
        arrTemp[arr[i]]++;
    }

    for (int i = 0; i <= max; i++) {
        if (arrTemp[i] > 1)
            printf("[Sorted] using hashtable find duplicate miss elements: %d appearing %d times\n", i, arrTemp[i]);
    }
}

// Finding dulicate element in unsorted array
void findDulicateElementInUnsorted(int arr[], int element) {

    for (int i = 0; i < element; i++) {
        int count = 1;
        if (arr[i] != -1) {
            for (int j = i+1; j < element; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    arr[j] = -1;
                }
            }
        }
        if (count > 1)
            printf("[Unsorted] Find duplicate miss elements: %d appearing %d times\n", arr[i], count);
    }
}

// Using hashtable/bitset finding duplicate elements in a unsorted array (best solution)
void findDulicateElementInUnsortedByHashTable(int arr[], int element) {
    int low, high;
    int *arrMaxMin = findMaxAndMin(arr, element);
    
    low = arrMaxMin[0];
    high = arrMaxMin[1];
    int arrTemp[high];
    memset(arrTemp, 0, sizeof(arrTemp));

    for (int i = 0; i < element; i++) {
        arrTemp[arr[i]]++;
    }
    
    for (int i = low; i < high; i++) {
        if (arrTemp[i] > 1)
            printf("[Unsorted] using hashtable find duplicate miss elements: %d appearing %d times\n", i, arrTemp[i]);
    }
    free(arrMaxMin);
}

// Finding a pair with sum k (a+b = k) in unsorded array
void findAPairWithSumInUnsorted(int arr[], int element, int k) {
    int i, j;
    for(i = 0; i < element-1; i++) {
        for (j = i+1; j < element; j++) {
            if ((arr[i] + arr[j]) == k) {
                printf("[Unsorted] %d + %d = %d \n", arr[i], arr[j], k);
            }
        }
    }
}

// Using hashtable/bitset finding a pair with sum k (a+b = k) in unsorded array (best solution)
void findAPairWithSumInUnsortedByHashTable(int arr[], int element, int k) {
    int low, high;
    int *arrMaxMin = findMaxAndMin(arr, element);
    
    low = arrMaxMin[0];
    high = arrMaxMin[1];
    int arrTemp[high];
    memset(arrTemp, 0, sizeof(arrTemp));

    for (int i = 0; i < element; i++) {
        if (k-arr[i] >= 0 && arrTemp[k-arr[i]] != 0) {
            printf("[Unsorted] using hashtable %d + %d = %d \n", arr[i], k-arr[i], k);
        }
        arrTemp[arr[i]]++;
    }
}

// Finding a pair with sum k (a+b = k) in sorded array
void findAPairWithSumInSorted(int arr[], int element, int k) {
    int i, j;
    i = 0;
    j = element - 1;

    while (i < j) {
        if (arr[i] + arr[j] == k) {
            printf("[Sorted] %d + %d = %d \n", arr[i], arr[j], k);
            i++;
            j--;
        }
        else if (arr[i] + arr[j] < k)
            i++;
        else
            j--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12};
    findSingleMiss(arr, 11);
    printf("\n");
    int arr2[] = {5, 6, 8, 10, 13, 14, 15};
    findMultipleMiss(arr2, 7);
    printf("\n");
    int arr3[] = {7, 5, 9, 4, 12, 14, 15};
    findMultipleMissInUnsorted(arr3, 7);
    printf("\n");
    int arr4[] = {3, 5, 8, 8, 9, 12, 12, 12, 15 , 16, 16, 17};
    findDuplicateElement(arr4, 12);
    printf("\n");
    findDuplicateElementByHashTable(arr4, 12);
    printf("\n");
    int arr5[] = {5, 4, 8,  9, 4, 8, 11, 15, 5, 16, 4, 4};
    findDulicateElementInUnsorted(arr5, 12);
    printf("\n");
    int arr6[] = {5, 4, 8,  9, 4, 8, 11, 15, 5, 16, 4, 4};
    findDulicateElementInUnsortedByHashTable(arr6, 12);
    printf("\n");
    int arr7[] = {5, 4, 8,  9, 4, 8, 11, 15, 5, 16, 6, 1};
    findAPairWithSumInUnsorted(arr7, 12, 10);
    printf("\n");
    int arr8[] = {5, 4, 8,  9, 4, 8, 11, 15, 5, 16, 6, 1};
    findAPairWithSumInUnsortedByHashTable(arr8, 12, 10);
    printf("\n");
    int arr9[] = {-2, 1, 2, 3, 5, 6, 7, 8, 9, 10, 11, 12};
    findAPairWithSumInSorted(arr9, 12, 10);
    return 0;
}

