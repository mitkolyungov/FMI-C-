#include <iostream>

template<typename T>
class Set {
    int capacity, size;
    T* arr;
    void copy(const Set<T> &other);
    void erase();

public:
    Set();
    Set(const Set<T> &other);
    Set<T> operator=(const Set<T>& other);
    ~Set();
    void add(const T &element);
    bool isEmpty();
    void print();
    bool containsElement(const T &element);
};

template<typename T>
Set<T>::Set() {
    const int cap = 8;
    arr = new T[cap];
    capacity = cap;
    size = 0;
}

template<typename T>
Set<T>::Set(const Set<T> &other) {
   
}

template<typename T>
Set<T>::~Set() {
    erase();
}

template<typename T>
Set<T> operator+(const Set<T> &a,const  Set<T> &b) {

}

template<typename T>
void Set<T>::copy(const Set<T>& a) {
    
}

template<typename T>
void Set<T>::erase() {
    delete[] arr;
    size = 0;
    capacity = 0;
}

template<typename T>
bool Set<T>::isEmpty() {
    return size != 0;
}

template<typename T>
bool Set<T>::containsElement(const T& a) {
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == a) {
            retrun true;
        }
    }

    return false;
}

template<typename T>
void Set<T>::print() {
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
 

int main()
{
    std::cout << "Hello World!\n";
}
