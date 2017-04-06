#include "lista.h"
#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//***************************************************************************************************
// CRIAR MATRIZ
void criarMatri(struct tLista **pLista, char *nome, int y, int x) {
  if (*pLista == NULL) {
    *pLista = (tLista *)malloc(sizeof(tLista));
    strcpy((*plista)->nome, nome);
    (*plista)->mat = (float *)malloc(sizeof(float) * y * x);
  }
  criarMatriz((*pLista)->prox, nome, y, x);
}
//***************************************************************************************************
// DESTRUIR MATRIZ
void destruirMatriz(struct tLista **pLista, char *nome) {}
//***************************************************************************************************
// IMPRIMIR MATRIZ
void imprimirMatriz(struct tLista **pLista, char *nome) {}
//***************************************************************************************************
// ATRIBUIR ELEMENTO
void atribuirElemento(struct tLista **pLista, char *nome, int y, int x,
                      float num) {}
//***************************************************************************************************
// ATRIBUIR LINHA
void atribuirLinha(struct tLista **pLista, char *nome, int y) {}
//***************************************************************************************************
// ATRIBUIR COLUNA
void atribuirColuna(struct tLista **pLista, char *nome, int x) {}
//***************************************************************************************************
// TRANSPOR MATRIZ
void transporMatriz(struct tLista **pLista, char *nome, char *nomeR) {}
//***************************************************************************************************
// SOMAR MATRIZ
void somarMatriz(struct tLista **pLista, char *nome1, char *nome2,
                 char *nomeR) {}
//***************************************************************************************************
// DIVIDIR MATRIZ
void dividirMatriz(struct tLista **pLista, char *nome1, char *nome2,
                   char *nomeR) {}
//***************************************************************************************************
// MULTIPLICAR MATRIZ
void multiplicarMatriz(struct tLista **pLista, char *nome1, char *nome2,
                       char *nomeR) {}
//***************************************************************************************************
// MULTIPLICAR ELEMENTOS
void multiplicarElem(struct tLista **pLista, char *nome1, char *nome2,
                     char *nomeR) {}
//***************************************************************************************************
