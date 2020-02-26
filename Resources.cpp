//
// Resources.cpp
// Assignment 1 Part 5
// Created by Alexandre Briere on 02-12-2020
//

#include "Resources.h"
#include <string>
#include <vector>
#include <cmath>
#include <stdlib.h>

using namespace std;

// HARVEST TILE CLASS ------------------------------------------------------------------------------------------

HarvestTile::HarvestTile() {

}
HarvestTile::HarvestTile(int indexOfHT) {

	switch (indexOfHT) {
		// 3 Different Resources Harvest Tiles

	case 1:  topLeft = "Stone";  topRight = "Stone";  bottomLeft = "Wheat";  bottomRight = "Sheep"; break;
	case 2:  topLeft = "Stone";  topRight = "Stone";  bottomLeft = "Wheat";  bottomRight = "Timber"; break;
	case 3:  topLeft = "Stone";  topRight = "Stone";  bottomLeft = "Sheep";  bottomRight = "Timber"; break;
	case 4:  topLeft = "Timber";  topRight = "Timber";  bottomLeft = "Sheep";  bottomRight = "Stone"; break;
	case 5:  topLeft = "Timber";  topRight = "Timber";  bottomLeft = "Wheat";  bottomRight = "Stone"; break;
	case 6:  topLeft = "Timber";  topRight = "Timber";  bottomLeft = "Sheep";  bottomRight = "Wheat"; break;
	case 7:  topLeft = "Wheat";  topRight = "Wheat";  bottomLeft = "Sheep";  bottomRight = "Stone"; break;
	case 8:  topLeft = "Wheat";  topRight = "Wheat";  bottomLeft = "Sheep";  bottomRight = "Timber"; break;
	case 9:  topLeft = "Wheat";  topRight = "Wheat";  bottomLeft = "Stone";  bottomRight = "Timber"; break;
	case 10: topLeft = "Sheep";  topRight = "Sheep";  bottomLeft = "Stone";  bottomRight = "Timber"; break;
	case 11: topLeft = "Sheep";  topRight = "Sheep";  bottomLeft = "Stone";  bottomRight = "Wheat"; break;
	case 12: topLeft = "Sheep";  topRight = "Sheep";  bottomLeft = "Wheat";  bottomRight = "Timber"; break;
		
		// 2 Different Resources Harvest Tiles

	case 13: topLeft = "Stone";  topRight = "Stone";  bottomLeft = "Stone";  bottomRight = "Sheep"; break;
	case 14: topLeft = "Stone";  topRight = "Stone";  bottomLeft = "Stone";  bottomRight = "Timber"; break;
	case 15: topLeft = "Stone";  topRight = "Stone";  bottomLeft = "Stone";  bottomRight = "Wheat"; break;
	case 16: topLeft = "Timber";  topRight = "Timber";  bottomLeft = "Timber";  bottomRight = "Wheat"; break;
	case 17: topLeft = "Timber";  topRight = "Timber";  bottomLeft = "Timber";  bottomRight = "Sheep"; break;
	case 18: topLeft = "Timber";  topRight = "Timber";  bottomLeft = "Timber";  bottomRight = "Stone"; break;
	case 19: topLeft = "Wheat";  topRight = "Wheat";  bottomLeft = "Wheat";  bottomRight = "Stone"; break;
	case 20: topLeft = "Wheat";  topRight = "Wheat";  bottomLeft = "Wheat";  bottomRight = "Timber"; break;
	case 21: topLeft = "Wheat";  topRight = "Wheat";  bottomLeft = "Wheat";  bottomRight = "Sheep"; break;
	case 22: topLeft = "Sheep";  topRight = "Sheep";  bottomLeft = "Sheep";  bottomRight = "Stone"; break;
	case 23: topLeft = "Sheep";  topRight = "Sheep";  bottomLeft = "Sheep";  bottomRight = "Timber"; break;
	case 24: topLeft = "Sheep";  topRight = "Sheep";  bottomLeft = "Sheep";  bottomRight = "Wheat"; break;

	}
}

// Destructor method

HarvestTile::~HarvestTile() {

}

// Accessor and mutator methods

string HarvestTile::getTopLeftResource() {
	return topLeft;
}

string HarvestTile::getTopRightResource() {
	return topRight;
}

string HarvestTile::getBottomLeftResource() {
	return bottomLeft;
}

string HarvestTile::getBottomRightResource() {
	return bottomRight;
}

void HarvestTile::setTopLeftResource(string resource) {
	TopLeft = resource;
}
void HarvestTile::setTopRightResource(string resource) {
	TopRight = resource;
}
void HarvestTile::setBottomLeftResource(string resource) {
	BottomLeft = resource;
}
void HarvestTile::setBottomRightResource(string resource) {
	BottomRight = resource;
}

