#ifndef TERRITORYMAP_H
#define TERRITORYMAP_H


const int GRIDWIDTH = 75;
const int GRIDHEIGHT = 50;
const int MAXTERRITORIES = 8;
const int MINTERRITORIES = 3;


class territoryMap
{
    public:
        territoryMap();
        void printMap();
    protected:
    private:
        int tMap[GRIDWIDTH][GRIDHEIGHT];
        int numTerritories;
};

#endif // TERRITORYMAP_H
