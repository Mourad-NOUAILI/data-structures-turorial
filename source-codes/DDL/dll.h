#include <bits/stdc++.h>

template <class T>
class dll {
    private:
        // Internal Node class to represent a node
        class Node {
            public:
                T data;
                Node  *prev;
                Node *next;

            public:
                Node(T data, Node *prev, Node *next){
                    this->data =data;
                    this->prev = prev;
                    this->next = next;
                }
        };

        int dll_size = 0;
        Node  *head = nullptr;
        Node  *tail = nullptr;
    
    public:
        // Empty the dll: O(n) 
        void clear();

        // Display all data of the dll
        void display();

        // Get the size of the dll: O(1)
        int size();

        // Check if the dll is empty or not: O(1)
        bool is_empty();

        // Add an element at the beginning of the dll: O(1)
        void add_begin(T data);

        // Add an element at the end of the dll: O(1)
        void add_end(T data);

        // Insert a node at a particular position: O(n)
        void add_at(int ins_pos, T data);

        // Get the data of the first node: O(1)
        T peak_first();

        // Get the data of the last node: O(1)
        T peak_last();

        // Get the data from particular node by index from the dll: O(n)
        T peak_at(int index);

        // Get the data of the first node then remove it: O(1)
        T pop_first();

        // Get the data of the last node then remove it: O(1)
        T pop_last();

        // Remove a node: O(n)
        void pop(T data);

        // Get the data from particular node by index from the dll then remove it: O(n)
        T pop_at(int index);

        // Get the index of a node and a pointer pointed to it.
        void index_of(T data, int &index, Node **ptr);

        // get the node of a given index
        void access_by_index(int index, Node **ptr);

        // Check if a node exists in the dll
        bool contains(T data);
};
