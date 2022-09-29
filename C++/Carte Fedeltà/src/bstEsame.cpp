//============================================================================
// Name        : bstEsame.cpp
// Author      : Sciadi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>

#include "bst.h"

using namespace std;



int main() {
	int dim, n_carta;
	bst tree = NULL;
	carta C;
	const char* nome ="Ciccio";
	bnode* node;
	cout << "Quante carte?" << endl; // prints !!!Hello World!!!
	//cin>>dim;
	dim = 7;





	for (int i=0;i<dim;i++){
		strcpy(C.nome, nome);
		C.punti = 30 + i;
		/*	cout<<"n carta:\t ";*/
		cin>>n_carta;/*
		cout<<"nome:\t ";
		cin>>C.nome;
		cout<<"punti:\t ";
		cin>>C.punti;*/

		node = bst_newNode(n_carta,C);
		bst_insert(tree,node);

	}

	stampa(tree);
	return 0;
}
