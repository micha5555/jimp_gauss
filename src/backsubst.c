#include "backsubst.h"
#include <stdio.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {

	int n = b->r;
	int w, k;

	for( int i = 0; i < mat->r; i++)
		if( mat->data[i][i] == 0 ){
			printf("------Zero na diagonali-------\n");
			return 1;
			}

	if( mat->r != mat->c || b->r != mat->r || b->c != 1 ){
		printf("--------Nieprawidlowa macierz-----------\n");
		return 2;
	}

	for( w = n-1; w >= 0; w-- ){
		double suma = 0; 
		for( k = w +1; k < n; k++ )
			suma += mat->data[w][k] *  x->data[k][0] ;
	  	x->data[w][0] = ( b->data[w][0] - suma ) / mat->data[w][w];
	}

	return 0;
}
