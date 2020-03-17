/**
* Author: Zion Klinger
* Date: 2020-03-09
* Description: A template node class used in a doubly linked list. Able to accept any type in the data field
*/
#ifndef DNODE_H
#define DNODE_H
template<class T>
class dnode{
    private:
        T data_field;
        dnode * next_field;
        dnode * prev_field;
    public:
        dnode(T newData, dnode* newPrevious = NULL, dnode* newNext = NULL);

        const T& data() const{
            return data_field;
        }

        void setData(T newData){
            data_field = newData;
        }

        dnode* next() const{
            return next_field;
        }

        dnode* previous() const{
            return prev_field;
        }

        void setNext(dnode* newNext){
            next_field = newNext;
        }

        void setPrevious(dnode* newPrevious){
            prev_field = newPrevious;
        }

};

template<class T>
dnode<T>::dnode(T newData, dnode* newPrevious, dnode* newNext){
    data_field = newData;
    next_field = newNext;
    prev_field = newPrevious;
}

template<class T>
class node_iterator : public std::iterator<std::forward_iterator_tag, T>{
    public:
    node_iterator(dnode<T>* initial = NULL){
        current = initial;
    }

    const T& operator *()const{
        return current->data();
    }

    node_iterator& operator ++(){
        current = current->next();
        return *this;
    }

    node_iterator operator ++(int){
        node_iterator original(current);
        current = current->next();
        return original;
    }

    node_iterator& operator --(){
        current = current->previous();
        return *this;
    }

    node_iterator operator --(int){
        node_iterator original(current);
        current = current->previous();
        return original;
    }

    bool operator ==(node_iterator other){
        return(current == other.current);
    }

    bool operator !=(node_iterator other){
        return(current != other.current);
    }
    void insert_before(T item);

    void insert_after(T item);

    void remove();
    
    private:
    dnode<T> *current;
};

template<class T>
void node_iterator<T>::insert_before(T item){
    dnode<T>* temp;
    temp = new dnode<T>(item, current->previous(), current);
    current->previous()->setNext(temp);
    current->setPrevious(temp);
}
template<class T>
void node_iterator<T>::insert_after(T item) {
    dnode<T>* temp = new dnode<T>(item, current, current->next());
    current->next()->setPrevious(temp);
    current->setNext(temp);
}

template<class T>
void node_iterator<T>::remove() {
    current->previous()->setNext(current->next());
    current->next()->setPrevious(current->previous());
    delete current;
}
#endif