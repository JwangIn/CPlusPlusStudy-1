#include "lectures.h"
#include <string>

/*
*  �н� ��ǥ : c++ ��� �⺻ ������ ���� ����
*  �ۼ��� : 2024-08-22
*  �ۼ��� : ������
*/

/*
*  ���(inheritance) : �θ�� ���� ������ �̾�޴� ��
*  �θ�(Ŭ����) <-> �ڽ�(Ŭ����) ����Ѵ� : private ��� ���� ����. public �Լ��� �����ؼ� ��� ������ ����Ͽ���.
*  ����� �� �ִ� �� : �θ� ���� ����, �Լ��� �ڽ��� ����Ѵ�. �θ� ���� ��� ���� ��� �����Ѱ�?
*/

/*
*  ��ӿ��� ���� ���Ǵ� ��� ����
*  ����� ���ִ� Ŭ���� vs ����� �޴� Ŭ���� 
*  �θ�(parent) vs �ڽ�(child)
*  ���(base) vs ����,�Ļ�(derived)
*  ����(super) vs ����(sub)
*  ���� vs ����
*/

/*
*  ����� �⺻ ��� : �θ� Ŭ���� (��� �ϴ� Ŭ����)�� �ߺ����� �ʰ� ����� �� �ִ� �����̴�.
*  Ŭ������ ������ �Ҹ��� 
*/

/*
*  ���� ������
*  public : public ���� ���� ū ��� ����� ������ ����Ѵ�. private �̿��� ��� ������ ����Ѵ�.
*  private : �ڽ� Ŭ���� �̿��� ��� Ŭ������ ������ ���´�. �ڽ� Ŭ������ ���ٵ� �����Ѵ�.
*  protected : �⺻������ private�� �뵵�� ������, Ŭ������ ��ӵǾ��� �� �ڽ� Ŭ������ ������ ����ϴ� ����
*  c++ Ư���� ��� ���� : ���� ���, ���� ��� ������ ���� �����ڷ� �ذ��ϱ� ���ؼ� private, protected ����� �����Ѵ�.
*/

/*
*  ����� ������ ��� : public ���, private ���, protected ���
*  public ��� : (�θ� Ŭ����) private �̿��� ��� ������ ����Ѵ�. �θ� ���� �ִ� ���������ڿ� �����ϰ� �����´�.
*  protected ��� : (�θ� Ŭ����) private �̿��� ��� ������ protected �������� �����Ѵ�.
*  private ��� : ��� ������ private�� �����Ѵ�. ����� �ϴ� ������ ����
*/

/*
*  ����� ���� �ؾ��ϴ°� ?
*  Is-A : A is B �ΰ�? A�� B�ΰ�? child(parent + �߰������� child ������ ���)�� parent�ΰ�?
*  E-Book�� å�̴�. å�� Ŭ������ �����ϰ� E-Book å�� ������ ��� ���� �� �ִ�.
*  Is-A �� �� ����ض�
* 
*  Has-A : A�� B�� �����ϰ� �ִ�. Police(child)�� Gun(parent)�� �����ϰ� �ִ�.
*  Police(����)
*  Gun(��)
*/

class Book
{
private:
	char* title;
	int price;
public:
	Book(int price, char* title) :price(price) // == this_price=price; ���� ����
	{
		title = new char[strlen(title) + 1];
		strcpy_s(this->title, strlen((title)+1), title);
	}
	
	~Book()
	{
		delete[] title;
	}
	void ShowBookInfo() 
	{
		std::cout << "���� : " << title << std::endl;
		std::cout << "���� : " << price << std::endl;
	}
};

class EBook :public Book
{
private:
	char* DRMkey;
public:
	EBook(int price,  char* title,  char* key) :Book(price, title)
	{
		key = new char[strlen(key) + 1];
		strcpy_s(DRMkey, strlen((key)+1), key);
	}
	void ShowEBookInfo() 
	{
		ShowBookInfo();
		std::cout << "DRMkey : " << DRMkey << std::endl;
	}
	~EBook()
	{
		delete[] DRMkey;
	}
};

