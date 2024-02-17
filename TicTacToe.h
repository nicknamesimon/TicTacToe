//
// Created by Simon on 16/02/2024.
//

#ifndef TICTACTOE_TICTACTOE_H
#define TICTACTOE_TICTACTOE_H

#include <vector>

class TicTacToe {
public:
    TicTacToe();

    void startGame();

private:
    std::vector<char> field;
    char currentPlayer;

    void printField();

    // returns true when move was successful, else false
    bool playMove(int pos);

    bool isGameOver();

    bool checkHorizontal(char player);

    bool checkVertical(char player);

    bool checkDiagonal(char player);
};

#endif //TICTACTOE_TICTACTOE_H
