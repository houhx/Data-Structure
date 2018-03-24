//用一维数组实现链表 
#include "../include.h"

template<class T>
struct slNode{
	T data;
	int next;
	slNode(const T &d = -1, const int &n = 0):data(d),next(n){};
};

template<class T>
class sllist{
public:	
	sllist();
	~sllist();
	return_code insert(const int&, const T&);
	return_code insert(const T&, bool(*cmp)(const T&, const T&));
	return_code remove(const int&, T&);
	return_code retrieve(const int&, T&)const;
	void traver(void(*visit)(const T&));
	int size()const;
	bool empty()const;
	void clear();
private:
    static int maxsize;	   //数组空间的最大长度 
	slNode<T> *slnodes;    
	int first;             //指向链表的第一个元素的数组下标
	int unused;            //指向未用空间的第一个节点 
	int nowsize;
	int setposition(const int&)const; //返回定位元素相应的数组下标
	void freenode(int &); //将删掉的节点回收 
};

template<class T>
int sllist<T>::maxsize = 10;

template<class T>
int sllist<T>::setposition(const int &position)const{
	if(position == 0) return -1;
	
	int value = first;
	for(int i=1; i<position; i++){
		value = slnodes[value].next;
	}
	return value;
}

template<class T>
void sllist<T>::freenode(int &index){
	slnodes[index].next = unused;
	unused = index;
	
} 

template<class T>
sllist<T>::sllist(){
	slnodes = (slNode<T>*)malloc(sizeof(slNode<T>)*maxsize);
	for(int i=1; i<maxsize; i++){
		slnodes[i-1].next = i;
	}
	slnodes[maxsize-1] = -1;
	first = -1; 
	unused = 0; 
	nowsize = 0;
}

template<class T>
sllist<T>::~sllist(){
	free(slnodes);
}

template<class T>
return_code sllist<T>::insert(const int &position, const T &item){
	if(position < 1 || position > nowsize+1) return Range_error;
	
	if(nowsize == maxsize) return overflow;
	
	if(nowsize == 0){ //表为空时插入 
		first = unused;
		slnodes[first].data = item;
		unused = slnodes[unused].next;
		slnodes[first].next = -1;
	}
	else{
		int index = setposition(position-1); //找出插入位置的前一个元素 
		
		int newnode = unused; //指向新建节点的下标
		unused = slnodes[unused].next; 
		slnodes[newnode].data = item;
		
		if(index == -1){
			slnodes[newnode].next = first;
			first = newnode;
		}
		else{
			slnodes[newnode].next = slnodes[index].next;
			slnodes[index].next = newnode;
		}
	}
	
	nowsize++;
	return successful;
}

template<class T>
return_code sllist<T>::insert(const T &item, bool(*cmp)(const T&, const T&)){
	if(nowsize == maxsize) return overflow;
	
	int position = 1;
    int after = first;
	while(after != -1 && cmp(item, slnodes[after].data)){
		after = slnodes[after].next;
		position++;
	}
		
	insert(position, item);
	return successful;
}

template<class T>
return_code sllist<T>::remove(const int &position, T &save){
	if(position < 1 || position > nowsize) return Range_error;
	
	int index = setposition(position-1);
	if(index == -1){
		save = slnodes[first].data;
		int firstcopy = slnodes[first].next; 
		freenode(first);
		first = firstcopy;
	}
	else{
		int delnode = slnodes[index].next;
		save = slnodes[delnode].data;
		slnodes[index].next = slnodes[delnode].next;
		freenode(delnode);
	}
	
	nowsize--;
	return successful;
}

template<class T>
return_code sllist<T>::retrieve(const int &position, T &save)const{
	if(position < 1 || position > nowsize) return Range_error;
	
	int index = setposition(position);
	
	save = slnodes[index].data;
	return successful;
}

template<class T>
void sllist<T>::traver(void(*visit)(const T&)){
	int index = first;
	for(int i=0; i<nowsize; i++){
		visit(slnodes[index].data);
		index = slnodes[index].next;
	}
}

template<class T>
inline int sllist<T>::size()const{
	return nowsize;
}

template<class T>
inline bool sllist<T>::empty()const{
	return first == -1;
}

template<class T>
void sllist<T>::clear(){
	int index = first;
	for(int i=0; i<nowsize; i++){
		int copynext = slnodes[index].next;
		freenode(index);
		index = copynext;
	}
	first = -1;
	nowsize = 0;
}



