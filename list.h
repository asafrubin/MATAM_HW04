#ifndef HW04_LIST_H
#define HW04_LIST_H

#include <cstdio>
#include <cassert>


template <class T>
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

    //copy constructor
    Node(const Node& node)
    {
        data(new T(node.data));
        previous = node.previous;
        next = node.next;
    }

    //destructor
    ~Node()
    {
        delete data;
    }
    //returns the data of and object
    const T& getData() const
    {
        assert(this->data != NULL);
        return *this->data;
    }
    //returns a pointer to the next node
    Node* getNext() const
    {
        return this->next;
    }

    //returns a pointer to the previous node
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
        if(this->data) delete this->data;
        this->data = new T(data);
    }










};

template <class T>
class List{

};



#endif //HW04_LIST_H
