/*
	name: Jenny Haggerty and Noah Wilmore
	
	date: 11/1
	
	goal:implement an ADT that requires elements of two very different ADTs
	
*/

#if !defined (HYBRID_H)
#define HYBRID_H

#include "QueueLinked.h"
using CSC2110::QueueLinked;
#include "SortedListDoublyLinked.h"
#include <iostream>

template < class T >
class Hybrid
{

private:
    // Easy Implementation
    QueueLinked<T>* q;
	SortedListDoublyLinked<T>* sldl;
    // Complex Implementation
    /*QueueLinked < DoubleNode<T> >* q;
    SortedListDoublyLinked<T>* sldl;*/

public:
    
	//constructor
	Hybrid(int (*comp_items) (T* item_1, T* item_2), int (*comp_keys) (String* key, T* item));
	//deconstrutor
    ~Hybrid();

    //tells if the hybrid is empty
	bool isEmpty();
	//takes a T item and enqueue it
    void enqueue(T* item);
	//removes T item
    T* dequeue();
	//iterator for the list
    ListDoublyLinkedIterator<T>* iterator();

};

template < class T >
Hybrid<T>::Hybrid(int (*comp_items) (T* item_1, T* item_2), int (*comp_keys) (String* key, T* item))
{
    // Easy Implementation
    q = new QueueLinked<T>();
	sldl = new SortedListDoublyLinked<T>(comp_items, comp_keys);
    //Complex Implementation
    /*q = new QueueLinked<DoubleNode<T> >();
    sldl = new SortedListDoublyLinked<T>(comp_items, comp_keys);*/
}

template < class T >
Hybrid<T>::~Hybrid()
{
    delete q;
    delete sldl;
}

//DO THIS
//complete the implementation for the Hybrid ADT in two different ways
//as outlined in the Lab 10 description
//simply comment the first implementation out when working on the second implementation
//use the getKey method to dequeue/remove

template < class T>
T* Hybrid<T>::dequeue()
{
    // Check for empty
    if (isEmpty()){
        return NULL;
    }
   
    // Complex Implementation
    /*DoubleNode<T>* node = q->dequeue();
    T* item = node->getItem();
    sldl->remove(node);
    return item;*/
    
    // Easy Implementation
    T* data = q->dequeue();
    sldl->remove (data->getKey());
    return data;  
}
template < class T>
void Hybrid<T>::enqueue(T* item)
{

    // Complex Implementation
    /*DoubleNode<T>* node = sldl->addDN(item);
    q->enqueue(node);*/
    
    // Easy Implementation
    q->enqueue(item);
    sldl->add(item);
}

template < class T>
bool Hybrid<T>::isEmpty()
{
    return q->isEmpty();  
}
template < class T>
ListDoublyLinkedIterator<T>* Hybrid<T>::iterator()
{
    return sldl->iterator();
}
 
#endif
