#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <ctime>
#include "Item.h"


class Character
{
protected:
    std::string name;
    int hp;
    int InitHp;
    int attackOXP;
    std::vector<Item> inventory;

public:

    Character(const std::string& n, int h, int initH, int a, std::vector<Item> inv)
        : name(n), hp(h), InitHp(initH), attackOXP(a), inventory(inv) {
    }


    virtual ~Character() = default;


    virtual void DisplayChar() const
    {
        std::cout << name << ":" << std::endl;
        std::cout << "	PV : " << hp << std::endl;
        std::cout << "	Degats : " << attackOXP << " ou " << attackOXP * 1.5 << std::endl << std::endl;
    }

    void DisplayItem(std::vector<Item> inventory) const
    {
        int a = 0;
        std::cout << "Inventaire du Hero '" << name << "' :\n";
        for (const Item& i : inventory)
        {
            a++;
            i.DisplayItem(a);
        }
        std::cout << std::endl;
        if (a == 0)
        {
            std::cout << "L'inventaire de " << name << " est vide...";
        }
    }

    bool IsDead() const { return hp <= 0; }


    virtual void AttackItem(std::vector<Item> inventory, int a, Character& target)
    {
        int b = 1;
        for (const Item& i : inventory)
        {
            if (b == a)
            {
                if (i.AttackItem() == "Potion Soin")
                {
                    int heal = i.DammageItem();
                    std::cout << i.AttackItem() << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                    std::cout << name << " se soigne de " << heal << " PV !\n";
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    TakeHeal(heal);
                    system("cls");
                    return;
                }
                int dammage = i.DammageItem();
                std::cout << i.AttackItem() << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
                std::cout << name << " attaque " << target.name << " pour " << dammage << " degats !\n";
                std::this_thread::sleep_for(std::chrono::seconds(1));
                target.TakeDamage(dammage);
                system("cls");
                return;
            }
            b++;
        }
    }


    virtual void Attack(Character& target) {
        srand(time(NULL));
        int RandDammage = rand() % 2 ? attackOXP : attackOXP * 1.5;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << name << " attaque " << target.name << " pour " << RandDammage << " degats !\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        target.TakeDamage(RandDammage);
        system("cls");
    }

    void TakeHeal(int heal)
    {
        if (hp + heal >= InitHp)
            hp = InitHp;
        else
            hp += heal;
        std::cout << name << " a maintenant " << hp << " PV.\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    void TakeDamage(int dmg) {
        hp -= dmg;
        if (hp < 0) hp = 0;
        std::cout << name << " a maintenant " << hp << " PV.\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::string GetName() const { return name; }

    void InitVictoire(Character& target)
    {
        hp = InitHp;
        attackOXP += target.InitHp;
    }

    int HowManyXP()
    {
        return attackOXP;
    }
};

