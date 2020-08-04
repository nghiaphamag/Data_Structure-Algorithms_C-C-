#include <iostream>
#include "Array.h"

template <class T>
Array<T>::Array() {
    size = 10;
    length = 0;
    A = new T[size];
}

template <class T>
Array<T>::Array(int sz) {
    size = sz;
    length = 0;
    A = new T[sz];
}

template <class T>
void Array<T>::Display() {
    for (int i = 0; i < length; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
void Array<T>::Create() {
    std::cout << "Enter number of elements: " << std::flush;
    std::cin >> length;
    std::cout << "Enter the array elements: " << std::endl;
    for (int i = 0; i < length; i++) {
        std::cout << "Array element: " << i << " = " << std::flush;
        std::cin >> A[i];
    }
}

template <class T>
void Array<T>::Append(T value) {
    if (size > length) {
        A[length++] = value;
    }
}

template <class T>
void Array<T>::Insert(int index, T value) {
    if (index >= 0 && index <= length) {
        int i;
        for (i = length; i < index; i--)
            A[i] = A[i-1];
        A[index] = value;
        length++;
    }
}

template <class T>
T Array<T>::Delete(int index) {
    T x = 0;
    int i;
    if (index >= 0 && index < length) {
        x = A[index];
        for (i = index; i < length-1; i++)
            A[i] = A[i+1];
        length--;
        return x;
    }
    return 0;
}

template <class T>
Array<T>::~Array() {
    delete[] A;
}

int main() {
    Array<int> arr(10);
    arr.Insert(0, 23);
    arr.Insert(1, 21);
    arr.Insert(2, 33);
    std::cout << arr.Delete(1) << std::endl;
    arr.Display();
}