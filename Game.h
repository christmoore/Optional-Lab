#ifndef GAME_H
#define GAME_H

#include "GenPoint.h"

class Game
{
  private:
    char* fileName;
    char* word;
    int* bananas; //Array of object numbers for each banana image
    GenPoint* keys_ul;  //Array of GenPoint for upper left coordinates
    GenPoint* keys_lr;  //Array of GenPoint for lower right coordinates
    

  public:
    Game();
    ~Game();
    char* getFileName();
    void setFileName(char* fn);
    void setWord(int rand_no);
    char* getWord();
    void draw();  
    void play();

};

#endif