#pragma once
class Monster;

class Player : public Creature
{
public:
	// 전방선언
	void HelloMonster(class Monster* monster);

};

