#include "dll.h"

#include <assert.h>

// Clear the dll: O(n)
template <class T>
void dll<T>::clear() {
    Node *trav = head;
    while (trav != nullptr) {
        Node *next = trav->next;
        trav->prev = trav->next = nullptr;

		delete trav->next;
		delete trav->prev;
        
        trav = next;
    }

    // Delete all pointers from memory.
    trav = head = tail = nullptr;
    delete trav;
    delete head;
    delete tail;

    // Set DLL's size to zero. 
    dll_size = 0;
}

// Display all data of the dll: O(n)
template<class T>
void dll<T>::display() {
    Node *trav = head;
    while (trav != nullptr) {
        Node *next = trav->next;
        std::cout << trav->data << " ";
        trav = next;
    }
    std::cout<< '\n';   
}

// Get the size of the dll: O(1)
template <class T>
int dll<T>::size(){
    return dll_size;
}

 // Check if the dll is empty or not: O(1)
template <class T>
bool dll<T>::is_empty() {
    return size() == 0;
}

// Get the index of a node and a pointer pointed to it
template <class T>
void dll<T>::index_of(T data, int & index, Node **ptr){
    if (!is_empty()) {
        *ptr = head;
        index = 0;
        while((*ptr)->data != data && (*ptr) != nullptr) {
            *ptr = (*ptr)->next;
            index++;
        }
        if (*ptr == nullptr) index = -1;
    }
    else {
        index = -1;
        *ptr = nullptr;
    }
}

// Check if a node exists in the dll
template <class T>
bool dll<T>::contains(T data) {
    int pos;
    Node *ptr;
    index_of(data, pos, &ptr);

    return ptr != nullptr;
}

// get the node of a given index: O(n)
template <class T>
void dll<T>::access_by_index(int index, Node **ptr) {
     assert(index >= 0 && index < size());
    if (!is_empty()) {
        *ptr = head;
        int pos = 0;
        while (pos != index) {
            *ptr = (*ptr)->next;
            pos++;
        }
    }
    else
        *ptr = nullptr;
}

// Add an element at the beginning of the dll: O(1)
template<class T>
void dll<T>::add_begin(T data) {
    if (is_empty()){ // If the DLL is empty
        // The new node has no next or previous node...
        // ...both the head and the tail points to the new node
        head = tail =  new Node(data, nullptr, nullptr);
    }
    else { // If the DLL is not empty
        // The previous node of the head is the new node
        head->prev = new Node(data, nullptr, head /*the head will be the next node of the new node*/);
        head = head->prev; // the head will points to its previous node
    }

    dll_size++;
}

// Add an element at the end of the dll: O(1)
template<class T>
void dll<T>::add_end(T data) {
    if (is_empty()) { // If the DLL is empty
        // The new node has no next or previous node...
        // ...both the head and the tail points to the new node
        head = tail = new Node(data, nullptr, nullptr);
    }
    else { // If the DLL is not empty
        // The next node of the tail is the new node
        tail->next = new Node(data, tail/*the tail will be the previous node of the new node*/, nullptr);
        tail = tail->next;  // the tail will points to its next node
    }

    dll_size++;
}

 // Insert a node at a particular position: O(n)
 template <class T>
 void dll<T>::add_at(int ins_pos, T data){
     assert( ins_pos >= 0 && ins_pos <= size() );
     if (!is_empty()) {
         if (ins_pos == 0) add_begin(data); // if the insertion position is zero, insert in the begin of the dll
         else if (ins_pos == size()) add_end(data); // if the insertion position is at the end, insert in the end of the dll
         else { // otherwise
            // Seek the node that exists right before to the insertion position
            Node *trav = nullptr;
            access_by_index(ins_pos-1, &trav);
            

            // Create the new node
            // point the new node’s previous pointer, to the node pointed by the  pointer trav (1)
            // point the new node’s next pointer, to the node next the pointer trav (2)
            Node *new_node = new Node(data, trav /*(1)*/, trav->next /*(2)*/); 

            // make the node’s (that exist in the insertion position) previous pointer points to the new node
            trav->next->prev = new_node; 

            // make the node’s (pointed by the trav pointer) next pointer, points to the new node   
            trav->next = new_node;

            dll_size++;
         }

     }
 }

// Get the data of the first node: O(1)
template<class T>
T dll<T>::peak_first(){
    if (!is_empty()) return head->data;
    else {
       assert(size() != 0);
    }
}

// Get the data of the last node: O(1)
template<class T>
T dll<T>::peak_last(){
    if (!is_empty()) return tail->data;
    else {
        assert(size() != 0);
    }
}

// Get the data from particular node by index from the dll: O(n)
template<class T>
T dll<T>::peak_at(int index){
    if (!is_empty()){
        Node *trav = nullptr;
        access_by_index(index, &trav);
        return trav->data;
    }
    else {
        assert(size() != 0);
    }
}

// Get the data of the first node then remove it: O(1)
template<class T>
T dll<T>::pop_first() {
    if (!is_empty()) {
        T data = head->data;
        if (head->next != nullptr) { // if there is more than one node
            Node *temp = head->next;
            Node *to_remove = head;
            temp->prev = nullptr;
            head->next = nullptr;
            head = temp;
            to_remove = nullptr;
            delete to_remove;
            temp = nullptr;
            delete temp;
        }
        else { // If there is one node
            head = tail = nullptr;
            delete head;
            delete tail;
        }
        dll_size--;
   
        return data;
    }
    else {
        assert(size() != 0);
    }
}

// Get the data of the last node then remove it: O(1)
template<class T>
T dll<T>::pop_last(){
    if (!is_empty()) { // if there is more than one node
        T data = tail->data;
        if (tail->prev != nullptr) {
            Node *temp = tail->prev;
            Node *to_remove = head;
            temp->next = nullptr;
            tail->prev = nullptr;
            tail = temp;
            to_remove = nullptr;
            delete to_remove;
            temp = nullptr;
            delete temp;
        }
        else { // If there is one node
            head = tail = nullptr;
            delete head;
            delete tail;
        }

        dll_size--;
  
        return data;
    }
    else
        assert(size() != 0);
}

// Remove a node: O(n)
template<class T>
void dll<T>::pop(T data) {
    if (!is_empty()) {
        // To know the position of the data to remove
        int pos;
        Node *ptr;
        index_of(data, pos, &ptr);
        
        if (pos == 0) pop_first(); // if the data to remove is in the first node
        else if (ptr != nullptr && pos == size()-1) pop_last(); // if the data to remove is in the last node
        else if (ptr != nullptr && pos != -1) { // otherwise, and if the data exists in rhe dll
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            dll_size--;
            ptr = nullptr;
            delete ptr;
        }
    }
}

// Get the data from particular node by index from the dll then remove it: O(n)
template<class T>
T dll<T>::pop_at(int index){
    assert(index >= 0 && index < size());
    if (!is_empty()) {
        if (index == 0) return pop_first(); // if the node to remove is at position is zero, remove the first node of the dll
        else if (index == size()-1 ) return pop_last(); // if the node to remove is at the last, remove the last of the dll
        else { // otherwise
            // Seek the node that exists in that index

            Node *trav = nullptr;
            access_by_index(index, &trav);

            T data = trav->data;

            // setting the next’s pointer of the node right before trav to the node right after trav
            trav->prev->next = trav->next;

            // setting the previous’ pointer of the node right after trav  to the node right before trav
            trav->next->prev = trav->prev;

            dll_size--;

            // remove trav pointer from the memory
            trav = nullptr;
            delete trav;

            return data;
        }
    }
}
