#pragma once
class Cell
{
private:
	bool enemy;
	bool viking;
	bool HeroDescover;
public:
	void InitializeCell();
	void ChangeDisco() { HeroDescover = !HeroDescover; };
	void ChangeState(std::string state) {
		if (state == "enemie") enemy = !enemy;

		else if (state == "viking") viking = !viking;
		else {
			std::cout << "Error";
			system("pause");
		}
	};
	bool isEnemie() const { return enemy; };
	bool isViking() const { return viking; };
};
