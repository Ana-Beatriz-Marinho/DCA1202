#include "Poligono.h"
#include "Pontos.h"
#include <iostream>
#include <cmath>
#include <stdlib.h>

const double pi = 3.14159; 

using namespace std;

Poligono::Poligono(){

}

Poligono::Poligono(int _qntvertices){
	if(_qntvertices <= 2 || _qntvertices > 100){
		cout<<"Numero de vertices invalido!"<<endl;
	}
	qnt_vertice = _qntvertices;
	vertices = new Pontos[qnt_vertice];
}

void Poligono::ordenar(){
	for(int i = 0; i < qnt_vertice; i++){
		for (int j = 0; j < qnt_vertice; j++){
			if((vertices[i].norma() > vertices[j].norma()) && i != j){
				Pontos auxiliar(vertices[i]);
				vertices[i].setX(vertices[j].getX());
				vertices[i].setY(vertices[j].getY());
				vertices[j].setX(auxiliar.getX());
				vertices[j].setY(auxiliar.getY());
			}
		}
	}
}

int Poligono::getQntVertices(){
	return qnt_vertice;
}

void Poligono::addVertices(){
	int x, y;

	for (int i = 0; i < qnt_vertice; ++i){
		cout << "Digite x y do vertice " << i + 1 << endl;
		cin >> x >> y;
		vertices[i].setX(x);
		vertices[i].setY(y);
	}

	// ordenar();
}

void Poligono::addVertices(float *_x, float *_y){
	for (int i = 0; i < qnt_vertice; i++){
		vertices[i].setX(_x[i]);
		vertices[i].setY(_y[i]);
	}

	// ordenar();
}

void Poligono::setVertices(int _qntvertices){
	qnt_vertice = _qntvertices;
	vertices = new Pontos[qnt_vertice];
}

/*
Calculo da área encontrado no site:
http://www.profcardy.com/cardicas/como-obter-area-de-poligono-por-coordenadas.php
*/

float Poligono::area(){
	float sumX_Y = 0;
	float sumY_X = 0;

	for(int i = 0; i < (qnt_vertice - 1); i++){
		sumX_Y += (vertices[i].getX() * vertices[i + 1].getY());
	}

	for(int i = 0; i < (qnt_vertice - 1); i++){
		sumX_Y += (vertices[i + 1].getX() * vertices[i].getY());
	}

	return (sumX_Y - sumY_X)/2.0;
}

void Poligono::transladar(float a, float b){

	for(int i = 0; i < qnt_vertice; i++){
		vertices[i].setX(vertices[i].getX() + a);
		vertices[i].setY(vertices[i].getY() + b);
	}
}

void Poligono::rotacionar(float angulo, Pontos p){
    
    angulo = (angulo*pi)/180;
    float _x, _y;
    for(int i=0;i<qnt_vertice;i++){
        _x = p.getX() + (vertices[i].getX() - p.getX()) * cos(angulo) - (vertices[i].getY() - p.getY())*sin(angulo);
        _y = p.getY() + (vertices[i].getX() - p.getX())*sin(angulo) + (vertices[i].getY() - p.getY())*cos(angulo);
        vertices[i].setXY(_x, _y);
    }
}

void Poligono::imprimir(){
	for (int i = 0; i < qnt_vertice; ++i){
		cout << " --> ";
		vertices[i].imprimir();
	}

	cout << endl;
}

Pontos Poligono::centroMassa(){
    float cx=0.0, cy=0.0, x0=0.0, y0=0.0, x1=0.0, y1=0.0;
    float N_area = 6*area();
    Pontos centro;
    for(int i=0; i<qnt_vertice-1; i++){
        x0 = vertices[i].getX();
        y0 = vertices[i].getY();

        x1 = vertices[i+1].getX();
        y1 = vertices[i+1].getY();

        cx += (x0 + x1)*(x0 * y1 - x1 * y0);
        cy += (y0 + y1)*(x0 * y1 - x1 * y0);
    }


    x0 = vertices[qnt_vertice-1].getX();
    y0 = vertices[qnt_vertice-1].getY();

    x1 = vertices[0].getX();
    y1 = vertices[0].getY();

    cx += (x0 + x1)*(x0 * y1 - x1 * y0);
    cy += (y0 + y1)*(x0 * y1 - x1 * y0);

    cx = cx/N_area;
    cy = cy/N_area;
    centro.setXY(cx, cy);
    return centro;
}