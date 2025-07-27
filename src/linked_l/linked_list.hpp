#pragma once 

#include <cstddef>

namespace ds {

template <typename Type>
class LinkedList {

    struct Node {
        Type data;
        Node* next;
    };
    Node* m_root;
    size_t m_len;

public:
    LinkedList() :
        m_root(nullptr), m_len(0) {}

    LinkedList(Type new_data) :
        m_root(new Node(new_data, nullptr)), m_len(1) {}

    void append(Type& new_data);
    void insert(size_t index);
    Type remove(size_t index);

    Type& operator[](size_t index);

    ~LinkedList();

private:
        

};


}
