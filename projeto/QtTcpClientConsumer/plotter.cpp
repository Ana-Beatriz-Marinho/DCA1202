#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <cmath>
#include <QMouseEvent>

using namespace std;

#define PI 3.1415

Plotter::Plotter(QWidget *parent) : QWidget(parent){

}

void Plotter::paintEvent(QPaintEvent *evento){
QPainter painter(this);
QBrush brush;
QPen pen;
int x1, y1, x2, y2;

//brush cor amarela e sólida
brush.setColor(QColor(255,255,100));
brush.setStyle(Qt::SolidPattern);

//caneta cor vermelha
pen.setColor(QColor(255,0,0));
pen.setWidth(2);

//informe ao pintor qual o brush atual
painter.setBrush(brush);
//informa um retangulo abrangendo toda a extensao
painter.setPen(pen);
//desenha um retangulo abrangendo toda extensao
//componente
painter.drawRect(0,0,width(),height());

//desenha um seno na tela
pen.setColor(QColor(255,180,0));
painter.setPen(pen);

painter.drawLine(0, height()/2, width(), height()/2);

x1 = 0;
y1 = height()/2;

//desenha um seno na tela
pen.setColor(QColor(0,0,255));
painter.setPen(pen);

for(int i=1; i<width(); i++){
    x2 = i;
    y2 = height()/2 *(1- sin(2*PI*x2/width()));
    painter.drawLine(x1,y1,x2,y2);
    x1 = x2;
    y1 = y2;
}
}

void Plotter::mousePressEvent(QMouseEvent *event)
{
    emit mudouX(event->x());
    emit mudouY(event->y());
}
