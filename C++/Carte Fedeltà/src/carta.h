/*******************************/
/* HEADER MODULO "carta" 	   */
/*******************************/

struct carta{
	char nome[40];
	int punti;
};

typedef carta tipo_inf;


int compare(tipo_inf,tipo_inf);
void copy(tipo_inf&,tipo_inf);
void print(tipo_inf);
