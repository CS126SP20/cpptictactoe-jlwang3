// Copyright 2020 [Your Name]. All rights reserved.

#include <set>
#include <map>
#include <string>

#include <tictactoe/tictactoe.h>


namespace tictactoe {

using std::string;
std:: string board;
const static int boardSize = 3;
const static int boardLength = 9;

/**
 * This method checks for three in a row.
 * @param board The parameter should already be a string of length 9 in all upper case.
 * @return A map of X's and O's.
 */
    TicTacToeState ThreeInARow() {
        std::map <char, int> freqOfXO;
        for (int i = 0; i < boardSize; i++) {
            if (board[boardSize * i] == 'X' && board[boardSize * i + 1] == 'X' && board[boardSize * i + 2] == 'X') {
                return static_cast<TicTacToeState>('X');
            }
            if (board[boardSize * i] == 'O' && board[boardSize * i + 1] == 'O' && board[boardSize * i + 2] == 'O') {
                return static_cast<TicTacToeState>('O');
            }
        }

        for (int i = 0; i < boardSize; i++) {
            if (board[boardSize * 0 + i] == 'X' && board[boardSize * 1 + i] == 'X' && board[boardSize * 2 + i] == 'X') {
                return static_cast<TicTacToeState>('X');
            }
            if (board[boardSize * 0 + i] == 'O' && board[boardSize * 1 + i] == 'O' && board[boardSize * 2 + i] == 'O') {
                return static_cast<TicTacToeState>('O');
            }
        }

        if ((board[0] == 'X' && board[boardLength / 2] == 'X' && board[boardLength - 1] == 'X')
            || (board[boardSize - 1] == 'X' && board[boardLength / 2] == 'X' && board[boardSize * (boardSize - 1)] == 'X')) {
            return static_cast<TicTacToeState>('X');
        }
        if ((board[0] == 'O' && board[boardLength / 2] == 'O' && board[boardLength - 1] == 'O')
            || (board[boardSize - 1] == 'O' && board[boardLength / 2] == 'O' && board[boardSize * (boardSize - 1)] == 'O')) {
            return static_cast<TicTacToeState>('O');
        }
    }

/**
 * This method determines whether or not the board is an unreachable state using knowledge of how many X and O's there are.
 * Returns a boolean.
 */
    TicTacToeState IsUnreachableState() {
        //https://stackoverflow.com/questions/3867890/count-character-occurrences-in-a-string-in-c
        size_t x = std::count(board.begin(), board.end(), 'X');
        size_t o = std::count(board.begin(), board.end(), 'O');
        if (x != o && x != o + 1) {
            return static_cast<TicTacToeState>(true);
        }
        if (x == 0) {
            //if (ThreeInARow(setString)
        }
        //if there is a x == o and x has three in a row, if x == o + 1 and o has three in a row,
        // if there are any two instances of three in a row, it is an unreachable state.
    }

TicTacToeState EvaluateBoard(const string& setBoard) {

    if (setBoard.length() != 9) {
        return TicTacToeState::InvalidInput;
    }

    for (int i = 0; i < board.length(); i++) {
        board[i] = toupper(setBoard[i]);
    }

    if (IsUnreachableState) {
        return TicTacToeState::UnreachableState;
    }

    //Use Three in a Row function. Otherwise... no winner.
    if (ThreeInARow == 'X') {
        return TicTacToeState::Xwins;
    }
    if (ThreeInARow == 'O') {
        return TicTacToeState::Owins;
    }

  return TicTacToeState::NoWinner;
}


}  // namespace tictactoe