#pragma once
#include "Piece.hpp"
#include <iostream>
#define WIDTH 10
#define HEIGHT 20
class Board {
  public:
    Board(Piece *piece);
    ~Board();
    void initBoard();
    void savePiece(int type, int rotate, int px, int py);
    void deleteLine(int py);
    void deletePossibleLine();
    bool isBlock(int px, int py);
    bool isColission(int type, int rotate, int px, int py);

    bool isGameOver();

  private:
    int board[WIDTH][HEIGHT];
    Piece *piece;
    
};
