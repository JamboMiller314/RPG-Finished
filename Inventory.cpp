#include "Inventory.h"

#include "Character.h"

#include <iostream>
#include <string>
#include <vector>


Inventory::Inventory()
{
	
	m_WarriorInv = { "Heavy chest armor", "Heavy boots", "Heavy pants", "Sword", "Shield" };
	m_SorcererInv = { "Robe", "Cloak", "Staff" }; 
	m_RogueInv = { "Leather chest armor", "Leather boots", "Dagger" }; 
	m_WarlockInv = { "Dark chest armor", "Dark boots", "Dark staff" }; 
	m_PriestInv = { "Holy chest armor", "Holy boots", "Holy staff" }; 




	
}

void Inventory::displayWarrior(Character& character)
{
	if (character.getClass() == "warrior")
	{
		std::cout << "Here's your warrior's inventory to start: \n";
		for (size_t i = 0; i < m_WarriorInv.size(); ++i)
		{
			std::cout << m_WarriorInv[i] << std::endl;
		}
	}
	
	
	
}

void Inventory::displayPriest(Character& character)
{
	if (character.getClass() == "priest")
	{
		std::cout << "Here's your priest's inventory to start: \n";
		for (size_t i = 0; i < m_PriestInv.size(); ++i)
		{
			std::cout << m_PriestInv[i] << std::endl;
		}
	}
}

void Inventory::displaySorcerer(Character& character)
{
	if (character.getClass() == "sorcerer")
	{
		std::cout << "Here's your sorcerer's inventory to start: \n";
		for (size_t i = 0; i < m_SorcererInv.size(); ++i)
		{
			std::cout << m_SorcererInv[i] << std::endl;
		}
	}
}

void Inventory::displayRogue(Character& character)
{
	if (character.getClass() == "rogue")
	{
		std::cout << "Here's your rogue's inventory to start: \n";
		for (size_t i = 0; i < m_RogueInv.size(); ++i) 
		{
			std::cout << m_RogueInv[i] << std::endl;
		}
	}
}

void Inventory::displayWarlock(Character& character)
{
	if (character.getClass() == "warlock")
	{
		std::cout << "Here's your warlock's inventory to start: \n";
		for (size_t i = 0; i < m_WarlockInv.size(); ++i)
		{
			std::cout << m_WarlockInv[i] << std::endl;
		}
	}
}

void Inventory::addItemToInventory(const std::string& itemName)
{
	m_WarriorInv.push_back("Golden Sword");
	m_PriestInv.push_back("Staff of pure light");
	m_RogueInv.push_back("Golden Dagger");
	m_WarlockInv.push_back("Staff of pure darkness");
	m_SorcererInv.push_back("Golden Staff");
}