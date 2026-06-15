#ifndef TABLOGICA_H
#define TABLOGICA_H

#include <iostream>
#include <random>



#define max_verde 9
#define max_azul 25
#define max_vermelho 25
#define max_amarelo 25


#define max_baralho 31

// typedefs, structs , mapa 


typedef char classe; //floresta->f, realeza->r, povo->p, exercito->x, espíritos->e
typedef char atributo;//dano em área->d, atirador->a, alvo->t, guerreiro->g, suporte->s, curandeiro->c



int mapa [] = {1,2,1,2,1,1,2,1,1,4,1,2,3,1,4,6,1,2,1,2,1,1,2,1,1,1,1,4,1,6,1,3,1,1,2,3,2,1,1,4,1,2,6,1,3,1,2,1,5,1,4,1,6,5,4,7};


struct Carta {
    char nome [128];
    int dano;
    int vida;
    int cura;
    int raridade;//0->verde,1->azul,2-vermelho,3->amarelo
    classe cl;
    atributo at1;
    atributo at2;
    
    
};



struct Pilhas{

    Carta verde [max_verde] ;
    int spverde;
    Carta azul [max_azul] ;
    int spazul;
    Carta vermelha [max_vermelho] ;
    int spvermelha;
    Carta amarela [max_amarelo] ;
    int spamarela;
};


struct Jogador {
    Carta cartas[max_baralho];
    int spcartas;
    int posi;
    int vez;
};

Carta baralho [max_baralho];


int dado ();
int lancaDado (int d);
void baralhar (Carta baralho []);
void makePilhas(Pilhas & p,Carta baralho []);


void auxTileLaranja(Jogador * j);
void auxTileVerde(Jogador * j,Pilhas * p);
void auxTileAzul    (Jogador * j,Pilhas * p);
void auxTileAmarelo (Jogador * j,Pilhas * p);
void auxTileVermelho(Jogador * j,Pilhas * p);
void gereTiles (Jogador * j, int tile,Pilhas * p );
void jogaTab ();






#endif