#include "lista.h"
#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//***************************************************************************************************
// CRIAR MATRIZ
void criarMatriz(struct tLista **pLista, char *nome, int y, int x) {
  if (*pLista == NULL) {
    *pLista = (struct tLista *)malloc(sizeof(struct tLista));
    strcpy((*pLista)->nome, nome);
    (*pLista)->sizex = x;
    (*pLista)->sizey = y;
    (*pLista)->prox = NULL;
    initMatriz(&(*pLista)->mat, x, y);
  } else {
    if (strcmp((*pLista)->nome, nome) == 0)
      printf("ERRO\n");
    else
      criarMatriz(&(*pLista)->prox, nome, y, x);
  }
}
//***************************************************************************************************
// DESTRUIR MATRIZ
void destruirMatriz(struct tLista **pLista, char *nome) {
  struct tLista *dobby;
  if (strcmp((*pLista)->nome, nome) == 0) {
    dobby = *pLista;
    *pLista = (*pLista)->prox;
    eliminaMatriz(&(dobby->mat), dobby->sizex);
    free(dobby);
  } else {
    if ((*pLista)->prox == NULL)
      puts("ERRO");
    else {
      if (strcmp((*pLista)->prox->nome, nome) == 0) {
        dobby = (*pLista)->prox;
        (*pLista)->prox = (*pLista)->prox->prox;
        eliminaMatriz(&(dobby->mat), dobby->sizex);
        free(dobby);
      }
      destruirMatriz(&(*pLista)->prox, nome);
    }
  }
}

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
