#include "gauss.h"
#include <math.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
   
     int ir, ic; //ir- iterator po wierszach; ic- iterator po kolumnach

    ir=1;
    ic=0;
    int g=1;
    for(ic=0; ic<mat->c; ic++){
        
	int max = ic;
	for( int p = ic+1; p < mat->r ; p++ ){
		if( fabs( mat->data[p][ic] ) > fabs( mat->data[max][ic] ) ){
			max = p;
		}
	}

	if( max != ic ){
		double *tmp = mat->data[ic];
		mat->data[ic] = mat->data[max];
		mat->data[max] = tmp;
		
		tmp = b->data[ic];
		b->data[ic] = b->data[max];
		b->data[max] = tmp;
	}



	for(ir=g; ir<mat->r; ir++){
            double mnoznik=mat->data[ir][ic]/mat->data[ic][ic];
            int col=0;
            for(col=0; col<mat->c; col++){
                mat->data[ir][col]=mat->data[ir][col] - (mnoznik * mat->data[ic][col]);
            }
        b->data[ir][0]=b->data[ir][0] - (mnoznik * b->data[ic][0]);
        }
        g++;
    }
 
	for(ir=0, ic=0; ir<mat->r && ic<mat->c; ir++, ic++){
    	    if(mat->data[ir][ic]==0)
        	    return 1;
    }

		return 0;

}

