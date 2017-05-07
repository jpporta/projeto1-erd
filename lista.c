#include "lista.h"
#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//***************************************************************************************************
// BUSCAR LISTA
struct tLista *busca(struct tLista *pLista, char *nome) {
  aux = pLista;
  while (strcmp(nome, aux->nome) != 0 || (aux != NULL)) {
    aux = aux->prox;
  }
  if (strcmp(nome, aux->nome) == 0) {
    return aux;
  } else {
    return NULL;
  }
}
//***************************************************************************************************
// CRIAR MATRIZ
struct tLista *criarMatriz(struct tLista **pLista, char *nome, int y, int x) {
  if (*pLista == NULL) {
    *pLista = (struct tLista *)malloc(sizeof(struct tLista));
    strcpy((*pLista)->nome, nome);
    (*pLista)->sizex = x;
    (*pLista)->sizey = y;
    (*pLista)->prox = NULL;
    (*pLista)->mat = initMatriz(x, y);
    return *pLista;
  } else {
    if (strcmp((*pLista)->nome, nome) == 0)
      printf("ERRO\n");
    else
      return criarMatriz(&(*pLista)->prox, nome, y, x);
  }
}
//***************************************************************************************************
// DESTRUIR MATRIZ
void destruirMatriz(struct tLista **pLista, char *nome) {
  struct tLista *dobby;
  if (*pLista == NULL)
    puts("ERRO");
  else {
    if (strcmp((*pLista)->nome, nome) == 0) {
      dobby = *pLista;
      *pLista = (*pLista)->prox;
      eliminaMatriz((dobby->mat), dobby->sizex);
      printf("destrido %s\n", nome); //<--------------------------Excluir
      free(dobby);
    } else {
      if ((*pLista)->prox == NULL)
        puts("ERRO");
      else {
        if (strcmp((*pLista)->prox->nome, nome) == 0) {
          dobby = (*pLista)->prox;
          (*pLista)->prox = (*pLista)->prox->prox;
          eliminaMatriz((dobby->mat), dobby->sizex);
          printf("destrido %s\n", nome); //<--------------------------Excluir
          free(dobby);
        } else
          destruirMatriz(&(*pLista)->prox, nome);
      }
    }
  }
}

//***************************************************************************************************
// IMPRIMIR MATRIZ
void imprimirMatriz(struct tLista **pLista, char *nome) {
  if (*pLista == NULL)
    puts("ERRO");
  else {
    if (strcmp((*pLista)->nome, nome) == 0) {
      imprime(*pLista);
    } else {
      if ((*pLista)->prox == NULL)
        puts("ERRO");
      else {
        if (strcmp((*pLista)->prox->nome, nome) == 0) {
          imprime((*pLista)->mat, (*pLista)->x, (*pLista)->y);
        } else
          imprimirMatriz(&(*pLista)->prox, nome);
      }
    }
  }
}