// Harvest Tile Deck CLASS

// Constructor
HarvestTileDeck::HarvestTileDeck() {
	if (harvestTiles.size() == 0) {
		for (int i = 0; i < 60; i++) {
			HarvestTile* pointer = new HarvestTile(rand() % 24 + 1);
			harvestTiles.emplace_back(pointer);
		}
		random_shuffle(harvestTiles.begin(), harvestTiles.end());
	}
}

// Destructor
HarvestTileDeck::~HarvestTileDeck() {
	harvestTiles.clear();
}

// Method that returns a pointer to the harvest tile drawn from the deck
HarvestTile* HarvestTileDeck::drawHarvestTile() {
	HarvestTile &temp = *harvestTiles.back();
	harvestTiles.pop_back();
	return &temp;
}


// Returns the number of harvest tiles in the deck
int HarvestTileDeck::howManyHarvestTiles() {
	return harvestTiles.size();
}

// BUILDING CLASS ------------------------------------------------------------------------------------------

Building::Building() {

}
Building::Building(int indexOfB) {

	switch (indexOfB) {
		// 6 Buildings for green

	case 1: number = 1; color = "Green"; label = "Meadow"; break;
	case 2: number = 2; color = "Green"; label = "Meadow"; break;
	case 3: number = 3; color = "Green"; label = "Meadow"; break;
	case 4: number = 4; color = "Green"; label = "Meadow"; break;
	case 5: number = 5; color = "Green"; label = "Meadow"; break;
	case 6: number = 6; color = "Green"; label = "Meadow"; break;

		// 6 Buildings for gray
	case 7: number = 1; color = "Gray"; label = "Quarry"; break;
	case 8: number = 2; color = "Gray"; label = "Quarry"; break;
	case 9: number = 3; color = "Gray"; label = "Quarry"; break;
	case 10: number = 4; color = "Gray"; label = "Quarry"; break;
	case 11: number = 5; color = "Gray"; label = "Quarry"; break;
	case 12: number = 6; color = "Gray"; label = "Quarry"; break;

		// 6 Buildings for red
	case 13: number = 1; color = "Red"; label = "Forest"; break;
	case 14: number = 2; color = "Red"; label = "Forest"; break;
	case 15: number = 3; color = "Red"; label = "Forest"; break;
	case 16: number = 4; color = "Red"; label = "Forest"; break;
	case 17: number = 5; color = "Red"; label = "Forest"; break;
	case 18: number = 6; color = "Red"; label = "Forest"; break;

		// 6 Buildings for yellow
	case 19: number = 1; color = "Yellow"; label = "Wheatfield"; break;
	case 20: number = 2; color = "Yellow"; label = "Wheatfield"; break;
	case 21: number = 3; color = "Yellow"; label = "Wheatfield"; break;
	case 22: number = 4; color = "Yellow"; label = "Wheatfield"; break;
	case 23: number = 5; color = "Yellow"; label = "Wheatfield"; break;
	case 24: number = 6; color = "Yellow"; label = "Wheatfield"; break;

	}
}

// Destructor method

Building::~Building() {

}

// Accessor methods

int Building::getNumber() {
	return number;
}

string Building::getColor() {
	return color;
}


string Building::getLabel() {
	return label;
}

// Building Deck CLASS

// Constructor
BuildingDeck::BuildingDeck() {
	if (buildings.size() == 0) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 24; j++) {
				Building* pointer = new Building(j);
				buildings.emplace_back(pointer);
			}
		}
		random_shuffle(buildings.begin(), buildings.end());
	}
}

// Destructor
BuildingDeck::~BuildingDeck() {
	buildings.clear();
}


// Method that returns a pointer to the building drawn from the deck
Building* BuildingDeck::drawBuilding() {
	Building &temp = *buildings.back();
	buildings.pop_back();
	return &temp;
}

// Returns the number of buildings in the deck
int BuildingDeck::howManyBuildings() {
	return buildings.size();
}



// HAND OBJECT CLASS ------------------------------------------------------------------------------------------




// Constructor

HandObject::HandObject() {
	for (int i = 0; i < 2; i++) {
		displayHarvestTiles[i] = harvestTiles->drawHarvestTile();
	}
	for (int i = 0; i < 6; i++) {
		displayBuildings[i] = buildings->drawBuilding();
	}
}

// Destuctors

HandObject::~HandObject() {

}

