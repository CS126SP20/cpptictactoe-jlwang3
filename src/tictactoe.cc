// Copyright 2020 [Your Name]. All rights reserved.

#include <set>
#include <string>

#include <tictactoe/tictactoe.h>


namespace tictactoe {

using std::string;
const static int boardLength = 9;

TicTacToeState EvaluateBoard(const string& board) {

    //https://stackoverflow.com/questions/735204/convert-a-string-in-c-to-upper-case
    std::string = std::transform(board.begin(), board.end(), board.begin(), ::toupper);

    std::string BOARD [boardLength] =

    for (int n = 0; n < boardLength; n++) {
        std::string BOARD [n] = string.sub
    }


  return TicTacToeState::NoWinner;
}

}  // namespace tictactoe
