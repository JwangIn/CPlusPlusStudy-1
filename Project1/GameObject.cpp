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
	std::cout << "�÷��̾��� HP��" << AD << "��ŭ ������ϴ�." << std::endl;
	std::cout << "�÷��̾��� ���� ü�� : " << HP << std::endl;

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

