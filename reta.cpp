#include "screen.h"
#include "figurageometrica.h"
#include "reta.h"
#include <cmath>

Reta::Reta(float _x0, float _y0, float _x1, float _y1){
    x0 = _x0;
    y0 = _y0;
    x1 = _x1;
    y1 = _y1;
}

void Reta::draw(Screen &t){
    // Usando a equação y = ax+b
    float a, b;
    if(x0 == x1){
        for(int i=y0; i<=y1; i++)
        {
            t.setPixel(x0, i);
        }
    }else{
        a = (y1-y0)/(x1-x0);
        b = y1-a*x1;

        for(int i=x0; i<=x1; i++)
        {
            t.setPixel(i, round(a*i+b));
        }
    }
}
