#include <stdio.h>

int main(){
    int x, y, resultado;

    printf("Insira um valor na Var X\n");
    scanf("%d", &x);

    printf("Insira um valor na Var Y\n");
    scanf("%d", &y);

    resultado = x * y;
    printf("O Resultado foi %d", resultado);
}