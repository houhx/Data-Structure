#pragma once
#include "../include.h"

template<typename T>
struct LNode{
	T data;
	LNode<T> *next;
	LNode(): data(), next(nullptr){};
	LNode(const T &d, LNode<T> *n = nullptr): data(d), next(n){};
};

template<class T>
class linklist{
public:
	linklist();
	~linklist();
	linklist(const linklist<T>&);
	linklist<T>& operator=(const linklist<T>&);

	return_code insert(const int&, const T&);
	return_code insert(const T&, bool(*cmp)(const T&, const T&));
	return_code remove(const int&, T&);
	return_code retrieve(const int&, T&)const;
	void traver(void(*visit)(const T&));
	void ascendingsort();
	void descendingsort();

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
inline linklist<T>::~linklist(){
	while(head){
		delete head;
		head = head->next;
	}
}

template<class T>
linklist<T>::linklist(const linklist<T> &ll){
	nowsize = ll.size();
	LNode<T> *newlist;
	T temp;
	for(int i=0; i<nowsize; i++){
		ll.retrieve(i, temp);

		LNode<T> *newnode = new LNode<T>(temp);
		if(!newnode) cout << "overflow" << endl;

		if(i == 0 ) head = newlist = newnode;
		else{
			newlist->next = newnode;
			newlist = newlist->next;
		}
	}
}

template<class T>
linklist<T>& linklist<T>::operator=(const linklist<T> &ll){
	LNode<T> *todelete = head;

	nowsize = ll.size();

	if(nowsize == 0) head = nullptr;
	else{
		LNode<T> *copy, *newnode;
		T temp;
		for(int i=0; i<nowsize; i++){
			ll.retrieve(i, temp);

			newnode = new LNode<T>(temp);
			if(!newnode) cout << "overflow!" << endl;

			if(i == 0) head = copy = newnode;
			else{
				copy->next = newnode;
				copy = copy->next;
			}
		}
	}

	while(todelete){
		delete todelete;
		todelete = todelete->next;
	}
}

template<class T>
LNode<T>* linklist<T>::setposition(const int &position)const{
	//if(position == 0) return nullptr;
	
	LNode<T> *copy = head;
	int count = 0;
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
	
	if(position < 0 || position > nowsize) return Range_error;
	
	if(position == 0){
		newnode->next = head;
		head = newnode;
	}
	else{
		LNode<T> *before = setposition(position-1); //找出添加位置的前驱节点
		newnode->next = before->next;
		before->next = newnode;
	}
	nowsize++;
	return successful;
}

template<class T>
return_code linklist<T>::insert(const T &item, bool(*cmp)(const T&, const T&)){
	int i=0;
	while(i < nowsize && !cmp(item, setposition(i)->data)) i++;

	return insert(i, item);
}

template<class T>
return_code linklist<T>::remove(const int &position, T &save){
	if(position < 0 || position > nowsize-1) return Range_error;
	
	LNode<T> *todelete;
	if(position == 0){
		save = head->data;
		todelete = head;
		head = head->next;
	}
	else{
		LNode<T> *before = setposition(position-1); //找出删除位置的前驱节点
		todelete = before->next;
		save = todelete->data;
		before->next = todelete->next;
	}
	delete todelete;
	nowsize--;
	return successful; 
}

template<class T>
return_code linklist<T>::retrieve(const int &position, T &save)const{
	if(position < 0 || position > nowsize-1) return Range_error;
	
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

template<class T>
void linklist<T>::ascendingsort(){
	for(int i=1; i<nowsize; i++){
		LNode<T> *move = setposition(i);
		int j=i-1, temp = move->data;
		while(j>=0 && setposition(j)->data > temp) j--;

		if(j+1 == i) continue;

		LNode<T> *rowbefore = setposition(i-1), *nowbefore;
		rowbefore->next = move->next;
		if(j == -1){
			move->next = head;
			head = move;
		}
		else{
			nowbefore = setposition(j);
			move->next = nowbefore->next;
			nowbefore->next = move; 
		}
	}
}

template<class T>
void linklist<T>::descendingsort(){
	for(int i=1; i<nowsize; i++){
		LNode<T> *move = setposition(i);
		int j = i-1, temp = move->data;
		while(j>=0 && temp > setposition(j)->data ) j--;

		if(j+1 == i) continue;

		LNode<T> *rowbefore = setposition(i-1), *nowbefore;
		rowbefore->next = move->next;
		if(j == -1){
			move->next = head;
			head = move;
		}
		else{
			nowbefore = setposition(j);
			move->next  = nowbefore->next;
			nowbefore->next = move;
		}
	}
}
