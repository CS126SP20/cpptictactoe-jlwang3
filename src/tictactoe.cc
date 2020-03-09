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
 * This method checks for the number of instances of three in a row.
 */
    int ThreeInARowCount() {
        int threeInARowCount = 0;
        for (int i = 0; i < boardSize; i++) {
            if (board[boardSize * i] == 'X' && board[boardSize * i + 1] == 'X' && board[boardSize * i + 2] == 'X') {
                threeInARowCount++;
            }
            if (board[boardSize * i] == 'O' && board[boardSize * i + 1] == 'O' && board[boardSize * i + 2] == 'O') {
                threeInARowCount++;
            }
        }

        for (int i = 0; i < boardSize; i++) {
            if (board[boardSize * 0 + i] == 'X' && board[boardSize * 1 + i] == 'X' && board[boardSize * 2 + i] == 'X') {
                threeInARowCount++;
            }
            if (board[boardSize * 0 + i] == 'O' && board[boardSize * 1 + i] == 'O' && board[boardSize * 2 + i] == 'O') {
                threeInARowCount++;
            }
        }

        if ((board[0] == 'X' && board[boardLength / 2] == 'X' && board[boardLength - 1] == 'X')
            || (board[boardSize - 1] == 'X' && board[boardLength / 2] == 'X' && board[boardSize * (boardSize - 1)] == 'X')) {
            threeInARowCount++;
        }
        if ((board[0] == 'O' && board[boardLength / 2] == 'O' && board[boardLength - 1] == 'O')
            || (board[boardSize - 1] == 'O' && board[boardLength / 2] == 'O' && board[boardSize * (boardSize - 1)] == 'O')) {
            threeInARowCount++;
        }
        return threeInARowCount;
    }

    /**
     * This method determines whether X has three in a row.
     */
    bool XHasThreeInARow() {
        for (int i = 0; i < boardSize; i++) {
            if (board[boardSize * i] == 'X' && board[boardSize * i + 1] == 'X' && board[boardSize * i + 2] == 'X') {
                return true;
            }
        }

        for (int i = 0; i < boardSize; i++) {
            if (board[boardSize * 0 + i] == 'X' && board[boardSize * 1 + i] == 'X' && board[boardSize * 2 + i] == 'X') {
                return true;
            }
        }

        return (board[0] == 'X' && board[boardLength / 2] == 'X' && board[boardLength - 1] == 'X')
               || (board[boardSize - 1] == 'X' && board[boardLength / 2] == 'X' &&
                   board[boardSize * (boardSize - 1)] == 'X');
    }

    /**
     * This method determines whether O has three in a row.
     */
    bool OHasThreeInARow() {
        for (int i = 0; i < boardSize; i++) {
            if (board[boardSize * i] == 'O' && board[boardSize * i + 1] == 'O' && board[boardSize * i + 2] == 'O') {
                return true;
            }
        }

        for (int i = 0; i < boardSize; i++) {
            if (board[boardSize * 0 + i] == 'O' && board[boardSize * 1 + i] == 'O' && board[boardSize * 2 + i] == 'O') {
                return true;
            }
        }

        return (board[0] == 'O' && board[boardLength / 2] == 'O' && board[boardLength - 1] == 'O')
               || (board[boardSize - 1] == 'O' && board[boardLength / 2] == 'O' &&
                   board[boardSize * (boardSize - 1)] == 'O');
    }

/**
 * This method determines whether or not the board is an unreachable state.
 */
    bool IsUnreachableState() {
        //https://stackoverflow.com/questions/3867890/count-character-occurrences-in-a-string-in-c
        size_t x = std::count(board.begin(), board.end(), 'X');
        size_t o = std::count(board.begin(), board.end(), 'O');
        if (x != o && x != o + 1) {
            return true;
        }
        return (x == o && XHasThreeInARow()) || ((x == o + 1 && OHasThreeInARow()) || ThreeInARowCount() > 1);
    }

TicTacToeState EvaluateBoard(const string& setBoard) {

    if (setBoard.length() != 9) {
        return TicTacToeState::InvalidInput;
    }

    for (int i = 0; i < boardLength; i++) {
        board[i] = toupper(setBoard[i]);
    }

    if (&IsUnreachableState) {
        return TicTacToeState::UnreachableState;
    }

    if (XHasThreeInARow()) {
        return TicTacToeState::Xwins;
    }

    if (OHasThreeInARow()) {
        return TicTacToeState::Owins;
    }

  return TicTacToeState::NoWinner;
    
}


}  // namespace tictactoe