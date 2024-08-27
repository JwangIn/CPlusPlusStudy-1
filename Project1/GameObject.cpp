#include "GameObject.h"

inline Player::Player(int HP, int AP) :HP(HP), AP(AP) {}

Player::~Player()
{
	
}

int Player::PlayerAttack()
{
	return AP;
}

void Player::PlayerBeAttaked()
{
	HP -= AD;
	std::cout << "플레이어의 HP가" << AD << "만큼 떨어젔습니다." << std::endl;
	std::cout << "플레이어의 현재 체력 : " << HP << std::endl;

}

int Monster::MonsterAttack()
{
	return AD;
}

void Monster::MonsterBeAttaked()
{
}

void Monster::Dropitem()
{
}

Goblin::Goblin(int HP, int AD) :Monster(HP, AD) {  };

