#pragma once
#include <string>

enum CommandType // 어떤 종류의 커맨드인지 구분하는 열거형(enum)
{
	CommandTypeNone,

	CommandTypeNorth,
	CommandTypeSouth,
	CommandTypeEast,
	CommandTypeWest,

	CommandTypeQuit,
	CommandTypeGet,
	CommandTypeInventory,
	CommandTypeHelp,
	CommandTypeInfo,

	// 향 후 업데이트 될 내용
};

// char* char[]
// c++ string 클래스
// TypeString string == "W"	 => CommandTypeNorth


class ConsoleTextCommand
{
public:
	CommandType commandType;
	std::string Parameter;	   // 직접 입력받을 문자 데이터 "W" => commandType의 CommandTypeNorth
};

ConsoleTextCommand ParseCommand();
