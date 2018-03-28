//the impelement of disjoint set

template<typename NODE_INFO>
struct setNode{
    NODE_INFO *info;
    setNode<NODE_INFO> *parent;
    int rink;
};

