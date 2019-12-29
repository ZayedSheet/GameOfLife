/**
 * \file GameState.h
 * \author Zayed Sheet, MacID: sheetz
 * \brief Module to read, initialize, write and visualize game states
 * \date 2019-04-12
 */
#include "GameState.h"
#include "Cell.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <unistd.h>

#ifndef A4_VIEW_H
#define A4_VIEW_H

/**
 * \brief Reads from an input file and initializes the board based on the input
 * @param fileName input file representing the initial state of the board
 * @return returns a board with input representing the initial state
 */
StateT initializeBoard(std::string fileName);

/**
 * \brief Write to an output file the current state of a board
 * @param board the board you want to extract the current state from
 * @param fileName the name you'd like the output file to be
 */
void writeBoard(StateT board, std::string fileName);

/**
 * \brief print the current state of the game as a visual representation
 * @param board the game board you want to print the state of
 */
void printState(StateT board);
#endif //A4_VIEW_H

