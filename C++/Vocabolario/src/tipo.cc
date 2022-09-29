#include "tipo.h"
#include <iostream>
#include <string.h>
using namespace std;
int compare(tipo_inf i1,tipo_inf i2){
	return strcmp(i1,i2);
}

void copy(tipo_inf& dest,tipo_inf src){

	int a = sizeof(&src);
	// size of non è strettamente necessario
	// potevo anche mettere un valore prefissato massimo
	// tipo 20 per la dimensione della parola
	dest = new char[a+1];
	strcpy(dest,src);


}

void print(tipo_inf i){
	cout<<i<<endl;
}
