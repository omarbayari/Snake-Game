#include "MacUILib.h"
#include "Food.h"
#include <cstdlib> 
#include <ctime>   
#include "Player.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"



Food::Food(GameMechs* thisGMRef):gameMechsRef(thisGMRef) 
{
    srand(static_cast<unsigned>(time(0))); 
    foodPos = objPos(0, 0, '$'); 
}

Food::~Food() {

}

void Food::generateFood(objPosArrayList* playerPosList) {
    int boardX = gameMechsRef->getBoardSizeX()-2;
    int boardY = gameMechsRef->getBoardSizeY()-2;

    bool isOnSnake;

    int newX, newY;
    do {
        newX = (rand() % boardX) + 1; 
        newY = (rand() % boardY) + 1; 


        isOnSnake = false;
        for (int i = 0; i < playerPosList->getSize(); i++) {
            if (newX == playerPosList->getElement(i).getX() && newY == playerPosList->getElement(i).getY()) 
            {
                isOnSnake = true;
                break; 
            } 
        }
    }
    while (isOnSnake);
    
    

    gameMechsRef->setNewFoodFalse();

    foodPos = objPos(newX, newY, '$'); 
}

objPos Food::getFoodPos() const {
    return foodPos;
}
