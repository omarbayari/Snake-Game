#include "Player.h"
#include "objPosArrayList.h"
#include "Food.h"
#include "GameMechs.h"


Player::Player(GameMechs* thisGMRef, Food* foodref)
{
    mainGameMechsRef = thisGMRef;
    myDir = LEFT;
    mainFoodRef = foodref;
    
    // more actions to be included

    playerPosList = new objPosArrayList[20];
    objPos start =  {7, 15, 'o'};
    playerPosList->insertHead(start);

}


Player::~Player()
{
    // delete any heap members here
    delete[] playerPosList;

}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPosList;



}

void Player::updatePlayerDir()
{

    char input = mainGameMechsRef->getInput();
        // PPA3 input processing logic       
    if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case ' ':  // exit
                mainGameMechsRef->setExitTrue();
                break;
            case 'W':
            case 'w':
                if (myDir == LEFT || myDir == RIGHT)
                {
                    myDir = UP;
                }
                break;
            
            case 'a':
            case 'A':
                if (myDir == UP || myDir == DOWN)
                {
                    myDir = LEFT;
                }    
                break;

            case 's':
            case 'S':
                if (myDir == LEFT || myDir == RIGHT)
                {
                    myDir = DOWN;
                }
                break;
            
            case 'd':
            case 'D':
                if (myDir == UP || myDir == DOWN)
                {
                    myDir = RIGHT;
                }
                break;

            default:
                break;
        }
        mainGameMechsRef->clearInput();
    }

}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    int newX = playerPosList->getHeadElement().getX();
    int newY = playerPosList->getHeadElement().getY();

    switch (myDir)
    {
    case UP:
        newY -= 1;
        break;
    case DOWN:
        newY +=1;
        break;

    case LEFT:
        newX -= 1;
        break;

    case RIGHT:
        newX += 1;
        break;

    default:
        break;
    }    
        
    if (newX < 1) newX = mainGameMechsRef->getBoardSizeX() - 2;     
    else if (newX > mainGameMechsRef->getBoardSizeX() - 2) newX = 1;    
    else if (newY < 1) newY = mainGameMechsRef->getBoardSizeY() - 2;    
    else if (newY > mainGameMechsRef->getBoardSizeY() - 2) newY = 1;

    objPos newPos = objPos(newX, newY, 'o'); 

    




    if (newX == mainFoodRef->getFoodPos().getX() && newY == mainFoodRef->getFoodPos().getY())
    {
        objPos newHead = objPos(mainFoodRef->getFoodPos().getX(), mainFoodRef->getFoodPos().getY(), 'o');
        playerPosList->insertHead(newHead);
        mainGameMechsRef->setNewFoodTrue();
        mainGameMechsRef->incrementScore();

    }
    else{
        playerPosList->insertHead(newPos);
        playerPosList->removeTail();
    }
    

}

bool Player::checkSelfCollision()
{
    
    for (int i = 1; i < playerPosList->getSize(); i++)
    {
        
        if (playerPosList->getHeadElement().getX() == playerPosList->getElement(i).getX() && playerPosList->getHeadElement().getY() == playerPosList->getElement(i).getY() )
        {
            return true;
        }
        
    }
    return false;
    
}

// More methods to be added