#ifndef COMP345_PLAYER_H
#define COMP345_PLAYER_H

using namespace std;//change to individual usings

class Player {
    private:
        VGMap* village;
        Hand* hand;
        int* resourceTracker[4];
        ResourceGatherer* resourceGatherer;
        ScoreCounter* scoreCounter;

    public:
        Player(string villageName);
        ~Player();
        void PlaceHarvestTile(GBMap board, Tile tile, int location, int orientation);
        void DrawBuilding();
        void DrawHarvestTile();
        int* ResourceTracker();
        void BuildVillage(Building building, int location, bool flipped);
        void CalculateResources(int newTileLocation);
        VGMap getVillage();
        Hand getHand();
};

class ResourceGatherer{
    public:
        int* CollectResources(GBMap board, int newTileLocation);
};

class ScoreCounter{
    public:
        int CalculateScore(VGMap village);
};

#endif //COMP345_PLAYER_H
