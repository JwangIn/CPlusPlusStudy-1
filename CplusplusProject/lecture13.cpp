#include "lectures.h"

/*
*  template 키워드
*  코드를 위한 틀을 만드는 것.(데이터 타입)
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
		std::cout << "a + b 의 연산자 오버로딩 출력" << std::endl;
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
*  클래스 템플릿과 함수 템플릿의 차이점
*  - 함수 템플릿은 호출 시에 <type> 명시하지 않으면 (인자)를 통해서 타입을 유추한다.
*  - 묵시적으로 템플릿 함수를 선언한다. 일반 함수가 존재한다면, 일반 함수가 먼저 실행이 된다.
*  - 클래스 템플릿은 묵시적으로 타입을 지정해주는 기능이 없다.
*/

// non type template<typenmae T, int Val>

template<typename T,int N>
class MyArray  // 우리가 직접 만드는 배열
{
private:
	T data[N]; // size 크기 만큼 배열을 선언하겠다.
public:
	MyArray() {} 
	MyArray(T(&arr)[N]) // 배열을 복사해서 저장하는 생성자
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

	// 연산자 오버로딩을 해서 []
};

/*
*  C, C++ << 언리얼 엔진, 클래스 만드는 법, 객체 지향 프로그래밍
*  추상화 : 현실에 존재하지 않는 것도 코드로 표현하는 것
*  정보 은닉, 캡슐화 => 프로그래머 실수를 방지.
*  다향성 : Play();, dynamic_cast<Dog*>
*  STL << Standard Template Library
*  - 안전성이 보장이 된다.
*  - Template : 데이터 타입을 모두 대응하는 일반화 프로그래밍.
*  Vector<>. 가변 배열 << 자료 구조
*/

// 플레이어 <-> 몬스터 배틀 시스템 (player - monster)
// GameManeger 클래스를 만들어보자.
// 기능 : 배틀 종료, 점수 시스템, 저장. 종료. 시작. 불러오기.

// GameManeger GM1; // 점수, 저장
// GameManeger GM2; // 시작, 종료
// 클래스가 한개만 존재해야 하는 패턴화 - 싱글톤 패턴
// template 클래스를 표현하면 -> 싱글톤 패턴이 필요한 클래스를 모두 사용할 수 있다.
// 상속 + 템플릿 클래스


template<typename T>
class SingleTon
{
	// 반드시 객체가 하나만 있어야 한다.
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
		std::cout << "게임 시작" << std::endl;
	}
	void GameEnd()
	{
		std::cout << "게임 종료" << std::endl;
	}
	void GameSave()
	{
		std::cout << "게임 저장" << std::endl;
	}

};

// GameData. 플레이 타입. 현재 진행중인 챕터.

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

	// 배열 
	int arrNum[3] = { 1,2,3 };
	MyArray<int, 3> mArr(arrNum);
	std::cout << "MyArray 클래스의 크기 : " << mArr.Size() << std::endl;
	mArr.ShowInfo();

	double arrDouble[5] = { 2.3,4.2,4.1,4.6,3.5 };
	MyArray<double, 5> arrD(arrDouble);
	arrD.ShowInfo();

	std::cout << "GameManeger 클래스" << std::endl;

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