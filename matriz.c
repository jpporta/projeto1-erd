#include "lista.h"
#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float **initMatriz(int x, int y) {
  float **M;
  M = (float **)malloc(x * sizeof(float *));
  for (int i = 0; i < x; i++) {
    M[i] = (float *)malloc(y * sizeof(float));
  }
  return M;
}
void eliminaMatriz(float **dobby, int x) {
  for (int i = 0; i < x; i++) {
    free(dobby[i]);
  }
}
void imprime(float **M, int x, int y) {
  for (int j = 0; j < y; j++) {
    for (int i = 0; i < x; i++) {
      if (j != 0)
        printf(" ");
      printf("%4.2f", M[i][j]);
    }
    printf("\n");
  }
}
