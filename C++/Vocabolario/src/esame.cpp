//============================================================================
// Name        : Compito.cpp
// Author      : Sciadi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string.h>
#include "liste.h"
#include "tipo.h"

// strcpy(dest,src)
// file txt nella cartella src per avviare ./[programma].exe file1, file2..
using namespace std;

void vocabolario(lista *vocabolario, char *parola)
{
	int idx = parola[0] - 'A';
	elem *e = new_elem(parola);

	lista l = vocabolario[idx];
	/**
	 * Controllo che la parola non sia presente nella lista
	 */
	while (l != NULL)
	{
		if (strcmp(head(l), parola) == 0)
		{
			cerr << "Errore, parola gi� presente\n";
			return;
		}
		l = tail(l);
	}

	vocabolario[idx] = insert_elem(vocabolario[idx], e);
	return;
}

void stampa(lista *vocabolario)
{
	lista l;
	for (int i = 0; i < 26; i++)
	{
		l = vocabolario[i];
		while (l != NULL)
		{
			print(head(l));
			l = tail(l);
		}
	}
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cerr << "Errore, manca file in input\n";
		return 0;
	}
	const char *PATH = argv[1];
	int n_parole;
	char* parola;
	lista V[26];
	ifstream file(PATH);
	if (file)
	{
		cout << "file aperto\n";
	}
	else
	{
		cerr << "errore\n";
	}

	file >> n_parole;

	for (int i = 0; i < 26; i++)
	{
		V[i] = NULL;
	}

	for (int i = 0; i < n_parole; i++)
	{
		parola = new char;
		file >> parola;

		vocabolario(V, parola);
		cout << "Parola aggiunta\n";
	}

	file.close();
	stampa(V);
}
