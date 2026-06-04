#include <iostream>
#include <random>


typedef char classe; //floresta->f, realeza->r, povo->p, exercito->x, espíritos->e
typedef char atributo;//dano em área->d, atirador->a, alvo->t, guerreiro->g, suporte->s, curandeiro->c



struct Carta {
    char nome [128];
    int dano;
    int vida;
    int cura;
    int raridade;//0
    classe cl;
    atributo at1;
    atributo at2;

    

};


Carta mineiro {   
    "Mineiro",
    3, //dano
    7, //vida
    0, //cura
    'p', //classe
    'g' //atributo

};
Carta bobo {  
    "Bobo", 
    0, //dano
    7, //vida
    0, //cura
    'p', //classe
    't' //atributo
};
Carta mulher_espiritos {   
    "Mulher que fala \ncom espíritos",
    4, //dano
    8, //vida
    0, //cura
    'e', //classe
    'g' //atributo

};




//no mapa os quadrados têm cores ->   nada - 1 ; verde - 2 ; laranja - 3; azul - 4; amarelo - 5; vermelho - 6;portal - 7;

int mapa [] = {1,2,1,2,1,1,2,1,1,4,1,2,3,1,4,6,1,2,1,2,1,1,2,1,1,1,1,4,1,6,1,3,1,1,2,3,2,1,1,4,1,2,6,1,3,1,2,1,5,1,4,1,6,5,4,7};



int dado () {

    

}