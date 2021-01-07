#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

    
	if (A == NULL) return -1;
	if (b == NULL) return -2;
    printf("\nMacierz początkowa A:\n");
	printToScreen(A);
    printf("Macierz wyrazów wolnych B:\n");
	printToScreen(b);
    printf("__________________________________________\n");

    if(A->r != A->c){
        printf("Macierz początkowa A nie jest macierzą kwadratową!\n\n");
        return -3;
    }

    if(A->r != b->r){
        printf("Liczba wierszy macierzy A nie zgadza się z liczbą wierszy macierzy wyrazów wolnych b!\n\n");
        return -4;
    }

	res = eliminate(A,b);
    if(res==1){
        printf("Podana macierz jest macierzą osobliwą!\n\n");
        return 1;        
    }     
 
    printf("Macierz A po zastosowaniu eliminacji:\n");  
        printToScreen(A);
    printf("Macierz B po zastosowaniu eliminacji:\n");
        printToScreen(b);

	x = createMatrix(b->r, 1);
	if (x != NULL) {
		res = backsubst(x,A,b);

        printf("\nMacierz wyników X:\n");
		printToScreen(x);
	  freeMatrix(x);
	} else {
					fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
