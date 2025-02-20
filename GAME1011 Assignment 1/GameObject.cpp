#include "GameObject.h"
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
void Wizard::SpecialAttack() {}

// Knight-------------------------------------------------------------
void Knight::SpecialAttack() {}

// Enemy-------------------------------------------------------------
void Enemy::NormalAttack() {}
Enemy::~Enemy() {}

// Orc-------------------------------------------------------------
void Orc::TauntPlayer() {}

// Undead-------------------------------------------------------------
void Undead::TauntPlayer() {}