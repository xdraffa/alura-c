#include <stdio.h>

void soma(int numeros[10]){
    int total = 0;
    for(int i = 0; i < 10; i++){
        total += numeros[i];
    }

    printf("O total é %d", total);
    return 0;
}

int main(){
    soma(1, 2);

}