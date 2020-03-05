// Copyright (c) 2020 [Your Name]. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <string>

#include <catch2/catch.hpp>
#include <tictactoe/tictactoe.h>


using tictactoe::EvaluateBoard;
using tictactoe::TicTacToeState;

TEST_CASE("No winner", "[no-winner]") {
  REQUIRE(EvaluateBoard("xxoooxxxo") == TicTacToeState::NoWinner);
}

TEST_CASE("No winner", "[no-winner]") {
    REQUIRE(EvaluateBoard("xo.......") == TicTacToeState::NoWinner);
}

TEST_CASE("X wins", "[x-wins]") {
    REQUIRE(EvaluateBoard("xO..xo..x") == TicTacToeState::Xwins);
}

TEST_CASE("X wins", "[x-wins]") {
    REQUIRE(EvaluateBoard("xxxo.o...") == TicTacToeState::Xwins);
}

TEST_CASE("O wins", "[o-wins]") {
    REQUIRE(EvaluateBoard("XXO.XO.O..") == TicTacToeState::Owins);
}

TEST_CASE("O wins", "[o-wins]") {
    REQUIRE(EvaluateBoard("oOo.x.x.x") == TicTacToeState::Owins);
}

TEST_CASE("Unreachable state", "[unreachable-state]") {
    REQUIRE(EvaluateBoard("xo..xo.ox") == TicTacToeState::UnreachableState);
}

TEST_CASE("Unreachable state", "[unreachable-state]") {
    REQUIRE(EvaluateBoard("xxxoxooox") == TicTacToeState::UnreachableState);
}

TEST_CASE("Unreachable state", "[unreachable-state]") {
    REQUIRE(EvaluateBoard("x..x.x.xO") == TicTacToeState::UnreachableState);
}

TEST_CASE("Unreachable state", "[unreachable-state]") {
    REQUIRE(EvaluateBoard("xoxxo..ox") == TicTacToeState::UnreachableState);
}

TEST_CASE("Invalid input", "[invalid-input]") {
    REQUIRE(EvaluateBoard("XXO.XO.O..-") == TicTacToeState::InvalidInput);
}