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
	void Bark()
	{
		std::cout << "�п�" << std::endl;

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
	void Hunting()
	{
		std::cout << "��ɰ��� ����� �մϴ�." << std::endl;
	}
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
	void Hide()
	{
		std::cout << "����̰� �������ϴ�." << std::endl;
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
	
	// Pet Ŭ������ �̿��ؼ� ���� �Լ��� �����Ű�� �ʹ�.
	// Pet�� ���� Ŭ������ Ÿ�� ��ȯ(Casing) ��Ű�� �ʹ�.
	// ����. ��� Pet�� ��ӹ޴� �ϳ��� �ڽ� Ŭ������ ��ȯ�� �� ����.
	// ������ �ʿ�������.

	// c��� ����ȯ (Ÿ��)�̸�;
	// c++��� ����ȯ ������ �߰��ؼ� �����ڷ� ���� �� �ִ�.
	// static_cast, dynamic_cast, reinterpret_cast, const_cast

	// dynamic_cast ����ȯ
	// if ���ǹ�����

	void Play2() // Cat, Dog,Bird ������ �Լ��� ������ּ���
	{
		/* if (myPet)  // ���࿡ huntdog���
		 huntdog->Hunting();*/
		HuntDog* huntdog = dynamic_cast<HuntDog*>(myPet);
		if(huntdog!=nullptr)
		huntdog->Hunting();

		Cat* cat = dynamic_cast<Cat*>(myPet);
		if (cat != nullptr)
			cat->Hide();
		Dog2* dog = dynamic_cast<Dog2*>(myPet);
		if (dog != nullptr)
			dog->Bark();


	}

	void ShowInfo()
	{
		std::cout << "���� �ݾ� : " << money << std:: endl;
		std::cout << "���� �ൿ�� : " << ActivePoint << std::endl;
		std::cout << "------���� ����------" << std::endl;
		myPet->ShowInfo();
	}
		
};

// ��ü���α׷����� �پ缺 : ���� ���·� ������ ����� ����
// Ŭ������ Ȯ���� �� ���� ���� �Լ��� �����ε��� �����ϴ� ���� ���ϰ�
// �ϳ��� �Լ��� ǥ���ϱ� ���ؼ�
// PetController�� ���� player.Play(); ���°� ��� ����.
// ����� ��� �ٸ���.

// ����� �Լ� Virtual void PlayWithMaster();
// �̸��� ��ȯ ���� ���� �Լ��� ��ӹ޴� Ŭ������ ������ ������Ѵ�.

// Pet�� ��ӹ޴� Ŭ�����ε�, �� Ŭ���� ������ �޼��带 �����ϴ� ���
// Hunting �����ϴ� ��.. Cat,Hide ������ �Ϸ��� ��� �ؾ��ϴ°�?

// Play(Pet* pet); ���� 
// PlayWithCat(Cat* cat); (Cat& cat); cat->Hide();
// ������ : �ٸ� ��ü�� ���鶧 ���� ���������� ��) PlayWithDog(Dog* dog)l

// Ŭ������ ����ϴ� ���� ù��°. PetController���� Pet�� ����ϴ� ����� �Լ��� �ѹ��� ǥ���Ѵ�.
// �ι�°. Ŭ���� Ȯ�强. Pet -> Dog,Cat,Bird ������ �Լ��� ���� �ȴ�. Cat,Dog,Bird ���ڷ� ������� �ϸ� ����������.
// ����ȯ(�ڽ�<->�θ�)dynamic_cast : ����ȯ�� �Ұ����ϸ� nullPtr ��ȯ�ϴ°� Ư¡

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
	p2.Play2();
	p2.ShowInfo();

	PetController p3(&huntdog, 1000, 5);
	p3.Play();
	p3.Play2();
	p3.ShowInfo();

	PetController p4(&cat, 1000, 5);
	p4.Play();
	p4.Play2();
}