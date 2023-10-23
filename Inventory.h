#ifndef __INVENTORY_H
#define __INVENTORY_H

#include <iostream>
#include <string>
#include <vector>
#include "Character.h"



class Inventory
{
public:
	Inventory();
	void displayWarrior( Character& character);
	void displaySorcerer(Character& charactera);
	void displayRogue(Character& character);
	void displayWarlock(Character& character);
	void displayPriest(Character& character);
	void addItemToInventory(const std::string& itemName);
	
	
	std::vector<std::string> m_WarriorInv; 
	std::vector<std::string> m_SorcererInv; 
	std::vector<std::string> m_RogueInv; 
	std::vector<std::string> m_WarlockInv;
	std::vector<std::string> m_PriestInv; 
};



#endif
