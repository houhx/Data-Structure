#pragma once
#include "../include.h"

const int defaultsize = 11;

class cqueue{
public:	
	cqueue(int s = defaultsize);
	return_code push(const elemtype &item);
	return_code pop(elemtype &save);
	return_code front(elemtype &save)const;
	return_code back(elemtype &save)const;
	void clear();
	bool empty()const;
	int size()const;
	int capacity()const;
	void setcapacity(const int &n);
	void traver(void(*visit)(elemtype&));
	~cqueue();
private:
    elemtype *elements;	
	int head, tail;
	int nowsize;
};

inline cqueue::cqueue(int s): nowsize(s){
	head = tail = 0;
	elements = new elemtype[nowsize]; 
}

return_code cqueue::push(const elemtype &item){
	if((tail-head+nowsize)%nowsize == nowsize-1) return overflow;
	elements[tail] = item;
	tail = (tail+1)%nowsize;
	return successful;
}

return_code cqueue::pop(elemtype &save){
	if(head == tail) return underflow;
	
	save = elements[head];
	head = (head+1)%nowsize;
	return successful;
}

return_code cqueue::front(elemtype &save)const{
	if(head == tail) return underflow;
	
	save = elements[head];
	return successful;
}

return_code cqueue::back(elemtype &save)const{
	if(head == tail) return underflow;
	
	save = elements[tail-1];
	return successful;
}

inline void cqueue::clear(){
	head = tail = 0;
}

inline bool cqueue::empty()const{
	return head == tail;
}

inline int cqueue::size()const{
	return (tail-head+nowsize) % nowsize;
}

inline int cqueue::capacity()const{
	return nowsize-1;
}

inline void cqueue::setcapacity(const int &n){
	nowsize = n;
}

void cqueue::traver(void(*visit)(elemtype&)){
	for(int i=head; i != tail; i= (i+1)%nowsize){
		visit(elements[i]);
	}
}

inline cqueue::~cqueue(){
	delete [] elements;
}
