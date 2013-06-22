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
    branchTerritories();
    fillGaps();
}

void territoryMap::fillGaps(){
    //go through each square.
    for(int i=0; i<GRIDWIDTH; i++){
        for(int j=0; j<GRIDHEIGHT; j++){
            //should we worry about this square?
            if(tMap[i][j] == 0){
                //get the number of neighbors
                int neighbors = getNeighbors(i,j);
                //do we have too many for being a blank square?
                if(neighbors >= 3){
                    //fill
                    tMap[i][j] = nearbyTerritories(i,j);
                }
            }
        }
    }
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

void territoryMap::branchTerritories()
{
    //Alright, so we need to "grow" territories.
    //let's cycle through. A lot.
    int growthLimit = (rand() % (MAXGROWTH-MINGROWTH)) + MINGROWTH;
    while(growthLimit > 0){
        //pick a spot.
        int xPos = rand() % GRIDWIDTH;
        int yPos = rand() % GRIDHEIGHT;

        //Can we grow it?
        if(tMap[xPos][yPos] == 0){
            int neighbor = nearbyTerritories(xPos, yPos);
            if(neighbor != 0){
                //success! Grow!
                tMap[xPos][yPos] = neighbor;
                // subtract from growth limit
                growthLimit--;
            }
        }
    }
}

bool territoryMap::isLegal(int x, int y)
{
    if(x < 0 || x >= GRIDWIDTH){
        return false;
    }
    if(y < 0 || y >= GRIDHEIGHT){
        return false;
    }
    return true;
}

int territoryMap::getNeighbors(int xPos, int yPos){
    int neighbors = 0;
    //up?
    if(isLegal(xPos,yPos-1)){
        if(tMap[xPos][yPos-1] != 0){
            neighbors++;
        }
    }
    //try down?
    if(isLegal(xPos, yPos+1)){
        if(tMap[xPos][yPos+1] != 0){
            neighbors++;
        }
    }
    //try left?
    if(isLegal(xPos-1, yPos)){
        if(tMap[xPos-1][yPos] != 0){
            neighbors++;
        }
    }
    //try right?
    if(isLegal(xPos+1, yPos)){
        if(tMap[xPos+1][yPos] != 0){
            neighbors++;
        }
    }
    return neighbors;
}

int territoryMap::nearbyTerritories(int xPos, int yPos)
{
    //try up?
    if(isLegal(xPos, yPos-1)){
        if(tMap[xPos][yPos-1] != 0){
            return tMap[xPos][yPos-1];
        }
    }
    //try down?
    if(isLegal(xPos, yPos+1)){
        if(tMap[xPos][yPos+1] != 0){
            return tMap[xPos][yPos+1];
        }
    }
    //try left?
    if(isLegal(xPos-1, yPos)){
        if(tMap[xPos-1][yPos] != 0){
            return tMap[xPos-1][yPos];
        }
    }
    //try right?
    if(isLegal(xPos+1, yPos)){
        if(tMap[xPos+1][yPos] != 0){
            return tMap[xPos+1][yPos];
        }
    }


    return 0;
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
