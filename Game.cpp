#include "Game.h"
#include<iostream>


Game::Game(void)
{
}


Game::~Game(void)
{
}

char* Game::getFileName()
{
}

void Game::setFileName(char* fn)
{
}

void Game::setWord(int rand_no)
{
}

char* Game::getWord()
{
}

void Game::draw() 
{
 int x=100;
 int y=250;
 int i=0;

 //Bananas
 bananas = new int[strlen(word)];

 for (i=0; word[i] != NULL; i++)
 {
	 if(i%2 == 0)
	 {
		bananas[i] = displayBMP("banana.bmp",125,65);	 
	 }
	 else
	 {
		bananas[i] = displayBMP("banana1.bmp",132,65);
	 }

 for (i = 0; word[i] != NULL; i++)
 {
   
	 //White Boxes
    drawRect(x,y,40,32);
 
 x+=45;
 }

 //Tree
	displayBMP("banana_tree.bmp",100,0);
	
//Line
	int line = drawLine(0,190,680,190);
	setColor(line,205,126,29);

//Text # of bananas
	gout<<setPos(400,100)<<"Number of Bananas: "<< endg;

//Letter Bank
char a = 'a';
char buffer[250];

	for(i=0; i<26; i++)
	{
		sprintf(buffer,"%c.bmp",a);
		if(i<14)
		displayBMP(buffer,100+(i*33),300);

		if(i>13)
		displayBMP(buffer,100+(i*33),333);
		
		a++;
	}
}

void Game::play()
{
}

