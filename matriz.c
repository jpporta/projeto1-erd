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
float **mult(float **mat1, float **mat2, int x1, int y1, int x2, int y2) {
  float matR;
  int aux = 0, aux1 = 0, aux2 = 0, i = 0, j = 0, k = 0;
  if (y1 == x2) {
    for (i = 0; i < x1; i++) {
      for (j = 0; j < y2; j++) {
        matR[i][j] = 0;
      }
    }
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
    return matR;
  } else {
    return NULL;
  }
}
//***************************************************************************************************
// DIV
// UTILIZADO PARA DIVIDIR MATRIZ ELEMENTO A ELEMENTO
float **divi(float **mat1, float **mat2, int x1, int y1, int x2, int y2) {
  float matR;
  int i, j;
  if (x1 == x2 && y1 == y2) {

    for (i = 0; i < x1; i++) {
      for (j = 0; j < y2; j++) {
	if (mat2[i][j] == 0)
	{ 
		return NULL;
	}
	else
	{
        	matR[i][j] = mat1[i][j] / mat2[i][j];
	}
      }
    }
    return matR;
  } else {
    return NULL;
  }
}
//***************************************************************************************************
// TRANS
// UTILIZADO PARA TRANSPOR UMA MATRIZ
float **trans		(float **mat1, int x1, int y1) {
  float matR;
  int i, j;
    for (i = 0; i < x1; i++) {
      for (j = 0; j < y1; j++) {
	matR[j][i] = mat1[i][j]
      }
    }
    return matR;
}
//***************************************************************************************************
// SOMA
// UTILIZADO PARA SOMAR MATRIZ ELEMENTO  A ELEMENTO
float **soma(float *mat1, float *mat2, int x1, int y1, int x2, int y2) {
  float matR;
  int i, j;
  if (x1 == x2 && y1 == y2) {

    for (i = 0; i < x1; i++) {
      for (j = 0; j < y2; j++) {
        matR[i][j] = mat1[i][j] + mat2[i][j];
      }
    }
    return matR;
  } else {
    return NULL;
  }
}
//***************************************************************************************************
// MULT
// UTILIZADO PARA MULTIPLICAR MATRIZ ELEMENTO  A ELEMENTO
float **mult_elemento(float **mat1, float **mat2, int x1, int y1, int x2,
                      int y2) {
  float **matR;
  int i, j;
  if (x1 == x2 && y1 == y2) {
    for (i = 0; i < x1; i++) {
      for (j = 0; j < y2; j++) {
        matR[i][j] = mat1[i][j] * mat2[i][j];
      }
    }
    return matR;
  } else {
    return NULL;
  }
}
