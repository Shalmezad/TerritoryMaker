#include "../include/territoryMap.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

territoryMap::territoryMap()
{
    //seed random generator
    srand(time(0));
    //initialize the map to 0's
    for(int i=0; i<GRIDWIDTH;i++){
        for(int j=0; j<GRIDHEIGHT; j++){
            tMap[i][j] = 0;
        }
    }
    //Pick the number of territories.
    numTerritories = (rand() % (MAXTERRITORIES-MINTERRITORIES)) + MINTERRITORIES;

    //1. Create a random amount of positions and use them to make some territories
    createSeeds();
}

void territoryMap::createSeeds()
{
    for(int i=1; i<=numTerritories; i++){
        int xPos,yPos;
        //pick a random not-taken position
        do{
            //pick a random xPos;
            xPos = rand() % GRIDWIDTH;
            //pick a random yPos;
            yPos = rand() % GRIDHEIGHT;
        }while(tMap[xPos][yPos] != 0);
        //make it the seed for this territory.
        tMap[xPos][yPos] = i;
    }
}

void territoryMap::printMap()
{
    for(int j=0; j<GRIDHEIGHT;j++){
        for(int i=0; i<GRIDWIDTH; i++){
            cout<<tMap[i][j];
        }
        cout<<endl;
    }
}
