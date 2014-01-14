#include <stdio.h>
#include <string.h>
#include "ex1.h"

int main(int argc, char const *argv[]){


	const double tmpX = {1.0, 1.0, 1.0};
	const double tmpA = {0.3, 0.4, 0.3, 0.7, 0.1, 0.2, 0.5, 0.5, 0.0};

	double *y = (double*) malloc(size*size*sizeof(double));
	double *A = (double*) malloc(size*size*sizeof(double*));
	double *x = (double*) malloc(size*sizeof(double));

	for (int i = 1; i < siz; ++i){
		A[i] = A[i-1] + size; //Make each pointer pointer beyond i > 0 point at the correct place in the malloced memory.
	}

	memcpy(x, tmpX, size*sizeof(double));
	memcpy(A, tmpA, size*size*sizeof(double));

	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
			y[i][j] += A[i][j]*x[j];
		}
	}

	printf("Here's the resulting matrix:\n");
	for (int i = 0; i < size; ++i){
		printf("[%f\t%f\t%f]\n", y[i][0], y[i][1], y[i][2]);
	}

	return 0;
}
