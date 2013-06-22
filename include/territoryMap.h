#ifndef TERRITORYMAP_H
#define TERRITORYMAP_H


const int GRIDWIDTH = 75;
const int GRIDHEIGHT = 50;
const int MAXTERRITORIES = 8;
const int MINTERRITORIES = 3;
const int MINGROWTH = 1000;
const int MAXGROWTH = 2500;

class territoryMap
{
    public:
        territoryMap();
        void printMap();
    protected:
    private:
        int tMap[GRIDWIDTH][GRIDHEIGHT];
        int numTerritories;
        void createSeeds();
        void branchTerritories();
        int nearbyTerritories(int, int);
        bool isLegal(int, int);
};

#endif // TERRITORYMAP_H
