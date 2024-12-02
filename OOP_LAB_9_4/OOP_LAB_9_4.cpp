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

    virtual void display() const 
    {
        cout << name << " (" << (isWarrior ? "Warrior" : "Mage") << "): Health = " << health << endl;
    }

    bool isAlive() const 
    {
        return health > 0;
    }

    // Getter for isWarrior
    bool isWarriorCharacter() const 
    {
        return isWarrior;
    }

    virtual void attack(Character* enemy) = 0;
    virtual void heal(Character* ally) = 0;

    // Method to receive damage
    void receiveDamage(int damage) 
    {
        health -= damage;
        if (health < 0) health = 0;  // Prevent health from going negative
    }

    string getName() const { return name; }
    int getHealth() const { return health; }
};

// Warrior Class
class Warrior : public Character 
{
public:
    Warrior(string name, int health) : Character(name, health, true) {}

    void attack(Character* enemy) override 
    {
        // Warriors can attack if enemy is weaker and within a random distance
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
        // Warriors cannot heal, so just print a message
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
        // Mages can attack but don't have high power compared to warriors
        int attackPower = rand() % 10 + 1;  // Random attack power between 1 and 10
        int distance = rand() % 5 + 1;  // Random distance between 1 and 5

        cout << this->getName() << " attacks " << enemy->getName()
            << " with magic power " << attackPower << " from distance " << distance << endl;
        enemy->receiveDamage(attackPower);
    }

    void heal(Character* ally) override 
    {
        // Mages can heal warriors
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

    // Remove dead characters from the list
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
                // Simulate attacking next character
                characters[i]->attack(characters[i + 1]);
                removeDeadCharacters();
            }
        }
        // Display all characters information
        cout << "\nCharacter Statuses after the fight:\n";
        for (auto& character : characters)
            character->display();
    }

    // Heal warriors if a mage is close enough (healing simulation)
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
};

int main() 
{
    srand(time(0));  // Seed for random number generation

    // Create a team and add warriors and mages
    Team team1;
    team1.addCharacter(new Warrior("Warrior 1", 100));
    team1.addCharacter(new Warrior("Warrior 2", 100));
    team1.addCharacter(new Mage("Mage 1", 80));
    team1.addCharacter(new Mage("Mage 2", 80));

    // Simulate a fight session
    team1.simulateFight();

    // Heal some warriors
    team1.simulateHealing();

    return 0;
}