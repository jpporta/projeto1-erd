#include "lista.h"
#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//***************************************************************************************************
// BUSCAR LISTA
struct tLista *busca(struct tLista *pLista, char *nome) {
  if (pLista == NULL)
    return NULL;
  if (strcmp(pLista->nome, nome) == 0)
    return pLista;
  return busca(pLista->prox, nome);
}
//***************************************************************************************************
// CRIAR MATRIZ
struct tLista *criarMatriz(struct tLista **pLista, char *nome, int y, int x) {
  if (busca((*pLista), nome) != NULL) {
    puts("ERRO");
    return NULL;
  } else {
    if (*pLista == NULL) {
      *pLista = (struct tLista *)malloc(sizeof(struct tLista));
      strcpy((*pLista)->nome, nome);
      (*pLista)->sizex = x;
      (*pLista)->sizey = y;
      (*pLista)->prox = NULL;
      (*pLista)->mat = initMatriz(x, y);
      puts("OK");
      return *pLista;
    } else {
      if (strcmp((*pLista)->nome, nome) == 0) {
        printf("ERRO\n");
        return NULL;
      } else
        return criarMatriz(&(*pLista)->prox, nome, y, x);
    }
  }
}
//***************************************************************************************************
// DESTRUIR MATRIZ
void destruirMatriz(struct tLista **pLista, char *nome) {
  struct tLista *dobby;
  if (busca((*pLista), nome) == NULL)
    puts("ERRO");
  else {
    if (*pLista == NULL)
      puts("ERRO");
    else {
      if (strcmp((*pLista)->nome, nome) == 0) {
        dobby = *pLista;
        *pLista = (*pLista)->prox;
        eliminaMatriz((dobby->mat), dobby->sizex);
        free(dobby);
        puts("OK");
      } else {
        if ((*pLista)->prox == NULL)
          puts("ERRO");
        else {
          if (strcmp((*pLista)->prox->nome, nome) == 0) {
            dobby = (*pLista)->prox;
            (*pLista)->prox = (*pLista)->prox->prox;
            eliminaMatriz((dobby->mat), dobby->sizex);
            free(dobby);
            puts("OK");
          } else
            destruirMatriz(&(*pLista)->prox, nome);
        }
      }
    }
  }
}

//***************************************************************************************************
// IMPRIMIR MATRIZ
void imprimirMatriz(struct tLista *pLista, char *nome) {
  struct tLista *aux;
  aux = busca(pLista, nome);
  if (aux == NULL)
    puts("ERRO");
  else {
    imprime(aux->mat, aux->sizex, aux->sizey);
  }
}

