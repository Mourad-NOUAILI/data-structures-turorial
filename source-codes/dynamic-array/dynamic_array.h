#include <iterator>

template <class T> 
class my_dynamic_array{
    private:
        int len = 0; // length user thinks array is
        int capacity = 0; // Actual array size
        T *arr;
    public:
        my_dynamic_array();
        my_dynamic_array(int capacity);
        int size();
        bool is_empty();
        T get(int index);
        void set(int index, T elem);
        void clear();
        void add(T elem);
        
        // TODO: all functions below
        void remove_at(int index);
        void remove(T elem);
        bool contains(T elem);
        int index_of(T elem);
};  