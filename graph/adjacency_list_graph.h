//the adjacency list implement of graph (undi & di)
#include "../include.h"
#include "../stack/link_stack.h"
#include "../queue/link_queue.h"


//the definition of adjacency vertex
template<typename INFO>
struct adjacency_vertex{
    int vertexpos;  //the position of vertex that attached to this vertex
    adjacency_vertex<INFO> *next;
    INFO *info;
    adjacency_vertex(int Vertexpos = -1, adjacency_vertex<INFO> *Next = nullptr, INFO *Info = nullptr) : 
                            vertexpos(Vertexpos), next(Next), info(Info){};
};

//the definition of vertex
template<typename VERTEX_INFO, typename INFO>
struct vertexNode_algraph{
    VERTEX_INFO *vertexinfo;
    adjacency_vertex<INFO> *firstvertex; //point to the first vertex that attached to its
    vertexNode_algraph() : vertexinfo(nullptr), firstvertex(nullptr){};
};

//the definition of adjacency list graph class
template<typename VERTEX_INFO, typename INFO>
class algraph{
  public:
    algraph(int Vertexnums = 0, int Edgenums = 0);
    ~algraph();

    int getvertexnums() const { return vertexnums; };
    int getedgenums() const { return edgenums; };
    vertexNode_algraph<VERTEX_INFO, INFO>* getvertexset() const { return vertexset; };

    int locate(const VERTEX_INFO &) const;
    void creategraph(const string &);

    void dfs_traverse_recursive(function<void(const VERTEX_INFO &)> &) const;
    void dfs_traverse_iterator(function<void(const VERTEX_INFO &)> &) const;

    void bfs_traverse_iterator(function<void(const VERTEX_INFO &)> &) const;

    algraph<VERTEX_INFO, INFO> *get_reverse_graph() const;
    void get_strong_connected_component() const;

    void prime_mst() const;

    void cyclic_judge_undigraph() const;
    void digraph_toposort_judgecyclic()const;
    void cyclic_judge_digraph_dfs() const;

    void critical_path_digraph() const;
    void critical_path_digraph_mythought() const;

  private:
    vertexNode_algraph<VERTEX_INFO, INFO> *vertexset;
    int vertexnums;
    int edgenums;
};

template<typename VERTEX_INFO, typename INFO>
inline algraph<VERTEX_INFO, INFO>::algraph(int Vertexnums, int Edgenums):vertexnums(Vertexnums), edgenums(Edgenums){
    if(vertexnums){
        vertexset = new vertexNode_algraph<VERTEX_INFO, INFO>[vertexnums];
    }
}

template<typename VERTEX_INFO, typename INFO>
inline algraph<VERTEX_INFO, INFO>::~algraph(){
    if(vertexset){
        delete[] vertexset;
        vertexset = nullptr;
    }
}

template<typename VERTEX_INFO, typename INFO>
inline int algraph<VERTEX_INFO, INFO>::locate(const VERTEX_INFO &vertexinfo)const{
    for (int i = 0; i < vertexnums; i++){
        if(*vertexset[i].vertexinfo == vertexinfo) return i;
    }

    return -1;
}

template<typename VERTEX_INFO, typename INFO>
void algraph<VERTEX_INFO, INFO>::creategraph(const string &inputfilename){
    ifstream in(inputfilename);
    if(!in.is_open()) cout << "open file error!";

    int count = 0;
    VERTEX_INFO temp, vinfo;
    while(count < vertexnums){
        in >> temp;
        vertexset[count++].vertexinfo = new VERTEX_INFO(temp);
        in.get();
    }

    count = 0;
    while(count < vertexnums){
        in >> temp;
        INFO edgeinfo;
        while(in.get()!='\n'){
            in >> vinfo >> edgeinfo;
            adjacency_vertex<INFO> *newadjacancyvertex = new adjacency_vertex<INFO>(locate(vinfo),
                                                                                vertexset[locate(temp)].firstvertex,
                                                                                new INFO(edgeinfo));
            vertexset[locate(temp)].firstvertex = newadjacancyvertex;
        }
        count++;
    }
    in.close();
}

template<typename VERTEX_INFO, typename INFO>
void algraph<VERTEX_INFO, INFO>::dfs_traverse_recursive(function<void(const VERTEX_INFO&)> &visit)const{
    unsigned char visited[vertexnums] = {0};

    function<void(int)> dfs;
    dfs = [&](int pos) -> void {
        visited[pos] = 1;
        visit(*vertexset[pos].vertexinfo);
        adjacency_vertex<INFO> *move = vertexset[pos].firstvertex;
        while(move){
            if(!visited[move->vertexpos]){
                dfs(move->vertexpos);
            }
            move = move->next;
        }
    };

    for (int i = 0; i < vertexnums; i++){
        if(!visited[i]) dfs(i);
    }
}

