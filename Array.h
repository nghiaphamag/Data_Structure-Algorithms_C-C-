#ifndef ARRAY_H_
#define ARRAY_H_

template <class T>
class Array {
    private:
        int length;
        int size;
        T *A;
    public:
        Array();
        Array(int sz);
        virtual void Create();
        virtual void Display();
        virtual void Append(T value);
        virtual void Insert(int index, T value);
        virtual T Delete(int index);   
        ~Array();
};


#endif  /* ARRAY_H_ */