#ifndef TERRITORYMAP_H
#define TERRITORYMAP_H


const int GRIDWIDTH = 75;
const int GRIDHEIGHT = 50;
const int GRIDSIZE = GRIDHEIGHT * GRIDWIDTH;
const int MAXTERRITORIES = 7;
const int MINTERRITORIES = 4;
const int MINGROWTH = GRIDSIZE * .50;
const int MAXGROWTH = GRIDSIZE * .80;

class territoryMap
{
    public:
        territoryMap();
        void printMap();
        void printFancyMap();
    protected:
    private:
        int tMap[GRIDWIDTH][GRIDHEIGHT];

        int numTerritories;
        void createSeeds();
        void branchTerritories();
        void fillGaps();
        int nearbyTerritories(int, int);
        int getNeighbors(int, int);
        bool isLegal(int, int);
};

#endif // TERRITORYMAP_H
