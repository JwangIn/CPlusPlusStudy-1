#include "GameObject.h"



void GameManger::MainMenu()
{
	// while �ݺ���. inputnum... 1.���� ���� 2. ���� ���� 3...
	while (true)
	{
		int userInput = 0;
		std::cout << "1. ���ӽ��� " << std::endl;
		std::cout << "2. ���� ����" << std::endl;
		std::cin >> userInput;
		if (userInput == 1)// ������ ����Ǹ� Ż���ض�)
		{
			GameStart();
		}
		else if (userInput == 2)
		{
			GameEnd();
		}
		else
		{
			std::cout << "�߸��� �Է�, �ٽ� �Է����ּ���." << std::endl;
		}

	}
}

void GameManger::GameStart()
{
	std::cout << "���ӽ���" << std::endl;
	// Ŭ���� ���� �̸�
	Board b;
	while (true)
	{
		// ������ �帧�� ����
	}
}

void GameManger::GameEnd()
{
	exit(0);
}

Board::Board()
{
}

Board::~Board()
{
}

void Board::insert_x(int pos)
{
	std::cin >> pos;
	// pos ĭ�� x�� �־��
}

void Board::insert_y(int pos)
{
	std::cin >> pos;
	// pos ĭ�� y�� �־��
}

std::string Board::get_item(int pos)
{
	return std::string();
}

bool Board::x_win()
{
	// x 3���� �������� �̾����� �¸�
	return false;
}

bool Board::o_win()
{
	return false;
}

std::ostream& operator<<(std::ostream& out, Board* b)
{
	// TODO: ���⿡ return ���� �����մϴ�.
}


void Board::GamePlay()
{
	while (true)
	{
		// ������ ����Ǹ� �¸��� �����ϰ� ����ȭ������ ���ư���. 
		// ������ �����Ѵ�.
	}
}


