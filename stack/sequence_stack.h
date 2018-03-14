#pragma once
#include "../include.h"

const int initcapacity = 10;
const int increasement = 5;
class sstack{
public:	
	sstack(int c = initcapacity);
	int size()const;
	int capacity()const;
	void setcapacity(int &n); 
	bool empty()const;
	void clear();
	return_code push(elemtype &item);
	return_code pop(elemtype &save);
	return_code top(elemtype &save)const;
	void traver(void(*visit)(elemtype&));
	~sstack();
private:	
	elemtype *elements;
	int ptop;
	int nowcapacity;
};

inline sstack::sstack(int c):nowcapacity(c){
	elements = (elemtype*)malloc(sizeof(elemtype)*nowcapacity);
	ptop = -1;
}

inline sstack::~sstack(){
	free(elements);
}

inline int sstack::size()const{
	return ptop+1;
}

inline int sstack::capacity()const{
	return nowcapacity;
}

inline void sstack::setcapacity(int &n){
	nowcapacity = n;
}

inline bool sstack::empty()const{
	return ptop == -1;
}

inline void sstack::clear(){
	ptop = -1;
}

return_code sstack::push(elemtype &item){
	if(ptop == nowcapacity-1){
		nowcapacity += increasement;
		elements = (elemtype*)realloc(elements, sizeof(elemtype)*nowcapacity);
		if(!elements) return overflow;
	}
	
	elements[++ptop] = item;
	return successful;
}

return_code sstack::pop(elemtype &save){
	if(ptop == -1) return underflow;
	
	save = elements[ptop--];
	return successful;
}

return_code sstack::top(elemtype &save)const{
	if(ptop == -1) return underflow;
	
	save = elements[ptop];
	return successful;
}

void sstack::traver(void(*visit)(elemtype&)){
	for( int i=ptop; i>-1; i--){
		visit(elements[i]);
	}
}


