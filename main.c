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
  char cmd[3];
  struct tLista *pLista;
  char nome1[10], nome2[10], nomeR[10];
  int x, y;
  float num;

  pLista = NULL;
  do {
    //    system("clear");
    scanf("%s", cmd);

    if (!(strcmp(cmd, "CM"))) {
      scanf("%s", nome1);
      scanf("%i %i", &y, &x);
      if (1 >= y || 50 <= y || 1 >= x || 50 <= x)
        puts("ERRO");
      else
        criarMatriz(&pLista, nome1, y, x);
    }
    if (!(strcmp(cmd, "DM"))) {
      scanf("%s", nome1);
      destruirMatriz(&pLista, nome1);
    }
    if (!(strcmp(cmd, "IM"))) {
      scanf("%s", nome1);
      imprimirMatriz(pLista, nome1);
    }
    if (!(strcmp(cmd, "AE"))) {
      scanf("%s", nome1);
      scanf("%i %i", &y, &x);
      scanf("%f", &num);
      atribuirElemento(&pLista, nome1, y, x, num);
    }
    if (!(strcmp(cmd, "AL"))) {
      scanf("%s", nome1);
      scanf("%i", &y);
      atribuirLinha(&pLista, nome1, y);
    }
    if (!(strcmp(cmd, "AC"))) {
      scanf("%s", nome1);
      scanf("%i", &x);
      atribuirColuna(&pLista, nome1, x);
    }
    if (!(strcmp(cmd, "TM"))) {
      scanf("%s", nome1);
      scanf("%s", nomeR);
      transporMatriz(&pLista, nome1, nomeR);
    }
    if (!(strcmp(cmd, "SM"))) {
      scanf("%s", nome1);
      scanf("%s", nome2);
      scanf("%s", nomeR);
      somarMatriz(&pLista, nome1, nome2, nomeR);
    }
    if (!(strcmp(cmd, "DV"))) {
      scanf("%s", nome1);
      scanf("%s", nome2);
      scanf("%s", nomeR);
      dividirMatriz(&pLista, nome1, nome2, nomeR);
    }
    if (!(strcmp(cmd, "MM"))) {
      scanf("%s", nome1);
      scanf("%s", nome2);
      scanf("%s", nomeR);
      // multiplicarMatriz(&pLista, nome1, nome2, nomeR);
    }
    if (!(strcmp(cmd, "ME"))) {
      scanf("%s", nome1);
      scanf("%s", nome2);
      scanf("%s", nomeR);
      // multiplicarElem(&pLista, nome1, nome2, nomeR);
    }
    if (!(strcmp(cmd, "FE")))
      break;
  } while (1);
  return 0;
}
