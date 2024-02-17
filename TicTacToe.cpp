#include "TicTacToe.h"

//
// Created by Simon on 16/02/2024.
//

#include <vector>
#include <iostream>

const char playerX{'X'};
const char playerO{'O'};
const char emptyField{'-'};



    TicTacToe::TicTacToe() {

        currentPlayer = {playerX};
        field = {
                emptyField, emptyField, emptyField,
                emptyField, emptyField, emptyField,
                emptyField, emptyField, emptyField
        };
    }

    void TicTacToe::startGame(){
        int inputPos = -1;

        while(!isGameOver()){
            printField();
            std::cout << "Player " << currentPlayer << " enter a number between 1 and 9!\n";
            std::cout << "Your number: ";
            std::cin >> inputPos;
            while(!playMove(inputPos-1)){
                std::cin >> inputPos;
            }
        }
    }

    void TicTacToe::printField() {
        std::cout << "#######################\n";
        for (int i = 0; i < field.size(); ++i) {
            std::cout << field.at(i) << ' ';
            if((i+1) % 3 == 0){
                std::cout << '\n';
            }
        }
        std::cout << "#######################\n";
    }

    // returns true when move was successful, else false
    bool TicTacToe::playMove(int pos) {
        if (pos > 9 || pos < 0) {
            std::cout << "Invalid field position!" << '\n';
            return false;
        }
        if(field.at(pos) == emptyField){
            field.at(pos) = currentPlayer;
            return true;
        }
        std::cout << "Field is already occupied!" << '\n';
        return false;
    }

    bool TicTacToe::isGameOver() {
        if(checkDiagonal(currentPlayer) || checkVertical(currentPlayer) || checkHorizontal(currentPlayer)){
            std::cout << currentPlayer << " has won the game!!!!!!!!!!!\n";
            return true;
        }
        currentPlayer = currentPlayer == playerX ? playerO : playerX;
        return false;
    }

    bool TicTacToe::checkHorizontal(char player) {
        for (int i = 0; i < 9; i += 3) {
            if (field.at(i) == player && field.at(i + 1) == player && field.at(i + 2) == player) {
                return true;
            }

        }
        return false;
    }

    bool TicTacToe::checkVertical(char player) {
        for (int i = 0; i < 3; ++i) {
            if (field.at(i) == player && field.at(i + 3) == player && field.at(i + 6) == player) {
                return true;
            }

        }
        return false;
    }

    bool TicTacToe::checkDiagonal(char player){
        if(field.at(0) == player  && field.at(4) == player && field.at(8) == player){
            return true;
        }

        if(field.at(2) == player  && field.at(4) == player && field.at(6) == player){
            return true;
        }
        return false;
    }

