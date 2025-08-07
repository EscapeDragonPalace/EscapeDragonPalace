#include "Rabbit.h"

Monster g_SmallFish = { { 10, MONSTER_Y }, Right, SMALLFISH_HP, true, E_MONSTER_SMALLFISH, 0, 0 }; // 물고기

bool GetSmallFishAlive()
{
	return g_SmallFish.alive;
}

bool GetSmallFishIsDamaged()
{
	return g_SmallFish.isDamaged;
}

MyPoint GetSmallFishPos()
{
	return g_SmallFish.pos;
}

int GetSmallFishDir()
{
	return g_SmallFish.dir;
}

void DrawSmallFish(int dir, int posX, int posY) {
	// 화면 범위 밖이면 출력 안 함
	if (posX + SMALLFISH_WIDTH < 0 || posX >= SCREEN_WIDTH) return;

	for (int y = 0; y < SMALLFISH_HEIGHT; y++) {
		char* line = g_SmallFishGraphic[dir][y];
		int len = strlen(line);

		for (int x = 0; x < len; x++) {
			if (line[x] != ' ') {
				if (0 <= posX + x && posX + x < SCREEN_WIDTH) {
					_DrawText(posX + x, posY + y, (char[]) { line[x], '\0' });
				}
			}
		}
	}

	_SetColor(15);

}

void SmallFishHitP() {
	player.Health -= E_SMALL_FISH_ATTACK;
}