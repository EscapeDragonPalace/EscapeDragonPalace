#include "Rabbit.h"

void TriggerClam() {

}

// �̰� rabbit.c�� GetMonsterRect() ����ؼ� �ٽ� �ڵ� ¥�°� ���� ��
void UpdateClam(MyPoint pos, bool alive) {

	// �÷��̾ ���� ���� �ö� �� �ߵ�
	if (player.Pos.x == pos.x && player.Pos.y == pos.y) {
		alive = false;
	}
}

// ���� �׸���
void DrawClam(int posX, int posY) {
	for (int y = 0; y < CLAM_HEIGHT; y++) {
		for (int x = 0; x < CLAM_WIDTH; x++)
		{
			// ���� ��ġ�� ȭ�� ���� ���� ���� ���
			if (posX + x >= 0 && posX + x < SCREEN_WIDTH)
			{
				_DrawText(posX + x, posY + y, (char[]) { g_ClamGraphic[x], 0 });
			}
		}
	}
}

void ClamHitP() {
	player.Health -= E_CLAM_ATTACK;
	player.Speed *= SPEEDDOWN;
}
