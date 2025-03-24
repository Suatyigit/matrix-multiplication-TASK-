#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM2 2
#define NUM3 3

int A[NUM2][NUM3];
int B[NUM3][NUM2];
int C[NUM2][NUM2];

void RandomGenerate() {
 
	for (size_t i = 0; i < NUM2; i++) {
		for (size_t j = 0; j < NUM3; j++) {
			A[i][j] = rand() % 100 + 1;
	    }
    }

	for (size_t i = 0; i < NUM3; i++) {
		 for (size_t j = 0; j < NUM2; j++) {
			 B[i][j] = rand() % 100 + 1;
	     }
    }
}

void PrintMatrix1( int  ROWS , int COLS ,int matrix[][NUM3]) {
	
	for(size_t i = 0 ; i < ROWS ; i++ ){
		for (size_t j = 0; j < COLS; j++) {
			printf("%d ", matrix[i][j]);
		}
		puts("");
	}
	puts("");
}

void PrintMatrix2(int  ROWS, int COLS, int matrix[][NUM2]) {

	for (size_t i = 0; i < ROWS; i++) {
		for (size_t j = 0; j < COLS; j++) {
			printf("%d ", matrix[i][j]);
		}
		puts("");
	}
	puts("");
}

void MultiMatrix() {
	for (size_t i = 0; i < NUM2; i++) {       
		for (size_t j = 0; j < NUM2; j++) {   
			C[i][j] = 0;  
			for (size_t k = 0; k < NUM3; k++) {  
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}


int main() {
	srand(time(NULL));
	RandomGenerate();
	MultiMatrix();

	printf("A matrixi elemanlari :\n");
	PrintMatrix1(NUM2, NUM3, A);
	
	printf("B matrixi elemanlari :\n");
    PrintMatrix2(NUM3, NUM2, B);
	
	printf("A(2x3) x B(3)(2) matrixlerinin çarpma işleminin sonucu :\n");
	PrintMatrix2(NUM2 , NUM2 ,C);

	printf("\nBoyut uyusmazligindan oturu toplama islemi yapilamaz (Eger koda yazilirsa hata ile karsilasilacaktir)\n\n");
}
