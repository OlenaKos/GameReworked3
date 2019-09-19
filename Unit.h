#pragma once
#include "Cell.h"
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>



enum LandingType

{

	Navy,

	Land,

	Air

};

enum UnitType

{

	Civil,

	Military

};

template <UnitType, LandingType >

class Unit

{

private:

	int health;

	int damage;

	Cell& cell;

	bool IsDefenced;

	std::string unitType;


public:

	Unit(int h, int ch, Cell& c);

	virtual ~Unit() 
	{

		std::cout << "Unit::~Unit()" << std::endl;

	}

	int getHealth();

	std::string getCell();

	Cell::Landscape getCurrentLandscape();

	bool getIsDefenced();

	virtual std::map <Cell::Landscape, int> getDefenceBonusMap() = 0;

	int getDefenceBonus();

};


template  < >
class Unit < UnitType::Civil, LandingType::Land > // template specialization for civil units

{

private:

	int health;

	int damage;

	Cell& cell;

	bool IsDefenced;

	std::string unitType;


public:

	//Constructor
	Unit(int h, int d, Cell& c) : health(h), damage(d), cell(c), IsDefenced(true)

	{

		std::cout << "Unit(int h, int d, cell& c) : health(h), damage(d), cell(c) isCivil(isCivil)  LandingTypeValue(lVal), IsDefenced(true) " << std::endl;

	}
	//Destructor
	virtual ~Unit()
	{

		std::cout << "Unit::~Unit()" << std::endl;

	}

	//Common functions
	int getHealth()
	{
		std::cout << this->health << std::endl;
		return this->health;
	}
	std::string getUnitType()
	{
		std::cout << this->unitType<< std::endl;
		return this->unitType;
	}
	void setUnitType(std::string uType)
	{
		std::cout <<this->unitType << std::endl;
		this->unitType = uType;
	}

	std::string getCellValues()
	{
		std::string cellValues = std::to_string(this->cell.getX()) + std::to_string(this->cell.getY());
		return cellValues;
	}
	std::string getUnitValues()
	{
		std::string unitValues = std::string(this->unitType) + ";"+ std::to_string(this->health) + ";" + std::to_string(this->damage) + ";" + std::to_string(this->IsDefenced) + ";" + getCellValues();
		return unitValues;
	}

	void Save()
	{
		std::ofstream outfile("UnitSave.txt");
		outfile << getUnitValues() << std::endl;
		outfile.close();

	}
	std::vector<std::string> LoadDataFromFile(std::string filename)
	{
		bool res = false;

		std::vector<std::string> myList;
		std::ifstream file("UnitSave.txt",  std::ios::in | std::ios::binary);
		if (!file) return myList;
		while (file)
		{
		std::string str;
		std::getline(file, str);
		myList.push_back(str);//std::getline(file, str);
		}

		file.close();

		return myList;
	}
	bool getIsDefenced()

	{

		std::cout << "this->IsDefenced = " << this->IsDefenced << std::endl;

		return this->IsDefenced;

	}
	Cell::Landscape getCurrentLandscape()
	{

		return this->cell.LandscapeValue;

	}
	virtual std::map <Cell::Landscape, int> getDefenceBonusMap() = 0;
	int getDefenceBonus()

	{

		std::cout<< "Unit::GetDefenceBonus()" << std::endl;

		Cell::Landscape landScapeValue = Unit::getCurrentLandscape();

		bool isDefenced = Unit::getIsDefenced();

		int defenceBonus;



		if (isDefenced)

		{

			defenceBonus = this->getDefenceBonusMap().find(landScapeValue)->second;

		}

		else

		{

			defenceBonus = 0;

		}



		return defenceBonus;

	}

};

template  <>
class Unit < UnitType::Military, LandingType::Air > // template specialization for military units

{

private:

	int health;

	int damage;

	Cell& cell;

	bool IsDefenced;

	std::string unitType;

public:

	//Constructor
	Unit(int h, int d, Cell& c) : health(h), damage(d), cell(c), IsDefenced(true)

	{

		std::cout << "Unit(int h, int d, cell& c) : health(h), damage(d), cell(c) isCivil(isCivil)  LandingTypeValue(lVal), IsDefenced(true) " << std::endl;

	}
	//Destructor
	virtual ~Unit()
	{

		std::cout << "Unit::~Unit()" << std::endl;

	}

	//Common functions
	int getHealth()
	{
		std::cout << this->health << std::endl;
		return this->health;
	}

	std::string getUnitType()
	{
		std::cout << this->unitType<< std::endl;
		return this->unitType;
	}
	void setUnitType(std::string uType)
	{
		std::cout <<this->unitType << std::endl;
		this->unitType = uType;
	}
	std::string getCellValues()
	{
		std::string cellValues = std::to_string(this->cell.getX()) + std::to_string(this->cell.getY());
		return cellValues;
	}
	std::string getUnitValues()
	{
		std::string unitValues = std::string(this->unitType) + ";" + std::to_string(this->health) + ";" + std::to_string(this->damage) + ";" + std::to_string(this->IsDefenced) + ";" + getCellValues();
		return unitValues;
	}

