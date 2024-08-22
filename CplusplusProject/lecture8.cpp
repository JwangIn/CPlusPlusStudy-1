#include "lectures.h"
#include <string>

/*
*  학습 목표 : c++ 상속 기본 문법에 대한 이해
*  작성일 : 2024-08-22
*  작성자 : 박종현
*/

/*
*  상속(inheritance) : 부모로 부터 유산을 이어받는 것
*  부모(클래스) <-> 자식(클래스) 상속한다 : private 멤버 변수 선언. public 함수를 선언해서 멤버 변수를 사용하였다.
*  상속할 수 있는 것 : 부모가 가진 변수, 함수를 자식이 사용한다. 부모가 가진 모든 것을 사용 가능한가?
*/

/*
*  상속에서 자주 사용되는 용어 정리
*  상속을 해주는 클래스 vs 상속을 받는 클래스 
*  부모(parent) vs 자식(child)
*  기반(base) vs 유도,파생(derived)
*  슈퍼(super) vs 서브(sub)
*  상위 vs 하위
*/

/*
*  상속의 기본 기능 : 부모 클래스 (상속 하는 클래스)를 중복하지 않고 사용할 수 있는 문법이다.
*  클래스의 생성자 소멸자 
*/

/*
*  접근 지정자
*  public : public 범위 보다 큰 모든 멤버의 접근을 허용한다. private 이외의 모든 접근을 허용한다.
*  private : 자신 클래스 이외의 모든 클래스의 접근을 막는다. 자식 클래스의 접근도 제한한다.
*  protected : 기본적으로 private과 용도가 같은데, 클래스가 상속되었을 때 자식 클래스의 접근을 허용하는 범위
*  c++ 특별한 상속 문법 : 다중 상속, 이중 상속 문제를 접근 지정자로 해결하기 위해서 private, protected 상속이 존재한다.
*/

/*
*  상속의 세가지 방법 : public 상속, private 상속, protected 상속
*  public 상속 : (부모 클래스) private 이외의 모든 접근을 허용한다. 부모가 갖고 있는 접근지정자와 동일하게 가져온다.
*  protected 상속 : (부모 클래스) private 이외의 모든 접근을 protected 접근으로 변경한다.
*  private 상속 : 모든 접근을 private로 변경한다. 상속을 하는 이유가 없음
*/

/*
*  상속을 언제 해야하는가 ?
*  Is-A : A is B 인가? A가 B인가? child(parent + 추가적으로 child 구현된 기능)가 parent인가?
*  E-Book은 책이다. 책을 클래스로 정의하고 E-Book 책의 내용을 상속 받을 수 있다.
*  Is-A 일 때 상속해라
* 
*  Has-A : A가 B를 소유하고 있다. Police(child)가 Gun(parent)을 소유하고 있다.
*  Police(경찰)
*  Gun(총)
*/

class Book
{
private:
	char* title;
	int price;
public:
	Book(int price, char* title) :price(price) // == this_price=price; 둘이 같다
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
		std::cout << "제목 : " << title << std::endl;
		std::cout << "가격 : " << price << std::endl;
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
	base(int value, int value3) :num1(value), num3(value3) {}  // 멤버 이니셜라이저
	base()
	{
		std::cout << "base() 생성자 호출!" << std::endl;
	}
	void Print()
	{
		num1 = 1;
		std::cout << "base()" << num1 << std::endl;
	}
	~base()
	{
		std::cout << "base() 소멸자 호출!" << std::endl;
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
		std::cout << "derived() 생성자 호출!" << std::endl;
	}
	void dPrintf()
	{
		num3 = 3;
		num2 = 2;
		std::cout << "derived" << num2 <<" " << num3 << std::endl;
	}
	~derived()
	{
		std::cout << "derived() 소멸자 호출!" << std::endl;
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
	// num3의 접근 지정자가 protected로 변경됨
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

class Police // IS-A 인가? HAS-A 인가? 경찰이 총을 소유하고 있다.
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
		std::cout << "발사!" << std::endl;
		std::cout << "남은 총알 수 : " << gun->ShowRemainBullet() << std::endl;
	}
};

class Police2 : public Gun
{
	// 경찰 중에 총을 소유 할 수 있고 안할 수 있다.
	// Has-A Police객체가 Gun을 상속해야할지 말아야할지 판단할 때 Gun클래스 소유안해도 되는 경우도 만들어야하는 case

	// 다른 무기도 소유하게 하고 싶으면 ?


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

// 예제 문제
// 정사각형(Square) 사각형(Rectangle)

// class Rectangle{}
// private : width , height
// 생성자 초기화
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
		std::cout << "사각형의 넓이 :" << width * height << std::endl;
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

	derived d1;  // 자식 클래스는 생성될 때 부모 클래스도 같이 생성해야 한다.
	d1.Print();
	d1.dPrintf();

	// 예제 풀이

	Rectangle re(2, 8);
	re.ShowAreaInfo();
	Square sq(4);
	sq.ShowAreaInfo();

	// protected 상속
	// 객체 지향의 정보 은닉 원칙을 지키려는 문법적 지원이다.
	parent p1;
	p1.num3 = 24;
	child c1;
	// c1.num3 = 100;  num3가 protected로 바뀌어서 변경불가

	//EBook ebook(100, "c++ 예제 문제", "asd8x4s");
	//ebook.ShowEBookInfo();

	Police police;
	police.Shot();

	// Pet 관리 프로그램. 상속으로 표현  Dog, Cat, Bird -> Pet 공통된 요소
	// Dog,Cat,Bird을 돌봐주는 사람 으로 표현하여 Pet이랑 상호작용한다.

}