/***************************************************************************************************************
   Projeto1 de Estrutura e Recuperacao de Dados
   Realizada por:
    Joao Pedro Porta        16039778
    Marcelo Dib Coutinho    16023673
    Rafael Fioramonte       16032708
***************************************************************************************************************/
#include "lista.h"
#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// inicio do programa
int main() {
  char cmd[2];
  struct matriz *pLista = NULL;
  char nome1[10], nome2[10], nomeR[10];
  int x, y;
  float num;

  do {
    system("clear");
    fgets(stdin, 2, cmd);

    if (!(strcmp(cmd, "CM"))) {
      fgets(stdin, 10, nome1);
      scanf("%i %i", &y, &x);
      if (1 > y || 50 < y || 1 > x || 50 < x)
        puts("ERRO");
      else
        criarMatriz(&pLista, nome1, y, x);
    }
    if (!(strcmp(cmd, "DM"))) {
      fgets(stdin, 10, nome1);
      destruirMatriz(&pLista, nome1);
    }
    if (!(strcmp(cmd, "IM"))) {
      fgets(stdin, 10, nome1);
      imprimirMatriz(&plista, nome1);
    }
    if (!(strcmp(cmd, "AE"))) {
      fgets(stdin, 10, nome1);
      scanf("%i %i", &y, &x);
      scanf("%f", &num);
      atribuirElemento(&plista, nome1, y, x, num);
    }
    if (!(strcmp(cmd, "AL"))) {
      fgets(stdin, 10, nome1);
      scanf("%i", &y);
      atribuirLinha(&pLista, nome1, y);
    }
    if (!(strcmp(cmd, "AC"))) {
      fgets(stdin, 10, nome1);
      scanf("%i", &x);
      atribuirColuna(&pLista, nome1, x);
    }
    if (!(strcmp(cmd, "TM"))) {
      fgets(stdin, 10, nome1);
      fgets(stdin, 10, nomeR);
      transporMatriz(&pLista, nome1, nomeR);
    }
    if (!(strcmp(cmd, "SM"))) {
      fgets(stdin, 10, nome1);
      fgets(stdin, 10, nome2);
      fgets(stdin, 10, nomeR);
      somarMatriz(&pLista, nome1, nome2, nomeR);
    }
    if (!(strcmp(cmd, "DV"))) {
      fgets(stdin, 10, nome1);
      fgets(stdin, 10, nome2);
      fgets(stdin, 10, nomeR);
      dividirMatriz(&pLista, nome1, nome2, nomeR);
    }
    if (!(strcmp(cmd, "MM"))) {
      fgets(stdin, 10, nome1);
      fgets(stdin, 10, nome2);
      fgets(stdin, 10, nomeR);
      multiplicarMatriz(&pLista, nome1, nome2, nomeR);
    }
    if (!(strcmp(cmd, "ME"))) {
      fgets(stdin, 10, nome1);
      fgets(stdin, 10, nome2);
      fgets(stdin, 10, nomeR);
      multiplicarElem(&pLista, nome1, nome2, nomeR);
    }
    if (!(strcmp(cmd, "FE")))
      break;
  } while (1);
  return 0;
}
