#pragma once
#include "../include.h"

struct sNode{
	elemtype data;
	sNode *next;
	sNode(){ next = nullptr;};
	sNode(elemtype &d, sNode *n = nullptr):data(d), next(n){}; 
};

class linkstack{
public:	
	linkstack();
	int size()const;
	bool empty()const;
	void clear();
	return_code push(elemtype &item);
	return_code pop(elemtype &save);
	return_code top(elemtype &save)const;
	void traver(void(*visit)(elemtype&));
private:	
	sNode *ptop;
	int nowsize;
};

inline linkstack::linkstack(){
	ptop = nullptr;
	nowsize = 0;
}

inline int linkstack::size()const{
	return nowsize;
}

inline bool linkstack::empty()const{
	return nowsize == 0;
}

void linkstack::clear(){
	sNode *copy;
	while(ptop){
		copy = ptop;
		ptop = ptop->next;
		delete copy;
	}
	nowsize = 0;
}

return_code linkstack::push(elemtype &item){
	sNode *newnode = new sNode(item, ptop);
	if(!newnode) return overflow; 
	ptop = newnode;
	nowsize++;
	return successful;
}

return_code linkstack::pop(elemtype &save){
	if(nowsize == 0) return underflow;
	
	save = ptop->data;
	
	sNode *copy = ptop;
	ptop = ptop->next;
	delete copy;
	nowsize--;
	return successful;
}

return_code linkstack::top(elemtype &save)const{
	if(nowsize == 0) return underflow;
	
	save = ptop->data;
	
	return successful;
}

void linkstack::traver(void(*visit)(elemtype&)){
	sNode *pass = ptop;
	while(pass){
		visit(pass->data);
		pass = pass->next;
	}
}
