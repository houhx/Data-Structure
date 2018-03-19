#pragma once
#include "../include.h"

template<typename T>
class sstack{
public:	
	sstack(int c = 10);
	~sstack();

	int size()const;
	int getcapacity()const;
	void setcapacity(int &n); 
	bool empty()const;
	void clear();
	return_code push(const T &item);
	return_code pop(T &out);
	return_code top(T &out)const;
	void traver(void(*visit)(const T&))const;
	
private:	
	T *elements;
	int ptop;
	int capacity;
	int increasement;
};

template<typename T>
inline sstack<T>::sstack(int c): ptop(-1), capacity(c), increasement(5){
	elements = (T*)malloc(sizeof(T)*capacity);
}

template<typename T>
inline sstack<T>::~sstack(){
	if(elements){
		free(elements);
		elements = nullptr;
	}
}

template<typename T>
inline int sstack<T>::size()const{
	return ptop+1;
}

template<typename T>
inline int sstack<T>::getcapacity()const{
	return capacity;
}

template<typename T>
inline void sstack<T>::setcapacity(int &n){
	capacity = n;
}

template<typename T>
inline bool sstack<T>::empty()const{
	return ptop == -1;
}

template<typename T>
inline void sstack<T>::clear(){
	for(int i=0; i<=ptop; i++) elements[i] = 0;
	ptop = -1;
}

template<typename T>
return_code sstack<T>::push(const T &item){
	if(ptop == capacity-1){
		capacity += increasement;
		elements = (T*)realloc(elements, sizeof(T)*capacity);
		if(!elements) return overflow;
	}
	
	elements[++ptop] = item;
	return successful;
}

template<typename T>
return_code sstack<T>::pop(T &out){
	if(ptop == -1) return underflow;
	
	out = elements[ptop--];
	return successful;
}

template<typename T>
return_code sstack<T>::top(T &out)const{
	if(ptop == -1) return underflow;
	
	out = elements[ptop];
	return successful;
}

template<typename T>
void sstack<T>::traver(void(*visit)(const T&))const{
	for( int i=ptop; i>-1; i--){
		visit(elements[i]);
	}
}


