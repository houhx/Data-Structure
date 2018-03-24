#pragma once
#include "../include.h"

const int initsize = 10;
const int increasenum = 5;

class squeue{
public:	
	squeue(int size=initsize, int increase=increasenum);
	~squeue();
	return_code push(const elemtype &item);
	return_code pop(elemtype &save);
	return_code front(elemtype &save)const;
	return_code back(elemtype &save)const;
	void clear();
	bool empty()const;
	int size()const;
	int capacity()const;
	void setcapacity(int &n);
	void traver(void(*visit)(elemtype&));
private:	
	elemtype *elements;
	int tail;
	int maxsize;
	int increasment;
};

inline squeue::squeue(int size, int increase):
	maxsize(size),increasment(increase){
		elements = (elemtype*)malloc(sizeof(elemtype)*maxsize);
		tail = -1;
	}
	
inline squeue::~squeue(){
	free(elements);
}	
	
return_code squeue::push(const elemtype &item){
	if(tail == maxsize-1){
		maxsize += increasment; 
		elements = (elemtype*)realloc(elements, sizeof(elemtype)*maxsize);
		
		if(!elements) return out_of_memory;
	}
	
	elements[++tail] = item;
	
	return successful;
}

return_code squeue::pop(elemtype &save){
	if(tail == -1) return underflow;
	
	save = elements[0];
	for(int i=1; i<=tail; i++){
		elements[i-1] = elements[i];
	}
	tail--;
	
	return successful;
}

return_code squeue::front(elemtype &save)const{
	if(tail == -1) return underflow;
	
	save = elements[0];
	
	return successful;
}

return_code squeue::back(elemtype &save)const{
	if(tail == -1) return underflow;
	
	save = elements[tail];
	
	return successful;
}

inline void squeue::clear(){
	tail = -1;
}

inline bool squeue::empty()const{
	return tail == -1;
}

inline int squeue::size()const{
	return tail+1;
}

inline int squeue::capacity()const{
	return maxsize;
}

inline void squeue::setcapacity(int &n){
	maxsize = n;
}

void squeue::traver(void(*visit)(elemtype&)){
	for(int i=0; i<=tail; i++){
		visit(elements[i]);
	}
}	
