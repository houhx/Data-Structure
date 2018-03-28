//use the orthogonal list to store the digraph
#include "../include.h"
#include "../stack/link_stack.h"
#include "../queue/link_queue.h"

//the definition of arcNode_oldigraph
template<typename ARC_INFO>
struct arcNode_oldigraph{
    int startpos, endpos;        //the start point and the terminal point of the edge
    arcNode_oldigraph *headnext,   //headnext point to the next edge that has the same head
                      *tailnext;   //tailnext point to the next edge that has the same tail
    ARC_INFO *arcinfo;              //the infomation of the edge
    arcNode_oldigraph(int hp = -1, int tp = -1, 
                    arcNode_oldigraph<ARC_INFO> *hn = nullptr, 
                    arcNode_oldigraph<ARC_INFO> *tn = nullptr, 
                    ARC_INFO *in = nullptr) :
                    startpos(hp), endpos(tp), headnext(hn), tailnext(tn), arcinfo(in){};
};

//the definition of vertexNode_oldigraph
template<typename VERTEX_INFO, typename ARC_INFO>
struct vertexNode_oldigraph{
    VERTEX_INFO *vertexinfo;           //the content of the vertex
    arcNode_oldigraph<ARC_INFO> *firstout, //point to the first arcNode_oldigraph that out of this vertexNode_oldigraph
                                *firstin;  //point to the first arcNode_oldigraph that enter this vertexNode_oldigraph
    vertexNode_oldigraph() : vertexinfo(nullptr), firstout(nullptr), firstin(nullptr){};
                                 //the  default constructor
};

template<typename VERTEX_INFO, typename ARC_INFO>
class OLdigraph{
  public:
    //the default constructor
    OLdigraph(const int &vn = 0, const int &an = 0); 

    //the destructor
    ~OLdigraph();                                    
    
    //locate the position of the vertex according to the vertexinfo
    int locatepos(const VERTEX_INFO &vertexinfo) const;

    //construct the OLdigraph
    void creategraph(const string &inputfilename);

    //two version of DFS
    void dfs_traverse_recursive(function<void(const VERTEX_INFO&)>&) const;
    void dfs_traverse_iterator(function<void(const VERTEX_INFO &)> &) const;

    //BFS
    void bfs_traverse_iterator(function<void(const VERTEX_INFO &)> &) const;

    //seek strong connected components
    void get_strong_connected_components() const;

  private:
    //point to an dynamic array of vertexNode_oldigraph
    vertexNode_oldigraph<VERTEX_INFO, ARC_INFO> *vertexset;
    int vertexnums;
    int arcnums;                 
};

template<typename VERTEX_INFO, typename ARC_INFO>
OLdigraph<VERTEX_INFO, ARC_INFO>::OLdigraph(const int &vn, const int &an):vertexnums(vn),arcnums(an){
    if(vertexnums > 0){
        vertexset = new vertexNode_oldigraph<VERTEX_INFO, ARC_INFO>[vertexnums];
    }
}

template<typename VERTEX_INFO, typename ARC_INFO>
OLdigraph<VERTEX_INFO, ARC_INFO>::~OLdigraph(){
    if(vertexnums){
        delete[] vertexset;
        vertexset = nullptr;
    }
}

template<typename VERTEX_INFO, typename ARC_INFO>
int OLdigraph<VERTEX_INFO, ARC_INFO>::locatepos(const VERTEX_INFO &vertexinfo)const{
    for (int i = 0; i<vertexnums; i++){
        if(*vertexset[i].vertexinfo == vertexinfo) return i;
    }
    return -1;
}

template<typename VERTEX_INFO, typename ARC_INFO>
void OLdigraph<VERTEX_INFO, ARC_INFO>::creategraph(const string &inputfilename){

    ifstream in(inputfilename);
    if(!in.is_open()) cout << "open file error!" << endl;

    VERTEX_INFO temp;
    int count = 0; //the position of the vertex that inputing now
    while(in >> temp){
        vertexset[count++].vertexinfo = new VERTEX_INFO(temp);
        if(in.get() == '\n') break;
    }

    VERTEX_INFO start, end;
    ARC_INFO edgeinfo;
    count = 0;
    while(count < arcnums){
        in >> start >> end >> edgeinfo;
        in.get();
        arcNode_oldigraph<ARC_INFO> *arcnode = new arcNode_oldigraph<ARC_INFO>(locatepos(start), locatepos(end),
                                                           vertexset[locatepos(end)].firstin,
                                                           vertexset[locatepos(start)].firstout,
                                                           new ARC_INFO(edgeinfo));
        vertexset[locatepos(start)].firstout = arcnode;
        vertexset[locatepos(end)].firstin = arcnode;
        count++;
    }
    cout << "create graph successful!" << endl;
    getchar();
    in.close();
}

