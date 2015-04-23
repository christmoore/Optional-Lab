#include "Game.h"
#include <iostream>
#include <fstream>
#include "graph1.h"
#include <string>
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
 
 x+=33;
 }

 //Tree
	 displayBMP("banana_tree.bmp",100,0);
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

	
//Line
	int line = drawLine(0,190,680,190, 2);
	setColor(line,205,126,29);

//Text # of bananas
	gout<<setPos(400,100)<<"Number of Bananas: "<< endg;

//Letter Bank
char a = 'a';
char buffer[250];

	for(i=0; i<13; i++)
	{
		sprintf(buffer,"%c.bmp",a);
		displayBMP(buffer,100+(i*33),300);
		a++;
	}
	for(i = 0; i < 13; i++)
	{
		sprintf(buffer,"%c.bmp",a);
		displayBMP(buffer,100+(i*33),333);
		a++;
	}


}
void Game::play()
{
	int numbananas = strlen(word);
	int cx = 0;
	int cy = 0;
	bool display[26];
	char* compare = new char[strlen(word) + 1];
	bool guess = false;
	int bananaid = 0;
	int x = 125;
	int y = 65;
	int counter = 0;

	

	for(int i = 0; i < 26; i++)
	{
		display[i] = true;
	}

	do
	{

	gout<<setPos(400,100)<<"Number of Bananas: "<< numbananas << endg;

	if (leftMouse(cx,cy))
	{
		if(display[0] == true)
		{
			if (cx > 100 && cy > 300 && cx < 132 && cy < 332)
			{
				int obj = drawRect(100, 300, 32, 32);
				setColor(obj, 50, 50, 50);
				display[0] = false;
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 'a')
					{
						displayBMP("a.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[0] = false;
					}
				}
			}
		}
		if(display[1] == true)
		{
			if (cx > 133 && cy > 300 && cx < 165 && cy < 332)
			{
				int obj = drawRect(133, 300, 32, 32);
				setColor(obj, 50, 50, 50);
				display[1] = false;
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 'b')
					{
						displayBMP("b.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[1] = false;
					}
				}
			}
		}
		if(display[2] == true)
		{
			if (cx > 166 && cy > 300 && cx < 198 && cy < 332)
			{
				int obj = drawRect(166, 300, 32, 32);
				setColor(obj, 50, 50, 50);
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 'c')
					{
						displayBMP("c.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[2] = false;
					}
				}
			}
		}
		if(display[3] == true)
		{
			if (cx > 199 && cy > 300 && cx < 231 && cy < 332)
			{
				int obj = drawRect(199, 300, 32, 32);
				setColor(obj, 50, 50, 50);
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 'd')
					{
						displayBMP("d.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[3] = false;
					}
				}
			}
		}
		if(display[4] == true)
		{
			if (cx > 232 && cy > 300 && cx < 264 && cy < 332)
			{
				int obj = drawRect(232, 300, 32, 32);
				setColor(obj, 50, 50, 50);
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 'e')
					{
						displayBMP("e.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[4] = false;
					}
				}
			}
		}
		if(display[5] == true)
		{
			if (cx > 265 && cy > 300 && cx < 297 && cy < 332)
			{
				int obj = drawRect(265, 300, 32, 32);
				setColor(obj, 50, 50, 50);
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 'f')
					{
						displayBMP("f.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[5] = false;
					}
				}
			}
		}
		if(display[6] == true)
		{
			if (cx > 298 && cy > 300 && cx < 330 && cy < 332)
			{
				int obj = drawRect(298, 300, 32, 32);
				setColor(obj, 50, 50, 50);
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 'g')
					{
						displayBMP("g.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[6] = false;
					}
				}
			}
		}
		if(display[7] == true)
		{
			if (cx > 331 && cy > 300 && cx < 363 && cy < 332)
			{
				int obj = drawRect(331, 300, 32, 32);
				setColor(obj, 50, 50, 50);
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 'h')
					{
						displayBMP("h.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[7] = false;
					}
				}
			}
		}
		if(display[8] == true)
		{
			if (cx > 364 && cy > 300 && cx < 396 && cy < 332)
			{
				int obj = drawRect(364, 300, 32, 32);
				setColor(obj, 50, 50, 50);
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 'i')
					{
						displayBMP("i.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[8] = false;
					}
				}
			}
		}
		if(display[9] == true)
		{
			if (cx > 397 && cy > 300 && cx < 429 && cy < 332)
			{
				int obj = drawRect(397, 300, 32, 32);
				setColor(obj, 50, 50, 50);
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 'j')
					{
						displayBMP("j.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[9] = false;
					}
				}
			}
		}
		if(display[10] == true)
		{
			if (cx > 430 && cy > 300 && cx < 462 && cy < 332)
			{
				int obj = drawRect(430, 300, 32, 32);
				setColor(obj, 50, 50, 50);
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 'k')
					{
						displayBMP("k.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[10] = false;
					}	
				}
			}
		}
		if(display[11] == true)
		{
			if (cx > 463 && cy > 300 && cx < 495 && cy < 332)
			{
				int obj = drawRect(463, 300, 32, 32);
				setColor(obj, 50, 50, 50);
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 'l')
					{
						displayBMP("l.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[11] = false;
					}
				}
			}
		}
		if(display[12] == true)
		{
			if (cx > 496 && cy > 300 && cx < 528 && cy < 332)
			{
				int obj = drawRect(496, 300, 32, 32);
				setColor(obj, 50, 50, 50);
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 'm')
					{
						displayBMP("m.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[12] = false;
					}
				}
			}
		}
		if(display[13] == true)
		{
			if (cx > 100 && cy > 333 && cx < 132 && cy < 365)
			{
				int obj = drawRect(100, 333, 32, 32);
				setColor(obj, 50, 50, 50);
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 'n')
					{
						displayBMP("n.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[13] = false;
					}
				}
			}
		}
		if(display[14] == true)
		{
			if (cx > 133 && cy > 333 && cx < 165 && cy < 365)
			{
				int obj = drawRect(133, 333, 32, 32);
				setColor(obj, 50, 50, 50);
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 'o')
					{
						displayBMP("o.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[14] = false;
					}
				}
			}
		}
		if(display[15] == true)
		{
			if (cx > 166 && cy > 333 && cx < 198 && cy < 365)
			{
				int obj = drawRect(166, 333, 32, 32);
				setColor(obj, 50, 50, 50);
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 'p')
					{
						displayBMP("p.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[15] = false;
					}
				}
			}
		}
		if(display[16] == true)
		{
			if (cx > 199 && cy > 333 && cx < 231 && cy < 365)
			{
				int obj = drawRect(199, 333, 32, 32);
				setColor(obj, 50, 50, 50);
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 'q')
					{
						displayBMP("q.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[16] = false;
					}
				}
			}
		}
		if(display[17] == true)
		{
			if (cx > 232 && cy > 333 && cx < 264 && cy < 365)
			{
				int obj = drawRect(232, 333, 32, 32);
				setColor(obj, 50, 50, 50);
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 'r')
					{
						displayBMP("r.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[17] = false;
					}
				}
			}
		}
		if(display[18] == true)
		{
			if (cx > 265 && cy > 333 && cx < 297 && cy < 365)
			{
				int obj = drawRect(265, 333, 32, 32);
				setColor(obj, 50, 50, 50);
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 's')
					{
						displayBMP("s.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[18] = false;
					}
				}
			}
		}
		if(display[19] == true)
		{
			if (cx > 298 && cy > 333 && cx < 330 && cy < 365)
			{
				int obj = drawRect(298, 333, 32, 32);
				setColor(obj, 50, 50, 50);
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 't')
					{
						displayBMP("t.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[19] = false;
					}
				}
			}
		}
		if(display[20] == true)
		{
			if (cx > 331 && cy > 333 && cx < 363 && cy < 365)
			{
				int obj = drawRect(331, 333, 32, 32);
				setColor(obj, 50, 50, 50);
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 'u')
					{
						displayBMP("u.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[20] = false;
					}
				}
			}
		}
		if(display[21] == true)
		{
			if (cx > 364 && cy > 333 && cx < 396 && cy < 365)
			{
				int obj = drawRect(364, 333, 32, 32);
				setColor(obj, 50, 50, 50);
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 'v')
					{
						displayBMP("v.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[21] = false;
					}
				}
			}
		}
		if(display[22] == true)
		{
			if (cx > 397 && cy > 333 && cx < 429 && cy < 365)
			{
				int obj = drawRect(397, 333, 32, 32);
				setColor(obj, 50, 50, 50);
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 'w')
					{
						displayBMP("w.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[22] = false;
					}
				}
			}
		}
		if(display[23] == true)
		{
			if (cx > 430 && cy > 333 && cx < 462 && cy < 365)
			{
				int obj = drawRect(430, 333, 32, 32);
				setColor(obj, 50, 50, 50);
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 'x')
					{
						displayBMP("x.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[23] = false;
					}
				}
			}
		}
		if(display[24] == true)
		{
			if (cx > 463 && cy > 333 && cx < 495 && cy < 365)
			{
				int obj = drawRect(463, 333, 32, 32);
				setColor(obj, 50, 50, 50);
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 'y')
					{
						displayBMP("y.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[24] = false;
					}
				}
			}
		}
		if(display[25] == true)
		{
			if(cx > 496 && cy > 333 && cx < 528 && cy < 365)
			{
				int obj = drawRect(496, 333, 32, 32);
				setColor(obj, 50, 50, 50);
				for (size_t i = 0; i < strlen(word) + 1; i++)
				{
					if(word[i] == 'z')
					{
						displayBMP("z.bmp", 100 +(i*33),250);
						counter++;
						guess = true;
						display[25] = false;
					}
				}
			}
		}
		if(guess != true && cx > 100 && cx < 528 && cy > 300 && cy < 365)
		 {
			numbananas -= 1;
			for (int i = 65; i < 168; i++)
			{
				Sleep(10);
				moveObject(bananas[bananaid], x, y += 1);
			}
			removeObject(bananas[bananaid]);
			y = 65;

			bananaid++;
		}
		if(numbananas == 0)
		{
				clearGraphics();
				//Tree
 				displayBMP("banana_tree.bmp",100,0);
 				//Line
				int line = drawLine(0,190,680,190 , 2);
				setColor(line,205,126,29);
 				//Statements
 				gout<<setPos(400,100)<<"Number of Bananas: 0"<<endg;
 				gout<<setPos(400,115)<<"Game Over"<<endg;
 				gout<<setPos(400,130)<<"Correct Word is: "<<word<<endg;
				break;
		}
		if(strlen(word) == counter)
		{
			 clearGraphics();
			 gout << setPos(400, 100) <<"You Win!!!"<<endg;
			 break;
		}
		guess = false;
		
	}
}while(numbananas > 0);
}
