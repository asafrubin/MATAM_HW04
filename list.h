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
    /**
	* This is the The Node default constructor, initiates all the data,next
	* Node and previous Node to NULL
	*/
    Node() : next(NULL), previous(NULL), T(NULL) {};

    /**
    *The Nodes non-default constructor. initiates the Nodes next and previous
    Nodes, and allocates memory for the Node's data.
    *@Input:
    *  data-
    *      The Nodes data, will be hold in a new allocated Memory space.
    *  next-
    *      a pointer to the new Node's next Node.
    *  previous-
    *      a pointer to the new Node's previous Node.
    *@ATTENTION:
    *  The constructor will change the given next Node's previous Node to be
    *      the new Node.
    *  The constructor will change the given previous Node's next Node to be
    *      the new Node.
    *  The constructor uses the data's copy constructor to copy a new data.
    */
    Node(const T& data, Node *next, Node *previous) : next(next), previous(previous), data(new T(data))
    {
        try{
            this->data= new T(data);
        }catch(std::exception& e){
            throw std::bad_alloc();
        }
        if(previous) previous->next = this;
        if(next) next->previous = this;
    }

    /**
	*The Node copy constructor, receives a Node and creates a new copied
	*Node initialized with the sent Node's parameters.
	*@ATTENTION:
	*  The new Node's data will be allocated, and will use the template T
	*  copy constructor.
	**/
    Node(const Node& node) : next(node.next), previous(node.previous), data(new T(node.data)) {}

    /**
	*The Node default destructor. deletes the memory allocated for the Node,
	*and the Node's data memory.
	*@ATTENTION:
	*  The destructors changes the Node's previous's Node's Next Node to be the
	*  Node's next Node. (and the opposite), for example:
	*                                          Node1 <-> Node2 <-> Node3
	*                                          ~Node2
	*                                          Node1 <-> Node3
	*/
    ~Node()
    {
        if (next) this->next->setPrevious(this->previous);
        if (previous) this->previous->setNext(this->next);
        if (data) delete data;
    }

    /**
	*The assumption operator will copy the received Nodes parameters and will
	* copy them into the calling Nodes's.
	*@ATTENTION:
	*  The calling Node's data will be deleted, and the sent Node's data will
	*  be memory allocated and copied with the template's copy constructor.
	**/
    Node& operator=(const Node& node) {
        T *temp = new T(*(node.data));
        delete this->data;
        this->next = node.next;
        this->previous = node.previous;
        this->data = temp;
        return *this;
    }

    /**
	*This function will return the Node's data.
	*@ATTENTION:
	*  This function asserts the Node's data!=NULL
	**/
    T& getData()
    {
        assert(this->data != NULL);
        return *this->data;
    }

    /**
	*This function will return an address to the Node's next Node.
	*@ATTENTION:
	*  If the calling Node doesnt have a next Node, the function will return
	*   NULL.
	**/
    Node* getNext() const
    {
        return this->next;
    }

    /**
	*This function will return an address to the Node's previous Node.
	*@ATTENTION:
	*  If the calling Node doesnt have a previous Node, the function will return
	*   NULL.
	**/
    Node* getPrevious() const
    {
        return this->previous;
    }

    /**
	*This function receives an address to a Node and sets The calling Node's
	* next Node to be the received Node.
	*@ATTENTION:
	*  Thid function sets the received Node's previous Node to be the calling
	*  Node.
	**/
    void setNext(Node* node)
    {
        this->next = node;
        if(node) node->previous = this;
    }

    /**
	*This function receives an address to a Node and sets The calling Node's
	* previous Node to be the received Node.
	*@ATTENTION:
	*  Thid function sets the received Node's next Node to be the calling
	*  Node.
	**/
    void setPrevious(Node* node)
    {
        this->previous = node;
        if(node) node->next = this;
    }

    /**
	*This function receives an data and allocates The calling Node's data's
	*address and uses the template's copy constructor to copy the received data.
	*@ATTENTION:
	*  This function DOES NOT deletes the Node's old data address.
	**/
    void setData(const T& data)
    {
        if(this->data) delete this->data;
        this->data = new T(data);
    }

};


template <class T, class Compare = std::less<T>>
class List{
public:
    class Iterator{
        private:
            Node<T>* node;
        public:
            friend class List<T>;

            Iterator() : node(NULL) {};

            Iterator operator--() {
                if(this->node->getPrevious()){
                    throw std::runtime_error("Element not found");
                }
                this->node = this->node->getPrevious();
                return *this;
            }

            Iterator operator--(int){
            Iterator tempI = *this;
            this->node = this->node->getPrevious();
            return tempI;
        }

            Iterator operator++(){
                this->node = this->node->getNext();
                return *this;
            }

            Iterator operator++(int){
                Iterator tempI = *this;
                this->node = this->node->getNext();
                return tempI;
            }

