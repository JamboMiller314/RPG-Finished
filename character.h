#ifndef __CHARACTER_H
#define __CHARACTER_H

#include <iostream>
#include <string>
#include <vector>

class Character
{
public:
    Character();
   //                             ~Character();
    std::string askAncestry();
    std::string askName();
    std::string askClass();
    void askTraitsSetup();
    void printCharacterTraits() const;
    std::string getClass() const;
    
    std::string getName() const
    {
        return m_Name;
    }
    void takeDamage(int damage);
    bool isAlive() const;
   
   
private:
    std::string m_Name;
    int m_strength, m_dexterity, m_intelligence, m_endurance, m_wisdom, m_hp, m_xp, m_level, m_mana;
    std::string m_Class;
    
    

    int readAbilityScore(const std::string& abilityName) const;
    bool validateAbilityScore(int score) const;
    void setAbilityScoreBonus(const std::string& selectedClass);
};
#endif 