#pragma once
#include "../include.h"

template<typename T>
struct sNode{
	T data;
	sNode<T> *next;
	sNode(): data(), next(nullptr){};
	sNode(const T &d, sNode *n = nullptr):data(d), next(n){}; 
};

template<typename T>
class linkstack{
public:	
	linkstack();
	linkstack(const linkstack<T> &);
	linkstack<T>& operator=(const linkstack<T> &);
	~linkstack();

	int size()const;
	bool empty()const;
	void clear();

	return_code push(const T &item);
	return_code pop(T &out);
	return_code top(T &out)const;
	void traver(void(*visit)(const T&))const;

private:	
	sNode<T> *ptop;
	int nowsize;
};

template<typename T>
inline linkstack<T>::linkstack(): ptop(nullptr), nowsize(0){}

template<typename T>
inline linkstack<T>::~linkstack(){
	if(ptop){
		delete ptop;
		ptop = nullptr;
	}
}

template<typename T>
linkstack<T>::linkstack(const linkstack<T> &ls){
	if((nowsize = ls.size())){
		T temp;
		ls.top(temp);
		sNode<T> *newhead = ptop = new sNode<T>(temp);
		ls.traver([&](const T &s)->void{
			newhead->next = new sNode<T>(s);
			newhead = newhead->next; 
		});
	}
}

template<typename T>
linkstack<T>& linkstack<T>::operator=(const linkstack<T> &ls){
	nowsize = ls.size();
	if(nowsize == 0 ){
		if(ptop) this->clear();
	}
	else{
		sNode<T> *todelete = ptop, *newnode;
		
		T temp;
		ls.top(temp);
		newnode = ptop = new sNode<T>(temp);
		ls.traver([&](const T &s)->void{
			newnode->next = new sNode<T>(s);
			newnode = newnode->next;
		});

		while(todelete){
			newnode = todelete;
			todelete = todelete->next;
			delete newnode;
		}
	}

	return *this;
}

template<typename T>
inline int linkstack<T>::size()const{
	return nowsize;
}

template<typename T>
inline bool linkstack<T>::empty()const{
	return nowsize == 0;
}

template<typename T>
void linkstack<T>::clear(){
	sNode<T> *todelete;
	while(ptop){
		todelete = ptop;
		ptop = ptop->next;
		delete todelete;
	}
	nowsize = 0;
}

template<typename T>
return_code linkstack<T>::push(const T &item){
	sNode<T> *newnode = new sNode<T>(item, ptop);
	if(!newnode) return overflow; 
	ptop = newnode;
	nowsize++;
	return successful;
}

template<typename T>
return_code linkstack<T>::pop(T &out){
	if(nowsize == 0) return underflow;
	
	out = ptop->data;
	
	sNode<T> *todelete = ptop;
	ptop = ptop->next;
	delete todelete;
	nowsize--;
	return successful;
}

template<typename T>
return_code linkstack<T>::top(T &out)const{
	if(nowsize == 0) return underflow;
	
	out = ptop->data;
	
	return successful;
}

template<typename T>
void linkstack<T>::traver(void(*visit)(const T&))const{
	sNode<T> *pass = ptop;
	while(pass){
		visit(pass->data);
		pass = pass->next;
	}
}
