#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Character.h"
#include "Story.h"
#include "Inventory.h"
#include "Battle.h"
















int main()
{
	Character character;
	Story story;
	Inventory inv;
	
	
	story.storyIntro();
	std::cout << "\nLet's create a legend! \n\n";


	character.askAncestry();
	character.askClass();
	character.askName();
	character.askTraitsSetup();
	character.printCharacterTraits();

	inv.displayWarrior(character);
	inv.displayPriest(character);
	inv.displaySorcerer(character);
	inv.displayWarlock(character);
	inv.displayRogue(character);
	story.storyIntraStuff();

	
	
	story.storyDirection();
	
	
}

