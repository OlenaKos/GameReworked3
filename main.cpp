#include "Unit.h"
#include "Factory.h"
#include "Cell.h"
#include <string>
#include <iostream>

Factory<UnitType::Military, LandingType::Land>* getDepartment(const std::string &);

int main(int argv, char* argc[])
{
   std::string unitType = "cavalry";//argc[1];
   Cell::Landscape land = Cell::Landscape::Grass;
   Cell* myCell = new Cell(land);
   Factory<UnitType::Military, LandingType::Land> factory;
   factory.addDepartment(getDepartment(unitType));
   Unit<UnitType::Military, LandingType::Land>* unit = factory.getUnit(unitType);

   Unit<UnitType::Military, LandingType::Land>* cavalry1 = factory.getUnit(unitType);
   Unit<UnitType::Military, LandingType::Land>* cavalry2 = factory.getUnit(unitType);
   // use unit there
   std::cout << "unit->getHealth ()" << unit->getHealth () << std::endl;
   std::cout << "myCell->getLandscape ()" << myCell->getLandscape ()<< std::endl;

   std::cout << "cavalry1->getHealth () before attack = " << cavalry1->getHealth() << std::endl;
   std::cout << "cavalry2->getHealth () before attack = " << cavalry2->getHealth() << std::endl;

   cavalry1->attack(cavalry2);
   cavalry1->Save();
   std::vector<std::string> loadedData = cavalry1->LoadDataFromFile("UnitSave.txt");

   std::cout << "cavalry1->getHealth () after attack = " << cavalry1->getHealth() << std::endl;
   std::cout << "cavalry2->getHealth () after attack = " << cavalry2->getHealth() << std::endl;
   int a  = myCell->getLandscape();
   delete unit;

   int temp;
   std::cin>>temp;
   return 0;
}