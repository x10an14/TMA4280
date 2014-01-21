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

	//Height is always treated as length, and vica versa



	return 0;
}

void printMatrix(double **ptr, int height, int width){
	for (int i = 0; i < height; ++i){
		printf("[");
		for (int j = 0; j < width-1; ++j){
			printf("%.2f,\t", ptr[i][j]);
		}
		printf("%.2f]\n", ptr[i][width-1]);
	}
}

void printVector(double *ptr, int length){
	printf("[");
	for (int i = 0; i < length-1; ++i){
		printf("%.2f,\t", ptr[i]);
	}
	printf("%.2f]\n", ptr[length-1]);
}

void randomVector(int length, double *resultVector){
	for (int i = 0; i < length; ++i){
		resultVector[i] = randFloVal;
	}
}

void randomMatrix(int height, int width, double **resultMatrix){
	for (int i = 0; i < height; ++i){
		for (int j = 0; j < width; ++j){
			resultMatrix[i][j] = randFloVal;
		}
	}
}

void multiplyConstantWithVector(double constant, double *vector, int length){
	for (int i = 0; i < length; ++i){
		vector[i] *= constant;
	}
}

void multiplyMatrixWithVector(double **matrix, int height, int width,
	double *vector, int length, double *resultVector){

}

void transposeVector(double *vector, int length, double *resultVector){

}

void multiplyVectorWithVector(double *vec1, double *vec2, int length, double *resultVector){

}
