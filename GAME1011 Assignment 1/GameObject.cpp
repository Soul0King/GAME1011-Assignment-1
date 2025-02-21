#include "GameObject.h"
#include <cstdlib>
#include <iostream>
#include <string>

// GameObject-------------------------------------------------------------
GameObject::~GameObject() {}

// Player-------------------------------------------------------------
void Player::NormalAttack() {}
Player::~Player() {}
ostream& operator<<(ostream& out, const Player& player)
{
    out << "Player Type: " << player.get_type() << endl;
    out << "Player Name: " << player.get_name() << endl;
    out << "Player Health: " << player.get_health() << endl;
    out << endl;
    return out;
}

// Wizard-------------------------------------------------------------
void Wizard::SpecialAttack() { cout << "\n              \"Fire Ball!!!\"\n\n"; }

// Knight-------------------------------------------------------------
void Knight::SpecialAttack() { cout << "\n              \"Power Smash!!!\"\n\n"; }

// Enemy-------------------------------------------------------------
void Enemy::NormalAttack() {}
Enemy::~Enemy() {}

// Orc-------------------------------------------------------------
string Orc::speciesName = "Orc";
void Orc::TauntPlayer()
{
    int r = rand() % 3;
    cout << "\n              \"" << taunts[r] << "\"" << endl << endl;
}

// Undead-------------------------------------------------------------
string Undead::speciesName = "Undead";
void Undead::TauntPlayer()
{
    int r = rand() % 3;
    cout << "\n              \"" << taunts[r] << "\"" << endl << endl;
}