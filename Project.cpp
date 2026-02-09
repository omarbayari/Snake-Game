#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "Food.h"




using namespace std;

#define DELAY_CONST 50000


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

Player* playerPtr = nullptr; 
GameMechs* gameMechsPtr = nullptr; 
Food* foodPtr = nullptr; 



int main(void)
{

    Initialize();

    while(gameMechsPtr->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

     
    gameMechsPtr = new GameMechs();

    extern GameMechs* gameMechsPtr; 

    foodPtr = new Food(gameMechsPtr); 


    playerPtr = new Player(gameMechsPtr, foodPtr);




}

void GetInput(void)
{
    
    gameMechsPtr->setInput(gameMechsPtr->getInput());
}

void RunLogic(void)
{

    
    
    

    playerPtr->updatePlayerDir();

    playerPtr->movePlayer();

    if (playerPtr->checkSelfCollision())
    {
        gameMechsPtr->setLoseFlag();
        gameMechsPtr->setExitTrue();
    }

    if (gameMechsPtr->getNewFood() == true)
    {
        foodPtr->generateFood(playerPtr->getPlayerPos());

    }
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   
 

    

    for (int row = 0; row < gameMechsPtr->getBoardSizeY(); row++) {

        for (int col = 0; col < gameMechsPtr->getBoardSizeX(); col++) {

            if (row == 0 || row == gameMechsPtr->getBoardSizeY() - 1 || col == 0 || col == gameMechsPtr->getBoardSizeX() - 1) {

                MacUILib_printf("#");

            }

            else if (row == foodPtr->getFoodPos().getY() && col == foodPtr->getFoodPos().getX())
            {
                MacUILib_printf("%c", foodPtr->getFoodPos().getSymbol());
            }

            else 
            {
                bool snakebodypart = false; 
                for (int i =0; i<playerPtr->getPlayerPos()->getSize(); i++) 
                {
                    if (row == playerPtr->getPlayerPos()->getElement(i).getY() && col == playerPtr->getPlayerPos()->getElement(i).getX())
                    {
                        MacUILib_printf("%c", playerPtr->getPlayerPos()->getHeadElement().getSymbol());
                        snakebodypart = true;
                        break;
                    }
                }
                if(snakebodypart == false)
                {
                    MacUILib_printf(" ");
            }
        
            }
            
            }
        
        MacUILib_printf("\n");


    }
    MacUILib_printf("Score: %d\n", gameMechsPtr->getScore());
    if (gameMechsPtr->getExitFlagStatus() && gameMechsPtr->getLoseFlagStatus())
    {
        MacUILib_printf("GAME OVER! DON'T PLAY AGAIN!");
    }
    
}


void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{

    delete playerPtr;
    playerPtr = nullptr;
    delete gameMechsPtr;
    gameMechsPtr = nullptr;
    delete foodPtr;
    foodPtr = nullptr;


    MacUILib_uninit();

    
}