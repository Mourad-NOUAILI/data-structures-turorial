#include <bits/stdc++.h>

template <class T>
class sll {
    private:
        // Internal Node class to represent a node in a SLL.
        class Node {
            public:
                Node *next; // Pointer to the next node.
                T data;
            public:
                Node(T data, Node *next) {
                    this->data = data;
                    this->next = next;
                }
        };

        int sll_size = 0;
        Node *head = nullptr;
        Node *tail = nullptr;
    public:
        // Return the size of the sll: O(1)
        int size();

        // Check is the sll is empty or not: O(1)
        bool is_empty();

        // Clear the sll: O(n)
        void clear();

        // Display the sll: O(n)
        void display();

        // Search a node by data, if exists return the position and a pointer to that node: O(n)
        void index_of(T data, int &index, Node **ptr);

        // Access to a node by its index, it returns a pointer to that node: O(n)
        void access_by_index(int index, Node **ptr);

        // Check if a node holding a giving data exists or not: O(n)
        bool contains(T data);

        // Returns the data of the first node: O(1)
        T peak_first();

        // Returns the data of the last node: O(1)
        T peak_last();

        // Returns the data of the a node at a giving index: O(n)
        T peak_at(int index);

        // Add a node at the begining of the sll, that hold a giving data: O(1)
        void add_front(T data);

        // Add a node at the end of the sll, that hold a giving data: O(1)
        void add_back(T data);

        // Add a node at a giving position of the sll, that hold a giving data: O(n)
        void add_at(T data, int index);

        // Return the data of the first node, then remove it: O(1)
        T pop_first();

        // Return the data of the last node, then remove it: O(n)
        T pop_last();

        // Return the data of node if exists, then remove it: O(n)
        T pop(T data);

        // Return the data of a node by index, then remove it: O(n)
        T pop_at(int index);
};