#ifndef EXERCISE_2_
#define EXERCISE_2_

#define randIntVal ((rand() % 20) +1)
#define randFloVal ((double)rand()/(double)/RAND_MAX) + (double) ((rand() % 20)+1)

int height, width;

void printMatrix(void **ptr, int height, int width);
void printVector(void *ptr, int length);

double* randomVector(int length, double *resultVector);
double** randomMatrix(int height, int width, double **resultMatrix);

void multiplyConstantWithVector(double constant, double *vector, int length);
double* multiplyMatrixWithVector(double **matrix, int height, int width,
	double *vector, int length, double *resultVector);
double* transposeVector(double *vector, int length);
double* multiplyVectorWithVector(double *vec1, double vec2*, int length);


#endif