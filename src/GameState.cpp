/**
 * \file GameState.cpp
 * \author Zayed Sheet, MacID: sheetz
 * \brief Module to represent the state of a game
 * \date 2019-04-12
 */
#include "GameState.h"

StateT::StateT(matrix s) {
    nat size = s.size();
    for(nat i = 0; i < size; i++){
        if (s[i].size() != size){
            throw std::invalid_argument("State Constructor Error");
        }
    }
    this->s = s;
}

void StateT::updateState() {
    unsigned int n = size();
    matrix newMatrix = matrix (n, std::vector<CellT>(n, Dead));

    for(nat row = 0; row < n; row++){
        for(nat col = 0; col < n; col++){
            newMatrix = updateCell(newMatrix, row, col);
        }
    }
    this->s = newMatrix;
}

matrix StateT::updateCell(matrix newMatrix, nat i, nat j) {
    int numAliveCells = countLiveCells(i, j);
    if(s.at(i).at(j) == Alive){
        if (numAliveCells == 2 || numAliveCells == 3){
            newMatrix.at(i).at(j) = Alive;
        }
    }
    else if(s.at(i).at(j) == Dead){
        if(numAliveCells == 3){
            newMatrix.at(i).at(j) = Alive;
        }
    }
    return newMatrix;
}

nat StateT::countLiveCells(nat i, nat j) {
    nat count = 0;
    int a = static_cast<int>(i);
    int b = static_cast<int>(j);
    for(int x = (i-1); x <= (a+1); x++){
        for(int y = (j-1); y <= (b+1); y++){
            if(!(x==a && y ==b)){
                if(validPoint(x,y) && s[x][y] == Alive){ //short circuit ensures if !validPoint it wont read s[x][y] meaning x,y wont be negative
                    count++;
                }
            }
        }
    }
    return count;
}

bool StateT::validPoint(int i, int j) {
    return i >= 0 && j >= 0 && (i < size()) && (j < size()); //short circuit ensures that if !(i >=0) it wont read i<size(), static cast not necessary
}


CellT StateT::getCell(nat i, nat j) {
    if (!validPoint(i,j)){
        throw std::invalid_argument("Cell doesn't exist");
    }
    return s.at(i).at(j);
}

nat StateT::size(){
    return s.size();
}