#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "forca.h"

char chutes[26];
char palavraSecreta[TAMANHO_PALAVRA];
int chutesDados = 0;

void abertura(){
    printf("**************************\n");
    printf("*     JOGO DE FORCA      *\n");
    printf("**************************\n\n");

}

void chuta(){
    char chute;
    scanf(" %c", &chute);

    chutes[chutesDados] = chute;
    chutesDados++;
}

void desenhaForca(){
    int erros = chutesErrados();
    printf("  _______      \n");
    printf(" |/      |     \n");
    printf(" |      %c%c%c \n", (erros >= 1 ?'(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    printf(" |      %c%c%c \n", (erros >= 2 ? '\\' : ' '),(erros >= 2 ? '|' : ' '), (erros >= 2 ? '/' : ' '));
    printf(" |       %c    \n", (erros >= 3 ? '|' : ' '));
    printf(" |      %c %c  \n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
    printf(" |             \n");
    printf("_|___          \n");
    printf("\n\n");
    
    
    for(int i = 0; i < strlen(palavraSecreta); i++){
       int achou = jaChutou(palavraSecreta[i]);
        if(achou) {
            printf("%c ", palavraSecreta[i]);
        } else {
            printf("_ ");
     }
}
    printf("\n");
}

void adicionaPalavra(){
    char quer;

    printf("Voce quer adicionar uma nova palavra ao jogo ? (S/N)");
    scanf(" %c", &quer);

    if(quer == 'S') {
        char novaPalavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra?");
        scanf("%s", novaPalavra);

        FILE* f;
        f = fopen("palavras.txt", "r+");

        if(f == 0){
        printf("Desculpe, banco de dados nao disponivel");
        exit(1);
        }
        
        int quantidade;
        fscanf(f, "%d", &quantidade);
        quantidade++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", quantidade);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novaPalavra);
        fclose(f);
    }
}

void escolhePalavra(){
    FILE* f;
    f = fopen("palavras.txt", "r");
    if(f == 0){
        printf("Desculpe, banco de dados nao disponivel");
        exit(1);
    }

    int quantidadeDePalavras;
    fscanf(f, "%d", &quantidadeDePalavras);

    srand(time(0));
    int random = rand() % quantidadeDePalavras;

    for(int i = 0; i <= random; i++){
        fscanf(f, "%s", palavraSecreta);
    }

    fclose(f);
}

int ganhou(){
    for(int i = 0; i < strlen(palavraSecreta); i++){
        if (!jaChutou(palavraSecreta[i])){
            return 0;
        }
    }

    return 1;
}
int chutesErrados(){
    int erros = 0;
    for(int i = 0; i < chutesDados; i++){
        int existe = 0;

        for(int j = 0; j < strlen(palavraSecreta); j++){
            if(jaChutou(palavraSecreta[i])){
                existe = 1;
                break; 
            }
        }
        if(!existe) erros++;
    }
    return erros;
}

int enforcou(){
    return chutesErrados() >= 5;
}

int jaChutou(char letra){
     int achou = 0;

     for(int j = 0; j < chutesDados; j++){
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }
    
    return achou;
}

int main(){
    abertura();
    escolhePalavra();

    do{
    desenhaForca();
    chuta();

   } while (!ganhou() && !enforcou());
    
    if (ganhou()){
        printf("\nParabéns, você ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");
    } else {
        printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavraSecreta);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }
    adicionaPalavra();
}