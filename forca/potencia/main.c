#include <stdio.h>

void potencia(int x, int n){
    int potencia = 1;
    int contador = 0;

   printf("\n\tCalculo de Potencias\n");
   printf("\nDigite um numero inteiro: ");
   scanf("%d", &x);
   printf("Digite um numero inteiro nao negativo: ");
   scanf("%d", &n);

    while (contador != n)
   {
       potencia = potencia * x;
       contador = contador + 1;
   }

    printf("\nO valor de %d elevado a %d: %d\n", x, n, potencia);
   
}

int main(){
    potencia(2, 2);
}