/**
 * \file testGameState.cpp
 * \author Zayed Sheet <sheetz@mcmaster.ca>
 */
#include <catch.h>
#include "View.h"

TEST_CASE("test for GameState","[GameState]"){
    matrix NormalM = {{Dead, Dead, Alive}, {Dead, Alive, Dead}, {Dead, Dead, Alive}};
    StateT state(NormalM);
    matrix emptyM = {};
    StateT emp(emptyM);
    SECTION("Test the constructor method"){
        REQUIRE(state.getCell(1,2) == Dead);
        REQUIRE(state.getCell(0,2) == Alive);
        REQUIRE(state.getCell(2,2) == Alive);
    }

//    SECTION("Test the constructor with empty matrix"){
//        matrix EmptyM = {{},{},{}};
//        REQUIRE_THROWS_AS(StateT(EmptyM), std::invalid_argument);
//    }

    SECTION("Test the constructor for non square matrix"){
        matrix DifferentSizes = {{Dead, Alive, Dead}, {Dead, Alive, Dead, Alive}, {Dead, Alive, Dead}};
        REQUIRE_THROWS_AS(StateT(DifferentSizes), std::invalid_argument);
    }

    SECTION("Test the update state method for all dead cells"){
        matrix DeadM = {{Dead, Dead, Dead, Dead},{Dead, Dead, Dead, Dead},{Dead, Dead, Dead, Dead},{Dead, Dead, Dead, Dead}};
        StateT x(DeadM);
        for(nat i = 0; i < 10; i++){
            x.updateState();
        }
        for(nat i = 0; i < DeadM.size(); i++){
            for(nat j = 0; j < DeadM.size(); j++){
                REQUIRE(x.getCell(i,j) == Dead);
            }
        }
    }

    SECTION("Test the update state method for one dying cell"){
        matrix DeadCell = {{Dead, Alive}, {Dead, Dead}};
        StateT x(DeadCell);
        REQUIRE(x.getCell(0,1) == Alive);
        x.updateState();
        REQUIRE(x.getCell(0,1) == Dead);
        x.updateState();
        REQUIRE(x.getCell(0,1) == Dead);
    }

    SECTION("Test the update state method for still life"){
        matrix StillM = {{Dead, Alive, Alive, Dead}, {Dead, Alive, Alive, Dead}, {Dead, Dead, Dead, Dead},{Dead, Dead, Dead, Dead}};
        StateT x(StillM);
        for(nat i = 0; i < 6; i++){
            REQUIRE(x.getCell(0,1) == Alive);
            REQUIRE(x.getCell(0,2) == Alive);
            REQUIRE(x.getCell(1,1) == Alive);
            REQUIRE(x.getCell(1,2) == Alive);
            x.updateState();
        }
    }

    SECTION("Test the update state method for oscillator"){
        matrix OscM = {{Dead, Alive, Dead}, {Dead, Alive, Dead}, {Dead, Alive, Dead}};
        StateT x(OscM);
        for(nat i = 0; i < 6; i++){
            //the dead test cases are the ensure not every cell is becoming alive or anything unexpected
            REQUIRE(x.getCell(0,0) == Dead);
            REQUIRE(x.getCell(1,0) == Dead);
            REQUIRE(x.getCell(2,0) == Dead);
            REQUIRE(x.getCell(0,1) == Alive);
            REQUIRE(x.getCell(1,1) == Alive);
            REQUIRE(x.getCell(2,1) == Alive);
            REQUIRE(x.getCell(0,2) == Dead);
            REQUIRE(x.getCell(1,2) == Dead);
            REQUIRE(x.getCell(2,2) == Dead);
            x.updateState();
            REQUIRE((x.getCell(0,0) == Dead));
            REQUIRE((x.getCell(0,1) == Dead));
            REQUIRE((x.getCell(0,2) == Dead));
            REQUIRE(x.getCell(1,0) == Alive);
            REQUIRE(x.getCell(1,1) == Alive);
            REQUIRE(x.getCell(1,2) == Alive);
            REQUIRE((x.getCell(2,0) == Dead));
            REQUIRE((x.getCell(2,1) == Dead));
            REQUIRE((x.getCell(2,2) == Dead));
            x.updateState();
        }
    }

    SECTION("Test the update state method for glider"){
        matrix gliderM = {{Dead, Dead, Dead, Dead, Dead, Dead},{Dead, Alive, Dead, Dead, Dead, Dead}, {Dead, Dead, Alive, Dead, Dead, Dead},
                          {Alive, Alive, Alive, Dead, Dead, Dead}, {Dead, Dead, Dead, Dead, Dead,Dead},{Dead, Dead, Dead, Dead, Dead,Dead}};
        StateT x(gliderM);
        x.updateState();
        REQUIRE(x.getCell(2,0) == Alive);
        REQUIRE(x.getCell(2,1) == Dead);
        REQUIRE(x.getCell(2,2) == Alive);
        REQUIRE(x.getCell(2,3) == Dead);
        REQUIRE(x.getCell(3,0) == Dead);
        REQUIRE(x.getCell(3,1) == Alive);
        REQUIRE(x.getCell(3,2) == Alive);
        REQUIRE(x.getCell(3,3) == Dead);
        REQUIRE(x.getCell(4,0) == Dead);
        REQUIRE(x.getCell(4,1) == Alive);
        REQUIRE(x.getCell(4,2) == Dead);
        x.updateState();
        REQUIRE(x.getCell(2,0)== Dead);
        REQUIRE(x.getCell(2,1)== Dead);
        REQUIRE(x.getCell(2,2)== Alive);
        REQUIRE(x.getCell(3,0)== Alive);
        REQUIRE(x.getCell(3,1)== Dead);
        REQUIRE(x.getCell(3,2)== Alive);
        REQUIRE(x.getCell(3,3)== Dead);
        REQUIRE(x.getCell(4,0)== Dead);
        REQUIRE(x.getCell(4,1)== Alive);
        REQUIRE(x.getCell(4,2)== Alive);
        REQUIRE(x.getCell(4,3)== Dead);
        x.updateState();
        REQUIRE(x.getCell(2,0) == Dead);
        REQUIRE(x.getCell(2,1) == Alive);
        REQUIRE(x.getCell(2,2) == Dead);
        REQUIRE(x.getCell(3,0) == Dead);
        REQUIRE(x.getCell(3,1) == Dead);
        REQUIRE(x.getCell(3,2) == Alive);
        REQUIRE(x.getCell(3,3) == Alive);
        REQUIRE(x.getCell(4,0) == Dead);
        REQUIRE(x.getCell(4,1) == Alive);
        REQUIRE(x.getCell(4,2) == Alive);
        REQUIRE(x.getCell(4,3) == Dead);
    }

    SECTION("Test the update state on empty game"){
        //this test case essentially makes sure that everything can work as expected with an empty game
        emp.updateState();
        emp.updateState();
        REQUIRE(emp.size() ==0);
    }

    SECTION("test size getter"){
        REQUIRE(state.size() == 3);
    }

    SECTION("Empty size getter"){
        REQUIRE(emp.size() == 0);
    }

    SECTION("Get Cell exception tester"){ //tests exception cases, other cases were tested implicitly while testing other methods
        REQUIRE_THROWS_AS(state.getCell(3,2), std::invalid_argument);
    }
}