void HandObject::deleteBuilding(int indexOfBuilding) {
	for(int i = indexOfBuilding; i<5, i++)
		displayBuildings[i]=displayBuildings[i+1]
}

void HandObject::deleteHarvestTile(int indexOfHarvestTile) {
	for (int i = indexOfHarvestTile; i<1, i++)
		displayHarvestTiles[i] = displayHarvestTiles[i + 1]
}

// exchange() method that allows the player to select the Harvest tile from 
// its position in the row and the column on the Game Board and assign the
// resource markers a value of the accumulated resources from the Harvest Tiles

void HandObject::exchange(GBMap board, int playerID, int indexOfHarvestTile, string position, int orientation) {

	HarvestTile* pointer = displayHarvestTiles[indexOfHarvestTile];

	for{i = 1; i < orientation; i++ } {
		// Store top left resource temporarily
		string* temp = pointer->getTopLeftResource();
		// Shift resources on tile 90 degrees
		pointer->setTopLeftResource(pointer->getBottomLeftResource());
		pointer->setBottomLeftResource(pointer->getBottomRightResource());
		pointer->setBottomRightResource(pointer->getTopRightResource());
		pointer->setTopRightResource(temp);
	}

	//Creating data based on tile to input into setTileData() function

	double TileData;

	// 1st digit of data

	if (pointer->getTopLeftResource == "Wheat")
		TileData = TileData + 10000;
	else if (pointer->getTopLeftResource == "Timber")
		TileData = TileData + 20000;
	else if (pointer->getTopLeftResource == "Stone")
		TileData = TileData + 30000;
	else if (pointer->getTopLeftResource == "Sheep")
		TileData = TileData + 40000;
	// 2nd digit of data

	if (pointer->getTopRightResource == "Wheat")
		TileData = TileData + 1000;
	else if (pointer->getTopRightResource == "Timber")
		TileData = TileData + 2000;
	else if (pointer->getTopRightResource == "Stone")
		TileData = TileData + 3000;
	else if (pointer->getTopRightResource == "Sheep")
		TileData = TileData + 4000;

	// 3rd digit of data

	if (pointer->getBottomLeftResource == "Wheat")
		TileData = TileData + 100;
	else if (pointer->getBottomLeftResource == "Timber")
		TileData = TileData + 200;
	else if (pointer->getBottomLeftResource == "Stone")
		TileData = TileData + 300;
	else if (pointer->getBottomLeftResource == "Sheep")
		TileData = TileData + 400;

	// 4th digit of data

	if (pointer->getBottomRightResource == "Wheat")
		TileData = TileData + 10;
	else if (pointer->getBottomRightResource == "Timber")
		TileData = TileData + 20;
	else if (pointer->getBottomRightResource == "Stone")
		TileData = TileData + 30;
	else if (pointer->getBottomRightResource == "Sheep")
		TileData = TileData + 40;

	// 5th digit of data

	TileData = TileData + playerID;

	// Set the tile on the board using the data generated

	board->setTileData(position, TileData)

	// Delete placed harvest tile from hand

	deleteHarvestTile(indexOfHarvestTile);

	// Draw new harvest tile to replace it

	displayHarvestTile[1]= harvestTiles->drawHarvestTile();
}

// Method that draws a harvest tile directly to the hand
void HandObject::drawHarvestTile() {
	HarvestTile &temp = *harvestTiles.back();
	harvestTiles.pop_back();
	displayHarvestTiles[1] = &temp;
}

// Method that draws a building directly to the hand
void HandObject::drawBuilding() {
	Building &temp = *buildings.back();
	buildings.pop_back();
	for (int i = displayBuildings.size() - 1; i >= 0; i--)
		displayBuildings[i + 1] = displayBuildings[i]
		displayBuildings[0] = &temp;
}

// To String object.
void HandObject::toString() {
	for (int i = 0; i < displayHarvestTiles.length(); i++) {
		cout << "\nThe harvest tile in position " << i + 1 <<  << "\t Top Left: " << displayHarvestTiles[i]->getTopLeftResource() << endl << "\t Top Right: " << displayHarvestTiles[i]->getTopRighttResource() << endl << "\t Bottom Left: " << displayHarvestTiles[i]->getBottomLeftResource() << endl << "\t Bottom Right: " << displayHarvestTiles[i]->getBottomRightResource() << endl;
	}
	for (int j = 0; j < displayBuildings.length(); j++) {
		cout << "\nThe building in position " << j + 1 <<  << "\t Number: " << displayBuildings[j]->getNumber() << endl << "\t Color: " << displayBuildings[j]->getColor() << endl << "\t Label: " << displayBuildings[j]->getLabel() << endl;
	}
}
