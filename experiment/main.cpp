/**
 * \file Cell.h
 * \author Zayed Sheet, MacID: sheetz
 * \date 2019-04-12
 */
#include "View.h"

int main() {
    StateT x = initializeBoard("test.txt");
    while(true) {
        printState(x);
        x.updateState();
        usleep(50000);
        writeBoard(x,"testfile.txt");
    }
    return 0;
}
