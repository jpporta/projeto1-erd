//structs lista
struct tLista {
        char nome[10];
        float *mat;
        int sizex, sizey;
        struct tLista *prox;
};

//incluindo funcoes
void criarMatriz        (struct tLista **pLista, char *nome, int y, int x);
void destruirMatriz     (struct tLista **pLista, char *nome);
// void imprimirMatriz     (struct tLista *pLista, char *nome);
// void atribuirElemento   (struct tLista *pLista, char *nome, int y, int x, float num);
// void atribuirLinha      (struct tLista *pLista, char *nome, int y);
// void atribuirColuna     (struct tLista *pLista, char *nome, int x);
// void transporMatriz     (struct tLista *pLista, char *nome, char *nomeR);
// void somarMatriz        (struct tLista *pLista, char *nome1, char *nome2, char *nomeR);
// void dividirMatriz      (struct tLista *pLista, char *nome1, char *nome2, char *nomeR);
// void multiplicarMatriz  (struct tLista *pLista, char *nome1, char *nome2, char *nomeR);
// void multiplicarElem    (struct tLista *pLista, char *nome1, char *nome2, char *nomeR);
