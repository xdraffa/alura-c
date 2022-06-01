#include <stdio.h>

int main(){
    int numero;
    scanf("%d", &numero);

    for(int i = 0; i <= 10; i++){
       
        int vezes = numero * i;
        printf("%d x %d = %d\n",numero, i, vezes);            
    }
}