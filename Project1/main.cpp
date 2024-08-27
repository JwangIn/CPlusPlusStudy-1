#include <iostream>
#include "GameObject.h"

// monster class - 추상 클래스로 표현을 한번 해보자
// Reward class - 경험치, 재화(money), 아이템 
// Is-A, Has-A

// player <-> monster battle system
// battle class. public: bool end: 플레이어가 죽었을 때. 몬스터가 죽었을 때. 플레이어가 도주 할 때
// 무한 반복
// 1. playerturn. 1. 공격 2. 방어 3. 도주
// NextTurn
// 2. MonsterTurn 1. 공격

// 몬스터가 죽으면 monster Class (has, is) -> reward
// Player. GetItem(monster* m1);


int main(void)
{
	std::cout << "RPG BATTLE SYSTEM" << std::endl;

	// 1. 게임 시작 화면

	// 2. 메인 게임 플레이

	// Phase 1. Map Adventure (맵을 돌아다니는 기능) (Step++ RandomEncount : Srand(5 ~25))
	// 특정 타일을 밟으면 몬스터랑 조우할지 안할지 랜덤 함수를 돌린다.

	// Phase 2. Player vs Monster (몬스터를 하나 만들고, 그 몬스터 같지만 다른 varitaion)

	// Player 객체 생성
	// monster 객체 생성
	// monster reward 객체
	// reward item 객체

	// while (true)

}