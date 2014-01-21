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

	double userConst = argv[1];

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

void printMatrix(void **ptr, int height, int width){

}

void printVector(void *ptr, int length){

}

double* randomVector(int length){

}

double** randomMatrix(int height, int width){

}