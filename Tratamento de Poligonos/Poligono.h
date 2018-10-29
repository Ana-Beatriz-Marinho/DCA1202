#ifndef POLIGONO_h
#define POLIGONO_h
#include "Pontos.h"

class Poligono{
private:
	void ordenar();
protected:
	int qnt_vertice;
	Pontos *vertices;
public:
	Poligono();
	Poligono(int _qntvertices);
	int getQntVertices();
	void addVertices();
	void addVertices(float *_x, float *_y);
	void setVertices(int _qntvertices);
	float area();
	void transladar(float a, float b);
	void rotacionar(float angulo, Pontos p);
	void imprimir();
	Pontos centroMassa();
};

#endif