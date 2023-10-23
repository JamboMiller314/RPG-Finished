#include "Story.h"

#include "Inventory.h"
#include "Character.h"

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <string>




Story::Story()
{
	 m_Direction = {"N", "S", "E", "W", "SafeHouse", "Town"};
}
void Story::storyIntro() const
{
	std::cout << "\nThere once was a great warrior named Odinfihr that roamed Midguard for centuries,\n";
	std::cout << "conquering villages and empires with his great army.\n";
	std::cout << "Odinfihr was a kind, good-willed soul who took care of his people. \n";
	std::cout << "He conquered but like most good guys, he had a rival named Lokithon.\n";
	std::cout << "Lokithon would often pin Odinfihr's people against him using dark magick and with spies.\n";
	std::cout << "He didn't like Odinfihr's rulings and hated being anything less than king. \n";
	std::cout << "Lokithon felt more suited for the role of king.\n";
	std::cout << "To gain favor with Odinfihr he would like you to explore outside the village.\n";

	
}


 void Story::storyIntraStuff()
{
	std::cout << "\nWelcome to Midguard! Let's get you out there to explore.\n ";
	
	
	
	
}
 void Story::storyDirection()
 {
	 

	 bool inSafeHouse = false;

	 int playerHP = 100;
	

	 while (true)

	 {
		 
		 for (int i = 0; i < m_Direction.size(); ++i)
		 {
			 std::cout << i + 1 << ": " << m_Direction[i] << " ";
		 }

		 std::string response;
		 std::cin >> response;

		

		 if (response == "N" || response == "n")
		 {
			 exploredDirections.insert("N");
			
			 battle.combat("skeleton");
			 storyDirection();
			

		 }
		 else if (response == "S" || response == "s")
		 {
			
			 exploredDirections.insert("S");
			 battle.combat("spider");
			
			 storyDirection();

		 }
		 else if (response == "E" || response == "e")
		 {
			 exploredDirections.insert("E");
			 battle.combat("vampire");
			 storyDirection();

		 }
		 else if (response == "W" || response == "w")
		 {
			 exploredDirections.insert("W");
			 battle.combat("wolf");
			 storyDirection();

		 }
		 else if (response == "safehouse")

		 {
			 inSafeHouse = true;
			 while (inSafeHouse)
			 {
				 Inventory inventory;
				 Character character;
				 do
				 {

					 std::cout << "Welcome to the safehouse!\n";
					 std::cout << "Type heal to heal up before heading back out! \n";
					 std::cout << "Type merchant to buy something new. \n";



					 std::string choice;
					 std::cin >> choice;
					 while (choice == "heal")
					 {
						 battle.heal(&playerHP);
						 storyDirection();

					 }

					 while (choice == "merchant")
					 {

						 for (int i = 0; i < m_ItemsToBuy.size(); ++i)
						 {
							 std::cout << m_ItemsToBuy[i] << "\n";
						 }
						 std::cout << "What would you like to buy? \n";

						 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore remaining characters (including newline)
						 std::getline(std::cin, response);

						 if (response == "Golden Sword")
						 {
							 inventory.addItemToInventory("Golden Sword");

						 }
						 else if (response == "Golden Dagger")
						 {
							 inventory.addItemToInventory("Golden Dagger");

						 }
						 else if (response == "Staff of pure darkness")
						 {
							 inventory.addItemToInventory("Staff of pure darkness");
						 }
						 else if (response == "Staff of pure light")
						 {
							 inventory.addItemToInventory("Staff of pure light");
						 }
						 std::cout << "You've bought " << response << " . " "\n";
						 std::cout << "Would you like to buy something else? y/n " "\n";
						 char response;
						 std::cin >> response;
						 if (response == 'y')
						 {
							 choice == "merchant";
						 }
						 else
						 {
							 storyDirection();
						 }
						 break;

					 }

				 } while (response == "safehouse");
			 }



		 }
		 else if(response == "Town")
		 {
			 if (exploredDirections.size() < 4)
			 {
				 std::cout << "You need to explore all directions given by Odinfihr before heading back to to town. " << std::endl  ;
			 }
			 else if (exploredDirections.size() == 4)
			 {
				 storyEnding();
				 
				 
			 }
			
		 }
		 break;
	 }





 
	
}




void Story::storyEnding() 
{
	
	
	
		std::cout << "Odinfihr welcomes you back with open arms and invites you to be part of his kingdom!\n";
		std::cout << "You present the king with your experience learned and gain praise. You are now known as a fearless warrior! ";
		std::cout << "The End. \n";
	
	
}