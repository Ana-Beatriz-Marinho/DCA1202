#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "screen.h"


    /**
    *
    * @brief The FiguraGeometrica class serve de base para uma figura geometrica
    *
    *
    * A classe FiguraGeometrica serve para criar uma figura geometrica e desenha a saida num fluxo de saida
    *
    */


class FiguraGeometrica
{
public:

    /**
    *
    * @brief FiguraGeometrica() eh o constructor da classe
    *
    */

    FiguraGeometrica();

    /**
    *
    * @brief draw(Screen &t) eh a funcao que serve para desenhar
    * a saida, usando um objeto de tipo Screen
    * @param &t aponta para o objeto Sreen usado para criar a saida
    *
    */
    virtual void draw(Screen &t)=0;
};

#endif // FIGURAGEOMETRICA_H