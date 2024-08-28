#pragma once
#include <iostream>
#include <string>
#include <vector>

// 몬스터와의 전투
// 1. 공격 - 공격력, 체력

class Item
{
private:
	std::string name;
	int index;
public:
	Item() {};
	Item(std::string name, int index) :name(name), index(index){}
	~Item() {};
	void ShowItemInfo()
	{
		std::cout << "아이템의 이름 : " << name << std::endl;
		std::cout << "아이템의 번호 : " << index << std::endl;
	}
};

class Reward
{
private:
	int Exp;
	int Money;
	Item* item;
public:
	Reward() {};
	Reward(int exp, int money,Item& item) :Exp(exp), Money(money)
	{
		this->item = new Item();
		this->item = &item;
	}
	~Reward()
	{
		delete item;
	}

	void RewardItem(std::vector<Item>* inventory);
	int RewardMoney(int& playerMoney);
	int RewardExp(int& playerExp);
};

class Monster;

class Player
{
private:
	int HP;
	int AP;
	int exp;
	int money;
	std::vector<Item> inventory; // 아이템 인벤토리를 확장하고 싶으면 가변 배열 vector
public:
	Player() ; // 기본 생성자
	Player(int HP, int AP);;
	~Player() ;

	void PlayerAttack(Monster* monster);
	void PlayerBeAttaked(int damage);
	// 사망 체크 함수
	bool IsDead();

	int GetAttackPower();
	int GetExp(int money) { return exp; };
	int GetMoney(int exp) { return money; };
	std::vector<Item>* GetInventory();

	void ShowStatus();

};

// 순수 가상함수
class Monster
{
protected:
	int HP;
	int AD;
	// std::string Name;
	Reward* monsterReward;
public:
	Monster() {}
	Monster(int HP, int AD);
	~Monster() {}

	virtual void MonsterAttack(Player* player) = 0;
	virtual void MonsterBeAttaked(Player* player)=0;
	virtual void DropReward(Player* player)=0;
};

class Goblin : public Monster
{

public:
	Goblin(){}
	Goblin(int HP, int AD,Reward* rewardPtr);
	~Goblin(){}
	void InsertDropItemTable(Reward* rewardPtr)
	{
		monsterReward = new Reward();
		monsterReward = rewardPtr;
	}
	void MonsterAttack(Player* player);
	void MonsterBeAttaked(Player* player);
	void DropReward(Player* player);
	bool IsDead();
};


