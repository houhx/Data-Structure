//use the orthogonal list to store the graph
#include "../include.h"

//the definition of arcNode
template<typename ARC_INFO>
struct arcNode{
    int headpos, tailpos;        //the start point and the terminal point of the edge
    arcNode *headnext,           //headnext point to the next edge that has the same head
            *tailnext;           //tailnext point to the next edge that has the same tail
    ARC_INFO *info;              //the infomation of the edge
    arcNode() : headpos(-1), tailpos(-1), 
                headnext(nullptr), tailnext(nullptr), info(nullptr){};
                                //the default constructor;
};

//the definition of vertexNode
template<typename VERTEX_INFO, typename ARC_INFO>
struct vertexNode{
    VERTEX_INFO *data;           //the content of the vertex
    arcNode<ARC_INFO> *firstout, //point to the first arcNode that out of this vertexNode
                      *firstin;  //point to the first arcNode that enter this vertexNode
    vertexNode() : data(nullptr), firstout(nullptr), firstin(nullptr){};
                                 //the  default constructor
};

template<typename VERTEX_INFO, typename ARC_INFO>
class OLgraph{
public:
    OLgraph(const int &vn = 0, const int &an = 0); //the default constructor
    ~OLgraph();                                    //the destructor

private:
    vertexNode<VERTEX_INFO, ARC_INFO> *mygraph;    //point to an dynamic array of vertexNode
    int vertexnums;                                //the nums of vertexNode
    int arcnums;                                   //the nums of arcNode
};

template<typename VERTEX_INFO, typename ARC_INFO>
OLgraph<VERTEX_INFO, ARC_INFO>::OLgraph(const int &vn, const int &an):vertexnums(vn),arcnums(an){
    cout << "start constructor..." << endl;

    if(vertexnums > 0){
        mygraph = new vertexNode<VERTEX_INFO, ARC_INFO>[vertexnums];
        cout << "the bytes of vertex* : " << sizeof(mygraph) << endl;
    }
}

template<typename VERTEX_INFO, typename ARC_INFO>
OLgraph<VERTEX_INFO, ARC_INFO>::~OLgraph(){
    if(vertexnums){
        delete[] mygraph;
        mygraph = nullptr;
    }

    cout << "destructor end..." << endl;
    getchar();
}


