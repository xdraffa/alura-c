#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define PILULA 'P'

struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};

struct posicao{
    int x;
    int y;
};

typedef struct mapa MAPA;
typedef struct posicao POSICAO;

void liberaMapa(MAPA* m);
void alocaMapa(MAPA* m);
void leMapa(MAPA* m);
void imprimeMapa(MAPA* m);
int encontraMapa(MAPA* m, POSICAO* p, char c);
int ehValida(MAPA* m, int x, int y);
int ehVazia(MAPA* m, int x, int y);
void andaNoMapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
void copiaMapa(MAPA* destino, MAPA* origem);
int ehParede(MAPA* m, int x, int y);
int podeAndar(MAPA* m, char personagem, int x, int y);
int ehPersonagem(MAPA* m, char personagem, int x, int y);



