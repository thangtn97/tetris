#ifndef Game_hpp
#define Game_hpp

#include "SDL2/SDL.h"
#include "Piece.hpp"
#include "Board.hpp"
#include <iostream>

class Game {
  public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscr);
    void handleEvent();
    void update();
    void render();
    void clean();

    void drawBoard();
    void drawPiece(int type, int rotate, int px, int py);
    void createNewPiece();

    bool running(){ return isRunning; }
  private:
    int count = 0;
    int cType, cRotate, cPx, cPy;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif 
