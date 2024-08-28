#include "GameObject.h"


Player::Player()
{}

Player::Player(int HP, int AP) :HP(HP), AP(AP) 
{
	std::cout << "�÷��̾ ������" << std::endl;
}

Player::~Player()
{
	std::cout << "�÷��̾ �Ҹ���" << std::endl;
}

void Player::PlayerAttack(Monster* monster)
{
	std::cout << "�÷��̾��� ����!" << std::endl;
	monster->MonsterBeAttaked(this);
	// monster -> beattacked(AP); : ���Ͱ� ���ݹ���

	// ���� ���� : bool is dead();

	// ���࿡ ���Ͱ� ������ -> ����(reward)Has-A ���� (Monster)
	// monster -> reward -> GetExp, GetGold, GetItem
}

void Player::PlayerBeAttaked(int damage)
{
	/*
	Goblin* goblin = dynamic_cast<Goblin*>(monster);
	HP -= goblin->MonsterAttack();
	std::cout << "�÷��̾��� HP��" << goblin->MonsterAttack() << "��ŭ ������ϴ�." << std::endl;
	std::cout << "�÷��̾��� ���� ü�� : " << HP << std::endl;
	*/
	std::cout << "�÷��̾ "<<damage<<"�������� �޾Ҵ�!" << std::endl;

	HP -= damage;
	if (IsDead() )
	{
		HP = 0;
		std::cout << "�÷��̾ ����Ͽ����ϴ�." << std::endl;
		exit(0);
		// GameManeger -> GameEnd() // ReturnLobby() �̷� Ŭ������ ���� �������ȴ�.
	}
}

bool Player::IsDead()
{
	if (HP <= 0) // �÷��̾ 0���� �۰ų� ���� ��
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
	std::cout << "ȹ���� �ݾ� : " << money << std::endl;
	this->money += money;
}

void Player::GetMoney(int exp)
{
	std::cout << "ȹ���� ����ġ : " << exp << std::endl;
	this->exp += exp;
}

std::vector<Item>* Player::GetInventory()
{
	return &inventory;
}

void Player::ShowStatus()
{
	std::cout << "���� ü�� : " << HP << std::endl;
	std::cout << "���� ���ݷ� : " << AP << std::endl;
	std::cout << "���� ����ġ : " << exp << std::endl;
	std::cout << "----�÷��̾� ����ǰ----" << std::endl;
	std::cout << "���� �ݾ� : " << money << std::endl;
	// �ݺ���. �������� �ִ� ��. Item �迭[i] -> ������ �̸�, ������ ��ȣ, ���...
	std::cout << "���� ������ : " << "�Լ��� �����ؾߵ�" << std::endl;
}

Monster::Monster(int HP, int AD) : HP(HP),AD(AD) {}


Goblin::Goblin(int HP, int AD,Reward* rewardPtr) :Monster(HP, AD) 
{
	std::cout << "��� ����!" << std::endl;
	InsertDropItemTable(rewardPtr);
}

void Goblin::MonsterAttack(Player* player)
{
	std::cout << "����� ����!" << std:: endl;
	player->PlayerBeAttaked(AD);
}
void Goblin::MonsterBeAttaked(Player* player)
{
	std::cout << "����� " << player->GetAttackPower() << "�� �޾Ҵ�!" << std::endl;
	HP -= player->GetAttackPower();
	if (IsDead())
	{
		HP = 0;
		std::cout << "����� óġ�ߴ�." << std::endl;


	}
}
void Goblin::DropReward(Player* player)
{
	std::cout << "����!" << std::endl;
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
	if (item != nullptr) // �������� ���� ��쿡�� �÷��̾� inventory�� �߰��ϱ� ���� ����
	{
		inventory->push_back(*item);
		std::cout << "������ ŉ�� !" << std::endl;
		item->ShowItemInfo();
	}
}
