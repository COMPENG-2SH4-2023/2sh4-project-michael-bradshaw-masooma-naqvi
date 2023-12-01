#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '*');

    // no heap member yet - never used new keyword
}


Player::~Player()
{
    // delete any heap members here

    // we can leave it empty for now
}

void Player::getPlayerPos(objPos &returnPos)
{
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic 
    
    char input = mainGameMechsRef->getInput();

    switch(input) 
    {
        case 'w':
            if(myDir != UP && myDir != DOWN)
            {
                myDir = UP;
            }
            break;

        case 'a':
            if(myDir != LEFT && myDir != RIGHT)
            {
                myDir = LEFT;
            }
            break;

        case 's':
            if (myDir != UP && myDir != DOWN)
            {
                myDir = DOWN;
            }
            break;

        case 'd':
            if(myDir != LEFT && myDir != RIGHT)
            {
                myDir = RIGHT;
            }
            break;
        
        default:
            break;
    }      
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    switch(myDir) 
    {
        // player wants to move up
        case UP:
            playerPos.y--;
            if(playerPos.y <= 0)
            {
                playerPos.y = mainGameMechsRef->getBoardSizeY()-2;
            }
            break;

        // player wants to move down
        case DOWN:
            playerPos.y++;
            if(playerPos.y >= mainGameMechsRef->getBoardSizeY())
            {
                playerPos.y = 1;
            }
            break;

        // player wants to move left
        case LEFT:
            playerPos.x--;
            if(playerPos.x <= 0)
            {
                playerPos.x = mainGameMechsRef->getBoardSizeX()-2;
            }
            break;

        // player wants to move right
        case RIGHT:
            playerPos.x++;
            if(playerPos.x >= mainGameMechsRef->getBoardSizeX())
            {
                playerPos.x = 1;
            }
            break;

        // default case
        default:
            break;

        

    }
}

