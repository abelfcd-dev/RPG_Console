#pragma once
#include "Character.h"


class Hero : public Character {
protected:
    std::vector<Item> inventory;

public:
    Hero(const std::string& n) : Character(n, 50, 50, 0, inventory) {}

    void DisplayChar() const
    {
        std::cout << name << ":" << std::endl;
        std::cout << "	PV : " << hp << std::endl;
        std::cout << "	XP : " << attackOXP << std::endl << std::endl;
    }

    void AttackItem(std::vector<Item> inventory, int a, Character& target) override {
        system("cls");
        Character::AttackItem(inventory, a, target);
    }
};