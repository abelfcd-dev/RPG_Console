#pragma once
#include <memory>
#include "Hero.h"
#include "Viking.h"
#include "HDC.h"
#include "Cell.h"

struct Pos {
    int x;
    int y;
};

enum class GameState {
    Menu,
    PlayGame,
    Victory,
    Defeat,
    Quit
};

class Game
{
private:

    std::vector<std::vector<Cell*>> map;



    bool isRunning;
    GameState state;

    std::unique_ptr<Hero> player;
    std::unique_ptr<Character> enemie;
    std::vector<Item> inventoryhero;


    std::string Narme;
    int Parme;
    std::string Nulty;
    int Pulty;
    std::string Npotion;
    int Ppotion;


public:
    Pos position = { 8, 13 };
    Game();

    void InitilizedMap(int row, int col);
    void PutHeroEnemy();
    void Move();
    void DisplayMap();
    void ManageGrid();
    void Initialize();
    void Loop();
    void ShowMenu();
    void PlayGame();
    void Victory();
    void Shutdown();
};

