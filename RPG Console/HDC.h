#pragma once
#include "Character.h"


class HDC : public Character {
protected:
    int attackPower;
    std::vector<Item> inventory;


public:
    HDC(const std::string& n) : Character(n, 20, 20, 10, inventory) {}

    void Attack(Character& target) override {
        system("cls");
        std::cout << name << " lance Pierre !\n";
        Character::Attack(target);
    }
};

