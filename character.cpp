#include "Character.h"
#include "Inventory.h"

#include <iostream>



Character::Character()
	: m_strength(0), m_dexterity(0), m_intelligence(0), m_endurance(0), m_wisdom(0), m_hp(100), m_xp(0), m_level(1), m_mana(100) {}

void Character::takeDamage(int damage)
{
	m_hp -= damage;
	if (m_hp < 0)
	{
		m_hp = 0;
	}
}

bool Character::isAlive() const
{
	return m_hp > 0;
}


std::string Character::getClass() const
{
	return m_Class;
}

std::string Character::askAncestry()
{

	std::cout << "Please choose a character ancestry: \n\n";

	std::vector<std::string> ancestries  { "human", "elf", "dwarf", "orc", "dark elf" };
	for (int i = 0; i < ancestries.size(); ++i)
	{
		std::cout << i + 1 << ". " << ancestries[i] << '\n';
	}

	int choice;

	while (true)
	{
		std::cout << "\nEnter the number corresponding to your race of choice: \n";
		std::cin >> choice;

		if (choice < 1 || choice > ancestries.size())
		{
			std::cout << "That's not something that exists. Please try again by picking a number between 1 and " << ancestries.size() << ".\n";
			std::cin.clear();
			
		}
		else
		{
			break;
		}
	}

	std::string selectedAncestry = ancestries[choice - 1];
	std::cout << "\n\nYou chose " << selectedAncestry << ". Great choice!!\n";

	return selectedAncestry;
}

std::string Character::askName()
{
	std::cin.ignore();

	while (true)
	{
		std::cout << "\nEnter the name you want for your character: \n";
		
		std::getline(std::cin, m_Name);

		if (m_Name.empty())
		{
			

		}
		else if (m_Name.length() > 10)
		{
			std::cout << "\nCharacter name cannot be more than 10 character. \n";
		}
		else
		{
			std::cout << "\nYou chose " << m_Name << ", good choice! \n";
			break;
		}

	}

	return m_Name;
}


std::string Character::askClass()
{

	std::cout << "\nPlease choose a character class: \n\n";

	std::vector<std::string> classes = { "sorcerer", "warrior", "rogue", "priest", "warlock"};
	for (int i = 0; i < classes.size(); ++i)
	{
		 std::cout << i + 1 << ". " << classes[i] << '\n';
	}

	int choice;

	while (true)
	{
		std::cout << "\nEnter the number corresponding to your class of choice: ";
		std::cin >> choice;

		if (choice < 1 || choice > classes.size())
		{
			std::cout << "That's not something that exists. Please try again by picking a number between 1 and " << classes.size() << ".\n";
			std::cin.clear();
			
		}
		else
		{
			break;
		}
		
			
	}

	std::string selectedClass = classes[choice - 1];
	std::cout << "\nYou chose " << selectedClass << ". Great choice!!\n";
	setAbilityScoreBonus(selectedClass);
	m_Class = selectedClass;
	return selectedClass;
}

void Character::setAbilityScoreBonus(const std::string& selectedClass) 
{
	if (selectedClass == "sorcerer") {
		m_intelligence += 3;
		
	}
	else if (selectedClass == "warrior") {
		m_strength += 3;
		m_hp += 25;
	}
	else if (selectedClass == "rogue") {
		m_dexterity += 3;
	}
	else if (selectedClass == "priest") {
		m_wisdom += 3;
	}
	else if (selectedClass == "warlock")
	{
		m_intelligence += 3;
	}
	
}


int Character::readAbilityScore(const std::string& abilityName) const 
{
	int score;

	while (true) {
		std::cout << abilityName << ": ";
		std::cin >> score;

		if (!validateAbilityScore(score)) {
			std::cout << "Invalid ability score. The score must be between 8 and 18.\n";
		}
		else {
			break;
		}

		std::cin.clear();
		
	}

	return score;
}

bool Character::validateAbilityScore(int score) const 
{

	return (score >= 8 && score <= 18);
}
                     

void Character::askTraitsSetup() 
{
	std::cout << "\n--- Trait Setup ---\n";
	std::cout << "Allocate points to each trait (Strength, Dexterity, Intelligence, Endurance, Wisdom).\n\n";
	std::cout << "Points should be between 8 and 18.\n\n";

	m_strength += readAbilityScore("Strength");
	m_dexterity += readAbilityScore("Dexterity");
	m_intelligence += readAbilityScore("Intelligence");
	m_endurance += readAbilityScore("Endurance");
	m_wisdom += readAbilityScore("Wisdom");
}

void Character::printCharacterTraits() const 
{
	std::cout << "\n--- Character Traits ---\n";
	std::cout << "\nName: " << m_Name << "\n";
	std::cout << "\nClass: " << m_Class << "\n"; 
	std::cout << "\nHP: " << m_hp << "\n";
	std::cout << "\nLevel: " << m_level << "\n";
	std::cout << "Strength: " << m_strength << "\n";
	std::cout << "Dexterity: " << m_dexterity << "\n";
	std::cout << "Intelligence: " << m_intelligence << "\n";
	std::cout << "Endurance: " << m_endurance << "\n";
	std::cout << "Wisdom: " << m_wisdom << "\n";

	
}