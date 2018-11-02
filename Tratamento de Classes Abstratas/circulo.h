#ifndef CIRCULO_H
#define CIRCULO_H

#include "screen.h"
#include "figurageometrica.h"


/**
*
* @brief A classe Circulo serve para criar uma figura geometrica de tipo circulo
*
*/

class Circulo : public FiguraGeometrica{
private:
    int x_centro; int y_centro; int raio; bool filled;
public:

    /**
    *
    * @brief Circulo(int _x_centro, int _y_centro, int _raio, bool _filled) eh o constructor que initializa
    * as cordenadas do centro, o raio e modo de preenchimento do circulo
    * @param _x_centro recebe a cordenada x do centro
    * @param _y_centro recebe a cordenada y do centro
    * @param _raio recebe o raio do circulo
    * @param _filled recebe um boolean que se true, o circulo vira um disco
    */
    Circulo(int _x_centro, int _y_centro, int _raio, bool _filled);

    /**
    *
    * @brief draw(Screen &t) eh a funcao que serve para desenhar
    * a saida, usando um objeto de tipo Screen
    * @param &t aponta para o objeto Sreen usado para criar a saida
    *
    */
    void draw(Screen &t);
};

#endif // CIRCULO_H
