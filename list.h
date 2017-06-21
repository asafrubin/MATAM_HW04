#ifndef HW04_LIST_H
#define HW04_LIST_H

#include <cstdio>
#include <cassert>
#include <iostream>


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

typedef class T T;
template <class T, class Compare, class Predicate>
class List{

};

class List{
    Node *first;
    //Node *last;
    int num_of_elements;
    Iterator<T> iterator;

    public:
        class Iterator<T> {
        private:
            Node<T>* iterator;
        public:
            friend class List;
            /**
             *
             */
            void Iterator::operator--() const {
                if(this->iterator == 0){
                    throw std::runtime_error("Element not found");
                }
                this->iterator == this->iterator->getNext();
            }
            /**
             *
             */
            void Iterator::operator++() const {
                //this->iterator++;
                this->iterator == this->iterator->getPrevious();
            }

            Node* Iterator::operator*() const {
                if(this->iterator == 0){
                    throw std::runtime_error("Element not found");
                }
                return iterator;
            }
        }
        /**
         *
         */
        Iterator<T> begin(){
             while(*iterator != first){
               Iterator.iterator--;
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
            while(iterator.iterator->getNext()){
                Iterator.iterator++;
            }
            return ;
        }
        void insert(const T& data, Iterator<T>iterator);
        void insert(const T& data);
        void remove(Iterator<T>iterator);
        Iterator<T> find(const Predicate& predicate);
        void sort(const Compare& compare);
        int getSize();

        List(void){ first = NULL; }
        void print();
    };

#endif //HW04_LIST_H
