#include "Board.hpp"
#include "Piece.hpp"
Board::Board(Piece *piece){
  this->piece = piece;
  initBoard();
}
Board::~Board(){}

void Board::initBoard()
{
  for(int i=0; i<WIDTH; i++) {
    for(int j=0; j<HEIGHT; j++) {
      board[i][j] = 0;
    }
  }
}

void Board::savePiece(int type, int rotate, int px, int py) 
{
  for( int i1=px, i2=0; i1<px+4; i1++, i2++ ) {
    for(int j1=py, j2=0; j1<py+4; j1++, j2++) {
      if(piece->getBlock(type, rotate, i2, j2)) {
        board[i1][j1] = 1;
      }
    }
  }
}

void Board::deleteLine(int py) 
{
  for(int y=py-1; y>0; y--) {
    for(int x=1; x<WIDTH; x++) {
      board[x][y+1] = board[x][y];
    }
  }
  for(int x=1; x<WIDTH; x++) {
    board[x][0] = 0;
  }
}

void Board::deletePossibleLine() {
  for(int i=HEIGHT -1; i>=0; i--) {
    bool check = true;
    for(int j=1; j<WIDTH; j++) {
      if(board[j][i] == 0) {
        check = false;
        break;
      }
    }
    if(check) {
      deleteLine(i);
      i++;
    }
  }
}

bool Board::isBlock(int px, int py)
{
  return board[px][py] == 1 ? true : false;
}

bool Board::isColission(int type, int rotate, int px, int py) 
{
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) {
      if(piece->getBlock(type, rotate, i, j) != 0) {
        int x = px + i;
        int y = py + j;
        if(x<0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        {
          std::cout << "y = " << y << std::endl;
          return true;
        }
        if(board[x][y] == 1) return true;
      }
    }
  }
  return false;
}

bool Board::isGameOver() {
  for(int i=1; i<WIDTH; i++) {
    if(board[i][0]) return true;
  }
  return false;
}

