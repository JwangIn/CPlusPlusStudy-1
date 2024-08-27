#pragma once
#include <iostream>
#include <string>


class Player
{
private:
	int HP;
	int AP;
public:
	Player(int HP, int AP);;
	~Player();

	int PlayerAttack();
	void PlayerBeAttaked();
};

class Monster
{
private:
	int HP;
	int AD;
	std::string Name;
	Reward* monsterReward;
public:
	Monster(int HP, int AD);
	~Monster();

	int MonsterAttack();
	void MonsterBeAttaked();
	void Dropitem();
};

class Goblin : public Monster
{

public:
	Goblin(int Hp, int AD);
};

class Reward
{
private:
	int Exp;
	int Money;
	Item* item;
public:

};

class Item
{
	
};



