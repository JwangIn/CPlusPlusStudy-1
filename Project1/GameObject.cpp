#include "GameObject.h"


Player::Player()
{}

Player::Player(int HP, int AP) :HP(HP), AP(AP) {}

Player::~Player()
{
	
}

int Player::PlayerAttack()
{
	return AP;
}

void Player::PlayerBeAttaked(Monster* monster)
{
	
	Goblin* goblin = dynamic_cast<Goblin*>(monster);
	HP -= goblin->MonsterAttack();
	std::cout << "플레이어의 HP가" << goblin->MonsterAttack() << "만큼 떨어젔습니다." << std::endl;
	std::cout << "플레이어의 현재 체력 : " << HP << std::endl;

}

Monster::Monster()
{}

Monster::Monster(int HP, int AD) : HP(HP),AD(AD) {}

int Monster::MonsterAttack() 
{
	return AD;
}

void Monster::MonsterBeAttaked(Player* player)
{
	HP -= player->PlayerAttack();

}

void Monster::Dropitem()
{
}

Goblin::Goblin(int HP, int AD) :Monster(HP, AD) {  };

