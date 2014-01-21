#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //For time(NULL) function used for random seeds
#include "ex2.h"

int main(int argc, char const *argv[]){

	if (argc <= 1){
		printf("You inputted too few arguments! Try again!\n");
		return 1;
	}

	srand((unsigned)time(NULL));

	double userConst = atof(argv[1]);

	height = randIntVal; //Give a random number between 1-20
	while(height <= 1){
		height = randIntVal;
	}

	width = randIntVal;
	while(width <= 1){
		width = randIntVal;
	}

	//printf("%d\n%d\n", height, width);

	//Height is always treated as length, and vica versa!!

	double *a = (double*) calloc(height, sizeof(double));
	double *b = (double*) calloc(height, sizeof(double));
	double *x = (double*) calloc(height, sizeof(double));
	double *y = (double*) calloc(height, sizeof(double));
	double *tmp = (double*) calloc(height, sizeof(double));
	double **A = (double**) calloc(height, sizeof(double*));
	A[0] = calloc(height*width, sizeof(double));

	for (int i = 1; i < height; ++i){
		A[i] = A[i-1] + height;
	}

	double **vectors = calloc(4, sizeof(double*));
	vectors[0] = a;
	vectors[1] = b;
	vectors[2] = x;
	vectors[3] = y;

	// printf("Printing all vectors, their size is %d:\n", height);
	// for (int i = 0; i < 4; ++i){
	// 	printVector(vectors[i], height);
	// 	printf("\n");
	// }

	// printf("Printing the matrix, it's a %dx%d matrix:\n", height, width);
	// printMatrix(A, height, width);

	printf("Initializing values for vectors a and b of size %d:\n", height);
	for (int i = 0; i < 2; ++i){
		randomVector(height, vectors[i]);
		printVector(vectors[i], height);
	}

	printf("Initializing values for the %dx%d matrix:\n", height, width);
	randomMatrix(height, width, A);
	printMatrix(A, height, width);

	printf("\nx = a + gamma*b:\n");
	multiplyConstantWithVector(userConst, b, height, tmp);
	addTwoVectors(a, tmp, height, x);
	printVector(x, height);

	for (int i = 0; i < height; ++i){
		tmp[i] = 0.0;
	}

	printf("\ny = a + Ab:\n");
	multiplyMatrixWithVector(A, height, width, b, height, tmp);
	addTwoVectors(a, tmp, height, y);
	printVector(y, height);

	printf("\nx^T*y = %.2f\n", calculateVectorDotProduct(x, y, height));

	return 0;
}

void printMatrix(double **ptr, int height, int width){
	for (int i = 0; i < height; ++i){
		printf("[%.2f", ptr[i][0]);
		for (int j = 1; j < width; ++j){
			printf(",\t%.2f", ptr[i][j]);
		}
		printf("\t]\n");
	}
}

void printVector(double *ptr, int length){
	printf("[%.2f", ptr[0]);
	for (int i = 0; i < length; ++i){
		printf(",\t%.2f", ptr[i]);
	}
	printf("\t]\n");
}

void randomVector(int length, double *resultVector){
	for (int i = 0; i < length; ++i){
		resultVector[i] = randFloVal-1;
	}
}

void randomMatrix(int height, int width, double **resultMatrix){
	for (int i = 0; i < height; ++i){
		for (int j = 0; j < width; ++j){
			resultMatrix[i][j] = randFloVal-1;
		}
	}
}

void multiplyConstantWithVector(double constant, double *vec, int length, double *resultVector){
	for (int i = 0; i < length; ++i){
		resultVector[i] = vec[i]*constant;
	}
}

void multiplyMatrixWithVector(double **matrix, int height, int width, double *vec, int length, double *resultVector){
	for (int i = 0; i < height; ++i){
		for (int j = 0; j < width; ++j){
			resultVector[i] += matrix[i][j]*vec[j];
		}
	}
}

void addTwoVectors(double *vec1, double *vec2, int length, double *resultVector){
	for (int i = 0; i < length; ++i){
		resultVector[i] += vec1[i]+vec2[i];
	}
}

double calculateVectorDotProduct(double *vec1, double *vec2, int length){
	double temp = 0.0;

	for (int i = 0; i < length; ++i){
		temp += vec1[i]+vec2[i];
	}

	return temp;
}
