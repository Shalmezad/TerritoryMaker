#include <iostream>
#include "include/territoryMap.h"

using namespace std;

int main()
{
    territoryMap tM;
    tM.printFancyMap();
    return 0;


//7:30 [Aceeri] 1. Create a random amount of positions and use them to make some territories
//7:30 [Aceeri] 2. Branch off those territories
//7:30 [Aceeri] 3. Check with a loop if there are any stragglers (tiles without territories) and if so, make a new territory in that place and branch it
//7:31 [Aceeri] 4. Check it again to see if there are any stragglers

//7:31 [Aceeri] 5. If not, move on to checking if the territories are too small (under 40 tiles)
//7:32 [Aceeri] 6. Branch on it until it is larger than 40 and check again
//7:32 [Aceeri] 7. Split up the territories into a random number of counties, 2-13 counties

}