template<typename VERTEX_INFO, typename INFO>
void algraph<VERTEX_INFO, INFO>::dfs_traverse_iterator(function<void(const VERTEX_INFO&)> &visit)const{
    unsigned char visited[vertexnums] = {0};

    linkstack<int> ls;
    for (int i = 0; i < vertexnums; i++){
        if(!visited[i]){
            ls.push(i);
            int temp = -1;
            while(!ls.empty()){
                ls.pop(temp);

                if(!visited[temp]){
                    visited[temp] = 1;
                    visit(*vertexset[temp].vertexinfo);

                    adjacency_vertex<INFO> *move = vertexset[temp].firstvertex;
                    while(move){
                        if(!visited[move->vertexpos]){
                            ls.push(move->vertexpos);
                        }
                        move = move->next;
                    }
                }
            }
        }
    }
}

template<typename VERTEX_INFO, typename INFO>
void algraph<VERTEX_INFO, INFO>::bfs_traverse_iterator(function<void(const VERTEX_INFO&)> &visit)const{
    unsigned char visited[vertexnums] = {0};

    linkqueue<int> lq;
    for (int i = 0; i < vertexnums; i++){
        if(!visited[i]){
            lq.push(i);
            int temp = -1;
            while(!lq.empty()){
                lq.pop(temp);
                if(!visited[temp]){
                    visited[temp] = 1;
                    visit(*vertexset[temp].vertexinfo);

                    adjacency_vertex<INFO> *move = vertexset[temp].firstvertex;
                    while(move){
                        if(!visited[move->vertexpos]){
                            lq.push(move->vertexpos);
                        }
                        move = move->next;
                    }
                }
            }
        }
    }
}

template<typename VERTEX_INFO, typename INFO>
algraph<VERTEX_INFO, INFO>* algraph<VERTEX_INFO, INFO>::get_reverse_graph()const{
    algraph<VERTEX_INFO, INFO> *reverse_graph = new algraph<VERTEX_INFO, INFO>(vertexnums,edgenums);

    for (int i = 0; i < vertexnums; i++){
        reverse_graph->getvertexset()[i].vertexinfo = new VERTEX_INFO(*vertexset[i].vertexinfo);

        adjacency_vertex<INFO> *move = vertexset[i].firstvertex;
        while(move){
            adjacency_vertex<INFO> *newnode = new adjacency_vertex<INFO>(i,
                                                                   reverse_graph->getvertexset()[move->vertexpos].firstvertex, move->info);
            reverse_graph->getvertexset()[move->vertexpos].firstvertex = newnode;
            move = move->next;
        }
    }

    return reverse_graph;
}

template<typename VERTEX_INFO, typename INFO>
void algraph<VERTEX_INFO, INFO>::get_strong_connected_component()const{
    algraph<VERTEX_INFO, INFO> *reverse_graph = get_reverse_graph();

    unsigned char visited[vertexnums] = {0};
    unsigned char finished[vertexnums] = {0};

    int count = 0;
    function<void(int)> dfs, reverse_dfs;
    dfs = [&](int pos) -> void {
        visited[pos] = 1;
        adjacency_vertex<INFO> *move = vertexset[pos].firstvertex;
        while(move){
            if(!visited[move->vertexpos]){
                dfs(move->vertexpos);
            }
            move = move->next;
        }
        finished[count++] = pos;
    };

    reverse_dfs = [&](int pos) -> void {
        visited[pos] = 1;
        cout << *vertexset[pos].vertexinfo << "  ";
        adjacency_vertex<INFO> *move = reverse_graph->getvertexset()[pos].firstvertex;
        while(move){
            if(!visited[move->vertexpos]){
                reverse_dfs(move->vertexpos);
            }
            move = move->next;
        }
    };

    for (int i = 0; i < vertexnums; i++){
        if(!visited[i]) dfs(i);
   }

   memset(visited, 0, vertexnums);

   count = 0;
   for (int i = vertexnums - 1; i>=0; i--)
   {
       if (!visited[finished[i]])
       {
           cout << "the" << count + 1 << "strong connected component : ";
           reverse_dfs(finished[i]);
           cout << endl;
       }

    }
}

