#include <stdio.h>
#include <stdlib.h>

int linhas = 5;
int colunas = 10;
int** matriz;


int main(){

    matriz = malloc(sizeof(int*) * linhas);
    for(int i = 0; i < linhas; i++){
        matriz[i] = malloc(sizeof(int) * (colunas + 1));
    }

    for(int i = 0; i < linhas; i++){
        printf("%d\n", matriz[i]);
    }
}