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
    Carta cartas[31];
    int posi;
};


//no mapa os quadrados têm cores ->   nada - 1 ; verde - 2 ; laranja - 3; azul - 4; amarelo - 5; vermelho - 6;portal - 7;

int mapa [] = {1,2,1,2,1,1,2,1,1,4,1,2,3,1,4,6,1,2,1,2,1,1,2,1,1,1,1,4,1,6,1,3,1,1,2,3,2,1,1,4,1,2,6,1,3,1,2,1,5,1,4,1,6,5,4,7};
Carta baralho [max_baralho];











// funções base



int dado () {

    std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> die(1,6);


    return die(gen);
}


void baralhar (Carta baralho []){

    std::random_device rd;
    std::mt19937 gen(rd());

    for(int i =0;i<max_baralho;i++){
        
        std::uniform_int_distribution<> die(0,i);

        int r = die(gen);

        Carta temp = baralho[i];
        baralho [i] = baralho [r];
        baralho[r]=temp;

    }

}




Pilhas makePilhas(Carta baralho []){

    Pilhas  p ;


    p.spamarela=0;
    p.spazul =0;
    p.spverde =0;
    p.spvermelha =0;



    baralhar(baralho);




    //escreve as cartas nos seus sítios nos arrays dentro da pilha
    for(int i =0;i<max_baralho;i++){

        if(baralho[i].raridade == 0){
            p.verde[p.spverde] = baralho[i]; 
            p.spverde ++;
        }

        if(baralho[i].raridade == 1){
            p.azul[p.spazul] = baralho[i]; 
            p.spazul ++;
        }

        if(baralho[i].raridade == 2){
            p.vermelha[p.spvermelha] = baralho[i]; 
            p.spvermelha ++;
        }
            if(baralho[i].raridade == 3){
            p.amarela[p.spamarela] = baralho[i]; 
            p.spamarela ++;
        }

    }

    //assim os stackpointers apontam para a primeira carta da pilha
    p.spamarela--;
    p.spvermelha--;
    p.spverde--;
    p.spazul--;

    return p;

}

//no mapa os quadrados têm cores ->   nada - 1 ; verde - 2 ; laranja - 3; azul - 4; amarelo - 5; vermelho - 6;portal - 7;


void auxTileVerde(Jogador j){

}

void auxTileLaranja(Jogador j){
    
}



void auxTileAzul    (Jogador j){

}
void auxTileAmarelo (Jogador j){

}
void auxTileVermelho(Jogador j){

} 


void gereTiles (Jogador j, int tile){

    switch (tile){

        case 2:
            auxTileVerde(j);
            break;

        case 3:
            auxTileLaranja(j);
            break;
        
        case 4 :
            auxTileAzul(j);
            break;
        case 5:
            auxTileAmarelo(j);
            break;
        case 6:
            auxTileVermelho(j);    
        
        default : 
        break;
        
    }
}