// Copyright 2020 [Your Name]. All rights reserved.

#include <set>
#include <string>

#include <tictactoe/tictactoe.h>


namespace tictactoe {

using std::string;
std:: string board;
const static int boardLength = 9;

TicTacToeState EvaluateBoard(const string& setBoard) {

    if (setBoard.length() != 9) {
        return TicTacToeState::InvalidInput
    }

    for (int i = 0; i < board.length(); i++) {
        board[i] = toupper(setBoard[i]);
    }

    
  return TicTacToeState::NoWinner;
}

}  // namespace tictactoe
