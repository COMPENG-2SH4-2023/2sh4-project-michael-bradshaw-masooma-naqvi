#include "GameMechs.h"

GameMechs::GameMechs()
{

}

GameMechs::GameMechs(int boardX, int boardY)
{

}

// do you need a destructor?


bool GameMechs::getExitFlagStatus()
{

}

char GameMechs::getInput()
{

}

int GameMechs::getBoardSizeX()
{

}

int GameMechs::getBoardSizeY()
{

}


void GameMechs::setExitTrue()
{

}

void GameMechs::setInput(char this_input)
{

}

void GameMechs::clearInput()
{

}

Food::Food(objPos &blockOff){
    generateFood(objPos blockOff);
}

Food::~Food(){
    
}


void Food::generateFood(objPos &blockOff){
    srand(time(NULL));
    int randomX = 0;
    int randomY = 0;
    while !(randomX == blockOff.x && randomX == blockOff.y){
        randomX = rand()%getBoardSizeX();
        randomY = rand()%getBoardSizeY();
    }
    foodPos.x = randomX;
    foodPOs.y = randomY; 
    foodPos.symbol = 'A';
    active = 1; //Meaning that this food is in use.
}
void Food::getFoodPos(objPos &returnPos){
    foodPos.getObjPos(returnPos));
}