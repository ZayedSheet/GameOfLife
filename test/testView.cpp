/**
 * \file testGameState.cpp
 * \author Zayed Sheet <sheetz@mcmaster.ca>
 */
#include <catch.h>
#include "View.h"

TEST_CASE("test for View","[View]"){
    //because in our assumptions we expect the user to follow the correct format, we can avoid some test cases
    StateT x = initializeBoard("test.txt");
    SECTION("tests read normal case"){
        REQUIRE(x.size() == 20);
        REQUIRE(x.getCell(1,0) == Alive);
        REQUIRE(x.getCell(0,0) == Dead);
        REQUIRE(x.getCell(1,1) == Alive);
        REQUIRE(x.getCell(1,2) == Alive);
        REQUIRE(x.getCell(5,5) == Alive);
        REQUIRE(x.getCell(6,6) == Alive);
        REQUIRE(x.getCell(6,7) == Alive);
        REQUIRE(x.getCell(7,6) == Alive);
        REQUIRE(x.getCell(7,5) == Alive);
        REQUIRE(x.getCell(1,5) == Dead);
        REQUIRE(x.getCell(7,7) == Dead);
        REQUIRE(x.getCell(8,8) == Dead);
        REQUIRE(x.getCell(5,6) == Dead);
        REQUIRE(x.getCell(2,2) == Dead);
    }

    SECTION("tests read no file case"){
        REQUIRE_THROWS_AS(initializeBoard("testing.txt"), std::runtime_error);
    }

    SECTION("tests read improper alive coordinate case"){
        REQUIRE_THROWS_AS(initializeBoard("improperCord"), std::runtime_error);
    }

    SECTION("tests write to file "){ //this ensures that the format writing to a textfile is the same as format of reading (which we already tested)
        writeBoard(x, "testwrite.txt"); //writes x to a text file
        StateT y = initializeBoard("testwrite.txt"); //reads that text file we wrote to
        for(nat i = 0; i < x.size()-1; i++){
            for (nat j = 0; j < x.size(); j++){
                REQUIRE(x.getCell(i,j) == y.getCell(i,j));
            }
        }
    }

    //tested printState myself by playing the game
}
