#pragma once
#include "../include.h"

template<class T>
struct Node{
	T data;
	Node<T> *next;
	Node(){ next = nullptr; };
	Node(const T &d, Node<T> *n = nullptr):data(d), next(n){};
};

template<class T>
class linkqueue{
public:	
	linkqueue();
	return_code push(const T &item);
	return_code pop(T &save);
	return_code front(T &save)const;
	return_code back(T &save)const;
	void clear();
	bool empty()const;
	int size()const;
	void traver(void(*visit)(const T&));
private:	
	Node<T> *head, *tail;
	int len;
};

template<class T>
inline linkqueue<T>::linkqueue(){
	head = tail = nullptr;
	len = 0;  
}

template<class T>
return_code linkqueue<T>::push(const T &item){
	Node<T> *newnode = new Node<T>(item);
	if(!newnode) return out_of_memory;
	
	if(tail != nullptr){
		tail->next = newnode;
		tail = newnode;
	}
	else head = tail = newnode;
	
	len++;
	
	return successful;
}

template<class T>
return_code linkqueue<T>::pop(T &save){
	if(tail == nullptr) return underflow;
	
	save = head->data;
	Node<T> *first = head;
	head = head->next;
	delete first;
	if(head == nullptr) tail = head;
	len--;
	return successful;
}

template<class T>
return_code linkqueue<T>::front(T &save)const{
	if(tail == nullptr) return underflow;
	
	save = head->data;
	return successful;  
}

template<class T>
return_code linkqueue<T>::back(T &save)const{
	if(tail == nullptr) return underflow;
	
	save = tail->data;
	
	return successful;
}

template<class T>
void linkqueue<T>::clear(){
	Node<T>* copy;
	tail = nullptr;
	while(head){
		copy = head;
		head = head->next;
		delete copy;
	}
	len = 0;
}

template<class T>
inline bool linkqueue<T>::empty()const{
	return len == 0;
}

template<class T>
inline int linkqueue<T>::size()const{
	return len;
}

template<class T>
void linkqueue<T>::traver(void(*visit)(const T&)){
	Node<T>* copy = head;
	while(copy){
		visit(copy->data);
		copy = copy->next;
	}
}
