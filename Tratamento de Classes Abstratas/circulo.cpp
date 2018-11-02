#include "screen.h"
#include "figurageometrica.h"
#include "circulo.h"
#include <cmath>

Circulo::Circulo(int _x_centro, int _y_centro, int _raio, bool _filled){
    x_centro = _x_centro;
    y_centro = _y_centro;
    raio = _raio;
    filled = _filled;
}

void Circulo::draw(Screen &t){
    //Extremidades
    int x0, y0, x1, y1, y_temp;
    x0 = x_centro - raio;
    x1 = x_centro + raio;
    y0 = y_centro - raio;
    y1 = y_centro + raio;

    //Usando a formula y = raiz(r^2 - x^2)
    for(int i=x0; i<=x1; i++){
        y_temp = round(sqrt(pow(raio,2)-pow(i-x_centro, 2)) + y_centro);
        t.setPixel(i, y_temp);
        y_temp = round(y_centro - sqrt(pow(raio,2)-pow(i-x_centro, 2)));
        t.setPixel(i, y_temp);
    }

    //Preenchendo o circulo caso for um disco
    int temp;
    if(filled){
        for(int i = x0; i <= x1; i++){
            for(int j = y0; j <= y1; j++){
                temp = round(sqrt(pow(i-x_centro,2)+pow(j-y_centro, 2)));
                if(temp <= raio){
                    t.setPixel(i,j);
                }
            }
        }
    }
}
