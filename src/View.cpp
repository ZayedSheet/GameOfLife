/**
 * \file View.pp
 * \author Zayed Sheet, MacID: sheetz
 * \brief Module to Read/Initialize a game or write a game's state.
 * \date 2019-04-12
 */
#include "View.h"

StateT initializeBoard(std::string fileName){
    std::ifstream readfile (fileName);
    matrix grid;
    if (readfile.is_open()) {
        nat x,y,z;
        std::string fileline, xcord, ycord;
        getline(readfile, fileline);
        z = stoul(fileline);
        grid = matrix (z, std::vector<CellT>(z, Dead));
        while (getline(readfile, fileline)) {
            std::stringstream is(fileline);
            getline(is, xcord, ',');
            getline(is, ycord, ',');

            x = stoul(xcord);
            y = stoul(ycord);
            if(x >= z || y >= z || z < 0 || y < 0){
                throw std::runtime_error("Read File Cell Error");
            }
            grid.at(x).at(y) = Alive;
        }
    } else {
        throw std::runtime_error("Read File Error");
    }
    return StateT(grid);
}

void writeBoard(StateT board, std::string fileName){
        std::ofstream myfile (fileName);
        if (myfile.is_open())
        {
            myfile << board.size();
            for(nat row = 0; row < board.size(); row++){
                for(nat col = 0; col < board.size(); col++){
                    if(board.getCell(row,col) == Alive){
                        myfile << "\n" << row << "," << col;
                    }
                }
            }
            myfile.close();
        }
        else{
            throw std::runtime_error("Write File Error");
        }
}

void printState(StateT board){
    std::string ASCIIBoard;
    for(nat row = 0; row < board.size(); row++){
        for(nat col = 0; col < board.size(); col++){
            if(board.getCell(row,col) == Dead){
                ASCIIBoard.append("[ ]");
            }
            else ASCIIBoard.append("[o]");
        }
        ASCIIBoard.append("\n");
    }
    std::cout << ASCIIBoard << std::endl;
}

