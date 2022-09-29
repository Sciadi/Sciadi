//============================================================================
// Name        : es3bst.cpp
// Author      : Sciadi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include "grafo.h"
#include "ospedale.h"
using namespace std;
/**
 * Funzione che stampa
 * @param G grafo
 * @param P array di persone
 */
void stampa(graph G, persona* P){
	adj_list l;
	for(int i=1; i<=get_dim(G); i++){
		if(P[i-1].ruolo == 'M'){
			l=get_adjlist(G,i);
			while(l!=NULL){
				cout<<"Medico "<<(i)<<" cura paziente "<<get_adjnode(l)<<endl;
				l = get_nextadj(l);
			}
		}
	}
}

int main(int argc, char* argv[]) {
	const char* PATH = argv[1];
	persona* P;
	graph G;
	int n_nodi, n_archi, id;
	int src,dest;


	ifstream file(PATH);


	if(file){
		cout<<"file aperto\n";
	}
	else{
		cerr<<"errore\n";
	}
	file>>n_nodi;
	file>>n_archi;
	G = new_graph(n_archi);

	P = new persona[n_nodi];
	for(int i=0; i<n_nodi;i++){
		file>>id;
		file>>P[id-1].ruolo;
		file>>P[id-1].stato;
	}

	for(int i=0; i<get_dim(G); i++){
		file>>src;
		file>>dest;
		add_edge(G, src, dest, 0);
	}

	file.close();
	stampa(G,P);



	return 0;
}
