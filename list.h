#ifndef HW04_LIST_H
#define HW04_LIST_H

#include <cstdio>
#include <cassert>


template <class T, class compare>
class Node {
    Node* next;
    Node* previous;
    T *data;
public:
    // no paramteres constructor
    Node() : next(NULL), previous(NULL), T(NULL) {};

    Node(const T& data, Node *next, Node *previous) : next(next), previous(previous), data(new T(data))
    {
        if(previous) previous->next = this;
        if(next) next->previous = this;
    }

    const T& getData() const
    {
        assert(this->data != NULL);
        return *this->data;
    }

    Node* getNext() const
    {
        return this->next;
    }

    Node* getPrevious() const
    {
        return this->previous;
    }

    void setNext(Node* node)
    {
        this->next = node;
        if(node) node->previous = this;
    }

    void setPrevious(Node* node)
    {
        this->previous = node;
        if(node) node->next = this;
    }

    void setData(const T& data)
    {
        this->data = new T(data);
    }




};

template <class T>
class List{

};



#endif //HW04_LIST_H