            T& operator*() {
                if(this->node == 0){
                    throw std::runtime_error("Element not found");
                }
                return this->node->getData();
            }

            bool operator==(const Iterator& i) const {
                //assert(set == i.list);
                if(this->node->getPrevious()->getNext() == i.node->getPrevious()->getNext()){
                    return true;
                }
                return false;
            }

            bool operator!=(const Iterator& iterator2) const{
                return (this->node->getNext()->getData() != iterator2.node->getNext()->getData());
            }
    };

private:
    Node<T> *first;
    Iterator iterator;
    int num_of_elements;
public:
/*
    Node dummy;
    first = &dummy;
    dummy.setNext(NULL);
    dummy.setData(NULL);
    num_of_elements = 0;
*/

        List() : first(NULL), num_of_elements(0){};

        List(List<T>& list2)
        {
            begin();
            list2.begin();
            while(iterator.node->getData()){
                this->iterator.node->setData(list2.iterator.node->getData());
                this->iterator++;
                list2.iterator++;
            }
        }

        /**
        *This function will return an iterator pointing at the first element (Node)
        * of the set.
        *@ATTENTION:
        *  Incase of empty set, the function will return an iterator pointed at the
        *  end of the set
        **/
        Iterator begin(){
             iterator.node = first;
            return iterator;
        }

        /**
        *This function will return an iterator pointing at end of the set.
        *@ATTENTION:
        *  the end of the set is DOES NOT have a data.
        **/
        Iterator end()
        {
            if(first == NULL)
                return this->iterator;
            Iterator tempI;
            tempI.node = (first);
            while(tempI.node->getNext()){
                tempI.node++;
            }
            return tempI;
        }


        void insert(const T& data, Iterator iterator)
        {
            if(first == NULL){
                first = new Node<T>(data, NULL, NULL) ;
                num_of_elements++;
                return;
            }
            if(first == iterator.node){
                first = new Node<T>(data, iterator.node, iterator.node->getPrevious());
            }
            else Node<T>(data, iterator.node, iterator.node->getPrevious());
            num_of_elements++;
        }


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
        *This function receives a template data and and removes it from the
        *SortedSet.
        *@Input:
        *  data- the data to remove from the set.
        *@Output:
        *  false incase the data wasnt found in the set. (compared with the compare
        *   function in the template.
        *  true incase the data found, and was removed.
        *@ATTENTION:
        *  The function will delete the memory allocated for the data.
        **/
        void remove(Iterator iterator)
        {
            iterator.node->getPrevious()->setNext(iterator.node->getNext());
            iterator.node->getNext()->setPrevious(iterator.node->getPrevious());
            num_of_elements--;
            delete iterator.node;
        }


        template <class Predicate>
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


        void sort(const Compare& compare)
        {
            int tempsize = num_of_elements;
            begin();
            for(int i = 0; i < tempsize; i++){
                if(compare(iterator.node->getData() , iterator.node->getNext()->getData())){
                    Iterator tempIt = iterator++;
                    swapData(iterator, tempIt);
                }
                else iterator++;

            }
        }

        void swapData(Iterator& iterator1 , Iterator& iterator2)
        {
            T tempData;
            tempData = (iterator1.node->getData());
            iterator1.node->setData(iterator2.node->getData());
            iterator2.node->setData(tempData);
        }

        /**
        *This function will return the size of the calling list, i.e- the number
        *of elements in the set.
        **/
        int getSize()
        {
            return num_of_elements;
        }

        bool operator==(const List<T>& list3)
        {
            List<T> list2;
            list2 = list3;
            while (this->iterator.node->getNext() && list2.iterator.node->getNext()){
                if(this->iterator != list2.iterator){
                    return false;
                }
                this->iterator++;
                list2.iterator++;
            }
            if (this->iterator.node->getNext() && list2.iterator.node->getNext()){

            }
            return true;
        }

        bool operator==(const Node<T>& iterator2 )const
        {
            return (Compare(this->iterator.node->getData(), iterator2.getData()));
        }

        bool operator==(const T& data )const
        {
            return (this->iterator.node->getData() == data);
        }

        bool operator!=(const List<T>& list3 )
        {
            List<T> list2;
            list2 = list3;
            while (this->iterator.node->getNext() && list2.iterator.node->getNext()){
                if(this->iterator != list2.iterator){
                    return true;
                }
                this->iterator++;
                list2.iterator++;
            }
            if (this->iterator.node->getNext() && list2.iterator.node->getNext()){

            }
            return false;
        }

        bool operator!=(const Node<T>& iteraotr2 )const
        {
            return !(this->iterator.node->getData() == iteraotr2.getData());
        }

        bool operator!=(const T& data )const
        {
            return !(this->iterator.node->getData() == data);
        }


    };


#endif //HW04_LIST_H
