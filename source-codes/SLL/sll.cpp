#include "sll.h"

// Return the size of the sll: O(1)
template <class T>
int sll<T>::size() {
    return sll_size;
}

// Check is the sll is empty or not: O(1)
template<class T>
bool sll<T>::is_empty(){
    return size() == 0;
}

// Display the sll: O(n)
template <class T>
void sll<T>::display() {
    Node *trav = head;
    while(trav != nullptr) {
        std::cout << trav->data << " ";
        trav = trav->next;
    }
    std::cout << '\n';
}

// Clear the sll: O(n)
template <class T>
void sll<T>::clear() {
    Node *trav = head;
    while (trav != nullptr) {
        Node *next = trav->next;
        trav->next = nullptr;
        delete trav->next;
        trav = next; 
    }
    head = tail = nullptr;
    delete head;
    delete tail;
    delete trav;

    sll_size = 0;
}

// Check if a node holding a giving data exists or not: O(n)
template <class T>
bool sll<T>::contains(T data) {
    Node *ptr = nullptr;
    int index = -1;
    index_of(data, index, &ptr);
    return ptr != nullptr;
}

// Access to a node by its index, it returns a pointer to that node: O(n)
template <class T>
void sll<T>::access_by_index(int index, Node **ptr){
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

// Search a node by data, if exists return the position and a pointer to that node: O(n)
template <class T>
void sll<T>::index_of(T data, int &index, Node **ptr) {
    if (!is_empty()) {
        *ptr = head;
        index = 0;
        while ((*ptr) != nullptr && (*ptr)->data != data){
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

// Add a node at the beginning of the sll, that hold a giving data: O(1)
template <class T>
void sll<T>::add_front(T data) {
    if (is_empty()) head = tail = new Node(data, nullptr);
    else head = new Node(data, head);
    
    sll_size++;
}

// Add a node at the end of the sll, that hold a giving data: O(1)
template <class T>
void sll<T>::add_back(T data) {
    if (is_empty()) head = tail = new Node(data, nullptr);
    else {
        Node *new_node = new Node(data, nullptr);
        tail->next = new_node;
        tail = new_node;
    }

    sll_size++;
}


// Add a node at a giving position of the sll, that hold a giving data: O(n)
template <class T>
void sll<T>::add_at(T data, int index){
    assert( index >= 0 && index <= size());
    if (!is_empty()) {
        if (index == 0) add_front(data);
        else if (index == size()) add_back(data);
        else {
            Node *trav;
            access_by_index(index-1, &trav);
            trav->next = new Node(data, trav->next);
            sll_size++;
        }
    }
    else {
        head = tail = new Node(data, nullptr);
        sll_size++;
    }
}

// Returns the data of the first node: O(1)
template <class T>
T sll<T>::peak_first() {
    if (!is_empty()) return head->data;
    else return T();
}

// Returns the data of the last node: O(1)
template <class T>
T sll<T>::peak_last() {
    if (!is_empty()) return tail->data;
    else return T();
}

// Returns the data of the a node at a giving index: O(n)
template <class T>
T sll<T>::peak_at(int index){
    assert(index >= 0 && index < size());
    
    if (index == 0) return peak_first();
    else if (index == size()-1) return peak_last();
    else {
        Node *ptr;
        access_by_index(index, &ptr);
        return ptr->data;
    }
 
}

// Return the data of the first node, then remove it: O(1)
template <class T>
T sll<T>::pop_first() {
    assert(!is_empty());

    T data = head->data;
    if (head->next != nullptr) {
        Node *to_remove = head;
        head = head->next;
        to_remove->next = nullptr;
        to_remove = nullptr;
        delete to_remove;
    }
    else {
        head = tail = nullptr;
        delete head;
        delete tail;
    }
    sll_size--;
    
    return data;   
}

// Return the data of the last node, then remove it: O(n)
template <class T>
T sll<T>::pop_last(){
    assert(!is_empty());

    T data = tail->data;

    Node *trav = head;
    if (trav->next != nullptr) {
        while (trav->next != tail){
            trav = trav->next;
        }
        tail = trav;
        trav = trav->next;
        tail->next = nullptr;
        trav = nullptr;
        delete trav;
    }
    else {
        head = tail = nullptr;
        delete head;
        delete tail;
    }
    sll_size--;
    return data;
}

// Return the data of node if exists, then remove it: O(n)
template <class T>
T sll<T>::pop(T data){
    assert(!is_empty());
    
    if (head->next != nullptr) {
        Node *trav1 = head;
        Node *trav2 = head->next;
        while (trav1->data != data && trav2->data != data && trav2->next != nullptr) {
            trav1 = trav2;
            trav2 = trav2->next;
        }
        if (trav1 == head) return pop_first();
        else if (trav2 == tail && trav2->data == data) return pop_last();
        else if (trav2->next != nullptr) {
            Node *temp = trav2;
            trav2 = trav2->next;
            trav1->next = trav2;

            temp = nullptr;
            delete temp;
            sll_size--;
            return data;
        }
    }
    else {
        head = tail = nullptr;
        delete head;
        delete tail;
        sll_size--;
        return data;
    }

    return T();
}

template <class T>
// Return the data of a node by index, then remove it: O(n)
T sll<T>::pop_at(int index){
    std::cout << size();
    assert(index >= 0 && index < size());
    assert(!is_empty());

    Node *to_remove;
    access_by_index(index, &to_remove);
    if (to_remove == head) return pop_first();
    else if (to_remove == tail) return pop_last();
    else {
        T data = to_remove->data;
        Node *ptr;
        access_by_index(index - 1, &ptr);
        ptr->next = to_remove->next;
        to_remove->next = nullptr;
        delete to_remove;
        sll_size--;
        return data;
    }
}