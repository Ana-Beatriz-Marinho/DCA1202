#ifndef SCREEN_H
#define SCREEN_H
#include <vector>
#include <fstream>


using namespace std;

    /**
    *
    * @brief A classe Screen serve para criar um objeto que contem as configuracoes
    * como numeros de linhas e de colunas, brush
    *
    */


class Screen{
private:
  int nlin, ncol;
  char brush;
  vector< vector<char> > mat;

public:
    /**
    *
    * @brief Screen() eh o constructor da classe
    *
    */
  Screen();

  /**
    *
    * @brief Screen(int _nlin, int _ncol) eh o constructor que initializa
    * a matriz a ser usada na representacao
    * @param _nlinh recebe o numero de linhas
    * @param _ncol recebe o numero de colunas
    */
  Screen(int _nlin, int _ncol);
  /**
    *
    * @brief setPixel(int x, int y) eh a funcao que marca o ponto na matriz criada
    * @param x recebe a coordenada x
    * @param y recebe a coordenada y
    */
  void setPixel(int x, int y);
  /**
    *
    * @brief clear() eh a funcao que limpa a matriz, preenchendo ela de espaços
    */
  void clear();
  /**
    *
    * @brief setBrush(char brush) eh a funcao atribui o caratere a usar para marcar o ponto
    * @param brush recebe o caratere a usar
    */
  void setBrush(char brush);

  /**
    *
    * @brief operator<<(ostream &os, Screen &t) que retorna um fluxo de saida contendo os pontos marcados
    */
  friend ostream& operator<<(ostream &os, Screen &t);
};

#endif // SCREEN_H
