#include "Game.h"
#include <iostream>
#include <fstream>
#include "graph1.h"
using namespace std;

Game::Game(void)
{
	fileName = NULL;
	word = NULL;
}


Game::~Game(void)
{
	delete[] fileName;
	delete[] word;
}
char* Game::getFileName()
{
	char* buffer = new char[strlen(fileName) + 1 ];
	strcpy(buffer, fileName);
	return buffer;
}
void Game::setFileName(char* fn)
{
	this -> fileName = new char[strlen(fn) + 1];
	strcpy(this->fileName, fn);
}
void Game::setWord(int rand_no)
{
	int word_count = 0;
	char word[1000];

	//open fstream file
	fstream in_file(this->fileName, ios::in);

	if(!in_file)
	{
		cout<< "Cannot open " << this->fileName<<endl;
		exit(-1);
	}

	while(true)
	{
		//Read a word at a time
		in_file >> word;

		//test for eof

		if(in_file.eof())
		{
			break;
		}
		//compare word_count to rand_no
		if (word_count == rand_no)
			break;

		//OW increment word counter
		word_count++;
	}

	this -> word = new char[strlen(word) + 1];
	strcpy(this->word , word);
	
}
char* Game::getWord()
{
	char* buffer = new char[strlen(word) + 1];
	strcpy(buffer, word);
	return buffer;
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
