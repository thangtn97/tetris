#include "Game.hpp"
#include "Piece.hpp"
#include "Board.hpp"
#include  <cstdlib>
#include  <ctime>

Board *board = nullptr;
Piece *piece = nullptr;
Game::Game(){
  piece = new Piece();
  board = new Board(piece);
}
Game::~Game(){}

void Game::init(const char*title, int xpos, int ypos, int width, int height, bool fullscr)
{
  int flags = 0;
  if(fullscr) 
  {
    flags = SDL_WINDOW_FULLSCREEN;
  }
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    std::cout << "SubSystem init..." << std:: endl;
    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if(window)
    {
      std::cout << "Window created..." << std:: endl;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer) {
      std::cout << "Renderer cretated..." << std::endl;
    }
    isRunning = true;
    createNewPiece();
  }
  else {
    isRunning = false;
  }

}

void Game::handleEvent()
{
  SDL_Event event;
  SDL_PollEvent(&event);
  if(board->isGameOver()) isRunning = false;
  else{
    if (SDL_WaitEventTimeout(&event, 125)) {
   switch(event.type) {
     case SDL_QUIT:
       isRunning = false;
       break;
     case SDL_KEYDOWN:
       switch(event.key.keysym.sym) {
         case SDLK_UP:{
           if(!board->isColission(cType, (cRotate+1)%4, cPx, cPy)) {
           cRotate = (cRotate+1)%4;
           }
           break;
         }
           
         case SDLK_LEFT: {
           if(!board->isColission(cType, cRotate, cPx-1, cPy)) {
             cPx--;
           }
           break;
         }
         case SDLK_RIGHT: {
           if(!board->isColission(cType, cRotate, cPx+1, cPy)) {
             cPx++;
           }
           break;
         }
      }
     default:
       break;
    }
  }
  }
  
}

void Game::update()
{
  if(!board->isColission(cType, cRotate, cPx, cPy+1)) {
    cPy++;
  }else {
    board->savePiece(cType, cRotate, cPx, cPy);
    board->deletePossibleLine();
    createNewPiece();
  }
}

void Game::render()
{
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
  SDL_RenderClear(renderer);
  drawBoard();
  drawPiece(cType, cRotate, cPx, cPy);
  SDL_RenderPresent(renderer);
}

void Game::clean()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Game Cleaned" << std::endl;
}

void Game::createNewPiece() 
{
  srand(time(NULL));
  cType = rand() % 6;
  cRotate = rand() % 3;
  cPx = WIDTH / 2;
  cPy = 0;
}

void Game::drawPiece(int type, int rotate, int px, int py) {
  SDL_SetRenderDrawColor(renderer, 365, 365, 365, 365);
  for(int i = 0; i < 4; i++) {
    for(int j=0; j<4; j++){
      if(piece->getBlock(type, rotate, i, j) == 1) {
        std::cout << type << std::endl;
        std::cout << py << std::endl;
        SDL_Rect rect{(px+i)*18, (py+j)*18, 17, 17};
        SDL_RenderFillRect(renderer, &rect);
      }
    }
  }
}

void Game::drawBoard()
{
  SDL_SetRenderDrawColor(renderer, 365, 365, 365, 365);
  for(int i=0; i<WIDTH; i++) {
    for(int j=0; j<HEIGHT; j++) {
      if(board->isBlock(i,j)) {
        SDL_Rect rect{i*18, j*18, 17, 17};
        SDL_RenderFillRect(renderer, &rect);
      }
    }
  }
}
