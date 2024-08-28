#include <iostream>
#include "GameObject.h"

// monster class - �߻� Ŭ������ ǥ���� �ѹ� �غ���
// Reward class - ����ġ, ��ȭ(money), ������ 
// Is-A, Has-A

// player <-> monster battle system
// battle class. public: bool end: �÷��̾ �׾��� ��. ���Ͱ� �׾��� ��. �÷��̾ ���� �� ��
// ���� �ݺ�
// 1. playerturn. 1. ���� 2. ��� 3. ����
// NextTurn
// 2. MonsterTurn 1. ����

// ���Ͱ� ������ monster Class (has, is) -> reward
// Player. GetItem(monster* m1);


int main(void)
{
	std::cout << "RPG BATTLE SYSTEM" << std::endl;

	Player player(100, 10);
	player.PlayerBeAttaked(10);
	
	Item sword("�ҵ�", 1);
	Reward slimeReward(50,100,sword);
	Goblin goblin(50, 5,&slimeReward);

	int userInput = 0;
	int turn = 1;
	while (true)
	{
		std::cout << "���� �������� �� �� : " << turn << std::endl;
		std::cout << "1�� ����, 2�� ??, 3�� ?? " << std::endl;
		std::cin >> userInput;
		if (userInput == 1)
		{
			player.PlayerAttack(&goblin);
		}
		else if (userInput == 2)
		{
			player.ShowStatus();
		}
		std::cout << "����� Turn" << std::endl;
		goblin.MonsterAttack(&player);

		if (player.IsDead() || goblin.IsDead())
		{
			break;
		}


	}


	// 1. ���� ���� ȭ��

	// 2. ���� ���� �÷���

	// Phase 1. Map Adventure (���� ���ƴٴϴ� ���) (Step++ RandomEncount : Srand(5 ~25))
	// Ư�� Ÿ���� ������ ���Ͷ� �������� ������ ���� �Լ��� ������.

	// Phase 2. Player vs Monster (���͸� �ϳ� �����, �� ���� ������ �ٸ� varitaion)

	// Player ��ü ����
	// monster ��ü ����
	// monster reward ��ü
	// reward item ��ü

	// while (true)

}