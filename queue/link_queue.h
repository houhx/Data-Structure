#pragma once
#include "../include.h"

template<class T>
struct qNode{
	T data;
	qNode<T> *next;
	qNode(): data(), next(nullptr){};
	qNode(const T &d, qNode<T> *n = nullptr):data(d), next(n){};
};

template<class T>
class linkqueue{
public:	
	linkqueue();
	linkqueue(const linkqueue<T>&);
	linkqueue<T>& operator=(const linkqueue<T>&);
	~linkqueue();

	return_code push(const T &item);
	return_code pop(T &save);
	return_code front(T &save)const;
	return_code back(T &save)const;
	void traver(void(*visit)(const T&))const;

	void clear();
	bool empty()const;
	int size()const;
private:	
	qNode<T> *head, *tail;
	int len;
};

template<class T>
inline linkqueue<T>::linkqueue(): head(nullptr), tail(nullptr), len(0){}

template<typename T>
linkqueue<T>::~linkqueue(){
	clear();
}

template<typename T>
linkqueue<T>::linkqueue(const linkqueue<T> &lq){
	len = lq.size();
	if(len == 0){
		head = tail = nullptr;
	}
	else{
		qNode<T> *pre;
		head = tail = new qNode<T>();
		lq.traver([&](const T &q)->void{
			tail->next = new qNode<T>(q);
			pre = tail;
			tail = tail->next;
		});
		head = head->next;
		tail = pre;
	}
}

template<typename T>
linkqueue<T>& linkqueue<T>::operator=(const linkqueue<T> &lq){
	len = lq.size();
	
	if(len == 0){
		if(head) this->clear();
	} 
	else{
		qNode<T> *todelete = head;
		qNode<T> *pre;
		head = tail = new qNode<T>();
		lq.traver([&](const T &q)->void{
			tail->next = new qNode<T>(q);
			pre = tail;
			tail = tail->next;
		});
		head = head->next;
		tail = pre;

		while(todelete){
			pre = todelete;
			todelete = todelete->next;
			delete pre;
		}
	}
}

template<class T>
return_code linkqueue<T>::push(const T &item){
	qNode<T> *newnode = new qNode<T>(item);
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
	qNode<T> *first = head;
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
	qNode<T> *todelete;
	tail = nullptr;
	while(head){
		todelete = head;
		head = head->next;
		delete todelete;
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
void linkqueue<T>::traver(void(*visit)(const T&))const{
	qNode<T>* pass = head;
	while(pass){
		visit(pass->data);
		pass = pass->next;
	}
}
