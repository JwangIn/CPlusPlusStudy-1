#include "lectures.h"
#define _CRT_SECURE_NO_WARINGS

// Pet Ŭ���� 
// Dog, HuntDog, Cat : Pet�� ����ϴ� Ŭ����
// (dwon,child,derived) // (up,parent,base)

// PetController Handle Ŭ����
// Has-A. Feed(Pet* pet) Play(Pet* pet)

// 1. Ȯ�强�� ������ 
// Play(Dog,Cat,Bird...) Ȯ���ؾ� �ϴ� Ŭ������ŭ �����ε��� �ؾ��ϴ� ����
// 1-2 �ذ� ���
// Play(Pet* pet) -> Pet Ŭ���� �ȿ� �ִ� virtual void PlayWithMaster();
// virtual - override

// Ŭ���� �����Ϳ� ��� ����
// First Ŭ���� Ÿ��
// Second Ŭ���� Ÿ�� (First Ŭ���� + Second ���� ���)

// First* a = new First();
// First* b = new Second();

// Second* b = new Second();
// Second* a = new First();

class First
{
private:
	char* str1;
public:
	First(const char* _str1)
	{
		str1 = new char[strlen(_str1 + 1)];
		strcpy_s(str1, strlen(str1 ), _str1);
	}
	virtual void SimpleFunc()
	{
		std::cout << str1 << std::endl;
	}
};

class Second : public First
{
private:
	char* str2;
public:
	Second(const char* _str1, const char* _str2) : First(_str1)
	{
		str2 = new char[strlen(_str2 + 1)];
		strcpy_s(str2, strlen(str2 ), _str2);
	}
	void SimpleFunc() override
	{
		std::cout << str2 << std::endl;
	}
};

class Handler
{

};

// c��� ����ȯ (Ÿ��)�̸�;
// c++��� ����ȯ ������ �߰��ؼ� �����ڷ� ���� �� �ִ�.
// static_cast, dynamic_cast, reinterpret_cast, const_cast

// 1. static_cast ������ (static : ������)
// 2. dynamic_cast ������ (dynamic : ������)

// ù��°. �⺻ ������ Ÿ��(primitive Type) : int, double, char ���� ����ȯ�� ������ static_cast ����϶�

class Water
{
private:
	int mL;
public:
	Water(int mL):mL(mL){}
	virtual void Show()
	{
		std::cout << mL << "mL" << std::endl;
	}
};

class SparklingWater : public Water
{
private:
	int sparkle;
public:
	SparklingWater(int mL, int sparkle) : Water(mL),sparkle(sparkle){}
	void Show() override
	{
		Water::Show();
		std::cout << sparkle << std::endl;
	}
};

// ������, ������ ������ ����ȯ ������
// reinterpret_cast

/*
*  c++ ����ȯ  ������ ����
*  - �⺻ �ڷ����� ����ȯ�� static_cast�� ����϶�
*  - ��Ӱ��迡�� ����ȯ�� dynamic_cast�� ����϶�
*  - ��Ӱ��Կ��� ������ ����ȯ�� �ؾ��ϴ� ��쿡�� static_cast�� ����϶�
*  - ������/���� Ÿ�Կ��� ������ ����ȯ�� ���� ��Ű���� reinterpret_cast�� ����϶�
*  - const ������ ���ַ��� const_cast�� ����϶�
*/


void lecture10()
{
	First* fptr = new First("ù��° Ŭ����");
	fptr->SimpleFunc();

	First* sPtr = new Second("ù��° Ŭ����", "�ι�° Ŭ����");
	sPtr->SimpleFunc();

	// 1�� ���� static_cast
	std::cout << "static_cast �⺻ ����ȯ" << std::endl;
	int d = 4;
	char* iPtr = (char*)d; // c ��Ÿ���� ����ȯ
	// reinterpret_cast ����
	// �뵵 : ������, ������ ������ ����ȯ�� ������ �����Ų��.
	// parent* child*
	char* iPtr2 = reinterpret_cast<char*>(&d);
	First* sptr2 = reinterpret_cast<First*>(fptr);

	// const_cast ������
	// ��� Ű����� ������ ������ �� ����� �����ϴ� ������.
	const char* str = "Hello";
	char* str2 = const_cast<char*>(str);
	// ���� ���� str2[2] ='a'; // str2 ���� �����ؼ� �����ϴ� ���� �Ұ��� �ϴ�.
	std::cout << str2 << std::endl;

	int newint = static_cast<int>(d);

	// static_cast �� ����ϴ� ����
	// 1. ���� ����ȯ�� �Ʒ� �������� �����ϰ� �ִ�.
	// �ٸ� Ÿ�� ���� �� ��ȯ �����Ѵ�. (int <-> double <-> char)

	// 2. �θ� <-> �ڽ� Ŭ���� ����ȯ
	// Parent* parent = new Child();
	// (Child)parent;

	// dynamic_cast ������
	// ��Ӱ��迡���� ����ȯ�� �����ϰ� ó���� �� �ִ� ������
	// static_cast�� ��쿡�� ����ȯ�� �Ұ����� ��쿡�� �������� ����ϱ� ������
	// ��Ӱ��迡�� �Ҿ����� ����ȯ ����̴�.
	// dynamic_cast ����ؾ��Ѵ�.

	// �θ� Ŭ���� �ڽ� Ŭ������ ����ȯ�϶�
	std::cout << "�θ� �ڽ� ����ȯ ����" << std::endl;
	Water* water = new SparklingWater(100, 10);
	water->Show();

	SparklingWater* spWater = dynamic_cast<SparklingWater*>(water); // �θ� ������(ź����� ����ִ� ��ü)
	spWater->Show();

	Water* water2 = new Water(150);
	SparklingWater* spWater2 = dynamic_cast<SparklingWater*>(water2); // �θ� �����Ͱ� ����ִ�.
	if(spWater2!=nullptr)
	spWater2->Show();

	// spWater2�� static_cast�� ����ȯ�ϸ� �״�� ������ ������ �߻��Ѵ�.
	// spWater2�� dyanmic_cast�� ����ȯ�� �ؼ� �� ������� ����ȯ�� �Ұ����ϸ� nullPtr�� ��ȯ�Ѵ�.

	// Pet Dog Cat...
	// Cat* catPtr = dynamic_cast<Cat*>(myPet);
	// if(mypet != nullPtr)
	//     catPtr-> Hide();
	// Dog* 
}