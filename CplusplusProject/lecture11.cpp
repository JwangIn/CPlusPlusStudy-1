#include "lectures.h"

/*
*  1. c++ casting 연산자 예시
*  
*  2. virtual 가상 함수에 대한 이해 [객체 지향 프로그래밍의 다양성]
*  pure virtual
*  abstaract 클래스
*  vtable
* 
*  3. monster class(Goblin, Slime class) - Player 전투
* 
*  4. 전투 결과 Reward - Monster 죽었을 때 보상하는 아이템
*/

class AA
{
private:
	int Aint;
public:
	virtual void Show()
	{
		
		std::cout << "AA" << std::endl;
	}
};

class BB : public AA
{
private:
	int Bint;
public:
	void Show()
	{
		std::cout << "BB" << std::endl;
	}
	void MyBB()
	{
		Bint = 10;
		std::cout << "MyBB"<<std:: endl;
	}
};

class CC : public AA
{
public:
	void Show()
	{
		std::cout << "CC" << std::endl;
	}
	void MyCC()
	{

		std::cout << "MyCC" << std::endl;
	}
};
     //  2. virtual 가상 함수에 대한 이해[객체 지향 프로그래밍의 다양성]
     //  pure virtual : Pet_void Sound(Pet* pet) 개, 고양이, 새 공통적인 부분을 Pet. 울음 소리
	 //  Pet 클래스 자체는 추상적인 개념이다. 
	 // 
	 // 
     //  abstaract 클래스
     //  vtable 


class NewPet
{
public:
	virtual void Sound() = 0; // 순수 가상 함수 -> NewPet을 상속받는 Dog, Cat Sound 실행시켜라

};

// 순수 가상 함수 pure virtual function
// 기능 : 반드시 오버라이딩 되어야 하는 함수
// 순수 가상 함수를 포함하고 있는 클래스를 추상 클래스라고 한다.
// 추상 클래스는 반드시 하나 이상의 상속이 필요하다.
// NewPet*
// NewPet np1;

// virtual 가상 함수는 상속하는 클래스를 모두 참조해서 사용할 수 있다.
// 모든 함수를 virtual 함수 (가상 함수) 선언해도 문제가 없지 않나요?

// virtual 키워드 입력하는 의미 : 입력하지 않으면 키워드가 작동하지 않는다.

// 왜 c++ 기본 형식으로 virtual이 선언되지 않는가?
// virtual 내부적으로 vTable 공간을 생성한다. vPtr;
// virtual 선언하지 않았을 때 : 바로 해당 함수를 실행한다.

// 다향성이 필요하 때만 가상함수를 사용하는 것이 최적화와 속도가 빠른 코드가 될 수 있다.
// virtual 모든 함수에 사용해도 문제가 없어 보이지만 메모리, 시간에 조금씩 영향을 주고 있었다.

// monster class - 추상 클래스로 표현을 한번 해보자
// Reward class - 경험치, 재화(money), 아이템 
// Is-A, Has-A

// player <-> monster battle system
// battle class. public: bool end: 플레이어가 죽었을 때. 몬스터가 죽었을 때. 플레이어가 도주 할 때
// 무한 반복
// 1. playerturn. 1. 공격 2. 방어 3. 도주
// NextTurn
// 2. MonsterTurn 1. 공격

// 몬스터가 죽으면 monster Class (has, is) -> reward
// Player. GetItem(monster* m1);


class NewDog :public NewPet
{
public:
	virtual void Sound()
	{
		std::cout << "왈왈!" << std::endl;
	}

	virtual void Play()
	{
		std::cout << "놀다." << std::endl;
	}
	void DDD()
	{
		std::cout << "DDD" << std::endl;
	}
};






void lecture11()
{
	std::cout << "c++ casting 연산자" << std::endl;
	std::cout << "1. static_cast<type>" << std::endl;
	// 기본 자료형의 변환, 포인터 및 참조 변환, 상속 관꼐의 클래스 변환에 사용될 수 있다.

	double pi = 3.14;
	int pi_int =(int) (3.14 - 0.14); // (int)3.00000001 의 근사치 값 변환 // 3 - 0
	int pi_int2 = static_cast<int>(pi);
	std::cout << "pi_int의 값 : " << pi_int << std::endl;
	std::cout << "pi_int2의 값 : " << pi_int2 << std::endl;

	// 첫번째, 
	AA* aPtr1 = new AA();
	aPtr1->Show();
	AA* aPtr2 = new BB();
	aPtr2->Show();
	AA* aPtr3 = new CC();

	// static_cast 상속관계의 클래스를 표현

	BB* bPtr1=static_cast<BB*>(aPtr2);
	bPtr1->Show();
	bPtr1->MyBB();

	BB* bPtr2 = static_cast<BB*>(aPtr3);
	bPtr2->Show();
	bPtr2->MyBB();

	// static_cast<type> : 다음 객체는 무조건 TYPE형태로 형변환을 시킨다.

	// 상속 사이의 클래스의 형변환 dynamic_cast


	CC* cPtr1 = dynamic_cast<CC*>(aPtr3);
	if(cPtr1!=nullptr) // C언어 NULL #define NULL 0. 포인터 변수 0. 가리키는 주소가 없다. nullptr
	cPtr1->MyCC();

	//const_cast : const 키워드를 수식받는 변수의 상수성을 없애는 변환

	const int num = 10;
	int* NonConstNum = const_cast<int*>(&num);
	*NonConstNum = 12;

	std::cout << "num2의 값 : " << num << std::endl;
	std::cout << "NonConstNum의 값 : " << NonConstNum << std::endl;

	// reinterpret_cast

	// int 16 = 0 0 0 00001000()
	// char 63 = 0111119090

	int num2 = 63; // int 형 주소값  char주소랑  강제 형변환
	char* charPtr = reinterpret_cast<char*>(&num2);
	std::cout << "차형태로 강제 형변환 : " << *charPtr<<std::endl;

	double*  interPtrValue = reinterpret_cast<double*>(&num2);
	std::cout << "정수를 강제로 실수로 변환" << *interPtrValue << std::endl;

	NewPet* nP1 = new NewDog();
	nP1->Sound();

	

	NewDog* nD1 = dynamic_cast<NewDog*>(nP1);

	nD1->DDD();











}