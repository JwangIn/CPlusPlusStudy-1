#include "GameObject.h"



void GameManger::MainMenu()
{
	// while 반복문. inputnum... 1.게임 시작 2. 게임 종료 3...
	while (true)
	{
		int userInput = 0;
		std::cout << "1. 게임시작 " << std::endl;
		std::cout << "2. 게임 종료" << std::endl;
		std::cin >> userInput;
		if (userInput == 1)// 게임이 종료되면 탈출해라)
		{
			GameStart();
		}
		else if (userInput == 2)
		{
			GameEnd();
		}
		else
		{
			std::cout << "잘못된 입력, 다시 입력해주세요." << std::endl;
		}

	}
}

void GameManger::GameStart()
{
	std::cout << "게임시작" << std::endl;
	// 클래스 게임 이름
	Board b;
	while (true)
	{
		// 게임의 흐름을 정리
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
	// pos 칸에 x를 넣어라
}

void Board::insert_y(int pos)
{
	std::cin >> pos;
	// pos 칸에 y를 넣어라
}

std::string Board::get_item(int pos)
{
	return std::string();
}

bool Board::x_win()
{
	// x 3개가 연속으로 이어지면 승리
	return false;
}

bool Board::o_win()
{
	return false;
}

std::ostream& operator<<(std::ostream& out, Board* b)
{
	// TODO: 여기에 return 문을 삽입합니다.
}


void Board::GamePlay()
{
	while (true)
	{
		// 게임이 종료되면 승리를 선언하고 메인화면으로 돌아간다. 
		// 게임을 종료한다.
	}
}


