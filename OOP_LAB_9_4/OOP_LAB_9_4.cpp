#include <iostream>
#include <vector>
#include <cstdlib>  // For rand()
#include <ctime>    // For time()

using namespace std;

// Base class Character
class Character
{
protected:
    string name;
    int health;
    bool isWarrior;  // This indicates whether the character is a warrior

public:
    Character(string name, int health, bool isWarrior)
        : name(name), health(health), isWarrior(isWarrior) {}

    void display()
    {
        cout << name << " (" << (isWarrior ? "Warrior" : "Mage") << "): Health = " << health << endl;
    }

    bool isAlive()
    {
        return health > 0;
    }

    bool isWarriorCharacter()
    {
        return isWarrior;
    }

    virtual void attack(Character* enemy) = 0;
    virtual void heal(Character* ally) = 0;

    void receiveDamage(int damage)
    {
        health -= damage;
        if (health < 0) health = 0;  // Prevent health from going negative
    }

    string getName() { return name; }
    int getHealth() { return health; }
};

// Warrior Class
class Warrior : public Character
{
public:
    Warrior(string name, int health) : Character(name, health, true) {}

    void attack(Character* enemy) override
    {
        int attackPower = rand() % 20 + 5;  // Random attack power between 5 and 24
        int distance = rand() % 5 + 1;  // Random distance between 1 and 5

        if (enemy->getHealth() < this->getHealth())
        {  // Warrior can attack weaker enemy
            cout << this->getName() << " attacks " << enemy->getName()
                << " with power " << attackPower << " from distance " << distance << endl;
            enemy->receiveDamage(attackPower);
        }
    }

    void heal(Character* ally) override
    {
        cout << this->getName() << " cannot heal!" << endl;
    }
};

// Mage Class
class Mage : public Character
{
public:
    Mage(string name, int health) : Character(name, health, false) {}

    void attack(Character* enemy) override
    {
        int attackPower = rand() % 10 + 1;  // Random attack power between 1 and 10
        int distance = rand() % 5 + 1;  // Random distance between 1 and 5

        cout << this->getName() << " attacks " << enemy->getName()
            << " with magic power " << attackPower << " from distance " << distance << endl;
        enemy->receiveDamage(attackPower);
    }

    void heal(Character* ally) override
    {
        if (ally->isWarriorCharacter())
        {
            int healPower = rand() % 15 + 5;  // Random heal power between 5 and 20
            cout << this->getName() << " heals " << ally->getName()
                << " with power " << healPower << endl;
            ally->receiveDamage(-healPower);  // Negative damage means healing
        }
    }
};

// Team Class to manage the list of characters
class Team {
private:
    vector<Character*> characters;

public:
    void addCharacter(Character* character)
    {
        characters.push_back(character);
    }

    void removeDeadCharacters()
    {
        for (auto it = characters.begin(); it != characters.end(); )
        {
            if (!(*it)->isAlive())
            {
                cout << (*it)->getName() << " has been defeated!" << endl;
                it = characters.erase(it);
            }
            else
                ++it;
        }
    }

    void simulateFight()
    {
        for (size_t i = 0; i < characters.size() - 1; i++)
        {
            if (characters[i]->isAlive())
            {
                // Simulate attacking the next character
                characters[i]->attack(characters[i + 1]);
                removeDeadCharacters();
            }
        }
        // Display all characters' information
        cout << "\nCharacter Statuses after the fight:\n";
        for (auto& character : characters)
            character->display();
    }

    void simulateHealing()
    {
        for (size_t i = 0; i < characters.size(); i++)
        {
            if (characters[i]->isAlive() && !characters[i]->isWarriorCharacter())
            {
                for (size_t j = 0; j < characters.size(); j++)
                {
                    if (characters[i]->isAlive() && characters[j]->isWarriorCharacter() && characters[j]->getHealth() < 50)
                        characters[i]->heal(characters[j]);
                }
            }
        }
    }

    void displayTeamInfo()
    {
        for (auto& character : characters)
            character->display();
    }
};

int main()
{
    srand(time(0));  // Seed for random number generation

    // Create two teams and add warriors and mages
    Team team1;
    team1.addCharacter(new Warrior("Warrior 1", 100));
    team1.addCharacter(new Mage("Mage 1", 80));
    team1.addCharacter(new Warrior("Warrior 2", 90));
    team1.addCharacter(new Mage("Mage 2", 70));

    Team team2;
    team2.addCharacter(new Warrior("Warrior 3", 120));
    team2.addCharacter(new Mage("Mage 3", 75));
    team2.addCharacter(new Warrior("Warrior 4", 110));
    team2.addCharacter(new Mage("Mage 4", 65));

    // Simulate a fight session between the two teams
    cout << "Team 1 Attack Session:\n";
    team1.simulateFight();
    cout << "\nTeam 2 Attack Session:\n";
    team2.simulateFight();

    // Heal some warriors if possible
    cout << "\nHealing Warriors in Team 1:\n";
    team1.simulateHealing();
    cout << "\nHealing Warriors in Team 2:\n";
    team2.simulateHealing();

    // Display teams' information after healing
    cout << "\nTeam 1 after Healing:\n";
    team1.displayTeamInfo();
    cout << "\nTeam 2 after Healing:\n";
    team2.displayTeamInfo();

    return 0;
}
