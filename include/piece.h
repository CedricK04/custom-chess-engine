#ifndef PIECE_H
#define PIECE_H

#include <cstdint>

enum pieceType {
    NONE = 0b000,
    KING = 0b001,
    PAWN = 0b010,
    KNIGHT = 0b011,
    BISHOP = 0b100,
    ROOK = 0b101,
    QUEEN = 0b110
};

enum pieceColour {
    WHITE = 0b0000,
    BLACK = 0b1000
};

#endif