#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    boardSizeX = 30; 
    boardSizeY = 15;
    input = '\0'; 
    exitFlag = false; 
    loseFlag = false; 
    score = 0; 


}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY; 
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag; 
}
    

char GameMechs::getInput() const
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true; 
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }
    
    
}

void GameMechs::clearInput()
{
    input = '\0'; 

}


bool GameMechs::getNewFood()
{
    return newFood;
}

void GameMechs::setNewFoodTrue()
{
    newFood = true;
}
void GameMechs::setNewFoodFalse()
{
    newFood = false;
}


// More methods should be added here