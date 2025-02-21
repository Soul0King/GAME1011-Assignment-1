#include "GameObject.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

// global functions-------------------------------------------------------------
void CreateCharacter(Player*& p)
{
    int n;
    string s;
    while (true)
    {
        cout << "Choose your character type (input 1 for Knight / 2 for Wizard): ";
        cin >> n;
        cin.ignore();
        if (n == 1 || n == 2)
            break;
        cout << "Invalid choice.\n";
    }
    if (p != nullptr)
        delete p;
    p = (n == 1) ? (Player*)new Knight{} : (Player*)new Wizard{};
    cout << "What is your character's name: ";
    getline(cin, s);
    p->set_name(s);
    cout << "\nYou can view your character's info from the main menu!\n\n";
}
void ViewCharacter(Player*& p)
{
    if (p == nullptr)
        cout << "A character must be created first.\n\n";
    else
        cout << *(p);
}
void BattleSimulate(Player*& p, Enemy*& e)
{
    int n;
    do {
        cout << "Are you ready to witness an epic battle (input 1 for Yes / 0 for No): ";
        cin >> n;
        cin.ignore();
        if (n == 0 || n == 1)
            break;
        cout << "Invalid choice.\n";
    } while (n != 0);
    cout << endl;

    if (n == 0)
        return;

    if (p == nullptr)
    {
        cout << "A character must be created first.\n\n";
        return;
    }

    srand(time(0));
    int r = rand() % 2; // returns 0 or 1
    if (e != nullptr)
        delete e;
    e = (r == 0) ? (Enemy*)new Orc{} : (Enemy*)new Undead{};
    string eType = (typeid(*e) == typeid(Orc)) ? Orc::speciesName : Undead::speciesName;
    printf("          you encountered an %s with %0.0f health...\n", eType.c_str(), e->get_health());
    printf("          The %s taunts you:\n", eType.c_str());
    e->TauntPlayer();
    printf("          You fight back!\n");
    printf("          The %s taunts you:\n", eType.c_str());
    e->TauntPlayer();
    printf("          You use a special move:\n");
    p->SpecialAttack();
    printf("          The %s attacks!\n", eType.c_str());
    printf("          The %s attacks!\n", eType.c_str());
    printf("          You use a special move:\n");
    p->SpecialAttack();
    printf("          The %s taunts you:\n", eType.c_str());
    e->TauntPlayer();
    printf("          You use a special move:\n");
    p->SpecialAttack();
    printf("          You have killed the enemy!\n");
    printf("          You are the winner of this battle!\n\n");
}

// entry point-------------------------------------------------------------
int main()
{
    Player* player = nullptr;
    Enemy* enemy = nullptr;

    int choice;
    do {
        cout << "-------------------------------------\n";
        cout << "    Welcome to Battle Simulator!\n";
        cout << "-------------------------------------\n";
        cout << "1. Create Character\n";
        cout << "2. View Character Info\n";
        cout << "3. Start Battle!\n";
        cout << "0. Exit\n\n";
        cout << "Please enter your choice: ";
        cin >> choice;
        cin.ignore();
        cout << endl;
        switch (choice)
        {
        case 1: {
            CreateCharacter(player);
            break;
        }
        case 2: {
            ViewCharacter(player);
            break;
        }
        case 3: {
            BattleSimulate(player, enemy);
            break;
        }
        case 0:
            break;
        }
    } while (choice != 0);

    if (player != nullptr)
        delete player;
    if (enemy != nullptr)
        delete enemy;
    player = nullptr;
    enemy = nullptr;
    return 0;
};