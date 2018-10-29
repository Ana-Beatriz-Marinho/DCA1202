#include "screen.h"
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

Screen::Screen(){
}

Screen::Screen(int _nlin, int _ncol){
    nlin = _nlin;
    ncol = _ncol;
    mat.resize(nlin);
    for(int i=0;i<nlin;i++)
    {
        mat[i].resize(ncol, ' ');
    }
}

void Screen::setPixel(int x, int y){
    if(x >= 0 && x < ncol && y>=0 && y < nlin){
        mat[x][y] = brush;
    }
}

void Screen::clear(){
    for(int i = 0; i<nlin;i++){
        for(int j = 0; j<ncol;j++){
                mat[i][j]=' ';
            }
        }
}

void Screen::setBrush(char _brush){
    brush = _brush;
}

// envia a tela para um stream de saida
ostream& operator<<(ostream &os, Screen &t){
    for(int j=0; j< t.nlin; j++){
        for(int i=0; i< t.ncol; i++){
            os << setw(2)<<t.mat[j][i];
        }
        os << endl;
    }
    return os;
}
