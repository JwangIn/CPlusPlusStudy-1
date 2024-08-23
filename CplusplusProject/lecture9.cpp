#include "lectures.h"

/*
*  클래스 상속
*  1. class Parent{};
*  2. class Child : public Parent{}
*/

// 몬스터 : 추상적인 개념의 객체 ( 보유하고 있는 개념이 많음 )
// 예) Goblin,인간형,

/*
*  객체 포인터 참조관계
*  c++에서 포인터 변수는 해당 객체를 직접 혹은 간접적으로 가르킬 수 있다.
*  Dog : public Pet
*  Pet* pet; : 당연히 된다.
*  Pet* dog; : 상속된 클래스를 부모 포인터가 가르킬 수 없다.
*  Dog* dog;
*  Dog* pet; : 컴파일 에러 : 문법적으로 자식 클래스 포인터가 부모 클래스를 직접 가르키는 것을 막아두었다. -> 간접적으로 가능(형변환)
*  (Pet)Dog
*/

/*
*  정리 : 클래스의 확장성에 대한 문제를 개선하기 위한 방안1. <-> 시간
*  Dog클래스. Cat클래스도 Play(Dog* dog) Play(Cat* cat), Feed 함수로 표현
*  Cat과 Dog를 동시에 상속하는 Pet클래스를 인자로 넘겨준다.
*  Play(Pet* pet) <- Dog
*/

/*
*  부모 클래스를 인자로 사용해서 범용성 있는 함수를 구현하였다.
*  void Play(Pet* pet) -> pet을 상속받는 모든클래스를 범용적으로 표현가능하게 함
*  문제가 발생했다. pet을 상속받는 Dog,HuntDog 자식 클래스와 부모 클래스가 같은함수를 구현했는데...
*  -> 부모가 갖고 있는 함수를 자식버전으로 변경하고 싶다.
*  가삼 함수, override 키워드
*  virtual 키워드 -> 가상 함수
*  override 키워드 -> virtual과 함께 상용된다. 덮어쓰다
*/

/*
*  Pet* a=pet; : o
*  Pet* b=dog; : o
*  Pet* c=hdog; : o
* 
*  Dog* a=pet; : x
*  Dog* b=dog; : o
*  Dog* c=hdog; : o
* 
*  HuntDog* a=pet; : x
*  HuntDog* b=dog; : x
*  HuntDog* c=hdog; : o 
*/

class Pet // 플레이어가 추상적인 대상으로 접근할 수 있는 객체
{
protected:
	int hungry;
	int happy;
public:
	Pet() {};
	Pet(int hungry, int happy) :hungry(hungry), happy(happy)
	{
		std::cout << "Pet을 생성했습니다." << std::endl;
	}
	void ShowInfo()
	{
		std::cout << "배고픔 : " << hungry << std::endl << "행복도 : " << happy << std::endl;
	}
	virtual void PlayWithMaster()
	{
		std::cout << "펫과 놀아 주었다." << std::endl;
		hungry -= 10;
		happy += 5;
	}
	virtual void EatPrey()
	{
		std::cout << "펫이 기본 사료를 먹었다." << std::endl;
		hungry += 10;
		happy += 5;
	}
};
class Dog2 :public Pet
{
public:
	Dog2() {};
	Dog2(int hungry, int happy) :Pet(hungry,happy)
	{
		std::cout << "개를 생성했습니다." << std::endl;
	}
	void PlayWithMaster() override // virtual 함수로 작성된 함수가 있으면 반드시 이 함수로 override해라
	{
		std::cout << "개와 놀아주었다." << std::endl;
		hungry -= 10;
		happy += 5;
	}
};

class HuntDog : public Dog2
{
public:
	HuntDog() {};
	HuntDog(int hungry, int happy) :Dog2(hungry, happy)
	{
		std::cout << "사냥개를 생성했습니다." << std::endl;
	}
	void Hunting();
	void PlayWithMaster() override
	{
		std::cout << "사냥개와 놀아주었다." << std::endl;
		hungry -= 20;
		happy += 15;
	}
};

class Cat :public Pet
{
public:
	Cat() {};
	Cat(int hungry, int happy) :Pet(hungry, happy)
	{
		std::cout << "고양이를 생성했습니다." << std::endl;
	}
};

class PetController  // 펫 클래스를 제어하는 클래스 HAS-A일 때 클래스를 사용하는 법
{
private:
	Pet* myPet;
	int money;  // 펫 먹이, 활동을 통하여 돈 획득, 새로운 펫 구입
	int ActivePoint; // 행동력
	void UseActivePoint()
	{
		std::cout << "행동력을 1 소모했습니다." << std::endl;
		ActivePoint--;
		std::cout << "남은 행동력 : " << ActivePoint << std::endl;
	}

public:
	PetController() {}; // 디폴트 생성자
	PetController(Pet* pet, int money, int AP) :money(money), ActivePoint(AP)
	{
		myPet = pet;
	}
	void EarnMoney(int pay)
	{
		std::cout << pay << "만큼 돈을 획득했습니다." << std::endl;
		UseActivePoint();
		money += pay;
	}
	void Play()
	{
		myPet->PlayWithMaster();
		UseActivePoint();
	}
	void ShowInfo()
	{
		std::cout << "소지 금액 : " << money << std:: endl;
		std::cout << "남은 행동력 : " << ActivePoint << std::endl;
		std::cout << "------펫의 정보------" << std::endl;
		myPet->ShowInfo();
	}
		
};

// 1. 게임 난이도 
// 2. 펫을 고르는 것
// 3. 행동 종류 늘리기
// 4. AP를 다쓰면 날짜가 넘어 가는 것
// 5. 돈을 쓰는 것

void lecture9()
{
	Pet pet(100, 100);
	Dog2 dog(100, 100);
	Cat cat(100, 100);
	HuntDog huntdog(100, 100);
	PetController player(&pet, 1000, 3);
	player.Play();
	player.ShowInfo();
	
	PetController p2(&dog, 1000, 3);
	p2.Play();
	p2.ShowInfo();

	PetController p3(&huntdog, 1000, 5);
	p3.Play();
	p3.ShowInfo();

}