#include "dynamic_array.h"

#include <assert.h> // For assert


template<class T>
my_dynamic_array<T>::my_dynamic_array(){}

template<class T>
my_dynamic_array<T>::my_dynamic_array(int capacity){
    assert(capacity > 0);
    this->capacity = capacity;
    arr = new T[capacity];
}

template<class T>
int my_dynamic_array<T>::size() {return len;}

template<class T>
bool my_dynamic_array<T>::is_empty() {return size() == 0;}

template<class T>
T my_dynamic_array<T>::get(int index){
    assert( (0 <= index) && (index < size()) );
    return arr[index];
}

template<class T>
void my_dynamic_array<T>::set(int index, T elem) {
    assert( (0 <= index) && (index < size()) );
    arr[index] = elem;
}

template<class T>
void my_dynamic_array<T>::clear(){
    for (int i = 0 ; i < len ; ++i)
        arr[i] = T();
    len = 0;
}

template<class T>
void my_dynamic_array<T>::add(T elem){
    if (len == capacity){
        if (capacity == 0) capacity = 1;
        else capacity *= 2;
        T *new_arr = new T[capacity];
        for (int i = 0 ; i < len ; ++i)
            new_arr[i] = arr[i];
        arr = new_arr;
    }
    arr[len++] = elem;
}