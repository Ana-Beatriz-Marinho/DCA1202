#ifndef PONTOS_H
#define PONTOS_H

class Pontos{
private:
	float x;
	float y;

public:
	Pontos();
	Pontos(float _x, float _y);
	Pontos(Pontos &p);
	void setX(float _x);
	float getX();
    void setXY (float _x, float _y);
	void setY(float _y);
	float getY();
	void add(Pontos p);
	void sub(Pontos p);
	void transladar(float _x, float _y);
	void imprimir();
	float norma();
};

#endif