template <typename VERTEX_INFO, typename INFO>
void algraph<VERTEX_INFO, INFO>::prime_mst() const{

    struct{
        int adjvex;
        int lowcost;
        void set(int a, int l){ adjvex = a; lowcost = l;};
    }distance[vertexnums];

    int nowpos = rand() % vertexnums;
    for (int i = 0; i < vertexnums; i++){
        distance[i].set(nowpos, -1);  //-1 represent can't reach the mst

        if(i != nowpos){
            adjacency_vertex<INFO> *move = vertexset[i].firstvertex;
            while(move){
                if(move->vertexpos == nowpos){
                    distance[i].set(nowpos, *move->info);
                    break;
                }
                move = move->next;
            }
        }
        else distance[i].set(nowpos, 0); //0 means in the mst
    }

    for (int i = 1; i < vertexnums; i++){

        int minedge = INT_MAX, minpos = -1;
        for (int j = 0; j<vertexnums; j++){
            if(distance[j].lowcost != 0 && distance[j].lowcost != -1){
                minedge = minedge > distance[j].lowcost ? distance[minpos=j].lowcost : minedge;
            }
        }

        cout << *vertexset[distance[minpos].adjvex].vertexinfo << " --"
             << distance[minpos].lowcost << "--> " << *vertexset[minpos].vertexinfo << endl;

        distance[minpos].lowcost = 0;

        for (int i = 0; i < vertexnums; i++){
            if(i == minpos || distance[i].lowcost ==0 ) continue;

            adjacency_vertex<INFO> *move = vertexset[i].firstvertex;
            while(move){
                if(move->vertexpos == minpos){
                    if(distance[i].lowcost == -1 || distance[i].lowcost > *move->info){
                        distance[i].set(minpos, *move->info);
                        break;
                    }
                }
                move = move->next;
            }

        }
    }
}

template<typename VERTEX_INFO, typename INFO>
void algraph<VERTEX_INFO, INFO>::cyclic_judge_undigraph()const{
    //time complexity = O(|E|)
    unsigned char visited[vertexnums] = {0};

    //if have cyclic return true
    function<bool(int, int)> dfs;
    dfs = [&](int pos, int parent) -> bool {
        visited[pos] = 1;
        for (auto move = vertexset[pos].firstvertex; move; move = move->next){
            if(parent != -1 && move->vertexpos != parent && visited[move->vertexpos]) return true;

            if(!visited[move->vertexpos] && dfs(move->vertexpos, pos)) return true;
        }
        return false;
    };

    for(int i=0; i<vertexnums; i++){
        if(!visited[i]){
            if(dfs(i, -1)){
                cout << "cyclic!" << endl;
                return;
            }
        }
    }

    cout << "acyclic!" << endl;
}

template<typename VERTEX_INFO, typename INFO>
void algraph<VERTEX_INFO, INFO>::digraph_toposort_judgecyclic()const{
    //time complexity = O(||V| + |E|)
    unsigned char indegree[vertexnums] = {0};

    linkstack<int> ls; //save the 0 indegree vertex position

    //calculate indegree
    for (int i = 0; i < vertexnums; i++){
        for (auto move = vertexset[i].firstvertex; move; move = move->next){
            indegree[move->vertexpos]++;
        }
    }

    //init the 0 indegree into the stack
    for (int i = 0; i < vertexnums; i++){
        if(!indegree[i]) ls.push(i);
    }

    linkqueue<int> lq; //save the topologicalsortreult
    int temp = -1;
    while(!ls.empty()){
        ls.pop(temp);
        lq.push(temp);
        for (auto move = vertexset[temp].firstvertex; move; move = move->next){
            if(!(--indegree[move->vertexpos])) ls.push(move->vertexpos);
        }
    }

    if(lq.size() == vertexnums){
        cout << "topologicalsort result: \n";
        while(!lq.empty()){
            lq.pop(temp);
            cout << *vertexset[temp].vertexinfo << " ";
        }
        cout << endl;
        return;
    }

    cout << "cyclic!" << endl;
}

template<typename VERTEX_INFO, typename INFO>
void algraph<VERTEX_INFO, INFO>::cyclic_judge_digraph_dfs()const{

    //time complexity = O(|V| + |E|)
    unsigned char visited[vertexnums] = {0}, pre[vertexnums] = {0}, post[vertexnums] = {0};
    linkstack<int> ls;//save the topologicalsort result

    //return true indicates cyclic
    int count = 1;
    function<bool(int)> dfs;
    dfs = [&](int pos) -> bool {
        visited[pos] = 1;
        pre[pos] = count++;
        for (auto move = vertexset[pos].firstvertex; move; move = move->next){
            if(pre[move->vertexpos] != 0 && post[move->vertexpos] == 0) return true; //pre but not post means point to ancestor,so a cyclic

            if(!visited[move->vertexpos]){
                if(dfs(move->vertexpos)) return true;
            }
        }
        ls.push(pos);
        post[pos] = count++;
        return false;
    };

    for (int i = 0; i < vertexnums; i++){
        if(!visited[i]){
            if(dfs(i)){
                cout << "cyclic!" << endl;
                return;
            }
        }
    }

    cout << "topologicalsort result: \n";
    int temp = -1;
    while(!ls.empty()){
        ls.pop(temp);
        cout << *vertexset[temp].vertexinfo << " ";
    }
    cout << endl;
}

