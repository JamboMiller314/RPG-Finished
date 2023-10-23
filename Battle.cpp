#include "Battle.h"


#include <iostream>
#include <string>
#include <vector>


Battle::Battle()
{
    m_levelThresholds[0] = 0;
    m_levelThresholds[1] = 100;
    m_levelThresholds[2] = 550;
    m_levelThresholds[3] = 900;
    m_levelThresholds[4] = 1550;
    m_levelThresholds[5] = 2700;
    m_levelThresholds[6] = 3950;
    m_levelThresholds[7] = 5200;
    m_levelThresholds[8] = 6450;
    m_levelThresholds[9] = 7000;
    m_levelThresholds[10] = 9500;

    mPlayerXp = 0;
    mPlayerLevel = 1;
    mPlayerHP = 100;
}



   

int Battle::combat(const std::string& enemyName)
{
    std::cout << mPlayerXp << std::endl;
    std::cout << "You encounter a " << enemyName << "!\n";

   
    bool playerWins = (std::rand() % 10) < 9;

   
     mPlayerHP = 100;
    int m_enemyHP = 100;
    
   
    while (mPlayerHP > 0 && m_enemyHP > 0)
    {
        if (playerWins)
        {
            int playerDamage = std::rand() % 20 + 10; // Random damage between 10 and 30
            m_enemyHP -= playerDamage;
            std::cout << "You deal " << playerDamage << " damage to the " << enemyName << ". \n";

            if (m_enemyHP <= 0)
            {
                std::cout << "You defeated the " << enemyName << "! Congratulations!\n";
                if (enemyName == "skeleton")
                {

                    (mPlayerXp) += 250;
                   

                }
                else if (enemyName == "spider")
                {
                    (mPlayerXp) += 350;
                    
                }
                else if (enemyName == "vampire")
                {
                    (mPlayerXp) += 500;
                   
                }
                else if (enemyName == "wolf")
                {
                    (mPlayerXp) += 150;
                    
                }

                

                std::cout << "You have " << mPlayerXp << " XP " "\n";
                while (mPlayerLevel < 10 && mPlayerXp >= m_levelThresholds[mPlayerLevel])
                {
                    (mPlayerLevel)++;
                    std::cout << "\nCongrats! You're now level " << mPlayerLevel << "!\n";
                
                    
                    
                }
                    


               
            }
           

           
        }
        else
        {
            int enemyDamage = std::rand() % 2 + 1; 
            mPlayerHP -= enemyDamage;
            std::cout << "The " << enemyName << " deals " << enemyDamage << " damage to you. ";

            if (mPlayerHP <= 0)
            {
                std::cout << "You were defeated by the " << enemyName << ". Better luck next time!\n";
            }
            else
            {
                std::cout << "You have " << mPlayerHP << " HP left.\n";
            }

        }
       
    }
    
    return mPlayerHP;
}

 


int Battle::heal(int* playerHP)
{
   int m_HP = *playerHP;
    *playerHP = 100;
   
   
    std::cout << "Your all ready to go with " << *playerHP << "HP.\n";

    return m_HP;
}
    



