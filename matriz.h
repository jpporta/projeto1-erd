//incluindo funcoes
float ** initMatriz     (int x, int y);
void eliminaMatriz      (float **dobby, int x);
void imprime            (float **M, int x, int y);
float **mult            (float **mat1, float **mat2, int x1, int y1, int x2, int y2);
float **divi             (float **mat1, float **mat2, int x1, int y1, int x2, int y2);
float **mult_elemento   (float **mat1, float **mat2, int x1, int y1, int x2, int y2);
float **soma		(float **mat1, float **mat2, int x1, int y1, int x2, int y2);
float **trans		(float **mat1, int x1, int y1);
