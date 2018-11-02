#ifndef RETANGULO_H
#define RETANGULO_H

#include "screen.h"
#include "figurageometrica.h"

/**
*
* @brief A classe Retangulo serve para criar uma figura geometrica de tipo retangulo
*
*/


class Retangulo : public FiguraGeometrica
{
private:
    int x0; int y0; int largura; int altura; bool filled;
public:

    /**
    *
    * @brief Retangulo(int _x0, int _y0, int _largura, int _altura) eh o constructor que initializa
    * as cordenadas do ponto superior esquerdo, a largura e a altura do retangulo
    * @param _x0 recebe a cordenada x do ponto
    * @param _y0 recebe a cordenada y do ponto
    * @param _largura recebe a largura do retangulo
    * @param _altura recebe a altura do retangulo
    */

    Retangulo(int _x0, int _y0, int _largura, int _altura, bool _filled);

    /**
    *
    * @brief draw(Screen &t) eh a funcao que serve para desenhar
    * a saida, usando um objeto de tipo Screen
    * @param &t aponta para o objeto Sreen usado para criar a saida
    *
    */
    void draw(Screen &t);
};

#endif // RETANGULO_H
