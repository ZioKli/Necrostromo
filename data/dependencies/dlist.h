
/**
 * Author: Zion Klinger
 * Date: 2020-03-17
 * Description: a custom doubly linked list that can take a arbitrary type. Edited from the code I developed for project 4 in CS2401.
 * 
 */
#include "dnode.h"
#include <iostream>

template<class T>
class dlist{
    private:
        dnode<T>* head;
        dnode<T>* tail;
        int node_count;
        /**
         * a reusable function that deletes the entire list and sets head and tail to be NULL
         * used in the destructor,
         * but also sees use in the assignment operator
         */
        void clear_list();

    public:
        typedef node_iterator<T> iterator;

        dlist(){
            head = NULL;
            tail = NULL;
            node_count = 0;
        }

        ~dlist(){
            clear_list();
        }
        /**
         * Copy constructor 
         */        
        dlist(const dlist<T>& other);

        /**
         * Assignment operator
        */
        dlist<T>& operator =(dlist<T> & other);

        /**
         * Returns an external iterator pointing towards the head node
         */
        iterator begin(){
            return iterator(head);
        }

        /**
         * returns an iterator that has run off the end of the list 
         */
        iterator end(){
            return iterator();
        }

        /**
         * returns an iterator pointing towards the tail node,
         * used for walking backwards through a list
         */
        iterator r_begin(){
            return iterator(tail);
        }

        /**
         * returns an iterator that has run off the end of the list
         */
        iterator r_end(){
            return iterator();
        }
        /**
         * outputs each item in the list from head to tail
         * each item is on a different line
         */
        void show() const;

        /**
         * goes through the list in reverse printing each item to the terminal, works identically to show
         * but starts at tail and iterates to cursor->previous() instead of cursor->next()
         */
        void reverse_show() const;

        /**
         * Adds a new item to the tail of the list
         * if there are no items in the list both head and tail are set to be the new item
         */
        void rear_insert(T item);

        /**
         * adds a new item to the head of list
         */
        void front_insert(T item);

        /**
         * removes the last item in the list or if there is only one element
         * we set both head and tail to NULL
         */
        void rear_remove();

        /**
         * removes the first element of the list
         * if there is only one element we delete it and set both head and tail to NULL
         */
        void front_remove();

        void insert_before(iterator& iter, T item);

        void insert_after(iterator& iter, T item);

        int size(){
            return node_count;
        }
        void remove(iterator& iter);
};

template<class T>
void dlist<T>::insert_before(iterator& iter, T item) {
    if(iter == begin() || iter == end()){
        front_insert(item);
    }
    else{
        node_count++;
        iter.insert_before(item);
    }
}

template<class T>
void dlist<T>::insert_after(iterator& iter, T item) {
    if(iter == end()|| iter == r_begin()){
        rear_insert(item);
    }
    else{
        node_count++;
        iter.insert_after(item);
    }
}

template<class T>
void dlist<T>::remove(iterator& iter) {
    if(head == tail || head == NULL){
        rear_remove();
    }
    else{
        iter.remove();
    }
}
#include "dlist.template"