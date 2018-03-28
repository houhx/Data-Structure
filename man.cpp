#include "data_structure_test.h"
#include "bank_queueing_problem.h"
#include "string/sequence_string.h"
#include "matrix/sparse_matrix.h"
#include "graph/orthogonal_list_digraph.h"
#include "graph/adjacency_multilist_undigraph.h"
#include "graph/adjacency_list_graph.h"

void matrix_test_case(){
	//matrix's test case
	/*int m[6][7] = {{0,12,9,0,0,0,0},
	               {0,0,0,0,0,0,0},
				   {-3,0,0,0,0,14,0},
				   {0,0,24,0,0,0,0},
				   {0,18,0,0,0,0,0},
				   {15,0,0,-7,0,0,0}};

	int **p = new int*[6];
	for(int i=0; i<6; i++) p[i] = new int[7];
	for(int i=0; i<6; i++){
		for(int j=0; j<7; j++){
		   p[i][j] = m[i][j];
		}
	}
	smatrix sm(6, 7, p);
	sm.printm();
	cout << endl;

	smatrix transposem1, transposem2;
	sm.transposematrix_1(transposem1);
	transposem1.printm();
	cout << endl;
	sm.transposematrix_2(transposem2);
	transposem2.printm();
	int m[3][4]={{3,0,0,5},
	             {0,-1,0,0},
				 {2,0,0,0}};
	int n[4][2]={{0,2},{1,0},{-2,4},{0,0}};

	int **p = new int*[3];
	int **q = new int*[4];
	for(int i=0; i<3; i++) p[i] = new int[4];
	for(int i=0; i<4; i++) q[i] = new int[2];

	for(int i=0; i<3; i++){
		for(int j=0; j<4; j++) p[i][j] = m[i][j];
	}

	for(int i=0; i<4; i++){
		for(int j=0; j<2; j++) q[i][j] = n[i][j];
	}

	smatrix m1(3,4,p), m2(4,2,q), r;
	m1.printm();
	cout << endl;

	m2.printm();
	cout << endl;

	r.printm();
	cout << endl;

	multiplymatrix(r,m1,m2);
	r.printm();*/
}

void stop(){
	cout << endl;
	getchar();
}

int main(){
	//bank_simulation();

	//test();

	//matrix_test_case();

	algraph<string, int> graph(9,11);
	graph.creategraph("graph\\testcases\\critical_path_digraph_test.txt");
	graph.digraph_toposort_judgecyclic();
	stop();
	graph.cyclic_judge_digraph_dfs();
	stop();
	graph.critical_path_digraph();
	stop();
	graph.critical_path_digraph_mythought();
	stop();
	//function<void(const int&)> print = [](const int &i) -> void { cout << i << " "; };
	
}
