#include "screen.h"
#include "figurageometrica.h"
#include "retangulo.h"


Retangulo::Retangulo(int _x0, int _y0, int _largura, int _altura, bool _filled){
    x0 = _x0;
    y0 = _y0;
    largura = _largura;
    altura = _altura;
    filled = _filled;
}

void Retangulo::draw(Screen &t){

    //Preenchendo as larguras
    for(int i=x0; i<x0+largura; i++){
        t.setPixel(i, y0);
        t.setPixel(i, y0+altura);
    }

    //Preenchendo as alturas
    for(int j=y0; j<y0+altura; j++){
        t.setPixel(x0, j);
        t.setPixel(x0+largura-1, j);
    }
    
    //Retangulo preenchido
    if(filled){
		for(int i= x0; i<= x0+largura; i++){
			for(int j= y0; j<= y0+altura;j++){
				t.setPixel(i,j);
			}
		}
	}
}