template<typename VERTEX_INFO ,typename INFO>
void algraph<VERTEX_INFO, INFO>::critical_path_digraph()const{
    //calculate the indegrees for every vertex
    unsigned char indegree[vertexnums] = {0};
    for (int i = 0; i<vertexnums; i++){
        for (auto move = vertexset[i].firstvertex; move; move = move->next){
            indegree[move->vertexpos]++;
        }
    }

    //ls save the zero indegree vertex's position
    //topols save the topologicalsort result, to use in calculate the lv later
    linkstack<int> ls, topols;
    for (int i = 0; i < vertexnums; i++){
        if(!indegree[i]) ls.push(i);
    }

    //ve save vertex's earliest start time
    int ve[vertexnums] = {0};
    int temp = 0;
    while(!ls.empty()){
        ls.pop(temp);
        topols.push(temp);
        for (auto move = vertexset[temp].firstvertex; move; move = move->next){
            if(!(--indegree[move->vertexpos])) ls.push(move->vertexpos);

            //select the max cost from the all paths
            ve[move->vertexpos] = max(ve[move->vertexpos], ve[temp] + *move->info);
        }
    }

    //get the reverse graph to caculate the lv
    vertexNode_algraph<VERTEX_INFO, INFO> reverse_graph[vertexnums];
    for (int i = 0; i < vertexnums; i++){
        reverse_graph[i].vertexinfo = new VERTEX_INFO(*vertexset[i].vertexinfo);
        for (auto move = vertexset[i].firstvertex; move; move = move->next){
            adjacency_vertex<INFO> *newnode = new adjacency_vertex<INFO>(i,
                                                    reverse_graph[move->vertexpos].firstvertex,
                                                    new INFO(*move->info));
            reverse_graph[move->vertexpos].firstvertex = newnode;
        }
    }

    //vl saves the vertex's lastest start time
    int vl[vertexnums];
    for (int i = 0; i < vertexnums; i++) vl[i] = ve[vertexnums-1];
    while(!topols.empty()){
        topols.pop(temp);
        for (auto move = reverse_graph[temp].firstvertex; move; move = move->next){
            vl[move->vertexpos] = min(vl[move->vertexpos], vl[temp] - *move->info);
        }
    }
 
    //calculate every edge's e and l
    for (int i = 0; i < vertexnums; i++){
        for (auto move = vertexset[i].firstvertex; move; move = move->next){
            cout << *vertexset[i].vertexinfo << "-->" << *vertexset[move->vertexpos].vertexinfo << endl;
            cout << "e: " << ve[i] << "   l: " << vl[move->vertexpos] - *move->info << endl;
        }
    }
}

template<typename VERTEX_INFO,typename INFO>
void algraph<VERTEX_INFO, INFO>::critical_path_digraph_mythought()const{
    int previous[vertexnums] = {-1};
    int ve[vertexnums] = {0};

    int indegree[vertexnums] = {0};
    for (int i = 0; i < vertexnums; i++){
        for (auto move = vertexset[i].firstvertex; move; move = move->next){
            indegree[move->vertexpos]++;
        }
    }

    linkstack<int> ls;
    for (int i = 0; i < vertexnums; i++){
        if(!indegree[i]) ls.push(i);
    }

    int temp = -1 ,last = -1;
    while(!ls.empty()){
        ls.pop(temp);
        last = temp;
        for(auto move = vertexset[temp].firstvertex; move; move = move->next){
            if(!(--indegree[move->vertexpos])) ls.push(move->vertexpos);

            if(ve[move->vertexpos] < ve[temp] + *move->info){
                ve[move->vertexpos] = ve[temp] + *move->info;
                previous[move->vertexpos] = temp;
            }
        }
    }

    while(last != -1){
        ls.push(last);
        last = previous[last];
    }

    while(!ls.empty()){
        ls.pop(temp);
        cout << *vertexset[temp].vertexinfo << "  ";
    }
}