/**
 * \file GameState.h
 * \author Zayed Sheet, MacID: sheetz
 * \brief Module to represent and change the state of a game
 * \date 2019-04-12
 */

#ifndef A4_GAMESTATE_H
#define A4_GAMESTATE_H

#include "Cell.h"
#include <vector>
#include <string>
#include <stdexcept>

typedef unsigned int nat;
typedef std::vector<std::vector<CellT>> matrix;

/**
 * \brief represent the state of a game
 */
class StateT{
    private:
        matrix s;
        matrix updateCell(matrix s, nat i, nat j);
        nat countLiveCells(nat i, nat j);
        bool validPoint(int i, int j);

    public:
        /**
         * \brief Contructor for a Game State
         * @param s Starting state of the game
         */
        explicit StateT(matrix s);

        /**
         * \brief updates the current state of the game to the next state.
         */
        void updateState();

        /**
         * \brief getter function to retrieve a cell from specific coordinates
         * @param i row coordinate of the cell you're trying to retrieve
         * @param j column coordinate of the cell you're trying to retrieve
         * @return returns the cell at s[i][j]
         */
        CellT getCell(nat i, nat j);

        /**
         * \brief gets the size of the state variable (how many elements are in the matrix)
         * @return natural number representing the size of the state variable
         */
        nat size();
};

#endif //A4_GAMESTATE_H
