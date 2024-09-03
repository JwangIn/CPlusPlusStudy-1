#include "GameObject.h"




bool Board::isNum(std::string& s)
{
	// 조건 : bmap 데이터가 숫자면 true, 문자면 false;
	std::string::const_iterator it = s.begin();

	while (it != s.end() && std::isdigit(*it))
	{
		++it;
	}

	return !s.empty() && it == s.end();
}

Board::Board()// 생성자. size 3. 
{
	size = 3;
	bmap = new std::string * [size];

	// 이차원배열[세로][가로]

	for (int i = 0; i < size; i++)
	{
		bmap[i] = new std::string[size];

	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::string num = std::to_string((i * size) + j);
			bmap[i][j] = num;
		}
	}
}

Board::~Board()
{
}

bool Board::insert_x(int pos)
{
	int col = pos / size;
	int row = pos % size;
	if (isNum(bmap[col][row]))
	{
		bmap[col][row] = "X";
		return true;
	}
	else
	{
		return false;
	}
}

bool Board::insert_o(int pos)
{
	int col = pos / size;
	int row = pos % size;
	if (isNum(bmap[col][row]))
	{
		bmap[col][row] = "O";
		return true;
	}
	else
	{
		return false;
	}
}

std::string Board::get_item(int pos) const
{
	int col = pos / size;
	int row = pos % size;

	return bmap[col][row];
}

std::string Board::get_item(int col, int row) const
{
	return bmap[col][row];
}

void Board::Print()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << bmap[i][j];
		}
	}
}

bool Board::x_win()
{
	// 가로줄 완성
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (bmap[i][j] != "X")
				break;
			if (j == (size - 1))
				return true;
		}
	}
	// 세로줄 완성
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (bmap[i][j] != "X")
				break;
			if (i == (size - 1))
				return true;
		}
	}
	// 왼쪽위 -> 오른쪽아래 대각선
	for (int i = 0; i < size; i++)
	{
		if (bmap[i][i] != "X")
			break;
		if (i == (size - 1))
			return true;
	}
	// 오른쪽위 -> 왼쪽아래 대각선
	for (int i = 0; i < size; i++)
	{
		if (bmap[(size - 1) - i][i] != "X")
			break;
		if (i == (size - 1))
			return true;
	}
	return false;
}

bool Board::o_win()
{
	// 가로줄 완성
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (bmap[i][j] != "O")
				break;
			if (j == (size - 1))
				return true;
		}
	}
	// 세로줄 완성
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (bmap[i][j] != "O")
				break;
			if (i == (size - 1))
				return true;
		}
	}
	// 왼쪽위 -> 오른쪽아래 대각선
	for (int i = 0; i < size; i++)
	{
		if (bmap[i][i] != "O")
			break;
		if (i == (size - 1))
			return true;
	}
	// 오른쪽위 -> 왼쪽아래 대각선
	for (int i = 0; i < size; i++)
	{
		if (bmap[(size - 1) - i][i] != "O")
			break;
		if (i == (size - 1))
			return true;
	}
	return false;
}



void Board::GamePlay()
{
	bool xTurn = true;
	while (!o_win() && !x_win())
	{
		// x와 o의 턴을 만들어준다
		std::cout << std::string(30, '\n');
		std::cout << *this;

		if (xTurn)
		{
			bool inserted = false;
			while (!inserted) // insert_X가 정상적으로 true가 되었을 때 while이 종료된다.
			{
				int pos;
				std::cout << "X의 차례입니다. 숫자를 입력해주세요." << std::endl;
				std::cin >> pos;
				inserted = insert_x(pos);
			}
			xTurn = false;
		}
		else if (!xTurn)
		{
			bool inserted = false;
			while (!inserted) // insert_X가 정상적으로 true가 되었을 때 while이 종료된다.
			{
				int pos;
				std::cout << "O의 차례입니다. 숫자를 입력해주세요." << std::endl;
				std::cin >> pos;
				inserted = insert_o(pos);
			}
			xTurn = true;
		}

		// 게임이 종료되면 승리를 선언하고 메인화면으로 돌아간다. 
		// 게임을 종료한다.


		if (x_win())
		{
			std::cout << "X의 승리입니다." << std::endl;
			break;
		}
		else if (o_win())
		{
			std::cout << "O의 승리입니다." << std::endl;
		}

	}
}

std::ostream& operator<<(std::ostream& out, const Board b)
{

	for (int i = 0; i < b.GetSize(); ++i)
	{
		out << std::endl;
		for (int j = 0; j < b.GetSize(); ++j)
		{
			out << "----";
		}
		out << "-" << std::endl << "│";

		for (int j = 0; j < b.GetSize(); ++j)
		{
			std::string item = b.get_item(i, j);
			int len = item.length();

			if (len <= 1)
				out << std::setw(2) << item << std::setw(2) << "│";
			else if (len == 2)
				out << std::setw(1) << item << std::setw(2) << "│";
			else if (len == 3)
				out << std::setw(0) << item << std::setw(2) << "│";

		}
	}
	out << std::endl;
	for (int j = 0; j < b.GetSize(); ++j)
	{
		out << "----";
	}
	out << "-";
	out << std::endl;
	return out;

}
