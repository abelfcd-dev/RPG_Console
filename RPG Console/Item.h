#pragma once
#include <iostream>


class Item
{
private:
	std::string name;
	int spell;

public:
	Item(const std::string& n, int spell)
		: name(n), spell(spell) {
	}

	void DisplayItem(int i) const
	{
		std::cout << i << "- " << name << " -> " << spell << " PV" << std::endl;

	}

	int DammageItem() const
	{
		return spell;
	}

	std::string AttackItem() const
	{
		return name;
	}
};