//***************************************************************************************************
// ATRIBUIR ELEMENTO
void atribuirElemento(struct tLista **pLista, char *nome, int y, int x,
                      float num) {
  float **M;
  struct tLista *aux;
  aux = busca(pLista, nome);
  M = aux->mat;
  mat[x][y] = num;
}
//***************************************************************************************************
// ATRIBUIR LINHA
void atribuirLinha(struct tLista **pLista, char *nome, int y) {
  int count = 0;
  float num;
  float **M;
  struct tLista *aux;
  aux = busca(pLista, nome);
  M = aux->mat;
  while (scanf("%f", num) != '#') {
    M[count][y] = num;
    count++;
  }
}
//***************************************************************************************************
// ATRIBUIR COLUNA
void atribuirColuna(struct tLista **pLista, char *nome, int x) {
  int count = 0;
  float num;
  float **M;
  struct tLista *aux;
  aux = busca(pLista, nome);
  M = aux->mat;
  while (scanf("%f", num) != '#') {
    M[x][count] = num;
    count++;
  }
}
//***************************************************************************************************
// TRANSPOR MATRIZ
void transporMatriz(struct tLista **pLista, char *nome, char *nomeR) {
  struct tLista *aux1, *aux2;  
  float **matR;  
  if (pLista == NULL) {
    return 0;
  } else
    aux1 = busca(*pLista, nome1);
    aux2 = busca(*pLista, nomeR);
    if (aux2 != NULL)
    {
      puts("ERRO");
      return;
    }
    if (aux1 != NULL) {
      aux2 = criarMatriz(pLista, nomeR, aux1->sizex, aux1->sizey);
      (aux2->mat) = trans(aux1->mat, aux1->x, aux1->y);
      puts(*nomeR);
  } else
      puts("ERRO");
} 
//***************************************************************************************************
// SOMAR MATRIZ
void somarMatriz(struct tLista **pLista, char *nome1, char *nome2, char *nomeR) {
  struct tLista *aux1, *aux2, *aux3;
  float **matR;
  if (pLista == NULL) {
    return 0;
  } else
    aux1 = busca(*pLista, nome1);
    aux2 = busca(*pLista, nome2);
    if (aux1 != NULL && aux2 != NULL) {
      aux3 = criarMatriz(pLista, nomeR, aux1->sizex, aux1->sizey);
      (aux3->mat) = soma(aux1->mat, aux2->mat, aux1->x, aux1->y, aux2->x, aux2->y);
      puts(*nomeR);
  } else
      puts("ERRO");
}

}
//***************************************************************************************************
// DIVIDIR MATRIZ
void dividirMatriz(struct tLista **pLista, char *nome1, char *nome2, char *nomeR) {
  struct tLista *aux1, *aux2;
  float **matR;
  if (pLista == NULL) {
    return 0;
  } else
    aux1 = busca(*pLista, nome1);
  aux2 = busca(*pLista, nome2);
  if (aux1 != NULL && aux2 != NULL) {
    strcat(nome1, "X");
    strcat(nome1, nome2);
    aux1 = criarMatriz(pLista, nome1, aux1->sizex, aux2->sizey);
    (aux1->mat) = divi(aux1->mat, aux2->mat, aux1->x, aux1->y, aux2->x, aux2->y);
    if (aux1->mat == NULL) puts("ERRO");
  } else
    puts("ERRO");
}
//***************************************************************************************************
// MULTIPLICAR MATRIZ
void multiplicarMatriz(struct tLista **pLista, char *nome1, char *nome2,
                       char *nomeR) {
  struct tLista *aux1, *aux2;
  float **matR;
  if (pLista == NULL) {
    return 0;
  } else {
    aux1 = busca(*pLista, nome1);
    aux2 = busca(*pLista, nome2);
    if (aux1 != NULL && aux2 != NULL) {
      strcat(nome1, "X");
      strcat(nome1, nome2);
      aux1 = criarMatriz(pLista, nome1, aux1->sizex, aux2->sizey);
      (aux1->mat) = mult(aux1->mat, aux2->mat, aux1->x, aux1->y, aux2->x, aux2->y);
    } else
      puts("ERRO");
  }
}
//***************************************************************************************************
// MULTIPLICAR ELEMENTOS
void multiplicarElem(struct tLista **pLista, char *nome1, char *nome2, char *nomeR) {
  struct tLista *aux1, *aux2;
  float **matR;
  if (pLista == NULL) {
    return 0;
  } else
    aux1 = busca(*pLista, nome1);
  aux2 = busca(*pLista, nome2);
  if (aux1 != NULL && aux2 != NULL) {
    strcat(nome1, "X");
    strcat(nome1, nome2);
    aux1 = criarMatriz(pLista, nome1, aux1->sizex, aux2->sizey);
    (aux1->mat) =
        mult_elemento(aux1->mat, aux2->mat, aux1->x, aux1->y, aux2->x, aux2->y);
  } else
    puts("ERRO");
}
//***************************************************************************************************
