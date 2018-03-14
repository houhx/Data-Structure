#pragma once
#include "../include.h"

template<typename T>
struct LNode{
	T data;
	LNode<T> *next;
	LNode(){ next = nullptr; };
	LNode(const T &d, LNode<T> *n = nullptr): data(d), next(n){};
};

template<class T>
class linklist{
public:	
	linklist();
	return_code insert(const int&, const T&);
	return_code insert(const T&, bool(*cmp)(const T&, const T&));
	return_code remove(const int&, T&);
	return_code retrieve(const int&, T&)const;
	void traver(void(*visit)(const T&));
	int size()const;
	bool empty()const;
	void clear();
private:	
	LNode<T> *head;
	int nowsize;
	LNode<T>* setposition(const int &position)const; 
};

template<class T>
inline linklist<T>::linklist(){
	head = nullptr;
	nowsize = 0;
}

template<class T>
LNode<T>* linklist<T>::setposition(const int &position)const{
	if(position == 0) return nullptr;
	
	LNode<T> *copy = head;
	int count = 1;
	while(count < position){
		copy = copy->next;
		count++;
    }
    return copy;
}

template<class T>
return_code linklist<T>::insert(const int &position, const T &item){
	LNode<T> *newnode = new LNode<T>(item);
	if(!newnode) return out_of_memory;
	
	if(position < 1 || position > nowsize+1) return Range_error;
	
	LNode<T> *before = setposition(position-1); //找出添加位置的前驱节点 
	if(before == nullptr){
		newnode->next = head;
		head = newnode;
	}
	else{
		newnode->next = before->next;
		before->next = newnode;
	}
	nowsize++;
	return successful;
}

template<class T>
return_code linklist<T>::insert(const T &item, bool(*cmp)(const T&, const T&)){
	LNode<T> *newnode = new LNode<T>(item);
	if(!newnode) return out_of_memory;
	
	if(head == nullptr){
		head = newnode;
	}
	else{
		LNode<T> *after = head, *before = nullptr;
		while( after && cmp(item, after->data) ){
			before = after;
			after = after->next;
		}
		
		if(before == nullptr){
			newnode->next = head;
			head = newnode;
		}
		else{
			newnode->next = before->next;
		    before->next = newnode;
		}
	}
	nowsize++;
	return successful;
}

template<class T>
return_code linklist<T>::remove(const int &position, T &save){
	if(position < 1 || position > nowsize) return Range_error;
	
	LNode<T> *before = setposition(position-1); //找出删除位置的前驱节点
	if(before == nullptr){ //删除第一个节点 
		before = head;
		save = head->data;
		head = head->next;
		delete before;
	}
	else{
		LNode<T> *delnode = before->next;
		save = delnode->data;
		before->next = delnode->next;
		delete delnode;
	}
	nowsize--;
	return successful; 
}

template<class T>
return_code linklist<T>::retrieve(const int &position, T &save)const{
	if(position < 1 || position > nowsize) return Range_error;
	
	LNode<T> *targetnode = setposition(position);
	save = targetnode->data;
	return successful;
}

template<class T>
void linklist<T>::traver(void(*visit)(const T&)){
	LNode<T> *travernode = head;
	while(travernode){
		visit(travernode->data);
		travernode = travernode->next;
	}
}

template<class T>
inline int linklist<T>::size()const{
	return nowsize;
}

template<class T>
inline bool linklist<T>::empty()const{
	return nowsize == 0;
}

template<class T>
void linklist<T>::clear(){
	LNode<T> *destroynode;
	while(head){
		destroynode = head;
		head = head->next;
		delete destroynode;
	}
	nowsize = 0;
}

