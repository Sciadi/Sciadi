//============================================================================
// Name        : Es2-grafo.cpp
// Author      : Sciadi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string.h>
#include "grafi.h"
#include "node.h"
using namespace std;

void stampa(graph G){
	adj_list list;
	int dim = get_dim(G);
	for (int i=1;i<=dim;i++){
		list = get_adjlist(G,i);

		while (list != NULL){
			cout<<i<<" ";
			cout<<get_adjnode(list);
			cout<<"\n";
			list = get_nextadj(list);

		}

		cout<<endl;

	}
}

void stampa2(graph G, node *N){
	adj_list list;
	int check;
	int dim = get_dim(G);
	for (int i=1;i<=dim;i++){
		list = get_adjlist(G,i);
		while (list != NULL){
			cout<<N[i-1].cont<<" ";
			check = N[i-1].tipo- N[get_adjnode(list)-1].tipo;
			if (check == 0){
				cout<<"FOLLOW ";
			}
			else check < 0 ? cout<<"OWNER " : cout<<"LIKE ";

			cout<<N[get_adjnode(list)-1].cont<<endl;
			list = get_nextadj(list);
		}
		cout<<endl;
	}
}

int main(int argc, char* argv[]) {
	const char* GRAPH_INFO = argv[1];
	const char* NODES_INFO = argv[2];
	graph G;
	int dim, src, dest;
	int i;
	bool a = true;
	string tweet,type;
	node* N;
	ifstream file(GRAPH_INFO);



	file>>dim;

	G = new_graph(dim);

	while ((file>>src) && (file>>dest)){
			add_arc(G,src,dest,0);
		}
	//stampa(G);
	file.close();
	// ES 2

	file.open(NODES_INFO);
	N = new node[dim];

	i = 0;
	while(a){
			getline(file,tweet);
			getline(file, type);

			if (!file.eof()){
				strcpy(N[i].cont, tweet.c_str());
				N[i].tipo = type[0];
				i++;
			}
			else a=false;
		}

	stampa2(G,N);
	return 0;
}
