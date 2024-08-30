#include "lectures.h"

/*
*  template Ű����
*  �ڵ带 ���� Ʋ�� ����� ��.(������ Ÿ��)
*/

class One;

template <typename T>
void Plus(T a,T b)
{
	std::cout << a << " + " << b << " = " << a + b << std::endl;
}

template<typename T1,typename T2>
void SomeFunc(T1 a,T2 b){}

template<typename T1>
void SomeFunc(T1 a,int b){}

class One
{
public:
	void operator+(const One& one)
	{
		std::cout << "a + b �� ������ �����ε� ���" << std::endl;
	}

};

template<typename T>
class Point
{
private:
	T posX;
	T posY;
public:
	Point(){}
	Point(T x, T y) : posX(x), posY(y){}
	void Show()
	{
		std::cout << "posX : " << posX << std::endl;
		std::cout << "posY : " << posY << std::endl;
	}
};

/*
*  Ŭ���� ���ø��� �Լ� ���ø��� ������
*  - �Լ� ���ø��� ȣ�� �ÿ� <type> ������� ������ (����)�� ���ؼ� Ÿ���� �����Ѵ�.
*  - ���������� ���ø� �Լ��� �����Ѵ�. �Ϲ� �Լ��� �����Ѵٸ�, �Ϲ� �Լ��� ���� ������ �ȴ�.
*  - Ŭ���� ���ø��� ���������� Ÿ���� �������ִ� ����� ����.
*/

// non type template<typenmae T, int Val>

template<typename T,int N>
class MyArray  // �츮�� ���� ����� �迭
{
private:
	T data[N]; // size ũ�� ��ŭ �迭�� �����ϰڴ�.
public:
	MyArray() {} 
	MyArray(T(&arr)[N]) // �迭�� �����ؼ� �����ϴ� ������
	{
		for (int i = 0; i < N; i++)
		{
			data[i] = arr[i];
		}
	}

	T* GetArray() { return data; };

	int Size() { return N; };

	void ShowInfo()
	{
		for (int i = 0; i < N; i++)
		{
			std::cout << data[i] << ", ";
		}
		std::cout << std::endl;
	}

	// ������ �����ε��� �ؼ� []
};

/*
*  C, C++ << �𸮾� ����, Ŭ���� ����� ��, ��ü ���� ���α׷���
*  �߻�ȭ : ���ǿ� �������� �ʴ� �͵� �ڵ�� ǥ���ϴ� ��
*  ���� ����, ĸ��ȭ => ���α׷��� �Ǽ��� ����.
*  ���⼺ : Play();, dynamic_cast<Dog*>
*  STL << Standard Template Library
*  - �������� ������ �ȴ�.
*  - Template : ������ Ÿ���� ��� �����ϴ� �Ϲ�ȭ ���α׷���.
*  Vector<>. ���� �迭 << �ڷ� ����
*/

// �÷��̾� <-> ���� ��Ʋ �ý��� (player - monster)
// GameManeger Ŭ������ ������.
// ��� : ��Ʋ ����, ���� �ý���, ����. ����. ����. �ҷ�����.

// GameManeger GM1; // ����, ����
// GameManeger GM2; // ����, ����
// Ŭ������ �Ѱ��� �����ؾ� �ϴ� ����ȭ - �̱��� ����
// template Ŭ������ ǥ���ϸ� -> �̱��� ������ �ʿ��� Ŭ������ ��� ����� �� �ִ�.
// ��� + ���ø� Ŭ����


template<typename T>
class SingleTon
{
	// �ݵ�� ��ü�� �ϳ��� �־�� �Ѵ�.
private:
	static T* singleTon;
public:
	SingleTon(){}
	virtual ~SingleTon() {}
	static T* GetSingleTon()
	{
		if (nullptr == singleTon)
		{
			singleTon = new T;
		}
		return singleTon;
	}

	static void Release()
	{
		delete singleTon;
		singleTon = nullptr;
	}

};

template<typename T>
T* SingleTon<T> ::singleTon = nullptr;

class GameManeger : public SingleTon<GameManeger>
{
private:
	int score;
public:
	GameManeger() {}
	~GameManeger() {}
	GameManeger(int s) :score(s){}
	int GetScore() { return score; }
	void SetScore(int val) { score = val; }
	void GameStart()
	{
		std::cout << "���� ����" << std::endl;
	}
	void GameEnd()
	{
		std::cout << "���� ����" << std::endl;
	}
	void GameSave()
	{
		std::cout << "���� ����" << std::endl;
	}

};

// GameData. �÷��� Ÿ��. ���� �������� é��.

class GameData :public SingleTon<GameData>
{
private: 
	int areaInfo;

public:
	GameData(){}
	~GameData() {}
	int GetAreaInfo() { return areaInfo; }
	void SetAreaInfo(int area) { areaInfo = area; }
};

void lecture13()
{
	Point<int> p1(1, 2);
	p1.Show();
	Point<float> p2(1.2, 3.2);
	p2.Show();

	// �迭 
	int arrNum[3] = { 1,2,3 };
	MyArray<int, 3> mArr(arrNum);
	std::cout << "MyArray Ŭ������ ũ�� : " << mArr.Size() << std::endl;
	mArr.ShowInfo();

	double arrDouble[5] = { 2.3,4.2,4.1,4.6,3.5 };
	MyArray<double, 5> arrD(arrDouble);
	arrD.ShowInfo();

	std::cout << "GameManeger Ŭ����" << std::endl;

	GameManeger* gm = GameManeger::GetSingleTon();
	gm->SetScore(100);
	GameManeger* gm2 = GameManeger::GetSingleTon();
	gm2->SetScore(123);
	std::cout << gm->GetScore() << std::endl;
	std::cout << gm2->GetScore() << std::endl;
	gm->GameStart();

	GameData* gd = GameData::GetSingleTon();
	gd->SetAreaInfo(2);
	std::cout << gd->GetAreaInfo() << std::endl;
}