#ifndef HW04_LIST_H
#define HW04_LIST_H

#include <cstdio>
#include <cassert>
#include <iostream>
#include "Exceptions.h"


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

template <class T, class Compare, class Predicate>
class List{
    Node *first;
    //Node *last;

    int num_of_elements;
    Iterator<T> iterator;


    public:
        class Iterator<T> {
        private:
            Node *node;
        public:
            friend class List;
            /**
             *
             */
            void Iterator::operator--() {
                if(this->node == 0){
                    throw std::runtime_error("Element not found");
                }
                this->node = this->node->getNext();
            }

            /**
             *
             */
            void Iterator::operator++() {
                this->node = this->node->getPrevious();
            }

            Node* Iterator::operator*() const {
                if(this->node == 0){
                    throw std::runtime_error("Element not found");
                }
                return node;
            }
        }
        /**
         *
         */
        Iterator<T> begin(){
             while(node != first){
               Iterator.node--;
             }
            return iterator;
        }
        /**
       *
       * @return
       */
        Iterator<T> end()
        {
            Iterator iterator1 = List->last;
            while(iterator.node->getNext()){
                Iterator.node++;
            }
            return ;
        }
        void insert(const T& data, Iterator<T>iterator);
        void insert(const T& data);
        void remove(Iterator iterator)
        {
            Node *tempNode;
            if(this->num_of_elements == 0) throw mtm::ListExceptions::ElementNotFound();
            iterator.node->getNext()->setPrevious(iterator.node->getPrevious());
            iterator.node->getPrevious()->setNext(iterator.node->getNext());

            delete iterator;
        }
        Iterator<T> find(const Predicate& predicate);

        void sort(const Compare& compare)
        {

        }

        const int& getSize() const { return this->num_of_elements; }

        List(void){ first = NULL; }
        void print();
    };

#endif //HW04_LIST_H
