#include <iostream>
#include <cstdlib>
#include <iomanip>

class SampleSTD
{
public:
	SampleSTD(){}

	// �ܼ��� ��� ���� ����� �Լ� (������ ����)
	// setW(����) : ���� ��ŭ ũ�⸦ ä���� �����ش�.
	// std::left : ���� ����
	// std::right : ������ ����
	// std::setfill : ��ĭ�� (����)�� ä���ش�.

	void SetWidthExmaple()
	{
		int a = 42;
		int b = 12345;
		std::cout << std::setfill('!') << std::left << std::setw(10) << a << std::endl;
		std::cout << std::setfill('#') << std::right<< std::setw(20) << b << std::endl;
		int waitnum;
		std::cout << "�� ������ �����Ϸ��� �ƹ� ���ڸ� �Է����ּ���." << std::endl;
		std::cin >> waitnum;
		system("cls");
	}
	void IsDigitExample()
	{
		// �������� ���ڰ� �ƴϸ� false, true ��ȯ���ִ� �Լ�
		bool b;
		b = std::isdigit(10);
		std::cout << b << std::endl;
		bool a;
		if (std::isdigit(a))
		{
			std::cout << "��" << std::endl;
		}

	}
};

// ������
// *ptr : ������
// ptr++ : �ּ� + 1
// ++ptr

class Iterator
{
private:
	int* ptr;
public:
	Iterator(int* p):ptr(p){}

	// ������ �����ε�

	Iterator* operator++()
	{
		++ptr;
		return this;
	}
	Iterator* operator++(int)
	{
		Iterator* temp = this;
		++(*this);
		return temp;
	}

};

// Iterator Ŭ���� std
// �ڷᱸ�� class
// Ŭ���� �ȿ� ������(iterator Ŭ����)

// for�ݺ���

// for(int i=0; i< arr.Length; i++){}
// Iterator s;    s.begin();  s.End();
// while(s.End() != nullptr)
