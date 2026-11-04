#pragma once
#include "Character.h"

class Viking : public Character
{
protected:
    int attackPower;
    std::vector<Item> inventory;


public:
    Viking(const std::string& n) : Character(n, 100, 100, 10, inventory) {}

    void Attack(Character& target) override {
        system("cls");
        std::cout << name << " fait le coup du Berserker !\n";
        Character::Attack(target);
    }
};

