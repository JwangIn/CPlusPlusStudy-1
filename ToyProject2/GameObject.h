#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

// Ŭ���� Ű����. �̸�, ����� �ؾ��ϸ� ����� ����.
// ��ɰ� ��� ���� ���� private, public, protected
// ������, �Ҹ��� - ���������, ���� ���� - ���� ����
// ��� : virtual <-> �Ϲ� �Լ�
// ���⼺ ǥ�� - Ŭ������ Ȯ�强�� �������ش�.
// virtual �Լ�(); �ڽ� �Լ�(�̸��� ����) override;
// c++ ����ȯ. �θ� Ŭ���� -> �ڽ� Ŭ������ ��ȯ ���ִ� dynamic_cast .if ���� �Բ� ����ؼ� ������ ����ȯ ����
// template �Ϲ�ȭ �ڵ� �ۼ��ϴ� ��

// ƽ���� ���� 
// ������  3x3  �������� �������Ѵ�. -> Ŭ������ ǥ�� class Board
// ���1 : �÷��̾ ���� �׸���. X �Ǵ� O insert_X, insert_O 
// ���2 : X_Win, O_Win
// �¸� ���� : ������ �ϼ�, ������ �ϼ�, �밢��(���� ������ �Ʒ�), �밢��(������ ���� �Ʒ�)

// ����ϸ� ���� �Լ���
// std::cin >> input; �������� �ƴ��� �Ǻ�, std::isdigit();
// std::setw() ������ ���̸� �����ϰ� ���߾� �ִ� �Լ�
// �����͸� Ŭ������ ǥ���� �� -> iterator
// ���ڿ��� Ŭ������ ǥ���� �� -> string

template <typename T>
class SingleTon
{
private:
	static T* singleton;
public:
	SingleTon(){}
	virtual ~SingleTon(){}
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
	GameManger(){}
	~GameManger(){}
	// ��� : ���� ȭ�� ���, ���� ����, ���� ����
	void MainMenu();
	void GameStart();
	void GameEnd();
};

class Board
{
private:
	int size; // ũ�Ⱑ 3
	std::string** bmap;// 2���� �迭 [����][����]
public:
	Board();
	~Board();

	void GamePlay();

	// 2���� �迭�� �����͸� �ִ� �Լ�
	void insert_x(int pos);
	void insert_y(int pos);

	// 2���� �迭�ȿ� �����Ͱ� �ִ��� ������ üũ �ϴ� �Լ�
	std::string get_item(int pos);

	bool x_win();
	bool o_win();

	int GetSize() { return size; }

};

// std::cout �Լ��� �̿��ؼ� Ŭ������ ����ϰڴ�.
std::ostream& operator<< (std::ostream& out, Board* b);


