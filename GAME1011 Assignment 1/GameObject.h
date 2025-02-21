#include <string>
using namespace std;

class GameObject
{
  public:
    virtual void NormalAttack() = 0;
    virtual ~GameObject() = 0;
};

// Player, Wizard, Knight----------------------------------------------------
class Player : public GameObject
{
  private:
    string name;
    float health = 100.0f;

  public:
    inline string get_name() const { return name; }
    inline void set_name(string n) { name = n; }
    inline float get_health() const { return health; }
    inline void set_health(float v) { health = v; }
    inline virtual string get_type() const = 0;

    void NormalAttack() override;
    virtual void SpecialAttack() = 0;
    virtual ~Player() = 0;
};
std::ostream& operator<<(std::ostream& out, const Player& player);
class Wizard : public Player
{
  private:
    static string specialAttack;
    float specialDamage;

  public:
    inline string get_type() const override { return "Wizard"; }
    void SpecialAttack() override;
};
class Knight : public Player
{
  private:
    static string specialAttack;
    float specialDamage;

  public:
    inline string get_type() const override { return "Knight"; }
    void SpecialAttack() override;
};

// Enemy, Orc, Undead----------------------------------------------------
class Enemy : public GameObject
{
  private:
    float health = 200.0f;

  public:
    inline float get_health() const { return health; }
    inline void set_health(float v) { health = v; }

    void NormalAttack() override;
    virtual void TauntPlayer() = 0;
    virtual ~Enemy() = 0;
};
class Orc : public Enemy
{
  private:
    string taunts[3] = {"Meat's back on the menu boys!", "You're not wanted here!", "RRRAAAAAAAAAAAAAAAAARRRRRGGGG!"};

  public:
    static string speciesName;
    void TauntPlayer() override;
};
class Undead : public Enemy
{
  private:
    string taunts[3] = {"BRAAAAIIIINNNNSSS!", "Away! Away!", "UUUGGGGHHHHH!"};

  public:
    static string speciesName;
    void TauntPlayer() override;
};