#include "GameObject.h"




bool Board::isNum(std::string& s)
{
	// ���� : bmap �����Ͱ� ���ڸ� true, ���ڸ� false;
	std::string::const_iterator it = s.begin();

	while (it != s.end() && std::isdigit(*it))
	{
		++it;
	}

	return !s.empty() && it == s.end();
}

Board::Board()// ������. size 3. 
{
	size = 3;
	bmap = new std::string * [size];

	// �������迭[����][����]

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
	// ������ �ϼ�
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
	// ������ �ϼ�
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
	// ������ -> �����ʾƷ� �밢��
	for (int i = 0; i < size; i++)
	{
		if (bmap[i][i] != "X")
			break;
		if (i == (size - 1))
			return true;
	}
	// �������� -> ���ʾƷ� �밢��
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
	// ������ �ϼ�
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
	// ������ �ϼ�
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
	// ������ -> �����ʾƷ� �밢��
	for (int i = 0; i < size; i++)
	{
		if (bmap[i][i] != "O")
			break;
		if (i == (size - 1))
			return true;
	}
	// �������� -> ���ʾƷ� �밢��
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
		// x�� o�� ���� ������ش�
		std::cout << std::string(30, '\n');
		std::cout << *this;

		if (xTurn)
		{
			bool inserted = false;
			while (!inserted) // insert_X�� ���������� true�� �Ǿ��� �� while�� ����ȴ�.
			{
				int pos;
				std::cout << "X�� �����Դϴ�. ���ڸ� �Է����ּ���." << std::endl;
				std::cin >> pos;
				inserted = insert_x(pos);
			}
			xTurn = false;
		}
		else if (!xTurn)
		{
			bool inserted = false;
			while (!inserted) // insert_X�� ���������� true�� �Ǿ��� �� while�� ����ȴ�.
			{
				int pos;
				std::cout << "O�� �����Դϴ�. ���ڸ� �Է����ּ���." << std::endl;
				std::cin >> pos;
				inserted = insert_o(pos);
			}
			xTurn = true;
		}

		// ������ ����Ǹ� �¸��� �����ϰ� ����ȭ������ ���ư���. 
		// ������ �����Ѵ�.


		if (x_win())
		{
			std::cout << "X�� �¸��Դϴ�." << std::endl;
			break;
		}
		else if (o_win())
		{
			std::cout << "O�� �¸��Դϴ�." << std::endl;
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
		out << "-" << std::endl << "��";

		for (int j = 0; j < b.GetSize(); ++j)
		{
			std::string item = b.get_item(i, j);
			int len = item.length();

			if (len <= 1)
				out << std::setw(2) << item << std::setw(2) << "��";
			else if (len == 2)
				out << std::setw(1) << item << std::setw(2) << "��";
			else if (len == 3)
				out << std::setw(0) << item << std::setw(2) << "��";

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
