#include "Pontos.h"
#include <iostream>
#include <cmath>

using namespace std;


Pontos::Pontos(){
  //Construtor default vazio
}

Pontos::Pontos(float _x, float _y){
  x = _x;
  y = _y;
}

void Pontos::setX(float _x){
    x = _x;
}
void Pontos::setY(float _y){
    y = _y;
}
void Pontos::setXY(float _x, float _y){
    x = _x;
    y = _y;
}
float Pontos::getX(void){
    return x;
}
float Pontos::getY(void){
    return y;
}

//Utilizada na funçao ordenar em poligonos.cpp
Pontos::Pontos(Pontos &p){
  x = p.x;
  y = p.y;
}

void Pontos::add(Pontos p){
	x += p.x;
	y += p.y;
}

void Pontos::sub(Pontos p){
	x -= p.x;
	y -= p.y;
}

float Pontos::norma(){
	return (sqrt(x*x + y*y));
}

void Pontos::transladar(float _x, float _y){
	x += _x;
	y += _y;
}

void Pontos::imprimir(){
	cout << "(" << x << ", " << y << ")";
}

