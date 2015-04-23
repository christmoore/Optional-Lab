#include <iostream>
#include "graph1.h"
#include "Game.h"
#include <time.h>
using namespace std;
 void main()
{//Variable Declaration/Initialization
  int rand_no = 0;
  char fn[255];
  char repeat = 'y';
  Game game;
  
  //Display graphics
  displayGraphics();

  //Initialize random # generator
  srand(time(0));

  //Run program as many times as desired
  do
  {

    //Generate random #
    rand_no = rand()%1149;

    //Prompt for fn
    cout << "Enter filename that contains words: ";
    cin >> fn;

    //Set the filename
    game.setFileName(fn);

    //Set the word
    game.setWord(rand_no);

    //Draw the scene
    game.draw();

	  //Get the word
    char* temp = game.getWord();

    //Display the actual word
    cout << "Random word is: " << temp << endl;

    cout << "Repeat? (y/n): ";
    cin >> repeat;

    //Clear screen
    system("cls");
    clearGraphics();

    //Cleanup memory
    delete[] temp;

  }while ( (repeat == 'y') || (repeat == 'Y') );
 }