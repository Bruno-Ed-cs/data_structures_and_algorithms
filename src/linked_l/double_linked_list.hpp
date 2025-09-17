#pragma once 

class DLinkedList {

private:
    struct Node {
        
        int value;
        Node* next;
        Node* prev;
    };

    Node* m_root;
    Node* m_last;

public:

    DLinkedList() :
    m_root(nullptr), m_last(nullptr) {}

    DLinkedList(





};
