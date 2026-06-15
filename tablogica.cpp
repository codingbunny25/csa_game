#include <iostream>
#include <random>
#include "tablogica.h"


//no mapa os quadrados têm cores ->   nada - 1 ; verde - 2 ; laranja - 3; azul - 4; amarelo - 5; vermelho - 6;portal - 7;

//int mapa [] = {1,2,1,2,1,1,2,1,1,4,1,2,3,1,4,6,1,2,1,2,1,1,2,1,1,1,1,4,1,6,1,3,1,1,2,3,2,1,1,4,1,2,6,1,3,1,2,1,5,1,4,1,6,5,4,7};



// funções base



int dado () {

    std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> die(1,6);


    return die(gen);
}


int lancaDado (int d){
    int v [6] = {0};
    int n =0,tentativas =0;
    do {
        std::cout << "Escreve a tua tentativa(1 a 6)\n";
        std::cin >> n;

        if(n<1||n>6){
            std::cout << "Tentativa Inválida !!!\nTenta de novo : ) \n";
            continue;
        
        }
        if(v[n-1]==1){
            std::cout << "Já tinhas tentado esse número! \nTenta de novo : )";
            continue;
            }
        if(n!=d){
                std::cout << "Número errado : (\nTenta de novo : )\n";
                v[n-1] = 1;
                tentativas++;
                continue;
            }
        }
    while(n!=d);
    return 7-tentativas;
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




void makePilhas(Pilhas & p,Carta baralho []){



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

    return  &p;

}

//no mapa os quadrados têm cores ->   nada - 1 ; verde - 2 ; laranja - 3; azul - 4; amarelo - 5; vermelho - 6;portal - 7;



void auxTileLaranja(Jogador * j){
    j->posi += dado();
    j->vez =0;
}

void auxTileVerde(Jogador * j,Pilhas * p){
    int d = dado();
    if(d>1){
        j->cartas[j->spcartas]= p->verde[p->spverde];
        p->spverde--;
        j->spcartas++;
    }
    j->vez =0;
}



void auxTileAzul    (Jogador * j,Pilhas * p){
    int d = dado();
    if(d>2){
        j->cartas[j->spcartas]= p->azul[p->spazul];
        p->spazul--;
        j->spcartas++;
    }
    j->vez =0;
}

void auxTileAmarelo (Jogador * j,Pilhas * p){
    int d = dado();
    if(d==6){
        j->cartas[j->spcartas]= p->amarela[p->spamarela];
        p->spamarela--;
        j->spcartas++;
    }
    j->vez =0;
}

void auxTileVermelho(Jogador * j,Pilhas * p){
    int d = dado();
    if(d>4){
        j->cartas[j->spcartas]= p->vermelha[p->spvermelha];
        p->spvermelha--;
        j->spcartas++;
    }
    j->vez =0;
} 


void gereTiles (Jogador * j, int tile,Pilhas * p ){

    switch (tile){

        case 2:
            auxTileVerde(j,p);
            break;

        case 3:
            auxTileLaranja(j);
            break;
        
        case 4 :
            auxTileAzul(j,p);
            break;
        case 5:
            auxTileAmarelo(j,p);
            break;
        case 6:
            auxTileVermelho(j,p);    
        
        default : 
        break;
        
    }
}



void jogaTab (){
    Jogador *j1, *j2;
    j1->spcartas = j1->posi = 0;
    j2->spcartas = j2->posi = 0;

    Pilhas  pilhas;
    makePilhas(pilhas,baralho);

    while(j1->posi!=55&&j2->posi!=55){
        j1-> vez =1;
        gereTiles(j1,j1->posi,pilhas);
        j2->vez = 1;
        gereTiles(j2,j2->posi,pilhas);
    }

}