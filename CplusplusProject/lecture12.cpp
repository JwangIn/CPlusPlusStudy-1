#include "lectures.h"

/*
* 
* 
*/

/*
*  template �� ����ϴ°�?
*  �� ���� ���ϴ� �Լ�(int �� return)
*  �Լ� �����ε� : ���ڱ��� �����ؼ� �Լ��� �����Ѵ�.
*  �ѹ��� int, double, float.. ǥ���ϴ� ����� ������? template
*/

/*
*  template ��� ���
*  �Լ� �̸�<������ Ÿ��>()
*/

/*
*  ��� ����
*  template<typename T> �Լ� ����. �Լ��� ����µ� ����ϴ� ���ø��� �ǹ��Ѵ�.
*  ���ø� �Լ� : Add<int>(3,5);
*/

/*
*  �Լ� ���ø��� ������µ�, ���� ���ø� �Լ��� �����Ǵ°�?
*  Add<int>(3,5);
*  int Add<int>(int num1,int num2)
*  {
*    return num1 + num2;
*  }
*  �Լ� ���ø��� �����ϸ� ���ʿ��� �޸𸮸� ����ϴ� �� �ƴմϱ�?
*  -> Add<int>(3,5); �ڵ尡 �ۼ��Ǿ��� �� (������ ������) int Add<int> ������ �ȴ�.
*  -> ������ ������ T Ÿ�Կ� �ش��ϴ� �Լ��� ����ٸ� ��ǻ�� �ӵ��� ���������� �ʽ��ϱ�?
*  -> ������<->��Ÿ�� ���� : ���α׷� ���� ���� �Լ��� ���� ��������� ������ ���α׷� �ӵ��� ���� x
*/

/*
*  type T, �� T��� �� ����ؾߵǴ°�? (type�� T��)
*  -> �ٸ� ���� ����ص� ���� X
*/

template <typename T>
T Add(T num1, T num2)
{
	return num1 + num2;
}

/*
*  �Լ� ���ø��� ����ȭ(Specialization)
*/
template<>
char Add(char num1, char num2)
{
	std::cout << num1 << num2 << std::endl;
	return 0;
}


template<typename P>
P Minus(P num1, P num2)
{
	std::cout << "num1���� num2�� �� �� : ";
	return num1 - num2;
}

template<class C>
C Multiply(C num1,C num2)
{
	return num1 * num2;
}

// ���� ���� : template <class T> ��õ���� �ʴ´�.
// class Ŭ���� �̸� << Ű����� ȥ���ϴ� ��찡 �־ template Ű����� �ַ� ��� X

template<typename T1,typename T2>
void Showinfo(double a,double b)
{
	std::cout << "a�� T1���� ����ȭ�� �� : " << (T1)a << std::endl << "b�� T2�� ����ȭ�� �� : " << (T2)b << std::endl;

}

template<typename T>
T Divide(T num1,T num2)
{
	return num1 / num2;
}

int Add(int num1, int num2)
{
	return num1 + num2;
}

double Add(double num1, double num2)
{
	return num1 + num2;
}

// Max �� (a, b) ū ���� �������ִ� �Լ�
// ���� ���� ���� ��ϳ�? 
// ���̰� ����� �� ũ��(������),���ھ��� �ƽ�Ű �ڵ尡 ū���� �� ũ��(������) -> ����ȭ�� ���� �������Ͽ� �� ū���� ������

template<typename T>
T Max(T num1, T num2)
{
	return num1 < num2 ? num2 : num1; // ũ�⸦ ���ؼ� ũ�� b �۰ų� ������ a�� ������ �ڵ�
	                      // ������ a�� ������ �Լ���.

	/*
	if (num1 < num2)
	{
		return num2;
	}
	else if (num2 < num1)
	{
		return num1;
	}
	else if (num1 == num2)
	{
		return num1;
	}*/
	
}

template<>
const char* Max<const char*>(const char* num1, const char* num2)
{
	return strlen(num1) < strlen(num2) ? num2 : num1;
}

// Non-type ���ø� : type�� �ƴ� ���ø�

template<typename T, int val>
T Addvalue(T const& curValue)
{
	return curValue + val;
}

const int EventMoney = 10000; // int
const int EventExp = 100;     // double

void lecture12()
{
	std::cout << "int Add(a,b) ��� : " << Add(3, 5) << std:: endl;
	std::cout << "double Add(a,b) ��� : " << Add(3.4, 5.7) << std::endl;
	std::cout << "T Add<int>(a,b) ��� : " << Add<int>(3, 5) << std::endl;
	std::cout << "float Add<float>(a,b) ��� : " << Add<float>(3.4, 5.2) << std::endl;
	std::cout << Add<char>(23, 43) << std::endl;
	std::cout << Minus<int>(7, 2) << std::endl;

	Showinfo<float, int>(3.2, 3.5);

	std::cout << "float Divide<float> ��� : " << Divide<float>(9.5, 3.3)<<std::endl;
	

	std::cout << "Add ���ø� �Լ��� ����ȭ : " << std::endl;
	Add<char>(97, 98);

	std::cout << "�� �Լ� ��� ����" << std::endl;
	std::cout << Max<int>(8, 15) << std::endl;
	// �Լ� ���ø��� <T Ÿ���� ���������ʾƵ�> �����Ϸ��� ������ -> ����� ��ȯ ���� ���, �߸� ��ȯ ���� ���
	
	std::cout << Max("ascx", "xx") << std::endl;

	float myExp = 21.1f;
	int mymoney = 500;

	std::cout << Addvalue<float, EventExp>(myExp) << std::endl;
	std::cout << Addvalue<int, EventMoney>(mymoney) << std::endl;
}