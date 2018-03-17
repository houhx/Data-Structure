#include "../include.h"

template<class T>
class slist{
public:
    slist(int cap=10);
    slist(const slist<T> &s);
    slist<T>& operator=(const slist<T> &s);
    return_code setcapacity(int n);
    int getlen()const{ return nowlen; };
    int getcapacity()const{ return capacity; };
    int getincreasement()const{ return increasement; };
    void setincreasement(int n){ increasement = n; };
    bool empty()const{ return nowlen == 0; };
    void clear();
    return_code insert(int pos, const T &item);
    return_code deletelemt(int pos, T &out);
    return_code retrieve(int pos, T &out)const;
    void traver(void(*visit)(const T&));
    int locate(T &item, bool(*cmp)(const T&, const T&))const;
    void unionlist(const slist<T> &s);
    ~slist();
private:
    T *elements;   //存放数据元素
    int nowlen;    //当前线性表的长度
    int capacity;    //线性表的最大长度
    int increasement;  //增量
};

template<class T>
inline slist<T>::slist(int cap):nowlen(0), capacity(cap), increasement(5){
    elements = (T*)malloc(sizeof(T)*capacity);
    if(!elements){
        cout << "overflow" << endl;
        exit(1);
    }
}

template<class T>
slist<T>::slist(const slist<T> &s){
    nowlen = s.getlen();
    capacity = s.getcapacity();
    increasement = s.getincreasement();
    elements = (T*)malloc(sizeof(T)*capacity);
    int temp = 0;
    for(int i=0; i<nowlen; i++){
        s.retrieve(i, temp);
        elements[i] = temp;
    }
}

template<class T>
slist<T>& slist<T>::operator=(const slist<T> &s){
    nowlen = s.getlen();
    capacity = s.getcapacity();
    increasement = s.getincreasement();

    if(nowlen == 0){
        free(elements);
        elements = nullptr;
        return *this;
    }

    T *copy = elements;

    elements = (T*)malloc(sizeof(T)*nowlen);
    int temp = 0;
    for(int i=0; i<nowlen; i++){
        s.retrieve(i, temp);
        elements[i] = temp;
    }

    free(copy);
    return *this;
}

template<class T>
slist<T>::~slist(){
    if(elements){
        free(elements);
        elements = nullptr;
    }
}

template<class T>
return_code slist<T>::setcapacity(int n){
    if(n < nowlen) return Error;

    capacity = n;
    elements = (T*)realloc(elements, sizeof(T)*capacity);
    return successful;
}

template<class T>
inline void slist<T>::clear(){
    for(int i=0; i<nowlen; i++) elements[i] = 0;
    nowlen = 0;
}

template<class T>
return_code slist<T>::insert(int pos, const T &item){
    if(pos < 0 || pos > nowlen) return Range_error;

    if(nowlen == capacity){
        capacity += increasement;
        elements = (T*)realloc(elements, sizeof(T)*capacity);
    }

    for(int i=nowlen; i>pos; i--) elements[i] = elements[i-1];
    elements[pos] = item;
    nowlen++;
    return successful;
}

template<class T>
return_code slist<T>::deletelemt(int pos, T &out){
    if(pos < 0 || pos >nowlen-1) return Range_error;

    out = elements[pos];
    for(int i=pos; i<nowlen-1; i++) elements[i] =elements[i+1];
    nowlen--;
    return successful;
}

template<class T>
return_code slist<T>::retrieve(int pos, T &out)const{
    if(pos < 0 || pos > nowlen -1 ) return Range_error;

    out = elements[pos];

    return successful;
}

template<class T>
int slist<T>::locate(T &item, bool(*cmp)(const T&, const T&))const{
    for(int i=0; i<nowlen; i++){
        if(cmp(item,elements[i])) return i;
    }

    return -1;
}

template<class T>
void slist<T>::traver(void(*visit)(const T&)){
    for(int i=0; i<nowlen; i++){
        visit(elements[i]);
    }
}

template<class T>
void slist<T>::unionlist(const slist<T> &s){
    if(s.empty()) return;

    T temp = 0;
    for(int i=0; i<s.getlen(); i++){
        s.retrieve(i, temp);
        if(this->locate(temp,[](const T &e1, const T &e2)->bool{ return e1==e2; }) == -1){
            this->insert(nowlen, temp);
        }
    }
}