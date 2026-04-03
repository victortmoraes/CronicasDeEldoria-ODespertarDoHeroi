#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Heroi
{
    char nome[50];
    float hp;
    float poder;
    int vitorias;
    int derrotas;
};

struct Monstro
{
    char nome[50];
    int nivel;
    float hp;
    float poder;
};

struct TipoMonstro
{
    char nome[50];
    float hp;
    float poder;
    int variacao;
};

struct TipoMonstro tipos[10] = {
    {"Rastejante das Sombras", 40, 10, 3},
    {"Lobo das Brumas", 55, 18, 4},
    {"Goblin Saqueador", 70, 26, 5},
    {"Arqueiro Espectral", 80, 34, 6},
    {"Guardião de Pedra", 95, 42, 7},
    {"Feiticeiro Caído", 110, 50, 8},
    {"Górgona Crepuscular", 125, 60, 9},
    {"Quimera Rubra", 140, 72, 10},
    {"Titã do Trovão", 160, 85, 12},
    {"Dragão Abissal", 200, 100, 15}};

void setMonstro(int nivel, struct Monstro *m);

int main()
{

    struct Heroi h;
    struct Monstro m;

    // Inicializando o herói
    printf("Digite o nome do herói: ");
    fgets(h.nome, sizeof(h.nome), stdin);
    h.nome[strcspn(h.nome, "\n")] = 0;

    h.hp = 100.0;
    h.poder = 20.0;
    h.vitorias = 0;
    h.derrotas = 0;

    while (1)
    {
        printf("\nEscolha o nível do monstro (1-10) ou 0 para sair: ");
        int nivel;
        scanf("%d", &nivel);

        if (nivel == 0)
        {
            printf("Saindo do jogo...\n");
            break;
        }

        if (nivel < 1 || nivel > 10)
        {
            printf("Nível inválido!\n");
            continue;
        }

        setMonstro(nivel, &m);
    }

    return 0;
}

void setMonstro(int nivel, struct Monstro *m)
{
    struct TipoMonstro t = tipos[nivel - 1];

    strcpy(m->nome, t.nome);
    m->nivel = nivel;
    m->hp = t.hp;

    // variação aleatória no poder
    float var = ((float)rand() / RAND_MAX) * (2 * t.variacao) - t.variacao;
    m->poder = t.poder + var;
}