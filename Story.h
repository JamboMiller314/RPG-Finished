#ifndef __STORY_h
#define __STORY_H

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "Battle.h"


class Story
{
public:
	Story();
	void storyIntro() const;
	void storyIntraStuff() ;
	void storyEnding() ;
	void storyDirection();
	Battle battle;

	
	std::vector<std::string> m_Direction = { "N", "S", "E", "W", "SafeHouse", "Town"};
	std::vector<std::string> m_ItemsToBuy = { "Golden Sword", "Golden Staff", "Golden Dagger", "Staff of pure darkness", "Staff of pure light", };
	
private:
	std::set<std::string> exploredDirections;
};























#endif