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

template <class T, class Compare, class Predicate>
class List{
    Node *first;
    int num_of_elements;
    Iterator iterator;

    public:
        class Iterator {
        private:
            Node* node;
        public:
            friend class List;

            /**
             *
             */
            void Iterator::operator--() {
                if(this->node->getPrevious()){
                    throw std::runtime_error("Element not found");
                }
                this->node = this->node->getPrevious();
            }

            /**
             *
             */
            void Iterator::operator++() {
                this->node = this->node->getNext();
            }

            /**
             *
             * @return
             */
            Node* Iterator::operator*() {
                if(this->node == 0){
                    throw std::runtime_error("Element not found");
                }
                return iterator.node;
            }
        };
        /**
         *
         */
        Iterator begin(){
             iterator.node = first;
            return iterator;
        }

        /**
       *
       * @return
       */
        Iterator end()
        {
            while(iterator.node->getNext()){
                iterator.node++;
            }
            return iterator;
        }

        /**
         *
         * @param data
         * @param iterator
         */
        void insert(const T& data, Iterator iterator)
        {
            Node(data, iterator.node->getPrevious(), iterator.node->getNext());
            num_of_elements++;
        }

        /**
         *
         * @param data
         */
        void insert(const T& data)
        {
            Iterator tempI;
            tempI.node = this->first;
            while (tempI.node->getNext()){
                tempI.node++;
            }
            insert(data, tempI);
            num_of_elements++;
            return;
        }

        /**
         *
         * @param iterator
         */
        void remove(Iterator iterator)
        {
            iterator.node->getPrevious()->setNext(iterator.node->getNext());
            iterator.node->getNext()->setPrevious(iterator.node->getPrevious());
            num_of_elements--;
            delete *iterator.node;
        }

        /**
         *
         * @param predicate
         * @return
         */
        Iterator find(const Predicate& predicate)
        {
            iterator.node = first;
            while (!predicate(iterator.node->getData())){
                if(iterator.node->getNext()) {
                    iterator.node++;
                } else break;
            }
            return iterator;
        }

        /**
         *
         * @param compare
         */
        void sort(const Compare& compare)
        {
            int tempsize = num_of_elements;
            iterator.node = first;
            for(int i = 0 , i < tempsize, i++){
                if(compare(iterator.node->getData() , iterator.node->getNext()->getData())){
                    swapNodes(iterator.node, iterator.node->getNext());
                }
                iterator++;

            }
        }

        /**
         *
         */
        void swapNodes(Node& const node1, Node& const node2){
            Node tempNode;
            tempNode.setData(node1.getData());
            node1.setData(node2.getData());
            node2.setData(tempNode.getData());
        }

        /**
         *
         * @return
         */
        int getSize()
        {

        }


    };

#endif //HW04_LIST_H
