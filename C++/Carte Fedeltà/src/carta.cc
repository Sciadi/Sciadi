#include <iostream>
#include "carta.h"
using namespace std;

int compare(tipo_inf i1,tipo_inf i2){
	return i1.punti-i2.punti;
}
void copy(tipo_inf& dest,tipo_inf src){
	dest = src;
}
void print(tipo_inf info){
	cout<<info.nome<<endl;
	cout<<info.punti<<endl;
}
