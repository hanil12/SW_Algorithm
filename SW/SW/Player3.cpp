#include "Player3.h"

enum Type
{
	Player,
	Knight,
	Mage
};

class Player
{
protected:
	Type type = Type::Player;
};

class Knight : public Player
{
	Knight() { type = Type::Knight; }
};