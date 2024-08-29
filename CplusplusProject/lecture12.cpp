#include "lectures.h"

/*
* 
* 
*/

/*
*  template 왜 사용하는가?
*  두 수를 더하는 함수(int 값 return)
*  함수 오버로딩 : 인자까지 포함해서 함수를 구분한다.
*  한번에 int, double, float.. 표현하는 방법이 없을까? template
*/

/*
*  template 사용 방법
*  함수 이름<데이터 타입>()
*/

/*
*  용어 정리
*  template<typename T> 함수 정의. 함수를 만드는데 사용하는 템플릿을 의미한다.
*  템플릿 함수 : Add<int>(3,5);
*/

/*
*  함수 템플릿만 만들었는데, 언제 템플릿 함수가 생성되는가?
*  Add<int>(3,5);
*  int Add<int>(int num1,int num2)
*  {
*    return num1 + num2;
*  }
*  함수 템플릿은 서언하면 불필요한 메모리를 사용하는 것 아닙니까?
*  -> Add<int>(3,5); 코드가 작성되었을 때 (컴파일 시점에) int Add<int> 생성이 된다.
*  -> 컴파일 시점에 T 타입에 해당하는 함수를 만든다면 컴퓨터 속도가 느려지지는 않습니까?
*  -> 컴파일<->런타임 시점 : 프로그램 시작 전에 함수가 전부 만들어지기 때문에 프로그램 속도에 영향 x
*/

/*
*  type T, 꼭 T라는 언어를 사용해야되는가? (type의 T임)
*  -> 다른 문자 사용해도 문제 X
*/

template <typename T>
T Add(T num1, T num2)
{
	return num1 + num2;
}

/*
*  함수 템플릿의 전문화(Specialization)
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
	std::cout << "num1에서 num2을 뺀 값 : ";
	return num1 - num2;
}

template<class C>
C Multiply(C num1,C num2)
{
	return num1 * num2;
}

// 권장 사항 : template <class T> 추천하지 않는다.
// class 클래스 이름 << 키워드와 혼동하는 경우가 있어서 template 키워드로 주로 사용 X

template<typename T1,typename T2>
void Showinfo(double a,double b)
{
	std::cout << "a를 T1으로 형변화한 값 : " << (T1)a << std::endl << "b를 T2로 형변화한 값 : " << (T2)b << std::endl;

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

// Max 비교 (a, b) 큰 수를 리턴해주는 함수
// 문자 비교의 경우는 어떡하나? 
// 길이가 긴것이 더 크다(재정의),문자안의 아스키 코드가 큰것이 더 크다(재정의) -> 전문화를 통해 재정의하여 더 큰것을 정하자

template<typename T>
T Max(T num1, T num2)
{
	return num1 < num2 ? num2 : num1; // 크기를 비교해서 크면 b 작거나 같으면 a가 나오는 코드
	                      // 같으면 a가 나오는 함수다.

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

// Non-type 템플릿 : type이 아닌 템플릿

template<typename T, int val>
T Addvalue(T const& curValue)
{
	return curValue + val;
}

const int EventMoney = 10000; // int
const int EventExp = 100;     // double

void lecture12()
{
	std::cout << "int Add(a,b) 출력 : " << Add(3, 5) << std:: endl;
	std::cout << "double Add(a,b) 출력 : " << Add(3.4, 5.7) << std::endl;
	std::cout << "T Add<int>(a,b) 출력 : " << Add<int>(3, 5) << std::endl;
	std::cout << "float Add<float>(a,b) 출력 : " << Add<float>(3.4, 5.2) << std::endl;
	std::cout << Add<char>(23, 43) << std::endl;
	std::cout << Minus<int>(7, 2) << std::endl;

	Showinfo<float, int>(3.2, 3.5);

	std::cout << "float Divide<float> 출력 : " << Divide<float>(9.5, 3.3)<<std::endl;
	

	std::cout << "Add 템플릿 함수의 전문화 : " << std::endl;
	Add<char>(97, 98);

	std::cout << "비교 함수 사용 예제" << std::endl;
	std::cout << Max<int>(8, 15) << std::endl;
	// 함수 템플릿에 <T 타입을 선언하지않아도> 컴파일러가 묵시적 -> 제대로 변환 해줄 경우, 잘못 변환 해줄 경우
	
	std::cout << Max("ascx", "xx") << std::endl;

	float myExp = 21.1f;
	int mymoney = 500;

	std::cout << Addvalue<float, EventExp>(myExp) << std::endl;
	std::cout << Addvalue<int, EventMoney>(mymoney) << std::endl;
}