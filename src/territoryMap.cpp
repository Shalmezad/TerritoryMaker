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
