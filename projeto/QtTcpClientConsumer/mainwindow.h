#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QWidget>
#include <QTimer>
#include <QListWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
public slots:
  void getData();
  void tcpConnect();
  void tcpDisconnect();
  void tcpStart();
  void tcpStop();
  void tcpUpdate();
  void selectIp(QListWidgetItem *item);
  void setIntevalo ();

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  QTimer *clockWizard = new QTimer(this);
  int dados[20];
};

#endif // MAINWINDOW_H
