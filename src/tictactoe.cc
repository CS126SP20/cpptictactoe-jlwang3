// Copyright 2020 [Your Name]. All rights reserved.

#include <set>
#include <string>

#include <tictactoe/tictactoe.h>


namespace tictactoe {

using std::string;
std:: string board;
const static int boardSize = 3;
const static int boardLength = 9;

TicTacToeState EvaluateBoard(const string& setBoard) {

    if (setBoard.length() != 9) {
        return TicTacToeState::InvalidInput;
    }

    for (int i = 0; i < board.length(); i++) {
        board[i] = toupper(setBoard[i]);
    }

    //check isUnreachableState

    //Use Three in a Row function. Otherwise... no winner. 

  return TicTacToeState::NoWinner;
}

/**
 * This method checks for three in a row.
 * @param setString The parameter should already be a string of length 9 in all upper case.
 * @return X or O.
 */
TicTacToeState ThreeInARow(const string& setString) {
    for (int i = 0; i < boardSize; i++) {
        if (setString[boardSize * i] == 'X' && setString[boardSize * i + 1] == 'X' && setString[boardSize * i + 2] == 'X') {
            return static_cast<TicTacToeState>('X');
        }
        if (setString[boardSize * i] == 'O' && setString[boardSize * i + 1] == 'O' && setString[boardSize * i + 2] == 'O') {
            return static_cast<TicTacToeState>('O');
        }
    }

    for (int i = 0; i < boardSize; i++) {
        if (setString[boardSize * 0 + i] == 'X' && setString[boardSize * 1 + i] == 'X' && setString[boardSize * 2 + i] == 'X') {
            return static_cast<TicTacToeState>('X');
        }
        if (setString[boardSize * 0 + i] == 'O' && setString[boardSize * 1 + i] == 'O' && setString[boardSize * 2 + i] == 'O') {
            return static_cast<TicTacToeState>('O');
        }
    }

    if ((setString[0] == 'X' && setString[boardLength / 2] == 'X' && setString[boardLength - 1] == 'X')
    || (setString[boardSize - 1] == 'X' && setString[boardLength / 2] == 'X' && setString[boardSize * (boardSize - 1)] == 'X')) {
        return static_cast<TicTacToeState>('X');
    }
    if ((setString[0] == 'O' && setString[boardLength / 2] == 'O' && setString[boardLength - 1] == 'O')
    || (setString[boardSize - 1] == 'O' && setString[boardLength / 2] == 'O' && setString[boardSize * (boardSize - 1)] == 'O')) {
        return static_cast<TicTacToeState>('O');
    }
}
/**
 * This method determines whether or not the board is an unreachable state.
 * Returns a boolean.
 */
TicTacToeState isUnreachableState(const string& setString) {
    //https://stackoverflow.com/questions/3867890/count-character-occurrences-in-a-string-in-c
        size_t x = std::count(setString.begin(), setString.end(), 'X');
        size_t o = std::count(setString.begin(), setString.end(), 'O');
        if (x == o || x == o + 1) {
            return static_cast<TicTacToeState>(true);
        }
        //if there is a x == o and x has three in a row, if x == o + 1 and o has three in a row,
        // if there are any two instances of three in a row, it is an unreachable state.
}

}  // namespace tictactoe
