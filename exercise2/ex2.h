#ifndef EXERCISE_2_
#define EXERCISE_2_

#define randIntVal ((rand() % 20) +1)
#define randFloVal ((double)rand()/(double)/RAND_MAX) + (double) ((rand() % 20)+1)

int height, width;

void printMatrix(void **ptr, int height, int width);
void printVector(void *ptr, int length);

double* randomVector(int length);
double** randomMatrix(int height, int width);

extern const double *vecX, *vecA, *vecB, *vecY, *vecAlpha;
extern const double **matA;

#endif