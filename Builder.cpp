#include "Builder.h"
#include "Cell.h"
#include "Unit.h"
#include <iostream>
#include <map>

std::map < Cell::Landscape, int> Builder::DefenceBonusMap;

Builder::Builder(int h, int d, Cell& c) : Unit <UnitType::Civil, LandingType::Land> ( h, d, c)
{
	std::cout << "Builder(int h, damage d, Cell& c) : health (h), damage(d), cell(c)" << std::endl;
}

std::map<Cell::Landscape, int> Builder::getDefenceBonusMap()
{

	DefenceBonusMap.insert(std::make_pair(Cell::Landscape::Water, 2));
	DefenceBonusMap.insert(std::make_pair(Cell::Landscape::Grass, 1));
	DefenceBonusMap.insert(std::make_pair(Cell::Landscape::Sand, 3));
	DefenceBonusMap.insert(std::make_pair(Cell::Landscape::Soil, 3));
	DefenceBonusMap.insert(std::make_pair(Cell::Landscape::Marsh, 1));
	DefenceBonusMap.insert(std::make_pair(Cell::Landscape::Forest, 5));
	
	return this->DefenceBonusMap;
}

Builder::~Builder()
{
	std::cout << "Builder::~Builder()" << std::endl;
}