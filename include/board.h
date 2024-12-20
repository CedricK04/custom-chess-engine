#ifndef BOARD_H
#define BOARD_H

#include "piece.h"

class Board {
public:
    Board();
    ~Board();

    uint8_t board[32];
};

const uint8_t standardSetup[32] {
    0b11011011, //black rook - black knight | A8 - B8
    0b11001110, //black bishop - black queen | C8 - D8
    0b10011100, //black king - black bishop | E8 - F8
    0b10111101, //black knight - black rook | G8 - H8

    0b10101010, //black pawn x8 | A7 - B7
    0b10101010, //C7 - D7
    0b10101010, //E7 - F7
    0b10101010, //G7 - H7

    0b00000000, //none x32 | A6 - B6
    0b00000000, //C6 - D6
    0b00000000, //E6 - F6
    0b00000000, //G6 - H6
    0b00000000, //A5 - B5
    0b00000000, //C5 - D5
    0b00000000, //E5 - F5
    0b00000000, //G5 - H5
    0b00000000, //A4 - B4
    0b00000000, //C4 - D4
    0b00000000, //E4 - F4
    0b00000000, //G4 - H4
    0b00000000, //A3 - B3
    0b00000000, //C3 - D3
    0b00000000, //E3 - F3
    0b00000000, //G3 - H3

    0b00100010, //white pawn x8 | A2 - B2
    0b00100010, //C2 - D2
    0b00100010, //E2 - F2
    0b00100010, //G2 - H2

    0b01010011, //white rook - white knight | A1 - B1
    0b01000110, //white bishop - white queen | C1 - D1
    0b00010100, //white king - white bishop | E1 - F1
    0b00110101  //white knight - white rook | G1 - H1
};

#endif // BOARD_H