class base
{
private:
	int num1;
protected: 
	int num3;
public:
	base(int value, int value3) :num1(value), num3(value3) {}  // ��� �̴ϼȶ�����
	base()
	{
		std::cout << "base() ������ ȣ��!" << std::endl;
	}
	void Print()
	{
		num1 = 1;
		std::cout << "base()" << num1 << std::endl;
	}
	~base()
	{
		std::cout << "base() �Ҹ��� ȣ��!" << std::endl;
	}
};

class derived : public base
{
private:
	int num2;
public:
	derived(int value):num2(value){}
	derived()
	{
		std::cout << "derived() ������ ȣ��!" << std::endl;
	}
	void dPrintf()
	{
		num3 = 3;
		num2 = 2;
		std::cout << "derived" << num2 <<" " << num3 << std::endl;
	}
	~derived()
	{
		std::cout << "derived() �Ҹ��� ȣ��!" << std::endl;
	}
};

class parent
{
private:
	int num1;
protected:
	int num2;
public:
	int num3;
};

class child : protected parent
{
	// num3�� ���� �����ڰ� protected�� �����
};

class Gun
{
protected:
	int bulletCount;
public:
	Gun();
	Gun(int bullet)
	{
		bulletCount = bullet;
	}
	void UseGun()
	{
		bulletCount--;
	}
	int ShowRemainBullet()
	{
		return bulletCount;
	}

};

class Police // IS-A �ΰ�? HAS-A �ΰ�? ������ ���� �����ϰ� �ִ�.
{
private:
	Gun* gun;
public:
	Police()
	{
		gun = new Gun(10);

	}
	void Shot()
	{
		gun->UseGun();
		std::cout << "�߻�!" << std::endl;
		std::cout << "���� �Ѿ� �� : " << gun->ShowRemainBullet() << std::endl;
	}
};

class Police2 : public Gun
{
	// ���� �߿� ���� ���� �� �� �ְ� ���� �� �ִ�.
	// Has-A Police��ü�� Gun�� ����ؾ����� ���ƾ����� �Ǵ��� �� GunŬ���� �������ص� �Ǵ� ��쵵 �������ϴ� case

	// �ٸ� ���⵵ �����ϰ� �ϰ� ������ ?


};

/*
class derived2
{
private:
	int num1;
	int num2;
public:
	void Print()
	{
		num1 = 1;
		std::cout << "base()" << num1 << std::endl;
	}
	void dPrintf()
	{
		num2 = 2;
		std::cout << "derived()" << num2 << std::endl;
	}
};
*/

// ���� ����
// ���簢��(Square) �簢��(Rectangle)

// class Rectangle{}
// private : width , height
// ������ �ʱ�ȭ
// Rectangle(int width,int height) : width(width),height(height)
// public : ShowAreaInfo(width * height)
// 
// class Square : public Rectangle



class Rectangle
{
private: 
	int width;
	int height;
public:
	Rectangle(int width,int height) : width(width),height(height)
	{

	}
	void ShowAreaInfo()
	{
		std::cout << "�簢���� ���� :" << width * height << std::endl;
	}
};

class Square : public Rectangle
{
public:
	Square(int size) : Rectangle(size,size){}
};

void lecture8()
{
	base b1(1,3);
	b1.Print();

	derived d1;  // �ڽ� Ŭ������ ������ �� �θ� Ŭ������ ���� �����ؾ� �Ѵ�.
	d1.Print();
	d1.dPrintf();

	// ���� Ǯ��

	Rectangle re(2, 8);
	re.ShowAreaInfo();
	Square sq(4);
	sq.ShowAreaInfo();

	// protected ���
	// ��ü ������ ���� ���� ��Ģ�� ��Ű���� ������ �����̴�.
	parent p1;
	p1.num3 = 24;
	child c1;
	// c1.num3 = 100;  num3�� protected�� �ٲ� ����Ұ�

	//EBook ebook(100, "c++ ���� ����", "asd8x4s");
	//ebook.ShowEBookInfo();

	Police police;
	police.Shot();

	// Pet ���� ���α׷�. ������� ǥ��  Dog, Cat, Bird -> Pet ����� ���
	// Dog,Cat,Bird�� �����ִ� ��� ���� ǥ���Ͽ� Pet�̶� ��ȣ�ۿ��Ѵ�.

}