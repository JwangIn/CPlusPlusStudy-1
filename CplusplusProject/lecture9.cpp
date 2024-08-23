#include "lectures.h"

/*
*  Ŭ���� ���
*  1. class Parent{};
*  2. class Child : public Parent{}
*/

// ���� : �߻����� ������ ��ü ( �����ϰ� �ִ� ������ ���� )
// ��) Goblin,�ΰ���,

/*
*  ��ü ������ ��������
*  c++���� ������ ������ �ش� ��ü�� ���� Ȥ�� ���������� ����ų �� �ִ�.
*  Dog : public Pet
*  Pet* pet; : �翬�� �ȴ�.
*  Pet* dog; : ��ӵ� Ŭ������ �θ� �����Ͱ� ����ų �� ����.
*  Dog* dog;
*  Dog* pet; : ������ ���� : ���������� �ڽ� Ŭ���� �����Ͱ� �θ� Ŭ������ ���� ����Ű�� ���� ���Ƶξ���. -> ���������� ����(����ȯ)
*  (Pet)Dog
*/

/*
*  ���� : Ŭ������ Ȯ�强�� ���� ������ �����ϱ� ���� ���1. <-> �ð�
*  DogŬ����. CatŬ������ Play(Dog* dog) Play(Cat* cat), Feed �Լ��� ǥ��
*  Cat�� Dog�� ���ÿ� ����ϴ� PetŬ������ ���ڷ� �Ѱ��ش�.
*  Play(Pet* pet) <- Dog
*/

/*
*  �θ� Ŭ������ ���ڷ� ����ؼ� ���뼺 �ִ� �Լ��� �����Ͽ���.
*  void Play(Pet* pet) -> pet�� ��ӹ޴� ���Ŭ������ ���������� ǥ�������ϰ� ��
*  ������ �߻��ߴ�. pet�� ��ӹ޴� Dog,HuntDog �ڽ� Ŭ������ �θ� Ŭ������ �����Լ��� �����ߴµ�...
*  -> �θ� ���� �ִ� �Լ��� �ڽĹ������� �����ϰ� �ʹ�.
*  ���� �Լ�, override Ű����
*  virtual Ű���� -> ���� �Լ�
*  override Ű���� -> virtual�� �Բ� ���ȴ�. �����
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

class Pet // �÷��̾ �߻����� ������� ������ �� �ִ� ��ü
{
protected:
	int hungry;
	int happy;
public:
	Pet() {};
	Pet(int hungry, int happy) :hungry(hungry), happy(happy)
	{
		std::cout << "Pet�� �����߽��ϴ�." << std::endl;
	}
	void ShowInfo()
	{
		std::cout << "����� : " << hungry << std::endl << "�ູ�� : " << happy << std::endl;
	}
	virtual void PlayWithMaster()
	{
		std::cout << "��� ��� �־���." << std::endl;
		hungry -= 10;
		happy += 5;
	}
	virtual void EatPrey()
	{
		std::cout << "���� �⺻ ��Ḧ �Ծ���." << std::endl;
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
		std::cout << "���� �����߽��ϴ�." << std::endl;
	}
	void PlayWithMaster() override // virtual �Լ��� �ۼ��� �Լ��� ������ �ݵ�� �� �Լ��� override�ض�
	{
		std::cout << "���� ����־���." << std::endl;
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
		std::cout << "��ɰ��� �����߽��ϴ�." << std::endl;
	}
	void Hunting();
	void PlayWithMaster() override
	{
		std::cout << "��ɰ��� ����־���." << std::endl;
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
		std::cout << "����̸� �����߽��ϴ�." << std::endl;
	}
};

class PetController  // �� Ŭ������ �����ϴ� Ŭ���� HAS-A�� �� Ŭ������ ����ϴ� ��
{
private:
	Pet* myPet;
	int money;  // �� ����, Ȱ���� ���Ͽ� �� ȹ��, ���ο� �� ����
	int ActivePoint; // �ൿ��
	void UseActivePoint()
	{
		std::cout << "�ൿ���� 1 �Ҹ��߽��ϴ�." << std::endl;
		ActivePoint--;
		std::cout << "���� �ൿ�� : " << ActivePoint << std::endl;
	}

public:
	PetController() {}; // ����Ʈ ������
	PetController(Pet* pet, int money, int AP) :money(money), ActivePoint(AP)
	{
		myPet = pet;
	}
	void EarnMoney(int pay)
	{
		std::cout << pay << "��ŭ ���� ȹ���߽��ϴ�." << std::endl;
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
		std::cout << "���� �ݾ� : " << money << std:: endl;
		std::cout << "���� �ൿ�� : " << ActivePoint << std::endl;
		std::cout << "------���� ����------" << std::endl;
		myPet->ShowInfo();
	}
		
};

// 1. ���� ���̵� 
// 2. ���� ���� ��
// 3. �ൿ ���� �ø���
// 4. AP�� �پ��� ��¥�� �Ѿ� ���� ��
// 5. ���� ���� ��

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