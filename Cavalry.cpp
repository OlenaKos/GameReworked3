#include "Cavalry.h"
#include "Cell.h"
#include "LandUnit.h"
#include <iostream>
#include <map>

std::map <Cell::Landscape, int> Cavalry::AttackBonusMap;
std::map < Cell::Landscape, int> Cavalry::DefenceBonusMap;

Cavalry::Cavalry(int h, int d, Cell& c) : Unit <UnitType::Military, LandingType::Land >(h,d,c)
{
	setUnitType("Cavalry");
	std::cout << "Cavalry(int h, damage d, Cell& c) : health (h), damage(d), cell(c)" << std::endl;
}

std::map<Cell::Landscape, int> Cavalry::getAttackBonusMap()
{
	AttackBonusMap.insert(std::make_pair(Cell::Landscape::Water, -2));
	AttackBonusMap.insert(std::make_pair(Cell::Landscape::Grass, 10));
	AttackBonusMap.insert(std::make_pair(Cell::Landscape::Sand, 7));
	AttackBonusMap.insert(std::make_pair(Cell::Landscape::Soil, 10));
	AttackBonusMap.insert(std::make_pair(Cell::Landscape::Marsh, 5));
	AttackBonusMap.insert(std::make_pair(Cell::Landscape::Forest, 7));
	return this->AttackBonusMap;
}

std::map<Cell::Landscape, int> Cavalry::getDefenceBonusMap()
{
	DefenceBonusMap.insert(std::make_pair(Cell::Landscape::Water, 2));
	DefenceBonusMap.insert(std::make_pair(Cell::Landscape::Grass, 1));
	DefenceBonusMap.insert(std::make_pair(Cell::Landscape::Sand, 3));
	DefenceBonusMap.insert(std::make_pair(Cell::Landscape::Soil, 3));
	DefenceBonusMap.insert(std::make_pair(Cell::Landscape::Marsh, 1));
	DefenceBonusMap.insert(std::make_pair(Cell::Landscape::Forest, 5));
	return this->DefenceBonusMap;
}


Cavalry::~Cavalry()
{
   std::cout << "Cavalry::~Cavalry()" << std::endl;
}