	void Save()
	{
		std::ofstream outfile("UnitSave.txt");
		outfile << getUnitValues() << std::endl;
		outfile.close();

	}
	std::vector<std::string> LoadDataFromFile(std::string filename)
	{
		bool res = false;

		std::vector<std::string> myList;
		std::ifstream file("UnitSave.txt",  std::ios::in | std::ios::binary);
		if (!file) return myList;
		while (file)
		{
		std::string str;
		std::getline(file, str);
		myList.push_back(str);//std::getline(file, str);
		}

		file.close();

		return myList;
	}

	bool getIsDefenced()

	{

		std::cout << "this->IsDefenced = " << this->IsDefenced << std::endl;

		return this->IsDefenced;

	}
	Cell::Landscape getCurrentLandscape()
	{

		return this->cell.LandscapeValue;

	}
	virtual std::map <Cell::Landscape, int> getDefenceBonusMap() = 0;
	int getDefenceBonus()

	{

		std::cout << "Unit::GetDefenceBonus()" << std::endl;

		Cell::Landscape landScapeValue = Unit::getCurrentLandscape();

		bool isDefenced = Unit::getIsDefenced();

		int defenceBonus;



		if (isDefenced)

		{

			defenceBonus = this->getDefenceBonusMap().find(landScapeValue)->second;

		}

		else

		{

			defenceBonus = 0;

		}



		return defenceBonus;

	}

	//military
	void attack(Unit* unit)
	{

		int attackBonus = this->getAttackBonus();

		int defenceBonus = this->getDefenceBonus();

		int damage = this->damage + attackBonus - defenceBonus;

		unit->health = unit->health - damage;

		std::cout << this->getHealth() << std::endl;

		return;

	}
	int getAttackBonus()
	{
		std::cout << "Unit::GetAttackBonus()" << std::endl;

		Cell::Landscape landScapeValue = Unit::getCurrentLandscape();

		int attackBonus = this->getAttackBonusMap().find(landScapeValue)->second;

		return attackBonus;
	}
	virtual std::map <Cell::Landscape, int> getAttackBonusMap() = 0;

};

template  <>
class Unit < UnitType::Military, LandingType::Land > // template specialization for military units

{

private:

	int health;

	int damage;

	Cell& cell;

	bool IsDefenced;

	std::string unitType;

public:

	//Constructor
	Unit(int h, int d, Cell& c) : health(h), damage(d), cell(c), IsDefenced(true)

	{

		std::cout << "Unit(int h, int d, cell& c) : health(h), damage(d), cell(c) isCivil(isCivil)  LandingTypeValue(lVal), IsDefenced(true) " << std::endl;

	}
	//Destructor
	virtual ~Unit()
	{

		std::cout << "Unit::~Unit()" << std::endl;

	}

	//Common functions
	int getHealth()
	{
		std::cout << this->health << std::endl;
		return this->health;
	}
	std::string getUnitType()
	{
		std::cout << this->unitType<< std::endl;
		return this->unitType;
	}
	void setUnitType(std::string uType)
	{
		std::cout <<this->unitType << std::endl;
		this->unitType = uType;
	}
	std::string getCellValues()
	{
		std::string cellValues = std::to_string(this->cell.getX()) + std::to_string(this->cell.getY());
		return cellValues;
	}
	std::string getUnitValues()
	{
		std::string unitValues = std::string(this->unitType) + ";" + std::to_string(this->health) + ";" + std::to_string(this->damage) + ";" + std::to_string(this->IsDefenced) + ";" + getCellValues();
		return unitValues;
	}

	void Save()
	{
		std::ofstream outfile("UnitSave.txt");
		outfile << getUnitValues() << std::endl;
		outfile.close();

	}
		std::vector<std::string> LoadDataFromFile(std::string filename)
	{
		bool res = false;

		std::vector<std::string> myList;
		std::ifstream file("UnitSave.txt",  std::ios::in | std::ios::binary);
		if (!file) return myList;
		while (file)
		{
		std::string str;
		std::getline(file, str);
		myList.push_back(str);//std::getline(file, str);
		}

		file.close();

		return myList;
	}
	bool getIsDefenced()

	{

		std::cout << "this->IsDefenced = " << this->IsDefenced << std::endl;

		return this->IsDefenced;

	}
	Cell::Landscape getCurrentLandscape()
	{

		return this->cell.LandscapeValue;

	}
	virtual std::map <Cell::Landscape, int> getDefenceBonusMap() = 0;
	int getDefenceBonus()

	{

		std::cout << "Unit::GetDefenceBonus()" << std::endl;

		Cell::Landscape landScapeValue = Unit::getCurrentLandscape();

		bool isDefenced = Unit::getIsDefenced();

		int defenceBonus;



		if (isDefenced)

		{

			defenceBonus = this->getDefenceBonusMap().find(landScapeValue)->second;

		}

		else

		{

			defenceBonus = 0;

		}



		return defenceBonus;

	}

