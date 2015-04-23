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
}
void Game::play()
{
}