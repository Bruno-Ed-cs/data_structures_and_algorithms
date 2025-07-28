#pragma once 

#include <cstddef>
#include <stdexcept>
#include <string>
#include <iostream>

    //todo guard all functions for a empty list
    //and make a iterator
    //test everything
    //

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

    LinkedList(const Type new_data) :
        m_root(new Node(new_data, nullptr)), m_len(1) {}

    void append(const Type&& new_data) {

        Node* new_node = new Node{new_data, nullptr};
        if (m_root == nullptr) {
            m_root = new_node;
            m_len++;
            return;
        }

        Node* cur_node = m_root;

        while(cur_node->next != nullptr) {

            cur_node = cur_node->next;

        }

        cur_node->next = new_node;
        m_len++;
        return;
    }

    void insert(const size_t index, const Type new_data) {

        Node* new_node = new Node{new_data, nullptr};

        if (index == 0) {
            new_node->next = m_root;
            m_root = new_node;
            return;
        } 

        Node* prev_node = LinkedList<Type>::get(index - 1);

        new_node->next = prev_node->next;
        prev_node->next = new_node;
        m_len++;
        return;

    }

    void remove(const size_t index){

        if (m_root == nullptr)
            throw std::out_of_range("Error: deletion on empty list");

        if (index == 0) {

            Node* first = m_root;
            m_root = m_root->next;
            m_len--;
            return;

        }
        
        Node* prev_node = get(index);

        delete prev_node->next;

        prev_node->next = nullptr;
        m_len--;
        return;

    }

    size_t len() {

        return m_len;

    }

    Type pop() {

        if (m_root == nullptr)
            throw std::out_of_range("Error: deletion on empty list");

        Node* cur_node = m_root; 
        Node* prev_node = m_root;

        while (cur_node != nullptr) {

            prev_node = cur_node;
            cur_node = cur_node->next;

            if (cur_node->next == nullptr)
                break;
        }

        prev_node->next = nullptr;
        
        Type data = cur_node->data;

        delete cur_node;
        m_len--;
        return data;
    }

    Type& operator[](const size_t index) {

        if (index >= m_len) 
            throw std::out_of_range("Error: the index " + std::to_string(index) + " is out of range for the list\n");

        Node* cur_node = m_root;

        for (size_t i = 0; i < index; ++i) {

            cur_node = cur_node->next;
        }

        return cur_node->data;
    }

    ~LinkedList() {

        Node* cur_node = m_root;
        Node* prev_node = m_root;

        while (cur_node != nullptr) {

            prev_node = cur_node;
            cur_node = cur_node->next;

            delete prev_node;
        }

        //std::cout << "List freed\n";

    }

    private:

    //Node& last() {

    //    Node* cur_node = m_root;

    //    while (cur_node->next != nullptr) {

    //        cur_node = cur_node->next;
    //    }

    //    return cur_node;
    //}


    Node& get(const size_t index) {

        if (index >= m_len) 
            throw std::out_of_range("Error: the index " + std::to_string(index) + " is out of range for the list\n");

        Node* cur_node = m_root;

        for (size_t i = 0; i < index; ++i) {

            cur_node = cur_node->next;
        }

        return cur_node;
    }


};


}
