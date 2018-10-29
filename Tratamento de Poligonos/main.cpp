#include <iostream>
#include "Pontos.h"
#include "Poligono.h"
#include "Retangulo.h"

using namespace std;

int main (){
    //float x, y, alt, larg, area;
Retangulo ret(0.0, 0.0, 4.0, 4.0);
Pontos centro;

ret.imprimir();
cout << "Area do poligono: = " << ret.area() <<" u.a "<< endl;

ret.transladar(-3,4);
ret.imprimir();
cout << "Area do poligono transladado: = " << ret.area() <<" u.a "<< endl;

centro = ret.centroMassa();
ret.rotacionar(30.0, centro);
ret.imprimir();
cout<<"A area do poligono rotacionado: "<<ret.area()<<" u.a "<<endl;


return 0;

}