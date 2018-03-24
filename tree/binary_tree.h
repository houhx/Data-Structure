#include "../include.h"
#include "../stack/link_stack.h"
#include "../queue/link_queue.h"

template<typename T>
struct treenode{
    T data;
    treenode<T> *lnode, *rnode;
    treenode(): data(), lnode(nullptr), rnode(nullptr){};
    treenode(const T &d, treenode<T> *l = nullptr, treenode<T> *r = nullptr)
            :data(d), lnode(l), rnode(r){};
};

template<typename T>
class bitree{
public:
    bitree():root(nullptr), nums(0){};
    ~bitree();

    void createbitree_preorder();

    //递归版
    void preorder_traverse_recursion(void(*visit)(const T&))const;
    void inorder_traverse_recursion(void(*visit)(const T&))const;
    void postorder_traverse_recursion(void(*visit)(const T&))const;

    //非递归版
    void preorder_traverse(void(*visit)(const T&))const;
    void inorder_traverse(void(*visit)(const T&))const;
    void postorder_traverse(void(*visit)(const T&))const; 

    void clear();
    int size()const{ return nums; };
    bool empty()const{ return nums == 0; };

private:
    treenode<T> *root;
    int nums;

    //辅助递归函数
    void pre(treenode<T> *tnode, void(*visit)(const T&))const;
    void in(treenode<T> *tnode, void(*visit)(const T&))const;
    void post(treenode<T> *tnode, void(*visit)(const T&))const;
};

template<typename T>
void bitree<T>::createbitree_preorder(){
    cout << "请按照先序输入树中个元素值，空节点用-1表示，用空格隔开，回车结束：" << endl;
    T temp;
    linkstack<treenode<T>**> ls;
    ls.push(&root);
    treenode<T> **stop = nullptr;
    while(cin >> temp){
        ls.pop(stop);
        if(temp != -1){
            (*stop) = new treenode<T>(temp);
            nums++;
            ls.push(&((*stop)->rnode));
            ls.push(&((*stop)->lnode));
        }

        if(cin.get() == '\n') break;
    }

    cout << "树已创建成功！" << endl;
}

template<typename T>
void bitree<T>::clear(){
    if(root){
        linkqueue<treenode<T>*> lq;
        lq.push(root);
        root = nullptr;
        treenode<T> *todelete = nullptr;
        while(!lq.empty()){
            lq.pop(todelete);
            if(todelete->lnode) lq.push(todelete->lnode);
            if(todelete->rnode) lq.push(todelete->rnode);
            delete todelete;
        }

        nums = 0;
    }
}

template<typename T>
bitree<T>::~bitree(){
    clear();
}

template<typename T>
void bitree<T>::pre(treenode<T> *tnode, void(*visit)(const T&))const{
    if(tnode == nullptr) return;

    visit(tnode->data);
    pre(tnode->lnode,visit);
    pre(tnode->rnode,visit);
}

template<typename T>
void bitree<T>::in(treenode<T> *tnode, void(*visit)(const T&))const{
    if(tnode == nullptr) return;

    in(tnode->lnode,visit);
    visit(tnode->data);
    in(tnode->rnode,visit);
}

template<typename T>
void bitree<T>::post(treenode<T> *tnode, void(*visit)(const T&))const{
    if(tnode == nullptr) return;

    post(tnode->lnode,visit);
    post(tnode->rnode,visit);
    visit(tnode->data);
}

template<typename T>
void bitree<T>::preorder_traverse_recursion(void(*visit)(const T&))const{
    pre(root,visit);
}

template<typename T>
void bitree<T>::inorder_traverse_recursion(void(*visit)(const T&))const{
    in(root, visit);
}

template<typename T>
void bitree<T>::postorder_traverse_recursion(void(*visit)(const T&))const{
    post(root, visit);
}

template<typename T>
void bitree<T>::preorder_traverse(void(*visit)(const T&))const{
    if(root){
        linkstack<treenode<T>*> ls;
        ls.push(root);
        treenode<T> *first = nullptr;
        while(!ls.empty()){
            ls.pop(first);
            visit(first->data);
            if(first->rnode) ls.push(first->rnode);
            if(first->lnode) ls.push(first->lnode);
        }
    }
}

template<typename T>
void bitree<T>::inorder_traverse(void(*visit)(const T&))const{
    if(root){
        linkstack<treenode<T>*> ls;
        ls.push(root);
        treenode<T> *first = nullptr;
        while(!ls.empty()){
            ls.top(first);
            while(first){
                ls.push(first->lnode);
                ls.top(first);
            }
            ls.pop(first);
            if(!ls.empty()){
                ls.pop(first);
                visit(first->data);
                ls.push(first->rnode);
            }
        }
    }
}

template<typename T>
void bitree<T>::postorder_traverse(void(*visit)(const T&))const{
    if(root){
        linkstack<treenode<T>*> ls;
        ls.push(root);
        treenode<T> *first = nullptr, *temp = nullptr;
        while(!ls.empty()){
            ls.top(first);
            if(first){
                if(first->lnode) ls.push(first->lnode);
                else ls.push(first->rnode);
            } 
            else{
                ls.pop(first);
                ls.pop(temp);
                visit(temp->data);
                if(!ls.empty()){
                    ls.top(first);
                    if(temp == first->rnode) ls.push(nullptr);
                    else ls.push(first->rnode);
                }
            }
        }
    }
}