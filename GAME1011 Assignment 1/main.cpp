#include <iostream>
#include <string>

using namespace std;

class GameObject {
private:


public:
	virtual void NormalAttack() = 0;



};

class Player : GameObject {
private:
	string name;
	int health;


public:

	int get_health() { return health; }
	void set_health(int v) { health = v; }

	string get_name() { return name; }
	void set_name(string n) { name = n; }

	virtual void SpecialAttack() = 0;

	void NormalAtack() {

	}



 };

class Wizard : Player {
private:
	static string specialAttack;
	int specialDamage;


public:
	
	void SpecialAttack() {

	}


};

class Knight : Player {
private:
	static string specialAttack;
	int specialDamage;


public:
	void SpecialAttack() {

	}



};

class Enemy : GameObject {
private:
	int health;


public:

	int get_health() { return health; }
	void set_health(int v) { health = v; }

	virtual void TauntPlayer() = 0;

	void NormalAtack() {

	}



};

class Orc : Enemy {
private:
	static string speciesName;
	string taunts[3] = { "Meat's back on the menu boys!", "You're not wanted here!", "RRRAAAAAAAAAAAAAAAAARRRRRGGGG!" };


public:
	void TauntPlayer() {

	}


};

class Undead : Enemy {
private:
	static string speciesName;
	string taunts[3] = { "BRAAAAIIIINNNNSSS!", "Away! Away!", "UUUGGGGHHHHH!" };


public:
	void TauntPlayer() {

	}


};

int main() {
	// Here are just some prewritten print statements i made to save time.
	//printf("Welcome to battle simulation!");
	//printf("Would you like to play as a Wizard or a Knight?");
	//printf("What is your characters name");
	//printf("%n is a %c with %h health"); //%n is the name, %c is the class, %h is the health value
	//printf("Are you ready to witness an epic battle?");
	//printf("you are fighting a(n) %c with %h health"); //%c is the enemy class, %h is the enemy health value
	//printf("The %c taunts you!"); //%c is the enemy class
	//printf("You fight back!");
	//printf("You use a special move!");
	//printf("The enemy fights!");
	//printf("You have killed the enemy!");
	//printf("You are the winner of this battle!");
	

	return 0;
};

