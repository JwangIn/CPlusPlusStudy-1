#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>

// 클래스 키워드. 이름, 상속을 해야하면 상속을 선언.
// 기능과 멤버 변수 선언 private, public, protected
// 생성자, 소멸자 - 복사생성자, 얕은 복사 - 깊은 복사
// 상속 : virtual <-> 일반 함수
// 다향성 표현 - 클래스의 확장성을 제공해준다.
// virtual 함수(); 자식 함수(이름이 같은) override;
// c++ 형변환. 부모 클래스 -> 자식 클래스로 변환 해주는 dynamic_cast .if 문과 함께 사용해서 안전한 형변환 가능
// template 일반화 코드 작성하는 법

// 틱택토 게임 
// 보드판  3x3  격자판을 만들어야한다. -> 클래스로 표현 class Board
// 기능1 : 플레이어가 돌을 그린다. X 또는 O insert_X, insert_O 
// 기능2 : X_Win, O_Win
// 승리 조건 : 가로줄 완성, 세로줄 완성, 대각선(왼쪽 오른쪽 아래), 대각선(오른쪽 왼쪽 아래)

// 사용하면 좋은 함수들
// std::cin >> input; 숫자인지 아닌지 판별, std::isdigit();
// std::setw() 가로의 길이를 일정하게 맞추어 주는 함수
// 포인터를 클래스로 표현한 것 -> iterator
// 문자열을 클래스로 표현한 것 -> string

class Board
{
	bool isNum(std::string& s);
private:
	int size; // 크기가 3
	std::string** bmap;// 2차원 배열 [세로][가로]
public:
	Board();
	~Board();

	void GamePlay();

	// 2차원 배열에 데이터를 넣는 함수
	bool insert_x(int pos);
	bool insert_o(int pos);

	// 2차원 배열안에 데이터가 있는지 없는지 체크 하는 함수
	std::string get_item(int pos) const;
	std::string get_item(int col, int row)const;

	// 보드판에 들어 있는 값을 출력해주는 함수
	void Print();

	bool x_win();
	bool o_win();

	int GetSize()const { return size; }

};

// std::cout 함수를 이용해서 클래스를 출력하겠다.
std::ostream& operator<< (std::ostream& out, const Board b);



