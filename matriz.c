#include "lista.h"
#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//***************************************************************************************************
// INITMATRIZ
// Usado em criar matriz
float **initMatriz(int x, int y) {
  float **M;
  M = (float **)malloc(x * sizeof(float *));
  for (int i = 0; i < x; i++) {
    M[i] = (float *)malloc(y * sizeof(float));
  }
  return M;
}
//***************************************************************************************************
// ELIMINAR MATRIZ
// USADO EM DESTRUIR MATRIZ
void eliminaMatriz(float **dobby, int x) {
  for (int i = 0; i < x; i++) {
    free(dobby[i]);
  }
}
//***************************************************************************************************
// IMPRIME
// UTILIZADO PARA IMPRIMIR MATRIZ DADA
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
//***************************************************************************************************
// MULT
// UTILIZADO PARA MULTIPLICAR MATRIZ
float **mult(float *mat1, float *mat2, int x1, int y1, int x2, int y2) {
  float matR;
  int aux = 0, aux1 = 0, aux2 = 0, i = 0, j = 0, k = 0;
  if (y1 == x2) {
    for (i = 0; i < x1; i++) {
      for (j = 0; j < y2; j++) {
        matR[i][j] = 0;
      }
    }
    // printf("entre com a primeira matriz\n");
    // for (i = 0; i < 3; i++)
    //{
    //	for (j = 0; j < 4; j++)
    //	{
    //		scanf("%i", &m1[i][j]);
    //	}
    //}
    // printf("entre com a segunda matriz\n");
    // for (i = 0; i < 4; i++)
    //{
    //	for (j = 0; j < 4; j++)
    //	{
    //		scanf("%i", &m2[i][j]);
    //	}
    //}
    // i = 0; j = 0;
    while (i < x1 && k < x2 && j < y2) {
      matR[i][j] = matR[i][j] + (mat1[i][k] * mat2[k][j]);
      aux++;
      aux1++;
      k++;
      if (k > x2 - 1) {
        k = 0;
      }
      if (aux > x2 - 1) {
        aux2++;
        aux = 0;
      }
      if (aux1 > x2 - 1) {
        j++;
        aux1 = 0;
      }
      if (aux2 > y2 - 1) {
        i++;
        aux2 = 0;
      }
      if (j > y2 - 1) {
        j = 0;
      }
    }
    // printf("resultado\n");
    // for (i = 0; i < x1; i++)
    //{
    //	for (j = 0; j < y2; j++)
    //	{
    //		printf("%i ", matR[i][j]);
    //	}
    //	printf("\n");
    //}
    return matR;
  } else {
    return NULL;
  }
}
