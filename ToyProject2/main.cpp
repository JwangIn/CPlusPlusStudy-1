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

// GameManger Ŭ������ SingleTon ��ӹ޴´�. 
// SingleTon Ŭ������ ���������� ����ϰ��ִ�.
class GameManger : public SingleTon<GameManger>
{
private:
	// ���
public:
	GameManger() {}
	~GameManger() {}
	// ��� : ���� ȭ�� ���, ���� ����, ���� ����
	void MainMenu()
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

	void GameStart()
	{
		std::cout << "���ӽ���" << std::endl;
		// Ŭ���� ���� �̸�
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
	//std::cout << "Std �Լ� ����" << std::endl;
	//SampleSTD* sample=new SampleSTD;
	// sample->SetWidthExmaple();
	//sample->IsDigitExample();
	//delete sample;

	GameManger* gm = GameManger::GetSingleTon();
	
	gm->MainMenu();

}