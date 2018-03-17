#include "../include.h"

class mystring{
public:
    mystring();
    mystring(const char*);
    friend int strcmp(const mystring&, const mystring&);//比较两个串的大小
    int strlen(){return len;};//返回长度
    void clear();
    friend mystring strcat(mystring&, mystring&);//连接两个串
    char get(int index)const;
    mystring substr(int pos, int len);//返回子串
    void setlen(int l){len = l;};
    int index(mystring&, int);//普通的模式匹配
    int index_kmp(mystring&, int);//kmp算法的模式匹配
private:
    char *str;
    int  len;
    int* Next(mystring&); 
};

int* mystring::Next(mystring &need){
    int *next = new int(need.strlen());
    next[0] = -1;
    int i=0, j=-1;
    while(i<need.strlen()-1){
        if(j==-1 || need.str[i]==need.str[j]){
            i++;
            j++;
            if(need.str[i] == need.str[j]) next[i] = next[j];
            else next[i] = j;
        }
        else{
            j = next[j];
        }
    }
    return next;
}

inline mystring::mystring(): str(nullptr), len(0){}

inline mystring::mystring(const char *s){
    if(!s){
        str = nullptr;
        len = 0;
    }
    else{
        const char *copy = s;
        int count = 0;
        for(; *copy != '\0'; copy++,count++);

        str = (char*)malloc(count);

        for(int i=0; i<count; i++){
            str[i] = s[i];
        }

        len = count;
    }
}

int strcmp(const mystring& str1, const mystring &str2){
    for(int i=0; i<str1.len && i<str2.len; i++){
        if(str1.str[i] > str2.str[i]) return 1;
        if(str1.str[i] < str2.str[i]) return -1;
    }
    if(str1.len == str2.len) return 0;
    if(str1.len > str2.len) return 1;
    return -1;
}

void mystring::clear(){
    if(!str){
        free(str);
        str = nullptr;
    }
    len = 0;
}

mystring strcat(mystring &str1, mystring &str2){
    mystring newstr(str1);
    if(newstr.len == 0) newstr = str2;
    else{
        int originallen = newstr.len;
        newstr.len += str2.len; 
        newstr.str = (char*)realloc(newstr.str,newstr.len*sizeof(char));
        for(int i=originallen; i<newstr.len; i++){
            newstr.str[i] = str2.str[i-originallen];
        }
    }
    return newstr;
}

char mystring::get(int index)const{
    if(index < 0 || index > len-1){
        cout << "越界" << endl;
        abort();
    }
    return str[index];
}

mystring mystring::substr(int pos, int sublen){
    if(pos < 0 || pos > len-sublen || sublen < 0 || sublen > len){
        cout << "error" << endl;
        abort();
    }

    char *sub = new char(sublen);
    for(int i=0; i<sublen; i++){
        sub[i] = str[pos+i];
    }
    
    mystring returnstr(sub);
    delete sub;
    return returnstr;
}

int mystring::index(mystring &need, int pos){
    if(pos < 0 || pos > len-1){
        cout << "error" << endl;
        abort();
    }

    int i=pos, j=0;
    while(i<len && j<need.strlen()){
        if(str[i] == need.str[j]){
            i++;
            j++;
        }
        else{
            i = i-j+1;
            j = 0;
        }
    }
    if(j == need.strlen()) return i-j;

    return -1;
}

int mystring::index_kmp(mystring &need, int pos){
    if(pos < 0 || pos > len-1){
        cout << "error" << endl;
        abort();
    }

    int *next = Next(need);
    for(int i=0; i<need.strlen(); i++) cout << next[i] << "   ";
    cout << endl;

    int i=pos, j=0;
    while(i<len && j<need.strlen()){
        if(j==0 || str[i] == need.str[j]){
            i++;
            j++;
        }
        else{
            j = next[j];
        }
    }

    if(j == need.strlen()) return i-j;

    return -1;
}