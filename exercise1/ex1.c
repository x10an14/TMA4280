#include <stdio.h>	//printf
#include <stdlib.h>	//malloc
#include <string.h>	//memcpy
#include "ex1.h"

int main(int argc, char const *argv[]){
	const double tmpX[] = {1.0, 1.0, 1.0};
	const double tmpA[] = {0.3, 0.4, 0.3, 0.7, 0.1, 0.2, 0.5, 0.5, 0.0};

	double *y = (double*) malloc(size*sizeof(double));
	double **A = (double**) malloc(size*sizeof(double*));
	A[0] = malloc(size*size*sizeof(double));
	double *x = (double*) malloc(size*sizeof(double));

	for (int i = 1; i < size; ++i){
		A[i] = A[i-1] + size; //Make each pointer beyond i > 0 point at the correct place in the malloced memory.
	}

	memcpy(x, tmpX, size*sizeof(double));
	memcpy(A[0], tmpA, size*size*sizeof(double));

	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
			y[i] += A[i][j]*x[j];
		}
	}

	printf("Here's the resulting matrix:\n");
	printf("[%f\t%f\t%f]\n", y[0], y[1], y[2]);

	free(A[0]);
	free(A);
	free(x);

	return 0;
}