	//military
	void attack(Unit* unit)
	{

		int attackBonus = this->getAttackBonus();

		int defenceBonus = this->getDefenceBonus();

		int damage = this->damage + attackBonus - defenceBonus;

		unit->health = unit->health - damage;

		std::cout << this->getHealth() << std::endl;

		return;

	}
	int getAttackBonus()
	{
		std::cout << "Unit::GetAttackBonus()" << std::endl;

		Cell::Landscape landScapeValue = Unit::getCurrentLandscape();

		int attackBonus = this->getAttackBonusMap().find(landScapeValue)->second;

		return attackBonus;
	}
	virtual std::map <Cell::Landscape, int> getAttackBonusMap() = 0;

};

template  <>
class Unit < UnitType::Military, LandingType::Navy > // template specialization for military units

{

private:

	int health;

	int damage;

	Cell& cell;

	bool IsDefenced;

	std::string unitType;

public:

	//Constructor
	Unit(int h, int d, Cell& c) : health(h), damage(d), cell(c), IsDefenced(true)

	{

		std::cout << "Unit(int h, int d, cell& c) : health(h), damage(d), cell(c) isCivil(isCivil)  LandingTypeValue(lVal), IsDefenced(true) " << std::endl;

	}
	//Destructor
	virtual ~Unit()
	{

		std::cout << "Unit::~Unit()" << std::endl;

	}

	//Common functions
	int getHealth()
	{
		std::cout << this->health << std::endl;
		return this->health;
	}
	std::string getUnitType()
	{
		std::cout << this->unitType<< std::endl;
		return this->unitType;
	}
	void setUnitType(std::string uType)
	{
		std::cout <<this->unitType << std::endl;
		this->unitType = uType;
	}
	std::string getCellValues()
	{
		std::string cellValues = std::to_string(this->cell.getX()) + std::to_string(this->cell.getY());
		return cellValues;
	}
	std::string getUnitValues()
	{
		std::string unitValues = std::string(this->unitType) + ";" + std::to_string(this->health) + ";" + std::to_string(this->damage) + ";" + std::to_string(this->IsDefenced) + ";" + getCellValues();
		return unitValues;
	}

	void Save()
	{
		std::ofstream outfile("UnitSave.txt");
		outfile << getUnitValues() << std::endl;
		outfile.close();

	}

	//void LoadUnit(std::string unitStr)
	//{
	//	Cell* testCell = new Cell();
	//	std::string unitTypes = "cavalry";//argc[1];
	//	Factory<UnitType::Military, LandingType::Land> factory;
	//	factory.addDepartment(getDepartment(unitTypes));
	//	Unit< UnitType::Military, LandingType::Land >* cavalry1 = factory.getUnit(unitTypes);



	//	//return cavalry1;
	//}
	std::vector<std::string> LoadDataFromFile(std::string filename)
	{
		bool res = false;

		std::vector<std::string> myList;
		std::ifstream file("UnitSave.txt",  std::ios::in | std::ios::binary);
		if (!file) return myList;
		while (file)
		{
		std::string str;
		std::getline(file, str);
		myList.push_back(str);//std::getline(file, str);
		}

		file.close();

		return myList;
	}
	bool getIsDefenced()

	{

		std::cout << "this->IsDefenced = " << this->IsDefenced << std::endl;

		return this->IsDefenced;

	}
	Cell::Landscape getCurrentLandscape()
	{

		return this->cell.LandscapeValue;

	}
	virtual std::map <Cell::Landscape, int> getDefenceBonusMap() = 0;
	int getDefenceBonus()

	{

		std::cout << "Unit::GetDefenceBonus()" << std::endl;

		Cell::Landscape landScapeValue = Unit::getCurrentLandscape();

		bool isDefenced = Unit::getIsDefenced();

		int defenceBonus;



		if (isDefenced)

		{

			defenceBonus = this->getDefenceBonusMap().find(landScapeValue)->second;

		}

		else

		{

			defenceBonus = 0;

		}



		return defenceBonus;

	}

	//military
	void attack(Unit* unit)
	{

		int attackBonus = this->getAttackBonus();

		int defenceBonus = this->getDefenceBonus();

		int damage = this->damage + attackBonus - defenceBonus;

		unit->health = unit->health - damage;

		std::cout << this->getHealth() << std::endl;

		return;

	}
	int getAttackBonus()
	{
		std::cout << "Unit::GetAttackBonus()" << std::endl;

		Cell::Landscape landScapeValue = Unit::getCurrentLandscape();

		int attackBonus = this->getAttackBonusMap().find(landScapeValue)->second;

		return attackBonus;
	}
	virtual std::map <Cell::Landscape, int> getAttackBonusMap() = 0;

};



