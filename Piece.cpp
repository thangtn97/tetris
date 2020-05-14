#include "Piece.hpp"

bool Piece::getBlock(int type, int rotate, int px, int py) {
  return pieces[type][rotate][px][py];
}
