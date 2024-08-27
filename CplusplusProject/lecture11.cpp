#include "lectures.h"

/*
*  1. c++ casting ������ ����
*  
*  2. virtual ���� �Լ��� ���� ���� [��ü ���� ���α׷����� �پ缺]
*  pure virtual
*  abstaract Ŭ����
*  vtable
* 
*  3. monster class(Goblin, Slime class) - Player ����
* 
*  4. ���� ��� Reward - Monster �׾��� �� �����ϴ� ������
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
     //  2. virtual ���� �Լ��� ���� ����[��ü ���� ���α׷����� �پ缺]
     //  pure virtual : Pet_void Sound(Pet* pet) ��, �����, �� �������� �κ��� Pet. ���� �Ҹ�
	 //  Pet Ŭ���� ��ü�� �߻����� �����̴�. 
	 // 
	 // 
     //  abstaract Ŭ����
     //  vtable 


class NewPet
{
public:
	virtual void Sound() = 0; // ���� ���� �Լ� -> NewPet�� ��ӹ޴� Dog, Cat Sound ������Ѷ�

};

// ���� ���� �Լ� pure virtual function
// ��� : �ݵ�� �������̵� �Ǿ�� �ϴ� �Լ�
// ���� ���� �Լ��� �����ϰ� �ִ� Ŭ������ �߻� Ŭ������� �Ѵ�.
// �߻� Ŭ������ �ݵ�� �ϳ� �̻��� ����� �ʿ��ϴ�.
// NewPet*
// NewPet np1;

// virtual ���� �Լ��� ����ϴ� Ŭ������ ��� �����ؼ� ����� �� �ִ�.
// ��� �Լ��� virtual �Լ� (���� �Լ�) �����ص� ������ ���� �ʳ���?

// virtual Ű���� �Է��ϴ� �ǹ� : �Է����� ������ Ű���尡 �۵����� �ʴ´�.

// �� c++ �⺻ �������� virtual�� ������� �ʴ°�?
// virtual ���������� vTable ������ �����Ѵ�. vPtr;
// virtual �������� �ʾ��� �� : �ٷ� �ش� �Լ��� �����Ѵ�.

// ���⼺�� �ʿ��� ���� �����Լ��� ����ϴ� ���� ����ȭ�� �ӵ��� ���� �ڵ尡 �� �� �ִ�.
// virtual ��� �Լ��� ����ص� ������ ���� �������� �޸�, �ð��� ���ݾ� ������ �ְ� �־���.

// monster class - �߻� Ŭ������ ǥ���� �ѹ� �غ���
// Reward class - ����ġ, ��ȭ(money), ������ 
// Is-A, Has-A

// player <-> monster battle system
// battle class. public: bool end: �÷��̾ �׾��� ��. ���Ͱ� �׾��� ��. �÷��̾ ���� �� ��
// ���� �ݺ�
// 1. playerturn. 1. ���� 2. ��� 3. ����
// NextTurn
// 2. MonsterTurn 1. ����

// ���Ͱ� ������ monster Class (has, is) -> reward
// Player. GetItem(monster* m1);


class NewDog :public NewPet
{
public:
	virtual void Sound()
	{
		std::cout << "�п�!" << std::endl;
	}

	virtual void Play()
	{
		std::cout << "���." << std::endl;
	}
	void DDD()
	{
		std::cout << "DDD" << std::endl;
	}
};






void lecture11()
{
	std::cout << "c++ casting ������" << std::endl;
	std::cout << "1. static_cast<type>" << std::endl;
	// �⺻ �ڷ����� ��ȯ, ������ �� ���� ��ȯ, ��� ������ Ŭ���� ��ȯ�� ���� �� �ִ�.

	double pi = 3.14;
	int pi_int =(int) (3.14 - 0.14); // (int)3.00000001 �� �ٻ�ġ �� ��ȯ // 3 - 0
	int pi_int2 = static_cast<int>(pi);
	std::cout << "pi_int�� �� : " << pi_int << std::endl;
	std::cout << "pi_int2�� �� : " << pi_int2 << std::endl;

	// ù��°, 
	AA* aPtr1 = new AA();
	aPtr1->Show();
	AA* aPtr2 = new BB();
	aPtr2->Show();
	AA* aPtr3 = new CC();

	// static_cast ��Ӱ����� Ŭ������ ǥ��

	BB* bPtr1=static_cast<BB*>(aPtr2);
	bPtr1->Show();
	bPtr1->MyBB();

	BB* bPtr2 = static_cast<BB*>(aPtr3);
	bPtr2->Show();
	bPtr2->MyBB();

	// static_cast<type> : ���� ��ü�� ������ TYPE���·� ����ȯ�� ��Ų��.

	// ��� ������ Ŭ������ ����ȯ dynamic_cast


	CC* cPtr1 = dynamic_cast<CC*>(aPtr3);
	if(cPtr1!=nullptr) // C��� NULL #define NULL 0. ������ ���� 0. ����Ű�� �ּҰ� ����. nullptr
	cPtr1->MyCC();

	//const_cast : const Ű���带 ���Ĺ޴� ������ ������� ���ִ� ��ȯ

	const int num = 10;
	int* NonConstNum = const_cast<int*>(&num);
	*NonConstNum = 12;

	std::cout << "num2�� �� : " << num << std::endl;
	std::cout << "NonConstNum�� �� : " << NonConstNum << std::endl;

	// reinterpret_cast

	// int 16 = 0 0 0 00001000()
	// char 63 = 0111119090

	int num2 = 63; // int �� �ּҰ�  char�ּҶ�  ���� ����ȯ
	char* charPtr = reinterpret_cast<char*>(&num2);
	std::cout << "�����·� ���� ����ȯ : " << *charPtr<<std::endl;

	double*  interPtrValue = reinterpret_cast<double*>(&num2);
	std::cout << "������ ������ �Ǽ��� ��ȯ" << *interPtrValue << std::endl;

	NewPet* nP1 = new NewDog();
	nP1->Sound();

	

	NewDog* nD1 = dynamic_cast<NewDog*>(nP1);

	nD1->DDD();











}