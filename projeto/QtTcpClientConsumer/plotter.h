#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>

class Plotter : public QWidget
{
    Q_OBJECT
private:
    float amplitude, frequencia, velocidade, angulo;
    int timerId;
public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *evento);
    void timerEvent(QTimerEvent *event);
    void mousePressEvent(QMouseEvent *event);
signals:
    void mudouX(int);
    void mudouY(int);
public slots:
  void setAmplitude(int _amplitude);
  void setFrequencia(int _frequencia);
  void setVelocidade(int _velocidade);
};

#endif // PLOTTER_H
