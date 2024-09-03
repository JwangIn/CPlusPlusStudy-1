#include "GameObject.h"


template <typename T>
class SingleTon
{
private:
	static T* singleton;
public:
	SingleTon() {}
	virtual ~SingleTon() {}
	static T* GetSingleTon()
	{
		if (nullptr == singleton)
		{
			singleton = new T;
		}
		return singleton;
	}
	static void Release()
	{
		delete singleton;
		singleton = nullptr;
	}
};

template<typename T>
T* SingleTon<T>::singleton = nullptr;

// GameManger 클래스가 SingleTon 상속받는다. 
// SingleTon 클래스를 내부적으로 사용하고있다.
class GameManger : public SingleTon<GameManger>
{
private:
	// 멤버
public:
	GameManger() {}
	~GameManger() {}
	// 기능 : 게임 화면 출력, 게임 시작, 게임 종료
	void MainMenu()
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

	void GameStart()
	{
		std::cout << "게임시작" << std::endl;
		// 클래스 게임 이름
		Board b;
		b.GamePlay();
	}
	void GameEnd()
	{
		exit(0);
	}

};



int main()
{
	//std::cout << "Std 함수 예제" << std::endl;
	//SampleSTD* sample=new SampleSTD;
	// sample->SetWidthExmaple();
	//sample->IsDigitExample();
	//delete sample;

	GameManger* gm = GameManger::GetSingleTon();
	
	gm->MainMenu();

}