//use the adjacency multilist to implement the undigraph
#include "../include.h"
#include "../stack/link_stack.h"
#include "../queue/link_queue.h"


//the definition of edge node of amundigraph
template<typename EDGE_INFO>
struct edgeNode_amundigraph{
    bool visited;  //indicate whether or not it has been visited
    int ivertex, jvertex;  //the position of the two vertex that the edge attached to
    edgeNode_amundigraph<EDGE_INFO> *inext, *jnext;  //point to the next edge that attached to the same vertex
    EDGE_INFO *edgeinfo;  //the information that the edge has

    edgeNode_amundigraph(bool v = 0, int iv = -1, int jv = -1,
                        edgeNode_amundigraph<EDGE_INFO> *in = nullptr, 
                        edgeNode_amundigraph<EDGE_INFO> *jn = nullptr, 
                        EDGE_INFO *ifo = nullptr) : 
                        visited(v), ivertex(iv), jvertex(jv), inext(in), jnext(jn), edgeinfo(ifo){};
};


//the definition of vertex node
template<typename VERTEX_INFO, typename EDGE_INFO>
struct vertexNode_amundigraph{
    VERTEX_INFO *vertexinfo;  //the information of the vertex
    edgeNode_amundigraph<EDGE_INFO> *firstedge;  //point to the first edge that attached to this vertexNode_amundigraph
    vertexNode_amundigraph(VERTEX_INFO *vtin = nullptr, edgeNode_amundigraph<EDGE_INFO> *fe = nullptr) : 
                            vertexinfo(vtin), firstedge(fe){};
};

//the definition of adjacency nultilist undiagraph
template<typename VERTEX_INFO, typename EDGE_INFO>
class amundigraph{
  public:
    //constructor, 
    amundigraph(int Vertexnums = 0, int Edgenums = 0);

    //destructor
    ~amundigraph();
    
    //locate the position according the vertex infomation
    int locatepos(const VERTEX_INFO &veinfo) const;

    return_code creategraph(const string &inputfilename);

    //two versions of dfs
    void dfs_traverse_recursive(void (*visit)(const VERTEX_INFO &)) const;
    void dfs_traverse_iterator(void (*visit)(const VERTEX_INFO &)) const;

    //bfs
    void bfs_traverse_iterator(void (*visit)(const VERTEX_INFO &)) const;

  private:
    vertexNode_amundigraph<VERTEX_INFO, EDGE_INFO> *vertexset;
    int vertexnums;
    int edgenums;
};

template<typename VERTEX_INFO, typename EDGE_INFO>
amundigraph<VERTEX_INFO, EDGE_INFO>::amundigraph(int Vertexnums, int Edgenums):vertexnums(Vertexnums), edgenums(Edgenums){
    if(vertexnums != 0){
        vertexset = new vertexNode_amundigraph<VERTEX_INFO, EDGE_INFO>[vertexnums];
    }
}

template<typename VERTEX_INFO, typename EDGE_INFO>
amundigraph<VERTEX_INFO, EDGE_INFO>::~amundigraph(){
    if(vertexnums){
        delete[] vertexset;
        vertexset = nullptr;
    }
}

template<typename VERTEX_INFO, typename EDGE_INFO>
int amundigraph<VERTEX_INFO, EDGE_INFO>::locatepos(const VERTEX_INFO &veinfo)const{
    for (int i = 0; i < vertexnums; i++){
        if(*vertexset[i].vertexinfo == veinfo) return i;
    }
    return -1;
}

