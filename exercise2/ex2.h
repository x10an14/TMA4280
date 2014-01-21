#ifndef EXERCISE_2_
#define EXERCISE_2_

#define randIntVal ((rand() % 20) +1)
#define randFloVal ((double)rand()/((double)RAND_MAX)) + (double) ((rand() % 20)+1)

int height, width;

void printMatrix(double **ptr, int height, int width);
void printVector(double *ptr, int length);

void randomVector(int length, double *resultVector);
void randomMatrix(int height, int width, double **resultMatrix);

void multiplyConstantWithVector(double constant, double *vector, int length);
void multiplyMatrixWithVector(double **matrix, int height, int width,
	double *vector, int length, double *resultVector);
void transposeVector(double *vector, int length, double *resultVector);
void multiplyVectorWithVector(double *vec1, double *vec2, int length, double *resultVector);

#endif