#include "Rabbit.h"

void UpdateFish(unsigned int now) {

	// monster.c UpdateMonster()�� �̵�

}

// ������� �ּ� ����
void DrawFish(int dir, int posX, int posY) {

	// ȭ�� ���� ���̸� ��� �� ��
	if (posX + FISH_WIDTH < 0 || posX >= SCREEN_WIDTH) return;

	for (int y = 0; y < FISH_HEIGHT; y++) {
		char* line = g_FishGraphic[dir][y];
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