//***************************************************************************************************
// ATRIBUIR ELEMENTO
void atribuirElemento(struct tLista **pLista, char *nome, int y, int x,
                      float num) {
  float **M;
  struct tLista *aux;
  aux = busca(*pLista, nome);
  if (aux == NULL || x < 1 || y < 1 || x > aux->sizex - 1 || y > aux->sizey - 1)
    puts("ERRO");
  else {
    puts("OK");
    M = aux->mat;
    M[x][y] = num;
  }
}
//***************************************************************************************************
// ATRIBUIR LINHA
void atribuirLinha(struct tLista **pLista, char *nome, int y) {
  int count = 0;
  char num[20];
  float **M;
  struct tLista *aux;
  aux = busca(*pLista, nome);
  M = aux->mat;
  scanf("%s", num);
  while (strcmp(num, "#") != 0) {
    M[count][y] = strtof(num, NULL);
    count++;
    scanf("%s", num);
  }
}
//***************************************************************************************************
// ATRIBUIR COLUNA
void atribuirColuna(struct tLista **pLista, char *nome, int x) {
  int count = 0;
  char num[20];
  float **M;
  struct tLista *aux;
  aux = busca(*pLista, nome);
  M = aux->mat;
  scanf("%s", num);
  while (strcmp(num, "#") != 0) {
    M[x][count] = strtof(num, NULL);
    count++;
    scanf("%s", num);
  }
}
//***************************************************************************************************
// TRANSPOR MATRIZ
void transporMatriz(struct tLista **pLista, char *nome, char *nomeR) {
  struct tLista *aux1, *aux2;
  float **matR;
  if (pLista != NULL) {
    aux1 = busca(*pLista, nome);
    aux2 = busca(*pLista, nomeR);
    if (aux2 != NULL) {
      puts("ERRO");
      return;
    }
    if (aux1 != NULL) {
      aux2 = criarMatriz(pLista, nomeR, aux1->sizey, aux1->sizex);
      (aux2->mat) = trans(aux1->mat, aux1->sizex, aux1->sizey);
      imprime(aux2->mat, aux1->sizey, aux1->sizex);
    } else
      puts("ERRO");
  } else
    puts("ERRO");
}
//***************************************************************************************************
// SOMAR MATRIZ
void somarMatriz(struct tLista **pLista, char *nome1, char *nome2,
                 char *nomeR) {
  struct tLista *aux1, *aux2, *aux3;
  float **matR;
  if (pLista == NULL) {
    puts("ERRO");
  } else {
    aux1 = busca(*pLista, nome1);
    aux2 = busca(*pLista, nome2);
    if (aux1 != NULL && aux2 != NULL) {
      aux3 = criarMatriz(pLista, nomeR, aux1->sizex, aux1->sizey);
      (aux3->mat) = soma(aux1->mat, aux2->mat, aux1->sizex, aux1->sizey,
                         aux2->sizex, aux2->sizey);
      imprime(aux3->mat, aux3->sizex, aux3->sizey);
    } else
      puts("ERRO");
  }
}
//***************************************************************************************************
// DIVIDIR MATRIZ
void dividirMatriz(struct tLista **pLista, char *nome1, char *nome2,
                   char *nomeR) {
  struct tLista *aux1, *aux2;
  float **matR;
  if (pLista != NULL) {
    aux1 = busca(*pLista, nome1);
    aux2 = busca(*pLista, nome2);
    if (aux1 != NULL && aux2 != NULL) {
      strcat(nome1, "X");
      strcat(nome1, nome2);
      aux1 = criarMatriz(pLista, nome1, aux1->sizex, aux2->sizey);
      (aux1->mat) = divi(aux1->mat, aux2->mat, aux1->sizex, aux1->sizey,
                         aux2->sizex, aux2->sizey);
      imprime(aux1->mat, aux1->sizex, aux1->sizey);
      if (aux1->mat == NULL)
        puts("ERRO");
    } else
      puts("ERRO");
  } else
    puts("ERRO");
}
//***************************************************************************************************
// MULTIPLICAR MATRIZ
void multiplicarMatriz(struct tLista **pLista, char *nome1, char *nome2,
                       char *nomeR) {
  struct tLista *aux1, *aux2;
  float **matR;
  if (pLista != NULL) {
    aux1 = busca(*pLista, nome1);
    aux2 = busca(*pLista, nome2);
    if (aux1 != NULL && aux2 != NULL) {
      strcat(nome1, "X");
      strcat(nome1, nome2);
      aux1 = criarMatriz(pLista, nome1, aux1->sizex, aux2->sizey);
      (aux1->mat) = mult(aux1->mat, aux2->mat, aux1->sizex, aux1->sizey,
                         aux2->sizex, aux2->sizey);
      imprime(aux1->mat, aux1->sizex, aux1->sizey);
    } else
      puts("ERRO");
  } else
    puts("ERRO");
}
//***************************************************************************************************
// MULTIPLICAR ELEMENTOS
void multiplicarElem(struct tLista **pLista, char *nome1, char *nome2,
                     char *nomeR) {
  struct tLista *aux1, *aux2;
  float **matR;
  if (pLista != NULL) {
    aux1 = busca(*pLista, nome1);
    aux2 = busca(*pLista, nome2);
    if (aux1 != NULL && aux2 != NULL) {
      strcat(nome1, "X");
      strcat(nome1, nome2);
      aux1 = criarMatriz(pLista, nome1, aux1->sizex, aux2->sizey);
      (aux1->mat) = mult_elemento(aux1->mat, aux2->mat, aux1->sizex,
                                  aux1->sizey, aux2->sizex, aux2->sizey);
      imprime(aux1->mat, aux1->sizex, aux1->sizey);
      if ((aux1->mat) == NULL)
        puts("ERRO");
    } else
      puts("ERRO");
  } else
    puts("ERRO");
}
//***************************************************************************************************
