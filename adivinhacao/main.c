#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// COMPILAR = main gcc main.c -o main.exe - exec = /.main.exe
int main() {
    int segundos = time(0);
    srand(segundos);

    int numeroGrande = rand();
    int numeroSecreto = numeroGrande % 100;
    
    int numeroDeTentativas = 0;
    int tentativas = 1;

    int inputDificuldade = 0;
    
    int acertou = 0;
    int input;

printf("                     ________________________________________________\n");     
printf("                    /                                                \\\n ");
printf("                   |    _________________________________________     |\n");
printf("                   |   |                                         |    |\n");
printf("                   |   |  C:\\> _      SEJA BEM VINDO            |    |\n");
printf("                   |   |                AO JOGO DE               |    |\n");
printf("                   |   |           A D I V I N H A C A O         |    |\n");
printf("                   |   |                                         |    |\n");
printf("                   |   |                                         |    |\n");
printf("                   |   |                                         |    |\n");
printf("                   |   |                                         |    |\n");
printf("                   |   |                                         |    |\n");
printf("                   |   |                                         |    |\n");
printf("                   |   |                                         |    |\n");
printf("                   |   |                                         |    |\n");
printf("                   |   |                                         |    |\n");
printf("                   |   |_________________________________________|    |\n");
printf("                   |                                                  |\n");
printf("                   \\_________________________________________________/\n");
printf("                         \\___________________________________/\n");
printf("                        ___________________________________________\n");
printf("                     _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n");
printf("                  _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_\n");
printf("               _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_\n");
printf("            _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_\n");
printf("         _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_\n");
printf("        :-------------------------------------------------------------------------:\n");
printf("        `---._.-------------------------------------------------------------._.---'\n");


    for(int i = 1; i <= 2; i++){
    printf("Selecione a dificuldade\n\n");
    printf("FACIL - 1\n");
    printf("MEDIO - 2\n");
    printf("DIFICIL - 3\n");
    printf("IMPOSSIVEL - 4\n");

    scanf("%d", &inputDificuldade);  
    switch (inputDificuldade)
    {
    case 1:
        numeroDeTentativas = 20;
        break;
    case 2:
        numeroDeTentativas = 15;
        break;
    case 3:
        numeroDeTentativas = 10;
    case 4:
        numeroDeTentativas = 5;
        break;
    default:
        printf("Esta fora do escopo!");
        continue;
    }

    printf("VOCE TEM %d TENTATIVAS\n", numeroDeTentativas);
    
    for(int i = 1; i <= numeroDeTentativas; i++){
        printf("Qual e o seu chute? %d \n");
        scanf("%d", &input);
        printf("Voce chutou %d \n", input);

        if(input < 0) {
            printf("Voce nao pode chutar numeros negativos!\n");
            continue;
        }
        
        acertou = (input == numeroSecreto);
        int maior = input > numeroSecreto;

        if(numeroDeTentativas == i){
            break;
        }

        if(acertou){
            break;
        }

        else if(maior) {
            printf("Tentativa %d\n", tentativas);
            printf("Seu numero foi maior que o numero secreto! ");
        }

        else{
            printf("Tentativa %d\n", tentativas);
            printf("Seu numero foi menor que o numero secreto! ");
        }

        tentativas++;
    }

    printf("Fim de Jogo!\n");
    if(acertou){
        printf("Voce Venceu em %d tentativas!\n", tentativas);
        break;
        } else {
        printf("Voce Perdeu! Acabaram suas chances\n");
        break;
        }
    }
}
    