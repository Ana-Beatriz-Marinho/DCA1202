#ifndef RETA_H
#define RETA_H

#include "screen.h"
#include "figurageometrica.h"

/**
*
* @brief A classe Reta serve para criar uma figura geometrica de tipo reta
*
*/

class Reta : public FiguraGeometrica
{
private:
    float x0; float y0; float x1; float y1;
public:
   /**
    *
    * @brief Reta(float _x0, float _y0, float _x1, float _y1) eh o constructor que initializa
    * as cordenadas dos dois pontos a ser usados na construcao da reta
    * @param _x0 recebe a cordenada x do primeiro ponto
    * @param _y0 recebe a cordenada y do primeiro ponto
    * @param _x1 recebe a cordenada x do segundo ponto
    * @param _y1 recebe a cordenada y do segundo ponto
    */
    Reta(float _x0, float _y0, float _x1, float _y1);

    /**
    *
    * @brief draw(Screen &t) eh a funcao que serve para desenhar
    * a saida, usando um objeto de tipo Screen
    * @param &t aponta para o objeto Sreen usado para criar a saida
    *
    */
    void draw(Screen &t);
};

#endif // RETA_H
