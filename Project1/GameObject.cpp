#include "GameObject.h"


Player::Player()
{}

Player::Player(int HP, int AP) :HP(HP), AP(AP) 
{
	std::cout << "플레이어가 생성됨" << std::endl;
}

Player::~Player()
{
	std::cout << "플레이어가 소멸함" << std::endl;
}

void Player::PlayerAttack(Monster* monster)
{
	std::cout << "플레이어의 공격!" << std::endl;
	monster->MonsterBeAttaked(this);
	// monster -> beattacked(AP); : 몬스터가 공격받음

	// 몬스터 죽음 : bool is dead();

	// 만약에 몬스터가 죽으면 -> 보상(reward)Has-A 몬스터 (Monster)
	// monster -> reward -> GetExp, GetGold, GetItem
}

void Player::PlayerBeAttaked(int damage)
{
	/*
	Goblin* goblin = dynamic_cast<Goblin*>(monster);
	HP -= goblin->MonsterAttack();
	std::cout << "플레이어의 HP가" << goblin->MonsterAttack() << "만큼 떨어젔습니다." << std::endl;
	std::cout << "플레이어의 현재 체력 : " << HP << std::endl;
	*/
	std::cout << "플레이어가 "<<damage<<"데미지를 받았다!" << std::endl;

	HP -= damage;
	if (IsDead() )
	{
		HP = 0;
		std::cout << "플레이어가 사망하였습니다." << std::endl;
		exit(0);
		// GameManeger -> GameEnd() // ReturnLobby() 이런 클래스를 만들어서 끝내도된다.
	}
}

bool Player::IsDead()
{
	if (HP <= 0) // 플레이어가 0보다 작거나 같을 때
		return true;
	else
		return false;
}

int Player::GetAttackPower()
{
	return AP;
}

void Player::GetExp(int money)
{
	std::cout << "획득한 금액 : " << money << std::endl;
	this->money += money;
}

void Player::GetMoney(int exp)
{
	std::cout << "획득한 경험치 : " << exp << std::endl;
	this->exp += exp;
}

std::vector<Item>* Player::GetInventory()
{
	return &inventory;
}

void Player::ShowStatus()
{
	std::cout << "현재 체력 : " << HP << std::endl;
	std::cout << "현재 공격력 : " << AP << std::endl;
	std::cout << "현재 경험치 : " << exp << std::endl;
	std::cout << "----플레이어 소지품----" << std::endl;
	std::cout << "현재 금액 : " << money << std::endl;
	// 반복문. 아이템의 최대 수. Item 배열[i] -> 아이템 이름, 아이템 번호, 기능...
	std::cout << "현재 아이템 : " << "함수로 구현해야됨" << std::endl;
}

Monster::Monster(int HP, int AD) : HP(HP),AD(AD) {}


Goblin::Goblin(int HP, int AD,Reward* rewardPtr) :Monster(HP, AD) 
{
	std::cout << "고블린 생성!" << std::endl;
	InsertDropItemTable(rewardPtr);
}

void Goblin::MonsterAttack(Player* player)
{
	std::cout << "고블린의 공격!" << std:: endl;
	player->PlayerBeAttaked(AD);
}
void Goblin::MonsterBeAttaked(Player* player)
{
	std::cout << "고블린이 " << player->GetAttackPower() << "를 받았다!" << std::endl;
	HP -= player->GetAttackPower();
	if (IsDead())
	{
		HP = 0;
		std::cout << "고블린을 처치했다." << std::endl;


	}
}
void Goblin::DropReward(Player* player)
{
	std::cout << "보상!" << std::endl;
	monsterReward->RewardExp();
	monsterReward->RewardMoney();
	monsterReward->RewardItem(player->GetInventory());
}
bool Goblin::IsDead()
{
	if (HP <= 0) 
		return true;
	else
		return false;
}

void Reward::RewardItem(std::vector<Item>* inventory)
{
	if (item != nullptr) // 아이템이 있을 경우에만 플레이어 inventory에 추가하기 위한 조건
	{
		inventory->push_back(*item);
		std::cout << "아이템 흭득 !" << std::endl;
		item->ShowItemInfo();
	}
}
