#include "Retangulo.h"
#include "Pontos.h"
#include "Poligono.h"

Retangulo::Retangulo(float _x, float _y, float largura, float altura){
	// setVertices(4);
	qnt_vertice = 5;
	vertices = new Pontos[5];
	vertices[0] = Pontos(_x, _y);
	vertices[1] = Pontos(_x + largura, _y);
	vertices[2] = Pontos(_x + largura, _y + altura);
	vertices[3] = Pontos(_x, _y + altura);
	vertices[4] = Pontos(_x, _y);

}