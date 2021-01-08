#include "gauss.h"
#include <math.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
void putHighest(Matrix*, Matrix*, int);
int eliminate(Matrix *mat, Matrix *b){
   
    int ir, ic; //ir- iterator po wierszach; ic- iterator po kolumnach
    ir=1;
    ic=0;
    int g=1;
    for(ic=0; ic<mat->c; ic++){
        putHighest(mat, b, ic);
        
        if(mat->data[ic][ic]==0)
            return 1;

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

void putHighest(Matrix *mat, Matrix *b, int top){
    double highestValue=fabs(mat->data[top][top]);
    int lineOfHighest=top;
    int currentLine;
    
    for(currentLine=top+1; currentLine<mat->r; currentLine++){
        if( fabs(mat->data[currentLine][top]) > highestValue ){
            highestValue=fabs(mat->data[currentLine][top]);
            lineOfHighest=currentLine;
        }
    }

    if(lineOfHighest != top){
        int col;
        for(col=0; col<mat->c; col++){
            double tmp= mat->data[top][col];
            mat->data[top][col] = mat->data[lineOfHighest][col];
            mat->data[lineOfHighest][col]=tmp;
        }

        double tmp2 = b->data[top][0];
        b->data[top][0]=b->data[lineOfHighest][0];
        b->data[lineOfHighest][0]=tmp2;
    }
    
}

