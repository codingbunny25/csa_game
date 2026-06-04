#include <iostream>
#include <random>







#define max_verde 25
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



Carta mineiro {   
    "Mineiro",
    3, //dano
    7, //vida
    0, //cura
    0,//raridade
    'p', //classe
    'g' //atributo

};
Carta bobo {  
    "Bobo", 
    0, //dano
    7, //vida
    0, //cura
    0,raridade
    'p', //classe
    't' //atributo
};
Carta mulher_espiritos {   
    "Mulher que fala \ncom espíritos",
    4, //dano
    8, //vida
    0, //cura
    0,//raridade
    'e', //classe
    'g' //atributo

};

struct Pilhas{

    Carta verde [max_verde] ;
    int spverde;
    Carta azul [max_azul] ;
    int spazul;
    Carta vermelha [max_azul] ;
    int spvermelha;
    Carta amarela [max_amarelo] ;
    int spamarela;
};





//no mapa os quadrados têm cores ->   nada - 1 ; verde - 2 ; laranja - 3; azul - 4; amarelo - 5; vermelho - 6;portal - 7;

int mapa [] = {1,2,1,2,1,1,2,1,1,4,1,2,3,1,4,6,1,2,1,2,1,1,2,1,1,1,1,4,1,6,1,3,1,1,2,3,2,1,1,4,1,2,6,1,3,1,2,1,5,1,4,1,6,5,4,7};
Carta baralho [max_baralho];











// funções base



int dado () {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> die(1,6);


    return die(gen);
}


void baralhar (Carta baralho []){

    std::random_device rd;
    std::mt19937 gen(rd());

    for(int i =0;i<max_baralho;i++){
        
        std::uniform_int_distribution<> die(0,i);

        int r = max_baralho - die(gen);

        Carta temp = baralho[i];
        baralho [i] = baralho [r];
        baralho[r]=temp;

    }

}






Pilhas makePilhas(Carta baralho []){

    Pilhas p ;


    for(int i =0;i<max_baralho;i++){

    }





    return p;

}

