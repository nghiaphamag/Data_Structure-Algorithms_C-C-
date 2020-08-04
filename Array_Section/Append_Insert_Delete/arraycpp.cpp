#include <iostream>

class arraycpp
{
private:
    int length;
    int size;
    int* A;
public:
    arraycpp(int size) {
        this->size = size;
        A = new int[size];
    }

    void Create() {
        std::cout << "Enter number of elements: " << std::flush;
        std::cin >> length;
        std::cout << "Enter the array elements: " << std::endl;
        for (int i = 0; i < length; i++) {
            std::cout << "Array element: " << i << " = " << std::flush;
            std::cin >> A[i];
        }
    }

    // Add/Append function
    void Append(int x) {
        if (size > length) {
            A[length++] = x;
        }
    }

    // Insert function
    void Insert(int index, int value) {
        if (index >= 0 && index <= length) {
            int i;
            for (i = length; i < index; i--)
                A[i] = A[i-1];
            A[index] = value;
            length++;
        }
    }

    // Delete function
    int Delete(int index) {
        int x = 0;
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

    void Display(){
        for (int i = 0; i < length; i++) {
            std::cout << A[i] << " ";
        }
    }    

    ~arraycpp() {
        delete[] A;
        std::cout << "\nDestroy array" << std::endl;
    }
};

int main() {
    arraycpp arr(10);
    arr.Create();
    arr.Delete(0);
    // arr.Insert(4, 88);
    //arr.Append(10);
    arr.Display();

    return 0;
}
