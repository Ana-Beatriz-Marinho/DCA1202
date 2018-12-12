#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QTimer>

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
    /**
   * @brief tcpConnect Função que faz conexão com o servidor com ip que usuário passou.
   */
  void tcpConnect();
  /**
   * @brief tcpDisconnect Função que finaliza conexão com o servidor.
   */
  void tcpDisconnect();
  /**
   * @brief intervalo Função que indica o intervalo de tempo entre o envio de dois dados consecultivos.
   */
  void setIntervaloTemp();
  /**
   * @brief StartTemp Inicia transmissão de dados.
   */
  void StartTemp();
  /**
   * @brief StopTemp Finalisa a transmissão de dados.
   */
  void StopTemp();
  /**
   * @brief putData Função que cria dados aleatorios baseados na data e intervalo dado pelo usuário.
   */
  void putData();
private:
  /**
   * @brief ui ponteiro interface
   */
  Ui::MainWindow *ui;
  /**
   * @brief socket é reconhecido pela combinação IP+Porta. Usado para distinguir várias conexões que podem chegar a mesma porta.
   */
  QTcpSocket *socket;
  /**
   * @brief contTemp Ponteiro para reber o time.
   */
  QTimer *contTemp = new QTimer(this);
  /**
   * @brief info Variável QString para guardar dados.
   */
  QString info;
  /**
   * @brief atualizaBrowse Faz atualização dos dados no TextBrowse da interface.
   * @param s O parâmetro s guarda os dados.
   */

  void atualizaBrowse(QString s);
  /**
   * @brief conexao Função para informar ao usuário se está conectado ou desconectado.
   * @param a vai receber "Connected" ou "Disconnected".
   */
  void conexao(QString a);
};

#endif // MAINWINDOW_H