template<typename VERTEX_INFO, typename EDGE_INFO>
return_code amundigraph<VERTEX_INFO, EDGE_INFO>::creategraph(const string &inputfliename){
    //cout << "please input the vertex infomation: " << endl;
    ifstream in(inputfliename);
    if(!in.is_open())  cout << "open file error!" << endl;

    VERTEX_INFO temp;
    int count = 0;
    while(in >> temp){
        vertexset[count++].vertexinfo = new VERTEX_INFO(temp);
        if(in.get() == '\n') break;
    }

    //cout << "please input the edges: " << endl;
    VERTEX_INFO itemp, jtemp;
    EDGE_INFO edgeinfo;
    count = 0;
    while(count < edgenums){
        in >> itemp >> jtemp >> edgeinfo;
        in.get();
        edgeNode_amundigraph<EDGE_INFO> *newedge = new edgeNode_amundigraph<EDGE_INFO>(0, locatepos(itemp), locatepos(jtemp),
                                                               vertexset[locatepos(itemp)].firstedge,
                                                               vertexset[locatepos(jtemp)].firstedge,
                                                               new EDGE_INFO(edgeinfo));
        vertexset[locatepos(itemp)].firstedge = newedge;
        vertexset[locatepos(jtemp)].firstedge = newedge;
        count++;
    }
    //cout << "construct succeessfully!" << endl;
    in.close();
    return successful;
}

template<typename VERTEX_INFO, typename EDGE_INFO>
void amundigraph<VERTEX_INFO, EDGE_INFO>::dfs_traverse_recursive(void(*visit)(const VERTEX_INFO&))const{
    bool visited[vertexnums] = {0};

    function<void(int)> dfs;
    dfs = [&](int pos) -> void {
        visited[pos] = true;
        visit(*vertexset[pos].vertexinfo);
        edgeNode_amundigraph<EDGE_INFO> *move = vertexset[pos].firstedge;
        while(move){
            if(move->ivertex == pos && !visited[move->jvertex]){
                dfs(move->jvertex);
                move = move->inext;
            }
            else if(move->jvertex == pos && !visited[move->ivertex]){
                dfs(move->ivertex);
                move = move->jnext;
            }
            else return;
        }
    };

    for (int i = 0; i < vertexnums; i++){
        if(!visited[i]) dfs(i);
    }
}

template<typename VERTEX_INFO, typename EDGE_INFO>
void amundigraph<VERTEX_INFO, EDGE_INFO>::dfs_traverse_iterator(void(*visit)(const VERTEX_INFO&))const{
    bool visited[vertexnums] = {0};
    linkstack<int> ls;
    for (int i = 0; i < vertexnums; i++){
        if(!visited[i]) ls.push(i);

        int temp = 0;
        while(!ls.empty()){
            ls.pop(temp);
            if(!visited[temp]){
                visited[temp] = true;
                visit(*vertexset[temp].vertexinfo);
                edgeNode_amundigraph<EDGE_INFO> *nowedge = vertexset[temp].firstedge;
                while(nowedge){
                    if(nowedge->ivertex == temp && !visited[nowedge->jvertex]){
                        ls.push(nowedge->jvertex);
                        nowedge = nowedge->inext;
                    }
                    else if(nowedge->jvertex == temp && !visited[nowedge->ivertex]){
                        ls.push(nowedge->ivertex);
                        nowedge = nowedge->jnext;
                    }
                    else break;
                }
            }
        }
    }
}

template<typename VERTEX_INFO, typename EDGE_INFO>
void amundigraph<VERTEX_INFO, EDGE_INFO>::bfs_traverse_iterator(void(*visit)(const VERTEX_INFO&))const{
    bool visited[vertexnums] = {0};
    linkqueue<int> lq;
    for(int i=0; i<vertexnums; i++){
        if(!visited[i]){
            lq.push(i);
            int temp = 0;
            while(!lq.empty()){
                //pop the first vertex
                lq.pop(temp);

                //visited this vertex if not before
                if(!visited[temp]){

                    visited[temp] = true;
                    visit(*vertexset[temp].vertexinfo);

                    //push the neighbor node behind the queu
                    edgeNode_amundigraph<EDGE_INFO> *nowedge = vertexset[temp].firstedge;
                    while(nowedge){
                        if(nowedge->ivertex == temp && !visited[nowedge->jvertex]){
                            lq.push(nowedge->jvertex);
                            nowedge = nowedge->inext;
                        }
                        else if(nowedge->jvertex == temp && !visited[nowedge->ivertex]){
                            lq.push(nowedge->ivertex);
                            nowedge = nowedge->jnext;
                        }
                        else break;
                    }
                }
            }
        }
    }
}





