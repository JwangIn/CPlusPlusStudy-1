#include "GameCore.h"

void InitializeGame(PlayerState& playerState, WorldState& worldState)
{
	std::cout << "??? 섬에 오신것을 환영합니다." << std::endl;
	std::cout << "이 섬에 대한 추가 정보를 입력해주세요." << std::endl;

	playerState.CurrentPosition.posX = playerState.NewPosition.posX = 3;
	playerState.CurrentPosition.posY = playerState.NewPosition.posY = 3;

	// 첫번째 맵에 대한 정보
	// 0
	{
		std::string MapInfo =
			"###..###"
			"#......#"
			"#......#"
			"#......#"
			"########";

		MapData map = MapData("초원", "경치가 아름다운 곳이다. 앞에 이동할 수 있는 문이 보이는 것 같다.", MapInfo);
		map.MapPosition.posX = 0;
		map.MapPosition.posY = 0;

		worldState.Mapdatas.push_back(map);
	}
	//

	//
}