template<typename VERTEX_INFO, typename ARC_INFO>
void OLdigraph<VERTEX_INFO, ARC_INFO>::dfs_traverse_recursive(function<void(const VERTEX_INFO&)> &visit)const{
    unsigned char visited[vertexnums] = {0};

    function<void(int)> dfs;
    dfs = [&](int pos) -> void {
        visited[pos] = 1;
        visit(*vertexset[pos].vertexinfo);
        arcNode_oldigraph<ARC_INFO> *outarc = vertexset[pos].firstout;
        while(outarc){
            if(!visited[outarc->endpos]){
                dfs(outarc->endpos);
            }
            outarc = outarc->tailnext;
        }
    };

    for (int i = 0; i < vertexnums; i++){
        if(!visited[i]) dfs(i);
    }
}

template<typename VERTEX_INFO, typename ARC_INFO>
void OLdigraph<VERTEX_INFO, ARC_INFO>::dfs_traverse_iterator(function<void(const VERTEX_INFO&)> &visit)const{
    unsigned char visited[vertexnums] = {0};

    linkstack<int> ls;
    for (int i = 0; i < vertexnums; i++){
        if(!visited[i]){

            ls.push(i);
            int temp = 0;

            while(!ls.empty()){

                ls.pop(temp);
                if(!visited[temp]){

                    visited[temp] = 1;
                    visit(*vertexset[temp].vertexinfo);

                    arcNode_oldigraph<ARC_INFO> *outarc = vertexset[temp].firstout;
                    while(outarc){
                        if(!visited[outarc->endpos]){
                            ls.push(outarc->endpos);
                        }
                        outarc = outarc->tailnext;
                    }

                }
            }
        }
    }
}

template<typename VERTEX_INFO, typename ARC_INFO>
void OLdigraph<VERTEX_INFO, ARC_INFO>::bfs_traverse_iterator(function<void(const VERTEX_INFO&)> &visit)const{
    unsigned char visited[vertexnums] = {0};

    linkqueue<int> lq;
    for (int i = 0; i < vertexnums; i++){

        if(!visited[i]){

            lq.push(i);
            int temp = 0;

            while(!lq.empty()){

                lq.pop(temp);
                if(!visited[temp]){

                    visited[temp] = 1;
                    visit(*vertexset[temp].vertexinfo);

                    arcNode_oldigraph<ARC_INFO> *outarc = vertexset[temp].firstout;
                    while(outarc){
                        if(!visited[outarc->endpos]){
                            lq.push(outarc->endpos);
                        }
                        outarc = outarc->tailnext;
                    }

                }
            }
        }
    }
}

template<typename VERTEX_INFO, typename ARC_INFO>
void OLdigraph<VERTEX_INFO, ARC_INFO>::get_strong_connected_components()const{
    unsigned char visited[vertexnums] = {0};
    unsigned char finished[vertexnums] = {0};//store the vertex that has been totally visited, 
                                              //meaning that its child vertexes are all visited
    int count = 0;

    function<void(int)> dfs_order, dfs_reverse_order;
    dfs_order = [&](int pos) -> void {
        visited[pos] = 1;
        arcNode_oldigraph<ARC_INFO> *move = vertexset[pos].firstout;
        while(move){
            if(!visited[move->endpos]){
                dfs_order(move->endpos);
            }
            move = move->tailnext;
        }
        finished[count++] = pos;
    };

    dfs_reverse_order = [&](int pos) -> void {
        visited[pos] = 1;
        cout << *vertexset[pos].vertexinfo << "  ";
        arcNode_oldigraph<ARC_INFO> *move = vertexset[pos].firstin;
        while(move){
            if(!visited[move->startpos]){
                dfs_reverse_order(move->startpos);
            }
            move = move->headnext;
        }
    };

    for (int i = 0; i < vertexnums; i++){
        if(!visited[i]) dfs_order(i);
    }

    memset(visited, 0, vertexnums);
    count = 0;
    for (int i = vertexnums - 1; i >= 0; i--){
        if(!visited[finished[i]]){
            cout << "the " << count++ << " strong connected component: ";
            dfs_reverse_order(finished[i]);
        }
        cout << endl;
    }
}
