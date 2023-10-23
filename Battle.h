#ifndef __Battle_H
#define __Battle_H





#include <iostream>
#include <cstdlib>
#include <ctime>

class Battle
{
public:
	Battle();
	
	int combat(const std::string& enemyName);
	int heal(int* playerHP);
	
protected:
	int mPlayerXp;
	int mPlayerLevel;
	int mPlayerHP;
private:
	int m_levelThresholds[11];
	
};
#endif 