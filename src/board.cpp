#include "board.h"

Board::Board() {
    for (uint8_t i = 0; i < 32; i++) {
        board[i] = standardSetup[i];
    }
}

Board::~Board() {
}