//use the orthogonal list to store the graph
#include "../include.h"

//the definition of arcNode
template<typename ARC_INFO>
struct arcNode{
    int headpos, tailpos;        //the start point and the terminal point of the edge
    arcNode *headnext,           //headnext point to the next edge that has the same head
            *tailnext;           //tailnext point to the next edge that has the same tail
    ARC_INFO *info;              //the infomation of the edge
    arcNode(int hp = -1, int tp = -1, arcNode<ARC_INFO> *hn = nullptr, 
            arcNode<ARC_INFO> *tn = nullptr, ARC_INFO *in = nullptr) :
                headpos(hp), tailpos(tp), headnext(hn), tailnext(tn), info(in){};
                                //the constructor;
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

    int locatepos(const VERTEX_INFO &vertexinfo) const; //locate the position of the vertex according to the vertexinfo
    return_code creategraph(); //construct the OLgraph

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
    }
}

template<typename VERTEX_INFO, typename ARC_INFO>
OLgraph<VERTEX_INFO, ARC_INFO>::~OLgraph(){
    /*cout << "the bytes of vertex* : " << sizeof(mygraph) << endl
         << "the bytes of veretex[0] : " << sizeof(mygraph[0]) << endl;
    for (int i = 0; i < vertexnums; i++){
        cout << "the address of mygraph[" << i << "] : " << &mygraph[i] << endl
             << "the address of data:     " << &mygraph[i].data << "  sizeof data: " << sizeof(mygraph[i].data) << endl
             << "the address of firstout: " << &mygraph[i].firstout << "  sizeof firstout: " << sizeof(mygraph[i].firstout) << endl
             << "the address of firstin: "  << &mygraph[i].firstin  << "  sizeof firstin: " << sizeof(mygraph[i].firstin) << endl
             << "  the vertex is : " << *mygraph[i].data << endl << endl;
    }*/

    if(vertexnums){
        delete[] mygraph;
        mygraph = nullptr;
    }

    cout << "destructor end..." << endl;
    getchar();
}

template<typename VERTEX_INFO, typename ARC_INFO>
int OLgraph<VERTEX_INFO, ARC_INFO>::locatepos(const VERTEX_INFO &vertexinfo)const{
    for (int i = 0; i<vertexnums; i++){
        if(*mygraph[i].data == vertexinfo) return i;
    }
    return -1;
}

template<typename VERTEX_INFO, typename ARC_INFO>
return_code OLgraph<VERTEX_INFO, ARC_INFO>::creategraph(){
    //read the vertex
    cout << "please input the data of the vertex, separeted by space, ended by return: ";
    VERTEX_INFO temp;
    int count = 0; //the position of the vertex that inputing now
    while(cin >> temp){
        mygraph[count++].data = new VERTEX_INFO(temp);
        if(cin.get() == '\n') break;
    }

    //read the edges
    cout << "please input the infomation about all edges."
         << "every edge use the format \"start_vertex terminal_vertex edge_info(-1 if null)\". "
         << "one line one edge information:" << endl;
    VERTEX_INFO start, end;
    ARC_INFO edgeinfo;
    count = 0;
    while(count < arcnums){
        cin >> start >> end >> edgeinfo;
        cin.get();
        arcNode<ARC_INFO> *arcnode = new arcNode<ARC_INFO>(locatepos(start), locatepos(end),
                                                           mygraph[locatepos(end)].firstin,
                                                           mygraph[locatepos(start)].firstout,
                                                           new ARC_INFO(edgeinfo));
        mygraph[locatepos(start)].firstout = arcnode;
        mygraph[locatepos(end)].firstin = arcnode;
        count++;
    }
    cout << "input successfully!" << endl;
    return successful;
}

