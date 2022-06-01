#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'
#define BOMBA 'b'

void fantasmas();
int ondeOFantasmaVai(int xatual, int yatual, int* xdestino, int* ydestino);
void fantasmas();
int acabou();
int ehDirecao(char direcao);
void move(char direcao);
void explodePilula();
void CallExplodePilula(int x, int y, int somax, int somay, int qtd);
